#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <string.h>

void xlcThousands(double result);
double fact(int n);

void Taylor(double calc)
{
    
    double output = 0.0, real = 0.0;
    int level = 0;
    if (calc > 65)
    {
        MessageBox(NULL, "数字太大了，兄弟！", "Overflow!", MB_OK | MB_ICONERROR); /* 经过计算得知，当 x 超过 65 时，x ^ 170 会大于 double 的最大值。*/
        ExitProcess(OVERFLOW);
    }
    else
    {
        for (level = 0; level <= 170; level++) /* 按照 e ^ x 以 x 展开的 Peano 型余项的泰勒公式计算。*/
        {
            output += (pow(calc, level) / fact(level)); /* pow 为 double 类型，不能改变。*/
        }
        xlcThousands(output);
    }
}

double fact(int n) /* 计算 n!。*/
{
    int i = 0;
    long double end = 1.0;
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
    sprintf_s(temp_int, 30, "%.0lf", integar);
    sprintf_s(temp_dec, 13, "%.10lf", decimal);
    size_t size = strlen(temp_int);
    size_t size1 = strlen(temp_dec);
    int i = 0;
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
}