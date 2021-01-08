// ������ͼ�λ��� ���Ͽ�����ţ�ƴ��룬������������
//������ͼ��ѧ��һЩ֪ʶ�ɡ� 

#include <math.h>
#include <stdio.h>
#define T double

T f(T x, T y) {
	return sqrt(x * x + y * y) - 0.8f;  //sqrt()��ƽ��������0.8��ǿ�ƣ�ת��Ϊ�����ȸ�����
}

char outline(T x, T y) {
	T delta = 0.001;
	if (fabs(f(x, y)) < 0.05) { //fabs()�����ֵ��
		T dx = f(x + delta, y) - f(x - delta, y);   //c++�������κεط��������
		T dy = f(x, y + delta) - f(x, y - delta);
		return "|/=\\|/=\\|"[(int)((atan2(dy, dx) / 6.2831853072 + 0.5) * 8 + 0.5)];  //���ַ���ʹ��[]��������.
	}
	else if (f(x, y) < 0)
		return '.';
	else
		return ' ';
}

float c(float x, float y, float r, float p) {
	return powf(powf(fabsf(x), p) + powf(fabsf(y), p), 1 / p) - r;
}

int f(float x, float y) {
	float a = fmaxf(c(x, y, 15, 2), c(x, y + 25, 30, 2)), b = c(x, y - 7, 10, 4);
	if (a < -1) // cap pattern
		return c(fmodf(x + 20 + 3 * floorf((y + 20) / 6), 6) - 3, fmodf(y + 20, 6) - 3, 2, 2) >= 0;
	else if (a < 0.0f) // cap
		return 1;
	else if (b < -2) // face
		return c(fabsf(x) - 2.5f, y - 7.5f, 1.25f, 2) < 0 || (y > 10 && fabsf(c(x, y - 9, 4, 2)) < 0.5f);
	else // body
		return b < 0;
}

int main() {
	for (T y = -1; y < 1; y += 0.05, putchar('\n'))
		for (T x = -1; x < 1; x += 0.025)
			putchar(outline(x, y));

	float s = 1.0f, x, y;

	for (y = -18; y < 18; y += 1.0f / s, putchar('\n'))
		for (x = -18; x < 18; x += 0.5f / s)
			putchar(" *"[f(x, y)]);

	getchar();
}
