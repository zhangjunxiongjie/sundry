#include "public.h"

// ��ϰ

// �ع�����ĳ����������߳��������ܺ͡�����������ദ�����������ںˣ�Ӧ�����̼߳���ִ��ʱ�䡣
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

// ͨ�����ô�����������ͬʱִ�ж���̣߳�����1һ�㻯�����磬������������ĸ��ںˣ���Ӧ�������ĸ��̡߳�
void exercise1()
{
}

// �޸�����ĳ����� main() ���Լ����߳���ִ�� thread()������Ӧ���ܹ������ܺͣ�Ȼ��ѽ�����뵽��׼������Ρ�
// �����Ը��� calculate()��print() �� thread() ��ʵ�֣�ÿ�������Ľӿ����豣��һ�¡�Ҳ����˵ÿ������Ӧ����Ȼû���κβ�����
// Ҳ����Ҫ����һ��ֵ��
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

// ʵ��
void test_thread()
{
	for (int i = 0; i < 10; i++)
	{
		wait(1);
		std::cout << "thread: " << i << std::endl;
	}

	std::cout << boost::this_thread::get_id() << std::endl; // �߳�id
}
void test_boost_thread()
{
	boost::thread t(test_thread);  // �̱߳�����ʱ����ʼ���С�

	for (int i = 0; i < 10; i++)
	{
		wait(1);
		std::cout << "main: " << i << std::endl;
	}

	std::cout << boost::this_thread::get_id() << std::endl; // �߳�id

	t.join();
}



// ����
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

    clock_t timeDot = clock(); // ��ʱ

    worker[0].setup(n_tmp, a_tmp, b_tmp); // object part initial
    for (j = 1; j < number_threads; j++) // worker[0] �������洦��
    {
        n_tmp = n + 1;  // ÿ���߳���Ҫ�����Ԫ�ظ�����
        a_tmp = a_tmp + n - 1; // �ı�������ʼָ�롣
        b_tmp = b_tmp + n - 1;
        
        if (j == (number_threads - 1)) // ���һ���߳�ʱ
        {
            n_tmp = n_total - j * n + 2; // �����ʣ���Ԫ�ظ�����ȫ���������һ���̴߳���
            std::cout << "n_tmp: " << n_tmp << std::endl; 
        }

        worker[j].setup(n_tmp, a_tmp, b_tmp); // part initial

        // create this thread
        bthread[j] = new boost::thread(worker[j]); // 
    }

    // do this threads protion of the work
    worker[0]();   // ���̴߳��� worker[0] 

    // wait for other threads to finish
    for (j = 1; j < number_threads; j++) // �ȴ������߳���ɡ�
    {
        bthread[j]->join();
        delete bthread[j];
    }

    clock_t timeDot1 = clock(); //
    worker[0].setup(n_total, a, b);
    boost::thread single(worker[0]);
    single.join();
    clock_t timeDot2 = clock(); // 

    // more thread than single thread. ���̵߳����ܷ�����
    std::cout << "more thread: " << double(timeDot1 - timeDot) / CLOCKS_PER_SEC << std::endl;
    std::cout << "single thread: " << double(timeDot2 - timeDot1) / CLOCKS_PER_SEC << std::endl;

    // check the result
    float eps = 100.f * std::numeric_limits<float>::epsilon();
    for (i = 1; i < n_total; i++)
    {
        std::cout << "b" << i << ": " << b[i] << std::endl;
        ok &= std::fabs((2. * b[i] - a[i] - a[i - 1]) / b[i]) <= eps; // &= ��λ���Ҹ�ֵ�����
    }

    delete[] a;
    delete[] b;

    return ok;
}
