/*
在数据结构那本书上看到一个压缩存储的矩阵(稀疏矩阵)的转置算法（两种，以下是较难的那一种）
甚是伤透脑筋，但确实不失为一个好算法，现将它实现如下。
为了能够直观地看到矩阵转置后的结果做了可视化的函数。
*/
/*
有待改善的地方：可视化的两个函数是否能够使用一个函数实现有待实现，
这里使用了两个函数因为转置后的矩阵行列互换a[][n],n发生改变使得转置后的数组不能在使用上一个可视化函数（因为形参要求确定n值）
这里有尝试过形参使用二维指针然后再传入行列就能够实现两函数的合并可是经尝试二维指针语法错误不知何故
*/


#include <stdio.h>
#include <stdlib.h>

int Matr[11][3];  //存储于三元数组，压缩后的矩阵
//第一个三元组存储矩阵的基本信息：行，列，非零元素个数。
int Matrg[11][3];    //存储结果的三元组，虽然能将每一个转置后三元组直接填入其对应位置
//但是不能直接在原三元组上操作，因为这样会覆盖掉未转置的三元组


#define N 20  //有两个数组（存储每一列非零元素个数的数组，以及存储转置后每一列第一个非零元素所在位置的数组）的定义必须使用常数。。。醉了

#define Y 4   //矩阵行（转置前）
#define Z 5   //矩阵列（转置前）

void Compress(int tv[][Z],int m[][3]) //将矩阵压缩存储于三元数组
{
	int i,j,coun=1;

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

void WinRAR(int ty[][Y],int mg[][3])//将使用三元数组压缩存储的矩阵解压缩存储于二维数组
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

void Visuala(int t[][Z]) //用于可视化的函数
{
	int i, j;

	for (i = 0; i < Y; i++)
	{
		for (j = 0; j < Z; j++)
			printf("%d ", t[i][j]);
		printf("\n");
	}
}
void Visualb(int t[][Y]) //用于可视化的函数
{
	int i, j;

	for (i = 0; i < Z; i++)
	{
		for (j = 0; j < Y; j++)
			printf("%d ", t[i][j]);
		printf("\n");
	}
}

//传入参数使此函数使用Matr数组从第一个三元数组开始，以下为转置的核心代码。
void Tran(int t,int v,int R)  //利用矩阵压缩存储的三元数组对矩阵进行转置,传入行列数以及总的非零个数
{
	int st[N], sv[N];   //st存储每一列的非零元素个数，sv存储每一列第一个非零元素的‘位置’
	int i;

/*
	for (i = 1; i < R; i++) //确定每列的非零元素个数
	{
		if (st[Matr[i][1]] == 0)
			st[Matr[i][1]]++;
		else
			st[Matr[i][1]] = 0;
	}
这里不能这样初始化非零元素个数数组必须分开*/
	for (i = 0; i < v; i++)
		st[i]=0;
	for (i = 1; i < R; i++)
		st[Matr[i][1]]++;

	//printf("%d\n", v);
	//需要说明的是st，sv均是从数组的第一个元素（即0号位置）开始
	//这个取决于将二维的矩阵压缩至三元数组时怎么使用三元组存储矩阵元素坐标
	//这里将矩阵坐标从第0列0行开始存储,所以sv，st均从第一个元素开始
	sv[0] = 1; //第一列的第一个非零元素一定在第一个位置，
	for (i = 1; i < v; i++)    //确定每一列第一个非零元素所在位置
	{
		sv[i] = sv[i - 1] + st[i - 1];
//		printf("sv[%d]=%d,st[%d]=%d\n",i,sv[i],i,st[i]);
	}

	Matrg[0][0] = v;
	Matrg[0][1] = t;
	Matrg[0][2] = R;
//	printf("%d,%d,%d\n", v, t, R);

	
	for (i = 1; i < R; i++)
	{
		
		Matrg[sv[Matr[i][1]]][0] = Matr[i][1];
		Matrg[sv[Matr[i][1]]][1] = Matr[i][0];
		Matrg[sv[Matr[i][1]]][2] = Matr[i][2];
		
//		printf("Matr[i][1]=%d,sv[Matr[i][1]]=%d\n", Matr[i][1], sv[Matr[i][1]]);
		sv[Matr[i][1]]++;
	}
/*
	for (i = 0; i < R; i++)
	{
		printf("a=%d,b=%d,c=%d\n",Matrg[i][0], Matrg[i][1], Matrg[i][2]);
	}
*/
}


void main()
{
	int Matv[Y][Z] = { {0,2,0,0,1},
				   {0,0,6,0,9},
				   {4,0,5,0,0},
				   {0,0,7,0,8} };   //初始的二维数组存储的矩阵
	
	int Maty[Z][Y];    //用于存储解压缩的转置后的数组

	Visuala(Matv);
	Compress(Matv,Matr);

	Tran(Matr[0][0], Matr[0][1], Matr[0][2]);

	WinRAR(Maty,Matrg);
	printf("\n");
	Visualb(Maty);

	system("Pause");   //调用DOS命令暂停程序
}