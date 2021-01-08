
#include "public.h"

/*
本章介绍了 Boost C++ 库 Asio，它是异步输入输出的核心。名字本身就说明了一切：Asio 意即异步输入/输出。该库可以让 C++ 
异步地处理数据，且平台独立。异步数据处理就是指，任务触发后不需要等待它们完成。相反，Boost.Asio 会在任务完成时
触发一个应用。异步任务的主要优点在于，在等待任务完成时不需要阻塞应用程序，可以去执行其它任务。
异步任务的典型例子是网络应用。如果数据被发送出去了，比如发送至 Internet，通常需要知道数据是否发送成功。如果没有一个
象 Boost.Asio 这样的库，就必须对函数的返回值进行求值。但是，这样就要求待至所有数据发送完毕，并得到一个确认或是错误代码。
而使用 Boost.Asio，这个过程被分为两个单独的步骤：第一步是作为一个异步任务开始数据传输。一旦传输完成，不论成功或是错误，
应用程序都会在第二步中得到关于相应的结果通知。主要的区别在于，应用程序无需阻塞至传输完成，而可以在这段时间里执行其它操作。
*/

/*
使用 Boost.Asio 进行异步数据处理的应用程序基于两个概念：I/O 服务和 I/O 对象。I/O 服务抽象了操作系统的接口，
允许第一时间进行异步数据处理，而 I/O 对象则用于初始化特定的操作。鉴于 Boost.Asio 只提供了一个名为 boost::asio::io_service 
的类作为 I/O 服务，它针对所支持的每一个操作系统都分别实现了优化的类，另外库中还包含了针对不同 I/O 对象的几个类。
其中，类 boost::asio::ip::tcp::socket 用于通过网络发送和接收数据，而类 boost::asio::deadline_timer 则提供了一个计时器，
用于测量某个固定时间点到来或是一段指定的时长过去了。以下第一个例子中就使用了计时器，因为与 Asio 所提供的其它 I/O 对象
相比较而言，它不需要任何有关于网络编程的知识。
*/ 
void handler(const boost::system::error_code& ec)
{
	std::cout << "5 s." << std::endl;
}
void boost_asio()
{
	/*
	函数 main() 首先定义了一个 I/O 服务 io_service，用于初始化 I/O 对象 timer。就象 boost::asio::deadline_timer 那样，
	所有 I/O 对象通常都需要一个 I/O 服务作为它们的构造函数的第一个参数。由于 timer 的作用类似于一个闹钟，
	所以 boost::asio::deadline_timer 的构造函数可以传入第二个参数，用于表示在某个时间点或是在某段时长之后闹钟停止。 
	以上例子指定了五秒的时长，该闹钟在 timer 被定义之后立即开始计时。
	虽然我们可以调用一个在五秒后返回的函数，但是通过调用方法 async_wait() 并传入 handler() 函数的名字作为唯一参数，
	可以让 Asio 启动一个异步操作。请留意，我们只是传入了 handler() 函数的名字，而该函数本身并没有被调用。
	async_wait() 的好处是，该函数调用会立即返回，而不是等待五秒钟。一旦闹钟时间到，作为参数所提供的函数就会被相应调用。 
	因此，应用程序可以在调用了 async_wait() 之后执行其它操作，而不是阻塞在这里。
	像 async_wait() 这样的方法被称为是非阻塞式的。I/O 对象通常还提供了阻塞式的方法，可以让执行流在特定操作完成之前
	保持阻塞。例如，可以调用阻塞式的 wait() 方法，取代 boost::asio::deadline_timer 的调用。由于它会阻塞调用，
	所以它不需要传入一个函数名，而是在指定时间点或指定时长之后返回。
	再看看上面的源代码，可以留意到在调用 async_wait() 之后，又在 I/O 服务之上调用了一个名为 run() 的方法。
	这是必须的，因为控制权必须被操作系统接管，才能在五秒之后调用 handler() 函数。
	async_wait() 会启动一个异步操作并立即返回，而 run() 则是阻塞的。因此调用 run() 后程序执行会停止。 
	
	*/
	boost::asio::io_service io_service;
	
	boost::asio::deadline_timer timer(io_service, boost::posix_time::seconds(5));
	timer.async_wait(handler);
	
	io_service.run();
}

