#include "public.h"

// 练习

// 重构下面的程序用两个线程来计算总和。由于现在许多处理器有两个内核，应利用线程减少执行时间。
void exercise()
{
	boost::posix_time::ptime start = boost::posix_time::microsec_clock::local_time();

	boost::uint64_t sum = 0;
	for (int i = 0; i < 1000000000; ++i)
		sum += i;

	boost::posix_time::ptime end = boost::posix_time::microsec_clock::local_time();
	std::cout << end - start << std::endl;

	std::cout << sum << std::endl;
}

// 通过利用处理器尽可能同时执行多的线程，把例1一般化。例如，如果处理器有四个内核，就应该利用四个线程。
void exercise1()
{
}

// 修改下面的程序，在 main() 中自己的线程中执行 thread()。程序应该能够计算总和，然后把结果输入到标准输出两次。
// 但可以更改 calculate()，print() 和 thread() 的实现，每个函数的接口仍需保持一致。也就是说每个函数应该仍然没有任何参数，
// 也不需要返回一个值。
int ExerciseSum = 0;
void exercise2_calculate()
{
	for (int i = 0; i < 1000; ++i)
		ExerciseSum += i;
}

void exercise2_print()
{
	std::cout << ExerciseSum << std::endl;
}
void exercise2_thread()
{
	exercise2_calculate();
	exercise2_print();
}
void exercise2()
{
	exercise2_thread();
}

// 实验
void test_thread()
{
	for (int i = 0; i < 10; i++)
	{
		wait(1);
		std::cout << "thread: " << i << std::endl;
	}

	std::cout << boost::this_thread::get_id() << std::endl; // 线程id
}
void test_boost_thread()
{
	boost::thread t(test_thread);  // 线程被创建时即开始运行。

	for (int i = 0; i < 10; i++)
	{
		wait(1);
		std::cout << "main: " << i << std::endl;
	}

	std::cout << boost::this_thread::get_id() << std::endl; // 线程id

	t.join();
}



// 测试
# define NUMBER_THREADS 4
namespace {
    class worker_t
    {
    private:
        int    n_;
        float* a_;
        float* b_;
    public:
        void setup(size_t n, float* a, float* b)
        {
            n_ = static_cast<int>(n);
            a_ = a;
            b_ = b;
        }
        void a1(int n, float* a, float* b)
        {
            int i;
            
            for (i = 1; i < n; i++)
            {
                b[i] = (a[i] + a[i - 1]) / 2.0f; 
            }
                
            return;
        }
        void operator()()
        {
            a1(n_, a_, b_);
        }
    };
}
bool test_boost_thread_a11c(void)
{
    bool ok = true;

    // Test setup
    size_t i, j, n_total = 10;
    float* a = new float[n_total];
    float* b = new float[n_total];
    
    for (i = 0; i < n_total; i++)
        a[i] = float(i); // array initial

    // number of threads
    size_t number_threads = NUMBER_THREADS;

    // set of workers
    worker_t worker[NUMBER_THREADS]; // object array

    // threads for each worker
    boost::thread* bthread[NUMBER_THREADS]; // thread pointer array

    // Break the work up into sub work for each thread
    size_t  n = n_total / number_threads; // 
    size_t  n_tmp = n;
    float* a_tmp = a;
    float* b_tmp = b;

    clock_t timeDot = clock(); // 计时

    worker[0].setup(n_tmp, a_tmp, b_tmp); // object part initial
    for (j = 1; j < number_threads; j++) // worker[0] 放在外面处理。
    {
        n_tmp = n + 1;  // 每个线程需要处理的元素个数。
        a_tmp = a_tmp + n - 1; // 改变数组起始指针。
        b_tmp = b_tmp + n - 1;
        
        if (j == (number_threads - 1)) // 最后一个线程时
        {
            n_tmp = n_total - j * n + 2; // 计算出剩余的元素个数。全部交给最后一个线程处理。
            std::cout << "n_tmp: " << n_tmp << std::endl; 
        }

        worker[j].setup(n_tmp, a_tmp, b_tmp); // part initial

        // create this thread
        bthread[j] = new boost::thread(worker[j]); // 
    }

    // do this threads protion of the work
    worker[0]();   // 主线程处理 worker[0] 

    // wait for other threads to finish
    for (j = 1; j < number_threads; j++) // 等待其他线程完成。
    {
        bthread[j]->join();
        delete bthread[j];
    }

    clock_t timeDot1 = clock(); //
    worker[0].setup(n_total, a, b);
    boost::thread single(worker[0]);
    single.join();
    clock_t timeDot2 = clock(); // 

    // more thread than single thread. 多线程的性能分析。
    std::cout << "more thread: " << double(timeDot1 - timeDot) / CLOCKS_PER_SEC << std::endl;
    std::cout << "single thread: " << double(timeDot2 - timeDot1) / CLOCKS_PER_SEC << std::endl;

    // check the result
    float eps = 100.f * std::numeric_limits<float>::epsilon();
    for (i = 1; i < n_total; i++)
    {
        std::cout << "b" << i << ": " << b[i] << std::endl;
        ok &= std::fabs((2. * b[i] - a[i] - a[i - 1]) / b[i]) <= eps; // &= 按位与且赋值运算符
    }

    delete[] a;
    delete[] b;

    return ok;
}
