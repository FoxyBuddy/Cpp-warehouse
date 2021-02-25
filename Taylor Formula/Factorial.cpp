#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <string.h>

void toTaylorExp();

void xlcThousands(double result);
void TaylorExp(double calc);
double fact(int n);

double expont = 0.0;

void toTaylorExp()
{
    system("cls");
    printf("请输入 e ^ x 的指数部分。\n");
    /* 老版本 C/C++：scanf("%lf", &expont) */
    scanf_s("%lf", &expont);
    TaylorExp(expont);
}

void TaylorExp(double calc)
{

    double output = 0.0;
    int level_exp = 0;
    for (level_exp = 0; level_exp <= 170; level_exp++) /* 按照 e ^ x 以 x 展开的 Peano 型余项的泰勒公式计算。*/
    {
        double Taylorexp = (pow(calc, level_exp) / fact(level_exp)); /* pow 为 double 类型，不能改变。*/
        output += Taylorexp;
        if (calc > 65)
        {
            MessageBox(NULL, "数字太大了，兄弟！", "Overflow!", MB_OK | MB_ICONERROR);
            ExitProcess(OVERFLOW);
        }
    }
    xlcThousands(output);
}

double fact(int n) /* 计算 n!。*/
{
    int i = 0;
    double end = 1.0;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        for (i = 1; i <= n; i++)
        {
            end *= i;
        }
    }
    return end;
}

void xlcThousands(double result)
{
    char temp_int[30] = "", temp_dec[13] = ""; /* 把整数部分和小数部分分开，并分别存储。*/
    double integar = floor(result);
    double decimal = result - integar;
    /* 老版本 C/C++：
    sprintf(temp_int, "%.0lf", integar);
    sprintf(temp_dec, "%.10lf", decimal);*/
    sprintf_s(temp_int, 30, "%.0lf", integar);
    sprintf_s(temp_dec, 13, "%.10lf", decimal);
    size_t size = strlen(temp_int);
    size_t size1 = strlen(temp_dec);
    int i = 0;
    printf("Final: ");
    for (i = 0; i < size; i++)
    {
        printf("%c", temp_int[i]);
        if ((size - i - 1) % 3 == 0 && i != (size - 1))
        {
            printf(",");
        }
    }
    for (i = 1; i < size1; i++) /* 去除前置的 0，输出小数部分。*/
    {
        printf("%c", temp_dec[i]);
    }
    printf("\n继续计算按 1，结束按小写 q。\n");
}