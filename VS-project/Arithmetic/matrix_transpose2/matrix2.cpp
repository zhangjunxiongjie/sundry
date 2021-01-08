/*这一版本中使用另一种简单但时间复杂度‘较高’的算法，虽然如此但还是有必要增版如下。
因为只是对矩阵转置的算法做更改，而前版中将矩阵的转置处理实行了模块化，所以这一版不再重复造轮子，
而是在原有基础上对矩阵转置的模块进行更改，
*/
/*有待优化的地方：
①，矩阵只存储了最大一位的数值，能否优化使其输出时每行能适当对其，使多位数值的矩阵的可视化仍然美观。
②，
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>   //这一版中引进时间库，测算比较此三版各自的时间复杂度。

#define YZ 11   //前几版本中均将矩阵的压缩存储的三元组数组设为十一只能存储最多十个非零元素，这里做了简单优化
//使压缩存储矩阵的三元组数组大小可以自定义使其脱离于程序。也可以直接使YZ=Y*Z，亦是一个可行之策。

int Matr[YZ][3];  //存储于三元数组，压缩后的矩阵
//第一个三元组存储矩阵的基本信息：行，列，非零元素个数。
int Matrg[YZ][3];    //存储结果的三元组，虽然能将每一个转置后三元组直接填入其对应位置
//但是不能直接在原三元组上操作，因为这样会覆盖掉未转置的三元组


#define N 20  //有两个数组（存储每一列非零元素个数的数组，以及存储转置后每一列第一个非零元素所在位置的数组）的定义必须使用常数。。。醉了

#define Y 6   //矩阵行（转置前）
#define Z 4   //矩阵列（转置前）

void Compress(int tv[][Z], int m[][3]) //将矩阵压缩存储于三元数组
{
	int i, j, coun = 1;

	for (i = 0; i < Y; i++)
	{
		for (j = 0; j < Z; j++)
		{
			if (tv[i][j] != 0)
			{
				m[coun][0] = i;
				m[coun][1] = j;
				m[coun][2] = tv[i][j];
				coun++;
			}
		}
	}
	m[0][0] = Y;
	m[0][1] = Z;
	m[0][2] = coun;
}

void WinRAR(int ty[][Y], int mg[][3])//将使用三元数组压缩存储的矩阵解压缩存储于二维数组
{
	int i, j, coun = 1;

	for (i = 0; i < Z; i++)
	{
		for (j = 0; j < Y; j++)
		{
			if (i == mg[coun][0] && j == mg[coun][1])
			{
				ty[i][j] = mg[coun][2];
				coun++;
			}
			else
				ty[i][j] = 0;
		}
	}
}

void Visual(int y, int z, int t[][3]) //用于可视化的函数
{
	int i, j, coun = 1;

	for (i = 0; i < y; i++)
	{
		for (j = 0; j < z; j++)
		{
			if (i == t[coun][0] && j == t[coun][1])
			{
				printf("%d ", t[coun][2]);
				coun++;
			}
			else
				printf("0 ");
		}
		printf("\n");
	}
}

//传入参数使此函数使用Matr数组从第一个三元数组开始，以下为转置的核心代码。
void Tran(int t, int v, int R)  //利用矩阵压缩存储的三元数组对矩阵进行转置,传入行列数以及总的非零个数
{
	int i, j, coun = 1;
	for (i = 0; i < v; i++)
	{
		for (j = 1; j < R; j++)
		{
			if (Matr[j][1] == i)
			{
				Matrg[coun][0] = Matr[j][1];
				Matrg[coun][1] = Matr[j][0];
				Matrg[coun][2] = Matr[j][2];
				coun++;
			}
		}
	}
	Matrg[0][0] = Matr[0][0];
	Matrg[0][1] = Matr[0][1];
	Matrg[0][2] = Matr[0][2];
}


void main()
{
	clock_t t, h;
	h = clock();
	int Matv[Y][Z] = { {0,2,0,1},
				   {0,9,6,0},
				   {4,0,0,5},
				   {8,0,7,0},
				   {1,3,0,0},
				   {0,0,0,9}
	};   //初始的二维数组存储的矩阵

	int Maty[Z][Y];    //用于存储解压缩的转置后的数组

	Compress(Matv, Matr);
	Visual(Y, Z, Matr);
	printf("\n");

	Tran(Matr[0][0], Matr[0][1], Matr[0][2]);

	WinRAR(Maty, Matrg);
	Visual(Z, Y, Matrg);
	t = clock();
	printf("%ld\n", t-h);
	system("Pause");   //调用DOS命令暂停程序
}