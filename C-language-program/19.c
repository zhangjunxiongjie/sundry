//�����Լ��
#include <stdio.h>
int main()
{
	int m, n, a[50], b[50], c[50], i, t, f;
	scanf("%d,%d", &m, &n);

	for (t = 0, i = m; i > 0; i--) //����������Լ��
		if (m % i == 0)
		{
			a[t] = i;
			t++;
		}
	for (f = 0, i = n; i > 0; i--) //
		if (n % i == 0)
		{
			b[f] = i;
			f++;
		}
	for (m = 0, i = 0; m < t; m++) //������Լ���Ƚϣ���������Լ������ͬ������������c[]��
		for (n = 0; n < f; n++)
			if (a[m] == b[n])
			{
				c[i] = a[m];
				i++;
			}
	t = c[0];
	for (f = 1; f < i; f++) //��������ͬӵ�е�Լ���е����ֵ����t��
		if (t < c[f])
			t = c[f];
	printf("%d\n", t);
	return 0;
}

//�����������Լ��
#include <stdio.h>
int main()
{
	void digui(int a, int b); //ʹ���˵ݹ���ã���һ�������㷨
	int m, n, t;
	scanf("%d,%d", &m, &n);
	if (m < n)
	{
		t = n;
		n = m;
		m = t;
	}
	digui(m, n);
	return 0;
}

void digui(int a, int b)
{
	int m, n;
	if (a % b == 0)
		printf("%d\n", b);
	else
	{
		m = b;
		n = a % b;
		digui(m, n); //***�˵��ú��������ڿ�ͷ���������������ڴ��a��b�н�С�������ߵ�������Ϊʵ�δ�����һ��ݹ麯��
	}				 //����ֱ�Ӱ�a��b��Ϊdigui��ʵ�Σ���Ϊ��digui��a��b��������Ϊ���β�***
}

//����λ��
#include <stdio.h>
int main()
{
	int i, t, a[50];
	double m;
	scanf("%d", &t);
	for (i = 0; i < t; i++)
		scanf("%d", a + i);
	if (t % 2 == 0) //�ж�������һ���ж��ٸ���
		m = (a[(t - 1) / 2] + a[(t + 1) / 2]) / 2;
	else //��������Ӧ�ķ���������λ��������m��
		m = a[(t - 1) / 2];
	printf("%5.3f\n", m);
	return 0;
}

//������������С������
#include <stdio.h>
int main()
{
	int m, n, i, t, f, a[50], b[50], c[50];
	scanf("%d,%d", &m, &n);
	for (i = 1; i <= n; i++) //���m��1-n�������б�������a[]������
		a[i - 1] = i * m;
	for (i = 1; i <= m; i++) //
		b[i - 1] = i * n;

	for (t = 0, i = 0; t < m; t++) //�ڶԷ������ڱ�������ֵͬ��������c[]��
		for (f = 0; f < n; f++)
			if (a[f] == b[t])
			{
				c[i] = a[f];
				i++;
			}
	t = c[0];
	for (f = 1; f < i; f++) //�ҳ������ǹ�ͬӵ�й������е���Сֵ����t��
		if (t > c[f])
			t = c[f];
	printf("%d\n", t);
	return 0;
}