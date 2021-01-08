// Learn2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// STL 算法 算法用来处理群集内的元素，可以出于不同目的搜寻、排序、修改、使用那些元素。
// 所有容器的迭代器都提供一致的接口，通过迭代器的协助，算法程序可以用于任意容器。
/*
STL 提供了非常多的数据结构算法。这些算法在命名空间 std 的范围内定义，通过包含头文件 <algorithm> 来获得使用权。
常见的部分算法如下：
for_each()；
find()；
find_if()；
count()；
count_if()；
replace()；
replace_if()；
copy()；
unique_copy()；
sort()；
equal_range()；
merge()；
STL 中的所有算法都是基于模板实现的。
*/

#include <iostream> // For standard streams
#include <iomanip>  // For stream manipulators
#include <array>    // For array<T,N>
int main()
{
	const unsigned int min_wt{ 100U };
	const unsigned int max_wt{ 250U };
	const unsigned int wt_step{ 10U };
	const size_t wt_count{ 1 + (max_wt - min_wt) / wt_step };
	const unsigned int min_ht{ 48U };
	const unsigned int max_ht{ 84U };
	const unsigned int ht_step{ 2U };
	const size_t ht_count{ 1 + (max_ht - min_ht) / ht_step };
	const double lbs_per_kg{ 2.20462 };
	const double ins_per_m{ 39.3701 };
	std::array<unsigned int, wt_count> weight_lbs;
	std::array<unsigned int, ht_count> height_ins;
	// Create weights from lOOlbs in steps of lOlbs
	for (size_t i{}, w{ min_wt }; i < wt_count; w += wt_step, ++i)
	{
		weight_lbs.at(i) = w;
	}
	//Create heights from 48 inches in steps of 2 inches
	unsigned int h{ min_ht };
	for (auto& height : height_ins)
	{
		height = h;
		h += ht_step;
	}
	//Output table headings
	std::cout << std::setw(7) << " |";
	for (const auto& w : weight_lbs)
		std::cout << std::setw(5) << w << "11";
	std::cout << std::endl;
	// Output line below headings
	for (size_t i{ 1 }; i < wt_count; ++i)
		std::cout << "---------";
	std::cout << std::endl;
	double bmi{};
	unsigned int feet{};
	unsigned int inches{};
	const unsigned int inches_per_foot{ 12U };
	for (const auto& h : height_ins)
	{
		feet = h / inches_per_foot;
		inches = h % inches_per_foot;
		std::cout << std::setw(2) << feet << "'" << std::setw(2) << inches << "\"" << "|";
		std::cout << std::fixed << std::setprecision(1);
		for (const auto& w : weight_lbs)
		{
			bmi = h / ins_per_m;
			bmi = (w / lbs_per_kg) / (bmi * bmi);
			std::cout << std::setw(2) << "" << bmi << " |";
		}
		std::cout << std::endl;
	}
	for (size_t i{ 1 }; i < wt_count; ++i)
		std::cout << "---------";
	std::cout << "\nBMI from 18.5 to 24.9 is normal" << std::endl;

	system("Pause");
	return 0;
}