// 具有讽刺意味的是，许多操作系统只是通过阻塞函数来支持异步操作。以下例子显示了为什么这个限制通常不会成为问题。
void handler1(const boost::system::error_code& ec)
{
	std::cout << "5 s." << std::endl;
}
void handler2(const boost::system::error_code& ec)
{
	std::cout << "10 s." << std::endl;
}
void boost_asio1()
{
	/*
	上面的程序用了两个 boost::asio::deadline_timer 类型的 I/O 对象。第一个 I/O 对象表示一个五秒后触发的闹钟，
	而第二个则表示一个十秒后触发的闹钟。每一段指定时长过去后，都会相应地调用函数 handler1() 和 handler2()。
	在 main() 的最后，再次在唯一的 I/O 服务之上调用了 run() 方法。如前所述，这个函数将阻塞执行，把控制权交给操作系统
	以接管异步处理。在操作系统的帮助下，handler1() 函数会在五秒后被调用，而 handler2() 函数则在十秒后被调用。
	乍一看，你可能会觉得有些奇怪，为什么异步处理还要调用阻塞式的 run() 方法。然而，由于应用程序必须防止被中止执行，
	所以这样做实际上不会有任何问题。如果 run() 不是阻塞的，main() 就会结束从而中止该应用程序。如果应用程序不应被阻塞，
	那么就应该在一个新的线程内部调用 run()，它自然就会仅仅阻塞那个线程。
	一旦特定的 I/O 服务的所有异步操作都完成了，控制权就会返回给 run() 方法，然后它就会返回。
	以上两个例子中，应用程序都会在闹钟到时间后马上结束。
	*/

	boost::asio::io_service io_service;
	
	boost::asio::deadline_timer timer1(io_service, boost::posix_time::seconds(5));
	timer1.async_wait(handler1);
	
	boost::asio::deadline_timer timer2(io_service, boost::posix_time::seconds(10));
	timer2.async_wait(handler2);
	
	io_service.run();
}


/*
用 Boost.Asio 这样的库来开发应用程序，与一般的 C++ 风格不同。那些可能需要较长时间才返回的函数不再是以顺序的方式来调用。 
不再是调用阻塞式的函数，Boost.Asio 是启动一个异步操作。而那些需要在操作结束后调用的函数则实现为相应的句柄。
这种方法的缺点是，本来顺序执行的功能变得在物理上分割开来了，从而令相应的代码更难理解。
象 Boost.Asio 这样的库通常是为了令应用程序具有更高的效率。应用程序不需要等待特定的函数执行完成，而可以在期间执行其它任务，
如开始另一个需要较长时间的操作。
可扩展性是指，一个应用程序从新增资源有效地获得好处的能力。如果那些执行时间较长的操作不应该阻塞其它操作的话，
那么建议使用 Boost.Asio.由于现今的PC机通常都具有多核处理器，所以线程的应用可以进一步提高一个基于 Boost.Asio 
的应用程序的可扩展性。
如果在某个 boost::asio::io_service 类型的对象之上调用 run() 方法，则相关联的句柄也会在同一个线程内被执行。 
通过使用多线程，应用程序可以同时调用多个 run() 方法。一旦某个异步操作结束，相应的 I/O 服务就将在这些线程中的
某一个之中执行句柄。如果第二个操作在第一个操作之后很快也结束了，则 I/O 服务可以在另一个线程中执行句柄，
而无需等待第一个句柄终止。
*/
boost::asio::io_service IOService;
void asio_thread_single_service_run()
{
	IOService.run();
}
void boost_asio_thread_single_service()
{
	boost::asio::deadline_timer timer1(IOService, boost::posix_time::seconds(5));
	timer1.async_wait(handler1);
	
	boost::asio::deadline_timer timer2(IOService, boost::posix_time::seconds(5));
	timer2.async_wait(handler2);
	
	boost::thread thread1(asio_thread_single_service_run);
	boost::thread thread2(asio_thread_single_service_run);
	
	thread1.join();
	thread2.join();
}


