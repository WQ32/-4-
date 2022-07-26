#include <stdio.h>

//浮点数在内存中的存储
// 浮点数家族：float  double  long double类型
// 浮点数表示的范围：float.h中定义（在文件夹中寻找）
// 小数点后面默认是6位小数

//1.
int main()
{
	int n = 9;
	float* pFloat = (float*)&n;
	printf("n的值为：%d\n", n);       // 9
	// 00000000000000000000000000001001      正数（补码=原码），打印原码
	printf("*pFloat的值为：%f\n", *pFloat);   // 0.000000 
	// 0 00000000 00000000000000000001001 
	// (-1)^0 * 0.00000000000000000001001 * 2^-126    结果为0
	// 说明整型和浮点型的存储方式不同
	*pFloat = 9.0;
	// 1001.0
	// (-1)^0 * 1.001 * 2^3
	// E 2^3 存的是 3+127=130
	// 0 10000010 00100000000000000000000     9.0的存储形式
	printf("n的值为：%d\n", n);       // 1091567616    1091567616
	//  0 10000010 00100000000000000000000    以为是补码，又是正数，也是原码，直接打印
	printf("*pFloat的值为：%f\n", *pFloat);    // 9.000000 
	// 浮点数的形式放进内存，浮点数的形式取没问题,以整型的形式取就有问题
	return 0;
}

// 9.0
// 1001.0
// (-1)^0 * 1.001 * 2^3
// (-1)^S * M     * 2^E 
// 9.0的二进制表示： (-1)^S * M * 2^E   
// （(-1)^S表示符号位(S=0,正数，S=1,负数)，M表示有效数字，大于等于1，小于2, 2^E 表示指数位）
// 32bit位：S(1bit) E(8bit) M(23bit)  单精度浮点数存储模型
// 0.5
// (-1)^0 * 1.0 * 2^(-1)
// 这里E为负数，而实际上E是一个无符号数如果E为8位（float），他的取值范围为0-255，
//  所以当它为负数时，必须加一个中间数127，如果E是16位(double），则取值范围为0-2047
//  则中间数1023
// 所以E实际在内存中存储的不是0.1，而是-1+127=126(无论正数还是负数都是)
//int main()
//{
//	float f = 5.5;
//	// 5.5
//	// 101.1
//	// (-1)^0 * 1.011 * 2^2
//	// S = 0
//	// M = 1.011
//	// E = 2
//	// 0100 0000 1011 0000 0000 0000 0000 0000
//	// 0x40b00000
//	// 0 00000000 01100000000000000000000
//	// +- 0.011 * 2^-126
//	//	0 11111111 01100000000000000000000
//	// E +127 =255
//	// E = 128
//	//表示的是正负无穷大的数字
//	return 0;
//}