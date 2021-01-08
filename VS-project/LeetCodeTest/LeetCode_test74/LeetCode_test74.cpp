// 力扣驱动程序，[74]搜索二维矩阵

#include <iostream>

int main() {
	int matrix[3][4] = { {1,3,5,7},{10,11,16,20},{23,30,34,50} };
	int matrixSize = 3;
	int matrixColSize = 4;
	int target = 3;

	if (matrixSize == 0 || (matrixColSize) == 0)
	{
		return false;
	}
	if (target < matrix[0][0] || target > matrix[matrixSize - 1][(matrixColSize)-1])
	{
		return false;
	}

	int xmax = matrixColSize, ymax = matrixSize;

	// 映射关系：x = port % xmax; y = port / ymax;
	int left = 0, right = (xmax * ymax) - 1;

	while (true)
	{
		// 将搜索下标转化为矩阵下标
		int left_x = left % xmax, left_y = left / xmax;
		int right_x = right % xmax, right_y = right / xmax;

		int middle = (left + right) / 2;

		// 二维数组下标到一维搜索下标的映射关系。
		int middle_x = middle % xmax;
		int middle_y = middle / xmax;

		printf("middle = %d,left = %d, right = %d, right_x = %d, right_y = %d, left_x = %d, left_y = %d\n", middle, left, right, right_x, right_y, left_x, left_y);

		if (left == right && matrix[left_y][left_x] != target)
		{
			printf("-2\n");
			break;
		}
		else if (abs(left - right) == 1 && matrix[middle_y][middle_x] != target && matrix[left_y][left_x] != target && matrix[right_y][right_x] != target)
		{
			printf("-1\n");
			break;
		}
		else if (matrix[middle_y][middle_x] == target || matrix[left_y][left_x] == target || matrix[right_y][right_x] == target)
		{
			printf("1\n");
			break;
		}
		if (matrix[middle_y][middle_x] < target)
		{
			left = middle;
		}
		else if (matrix[middle_y][middle_x] > target)
		{
			right = middle;
		}
	}

	system("Pause");

	return 0;
}