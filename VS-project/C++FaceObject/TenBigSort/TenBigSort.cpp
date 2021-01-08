// 此项目使用C++面向对象的方法实现十大排序算法在控制台的动态可视化。
// 看看可不可以使用EasyX库。 

#include <iostream>
#include <vector>
#include <ctime>

#define NUM 100
#define MAX 100

using namespace std;


class StoreTarget
{
public:
	
	StoreTarget(); // 构造函数
	void Look(); // 查看所有成员。
	void Swap(int i, int j); // 数值交换

	void InserSort(); // （直接）插入排序
	void BinaryInserSort(); // 二分插入排序（是对插入排序的一个改进）

	void ShellSort(); // 希尔排序。

	void SelectSort(); // （直接）选择排序
	void TwoSelectSort(); // 双向选择排序。

	void Bubble_Sort(); // 冒泡排序
	void Shaker_Sort(); // 双向冒泡排序。

	void Quick_Sort();
	void Quick_Sort(int left, int right); //快速排序。递归实现

	void MergeSort();
	void MergeSort(int left, int right); // 归并排序。递归实现

	void CountingSort(); // 计数排序。

private:
	
	vector<int> Target; // 排序目标

};

StoreTarget::StoreTarget()
{
	for (int i = 0; i < NUM; i++)
	{
		Target.push_back( rand() % MAX ); // 产生100以内的随机数
	}
}
void StoreTarget::Look() // 查看所有成员。
{
	for (int see = 0; see < Target.size(); see++)
	{
		cout << Target.at(see) << " ";
	}
	cout << endl;
}
void StoreTarget::Swap(int i, int j) // 数值交换
{
	int middle = Target.at(i);
	Target.at(i) = Target.at(j);
	Target.at(j) = middle;
}



void StoreTarget::InserSort() // （直接）插入排序
{
	// 在前面已排序的部分找到一个位置插入当前元素
	for (int i = 1; i < Target.size(); i++)
	{
		int insertNum = Target.at(i); // insertNum当前元素
		int j = i;
		while (j > 0 && insertNum < Target.at(j - 1)) // 依次移动
		{
			Target.at(j) = Target.at(j - 1);
			j--;
		}
		Target.at(j) = insertNum; // 插入
	}
}
void StoreTarget::BinaryInserSort() // 二分插入排序（是对插入排序的一个改进）
{
	// 对直接插入的优化，在查找时是用了折半查找，但是在查找过程中无法实时移动，所以需要额外的移动处理。
	for (int i = 0; i < Target.size(); i++)
	{
		int insertNum = Target.at(i); // insertNum当前元素
		int left = 0;
		int right = i - 1;
		while (left <= right) // 依次移动
		{
			int middle = (left + right) / 2;
			if (insertNum > Target.at(middle))
				left = middle + 1;
			else
				right = middle - 1;
		}
		for (int j = i; j > left; j--) // 移动
		{
			Target.at(j) = Target.at(j - 1);
		}

		Target.at(left) = insertNum; // 插入
	}
}

void StoreTarget::ShellSort() // 希尔排序。
{
	// 将待排序序列分为由（Target.size()/gap）个元素组成的gap个组，然后依次对每个小的组进行直接插入排序，然后逐渐减小组数gap。分治法的思想。
	int gap = Target.size() / 2;
	// 此处实现上使用的是将gap作为间隔，相隔gap个位置的元素为一组，依次对每一组进行排序，然后减小间隔直到间隔为1时相当于对整个序列进行插入排序。
	// 这里的gap可以修改为number即每组的元素个数（逐渐增大），使得排序始终在一个连续的组序列（组序列逐渐增大）中进行，而不是在相隔gap个位置的元素间进行。
	// 如果这样修改就有点类似于归并排序了。
	while (gap)
	{
		for (int i = gap; i < Target.size(); i++)
		{
			int inserNum = Target.at(i);
			int j = i;
			while (j >= gap && inserNum < Target.at(j - gap)) // 对每一个小组进行直接插入排序。
			{
				Target.at(j) = Target.at(j - gap);
				j -= gap;
			}
			Target.at(j) = inserNum;
		}
		gap = gap / 2;
	}
}

void StoreTarget::SelectSort() // （直接）选择排序
{
	// 在剩余未排序的序列中找出最大或最小的那一个填充到已排序的序列末尾。
	// 一种改进的方法是在未排序的序列中同时寻找最大的书和最小的数，然后将其分别放在两端。
	for (int i = 0; i < Target.size(); i++)
	{
		int k = i;
		for (int j = i + 1; j < Target.size(); j++)
		{
			if (Target.at(j) < Target.at(k))
			{
				k = j;
			}
		}

		// 交换
		Swap(k, i);
	}

}
void StoreTarget::TwoSelectSort() // 双向选择排序。
{
	// 对直接选择排序的一种优化。
	int left = 0, right = Target.size() - 1;
	for ( ; left <= right; left++, right--) // 在未排序序列中分别找到最大值和最小值然后分别放在头部和尾部。
	{
		int min = left;
		int max = right;
		for (int j = left; j <= right; j++)
		{
			if (Target.at(j) < Target.at(min))
			{
				min = j;
			}
			if (Target.at(j) > Target.at(max))
			{
				max = j;
			}
		}

		// 交换
		Swap(min, left);
		Swap(max, right);
	}
}

