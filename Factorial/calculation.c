#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string.h>

void exponent(int exp);
void xlcThousands(double thousands);

/* 由于C / C++ 中不存在阶乘函数factorial，所以需要另外写函数。*/

void calc(int init) /* 形参 init 表示计算n!的数字n */
{
	int a = init;
	if (a < 0) /* 阶乘只在正实数内有定义，n为负数时，则直接提示错误。*/
	{
		MessageBox(NULL, "这不合理吧，兄弟！", "Wait, what?", MB_OK|MB_ICONERROR);
		ExitProcess(0);
}
	else if (a == 0) /* 0的阶乘为1，所以直接定义0！= 1。*/
	{
		init = 1;
		printf("Final: %d", init);
	}
	else if (a >= 1 && a <= 18) /* 当结果不太大时，直接返回结果。但由于阶乘的增长速度极快，所以输出结果以 double 存储。*/
	{
		int i = 0; double end = 1;
		for (i = 1; i <= a; i++)
		{
			end *= i;
		}
		xlcThousands(end);
	}
	else /* 当输出结果可能太大时，首先提示是否确认继续。若继续，则开始计算；反之停止程序。*/
	{
		int proof = 0;
		proof = MessageBox(NULL, "巨大的计算量可能要花费2~3分钟才能出结果，\n点击“是”以开始计算。\n如果没有耐心或电脑不太好，点“否”取消计算。", "你确定要这么做吗，兄弟？", MB_YESNO | MB_ICONQUESTION);
		if (proof == IDNO)
		{
			MessageBox(NULL, "也不能说你怂。", "行吧。。。", MB_OK | MB_ICONINFORMATION);
			ExitProcess(0);
		}
		else
		{
			exponent(a);
		}
	}
}

void exponent(int exp)/*当结果太大时，形参 exp 表示把结果化为科学计数法，之后返回结果。*/
{
	/* 为了防止溢出，这里的循环变量和终止值均使用 unsigned int 存储，且将输入的值强行转换成 unsigned int 类型。 */
	/* temp_exp 表示累加每一个数字对应的以10为底的对数值，temp_sci 表示对累加后的小数部分做10的幂，sci_base 表示对累加后的值取整。 */
	unsigned int j = 0, final_exp = (unsigned) exp;
	double temp_exp = 0.0, sci_base = 0.0, temp_sci = 0.0;
	for (j = 1; j <= final_exp; j++)
	{
		temp_exp += log(j) / log(10); /* C/C++下log()以e为底。*/
		temp_sci = pow(10, temp_exp - floor(temp_exp));
		sci_base = floor(temp_exp);
	}
	printf("Final: %.8lf × 10 ^ %.0lf", temp_sci, sci_base);
}

void xlcThousands(double thousands) /* 结果用国际上的千位分隔法表示。函数名中的 xlc 表示：东方中，从星莲船开始启用这种显示方式。*/
{
	char temp_thousands[17] = "";
	/* DEVC++ 等编译器：sprintf(temp_thousands, "%.0lf", thousands);*/
	sprintf_s(temp_thousands, sizeof(temp_thousands), "%.0lf", thousands); /* 把纯数字的结果转换为字符串并放入数组中，再进行分隔。*/
	size_t length = strlen(temp_thousands); 
	int i = 0; 
	printf("Final: ");
	for (i = 0; i < length; i++) /* strlen 获取字符串的长度，在循环中从高位顺次输出数字。*/
	{
		printf("%c", temp_thousands[i]);
		if ((length - i - 1) % 3 == 0 && i != length - 1) /* 先将长度 length 减去 1 来防止最后一位也输出“,”。再和 3 取余，并且同时判定 i 的位置，若同时满足两个条件则输出“,”。*/
		{
			printf(",");
		}
	}
}
