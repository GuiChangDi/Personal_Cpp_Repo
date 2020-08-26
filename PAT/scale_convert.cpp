#include <cstdio>

/// <summary>
///	转换至十进制
/// </summary>
/// <param name="n">数</param>
/// <param name="p">该数进制</param>
int scale_convert_to_ten(int n, int p) {
	int y = 0, product = 1;
	while (n != 0) {
		y = y + (n % 10) * product;
		n = n / 10;
		product = product * p;
	}
	printf("%d\n", y);
	return y;
}

/// <summary>
/// 十进制转换为其他进制
/// </summary>
/// <param name="n">数</param>
/// <param name="Q">进制</param>
/// <returns></returns>
int scale_convert(int n, int Q) {
	int a[32] = { 0 }, num = 0;
	while (n != 0) {
		a[num++] = n % Q;
		n /= Q;
	}
	for (int i = num-1; i >= 0; i--) {
		printf("%d", a[i]);
	}
	return 0;
}

int main()
{
	int a = 111;
	int b = scale_convert_to_ten(a, 2);
	scale_convert(b, 2);
	return 0;
}