void StoreTarget::Bubble_Sort() // 冒泡排序
{
	/*
	// 这种实现就有点类似于直接选择排序了，实际就是在未排序的序列中找出一个最大或最小的元素放在已排序序列末尾，只是在找这个元素的过程中，每次都在交换。
	for (int i = 0; i < Target.size(); i++)
	{
		for (int j = i + 1; j < Target.size(); j++)
		{
			if (Target.at(i) > Target.at(j))
			{
				Swap(i, j); // 数值交换
			}
		}
	}
	*/
	// 私认为更准确的冒泡实现，当某一次循环未做任何交换时实际上就可以直接结束排序了。
	for (int i = Target.size(); i > 0; i--)
	{
		for (int j = 1; j < i; j++)
		{
			if (Target.at(j - 1) > Target.at(j))
			{
				Swap(j - 1, j); // 数值交换
			}
		}
	}
	
}
void StoreTarget::Shaker_Sort() // 双向冒泡排序，对冒泡排序的一种改进方法。
{
	int left = 0, right = Target.size() - 1, shift = 0;
	while (left < right)
	{
		for (int i = left; i < right; i++) // 向右冒泡
		{
			if (Target.at(i) > Target.at(i + 1))
			{
				Swap(i, i + 1);
				shift = i;
			}
		}

		right = shift; // 更改未排序区间。此处为何可以这样缩小区间？？？
		
		for (int i = right; i > left; i--) // 向左冒泡。
		{
			if (Target.at(i) < Target.at(i - 1))
			{
				Swap(i, i - 1);
				shift = i;
			}
		}

		left = shift;
	}

}

void StoreTarget::Quick_Sort() // 递归入口
{
	
	Quick_Sort(0, Target.size() - 1);

}
void StoreTarget::Quick_Sort(int left, int right) //快速排序。
{
	// 找一个基准元素，将待排序序列中大于基准元素的项放在一边其余放在另一边，然后递归的对基准元素前面的序列和后面的序列进行排序。
	int i = left, j = right; // 从两头分别开始放大于和小于基准元素的项。
	int pivot = Target.at(left); // 基准项，基准项的选取策略决定着算法的效率
	while (i < j) // 将大于和小于基准元素的项分开放在基准元素的两头。
	{
		while (i < j && Target.at(j) >= pivot) j--; // 找出小于基准元素的项（如果是大于等于的话则继续循环不须操作），放到前面。
		if (i < j) Swap(i, j);

		while (i < j && Target.at(i) <= pivot) i++; // 找出大于基准元素的项
		if (i < j) Swap(i, j);
		
	}
	if (i != left) 
	{
		Quick_Sort(left, i - 1); // 
	}
	if (j != right)
	{
		Quick_Sort(j + 1, right);
	}
}

void StoreTarget::MergeSort()
{
	MergeSort(0, Target.size() - 1);
}
void StoreTarget::MergeSort(int left, int right)   // 归并排序。递归实现
{
	if (left >= right)
	{
		return;
	}
	else
	{
		int middle = (left + right) / 2;

		MergeSort(left, middle); // 先对左右两部分分别进行归并排序，然后对这两部分进行归并。
		MergeSort(middle + 1, right);

		// 进行有序序列的归并，这里在归并时要么使用额外的空间，要么就要消耗更多的时间用于移动。
		// 这里直接使用插入排序的思路，但是这样的话只是有效利用了前面的排序序列，而没有有效利用后面的有序序列。
		// 这里归并的方法还有待优化。
		for (int i = middle; i <= right; i++)
		{
			int insert = Target.at(i);
			int j = i;
			while (j > 0 && insert < Target.at(j - 1))
			{
				Target.at(j) = Target.at(j - 1);
				j--;
			}

			Target.at(j) = insert;
		}
	}
}

void StoreTarget::CountingSort() // 计数排序。
{
	// 通过对每个元素的计数以确定每个元素的位置，当数据值间隔较大时可以加一层映射以减少内存消耗。
	int* result = new int[Target.size()];
	int* mark = new int[MAX]; // MAX表示序列中最大的数。
	memset(mark, 0, MAX * sizeof(int)); // 对辅助数组进行初始化
	
	// 统计每个元素出现的次数
	for (int i = 0; i < Target.size(); i++) mark[Target.at(i)]++;
	
	// 计算元素在有序表中的位置 
	for (int i = 1; i < MAX; i++) mark[i] += mark[i - 1];
	
	// 将每个元素填入到计算确定的位置中。
	for (int i = Target.size() - 1; i >= 0; i--)
	{
		result[--mark[Target.at(i)]] = Target.at(i);
		/*
		result[mark[Target.at(i)] - 1] = Target.at(i);
		mark[Target.at(i)]--;
		*/
	}
	for (int i = 0; i < Target.size(); i++)
	{
		Target.at(i) = result[i];
	}

	delete result;
	delete mark;
}

int main()
{
	srand( (int)time(NULL) );   // 产生随机种子  把0换成NULL也行

	StoreTarget wait;

	wait.Look();

	wait.CountingSort();

	wait.Look();

	system("pause");
	return 0;
}
