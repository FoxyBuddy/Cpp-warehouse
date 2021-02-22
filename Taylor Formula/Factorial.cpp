#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <string.h>

void xlcThousands(double result);
double fact(int n);

void Taylor(double calc, double base)
{

    double output = 0.0, real = 0.0;
    int level = 0;
    for (level = 0; level <= 170; level++) /* ���� a ^ x �� x չ���� Peano �������̩�չ�ʽ���㡣*/
    {
        output += (pow(calc, level) * pow(log(base), level)/ fact(level)); /* pow Ϊ double ���ͣ����ܸı䡣*/
        if (output > pow(2, 65))
        {
            MessageBox(NULL, "����̫���ˣ��ֵܣ�", "Overflow!", MB_OK | MB_ICONERROR);
            ExitProcess(OVERFLOW);
        }
    }
    xlcThousands(output);
}

double fact(int n) /* ���� n!��*/
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
    char temp_int[30] = "", temp_dec[13] = ""; /* ���������ֺ�С�����ַֿ������ֱ�洢��*/
    double integar = floor(result);
    double decimal = result - integar;
    /* �ϰ汾 C/C++��
    sprintf(temp_int, "%.0lf", integar);
    sprintf(temp_dec, "%.10lf", decimal);*/
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
    for (i = 1; i < size1; i++) /* ȥ��ǰ�õ� 0�����С�����֡�*/
    {
        printf("%c", temp_dec[i]);
    }
}