/*
上一节中的例子现在变成了一个多线程的应用。通过使用在 boost/thread.hpp 中定义的 boost::thread 类，
它来自于 Boost C++ 库 Thread，我们在 main() 中创建了两个线程。这两个线程均针对同一个 I/O 服务调用了 run() 方法。 
这样当异步操作完成时，这个 I/O 服务就可以使用两个线程去执行句柄函数。
这个例子中的两个计时数均被设为在五秒后触发。由于有两个线程，所以 handler1() 和 handler2() 可以同时执行。
如果第二个计时器触发时第一个仍在执行，则第二个句柄就会在第二个线程中执行。如果第一个计时器的句柄已经终止，
则 I/O 服务可以自由选择任一线程。
线程可以提高应用程序的性能。因为线程是在处理器内核上执行的，所以创建比内核数更多的线程是没有意义的。
这样可以确保每个线程在其自己的内核上执行，而没有同一内核上的其它线程与之竞争。
要注意，使用线程并不总是值得的。以上例子的运行会导致不同信息在标准输出流上混合输出，因为这两个句柄可能会并行运行，
访问同一个共享资源：标准输出流 std::cout。这种访问必须被同步，以保证每一条信息在另一个线程可以向标准输出流写出
另一条信息之前被完全写出。在这种情形下使用线程并不能提供多少好处，如果各个独立句柄不能独立地并行运行。
多次调用同一个 I/O 服务的 run() 方法，是为基于 Boost.Asio 的应用程序增加可扩展性的推荐方法。 
另外还有一个不同的方法：不要绑定多个线程到单个 I/O 服务，而是创建多个 I/O 服务。然后每一个 I/O 服务使用一个线程。 
如果 I/O 服务的数量与系统的处理器内核数量相匹配，则异步操作都可以在各自的内核上执行。
*/
boost::asio::io_service IOService1;
boost::asio::io_service IOService2;
void asio_thread_more_service_run1()
{
	IOService1.run();
}
void asio_thread_more_service_run2()
{
	IOService2.run();
}
void boost_asio_thread_more_service()
{
	/*
	前面的那个使用两个计时器的例子被重写为使用两个 I/O 服务。这个应用程序仍然基于两个线程；但是现在每个线程
	被绑定至不同的 I/O 服务。此外，两个 I/O 对象 timer1 和 timer2 现在也被绑定至不同的 I/O 服务。
	这个应用程序的功能与前一个相同。在一定条件下使用多个 I/O 服务是有好处的，每个 I/O 服务有自己的线程，
	最好是运行在各自的处理器内核上，这样每一个异步操作连同它们的句柄就可以局部化执行。如果没有远端的数据或
	函数需要访问，那么每一个 I/O 服务就象一个小的自主应用。这里的局部和远端是指象高速缓存、内存页这样的资源。 
	由于在确定优化策略之前需要对底层硬件、操作系统、编译器以及潜在的瓶颈有专门的了解，所以应该仅在清楚这些
	好处的情况下使用多个 I/O 服务。
	*/
	boost::asio::deadline_timer timer1(IOService1, boost::posix_time::seconds(5));
	timer1.async_wait(handler1);
	
	boost::asio::deadline_timer timer2(IOService2, boost::posix_time::seconds(5));
	timer2.async_wait(handler2);
	
	boost::thread thread1(asio_thread_more_service_run1);
	boost::thread thread2(asio_thread_more_service_run2);
	
	thread1.join();
	thread2.join();
}



/*
虽然 Boost.Asio 是一个可以异步处理任何种类数据的库，但是它主要被用于网络编程。这是由于，事实上 Boost.Asio 
在加入其它 I/O 对象之前很久就已经支持网络功能了。网络功能是异步处理的一个很好的例子，因为通过网络进行数据传输
可能会需要较长时间，从而不能直接获得确认或错误条件。
Boost.Asio 提供了多个 I/O 对象以开发网络应用。以下例子使用了 boost::asio::ip::tcp::socket 类来建立与中另一台PC
的连接，并下载 'Highscore' 主页；就象一个浏览器在指向 www.highscore.de 时所要做的。
*/
boost::asio::io_service AsioIntrnetIOService;
boost::asio::ip::tcp::resolver resolver(AsioIntrnetIOService);
boost::asio::ip::tcp::socket sock(AsioIntrnetIOService);
boost::array<char, 4096> buffer;
void asio_intrnet_read_handler(const boost::system::error_code& ec, std::size_t bytes_transferred)
{
	if (!ec)
	{
		std::cout << std::string(buffer.data(), bytes_transferred) << std::endl;
		sock.async_read_some(boost::asio::buffer(buffer), asio_intrnet_read_handler);
	}
}
void asio_intrnet_connect_handler(const boost::system::error_code& ec)
{
	if (!ec)
	{
		boost::asio::write(sock, boost::asio::buffer("GET / HTTP 1.1\r\nHost: highscore.de\r\n\r\n"));
		sock.async_read_some(boost::asio::buffer(buffer), asio_intrnet_read_handler);
	}
}
void asio_intrnet_resolve_handler(const boost::system::error_code& ec, boost::asio::ip::tcp::resolver::iterator it)
{
	if (!ec)
	{
		sock.async_connect(*it, asio_intrnet_connect_handler);
	}
}
void boost_asio_intrnet()
{
	boost::asio::ip::tcp::resolver::query query("www.highscore.de", "80");

	resolver.async_resolve(query, asio_intrnet_resolve_handler);
	
	AsioIntrnetIOService.run();
}