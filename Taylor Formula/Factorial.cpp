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
    printf("������ e ^ x ��ָ�����֡�\n");
    /* �ϰ汾 C/C++��scanf("%lf", &expont) */
    scanf_s("%lf", &expont);
    TaylorExp(expont);
}

void TaylorExp(double calc)
{

    double output = 0.0;
    int level_exp = 0;
    for (level_exp = 0; level_exp <= 170; level_exp++) /* ���� e ^ x �� x չ���� Peano �������̩�չ�ʽ���㡣*/
    {
        double Taylorexp = (pow(calc, level_exp) / fact(level_exp)); /* pow Ϊ double ���ͣ����ܸı䡣*/
        output += Taylorexp;
        if (calc > 65)
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
    printf("Final: ");
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
    printf("\n�������㰴 1��������Сд q��\n");
}