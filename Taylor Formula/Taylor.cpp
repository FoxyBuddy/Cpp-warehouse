#include <stdio.h>
#include <math.h>
#include <windows.h>
#include "Taylor.h"

int main()
{
    char title[] = "��������";
    SetConsoleTitle(title);
    HANDLE PreventDouble = CreateMutex(NULL, TRUE, title);
    if (PreventDouble)
    {
        unsigned int Code = GetLastError();
        if (Code == ERROR_ALREADY_EXISTS)
        {
            HWND NoShow = FindWindow("ConsoleWindowClass", NULL);
            if (NoShow)
            {
                ShowWindow(NoShow, SW_HIDE);
                MessageBox(NULL, "����ͬʱ����ͬ�ĳ����ֵܣ�", "Program Already Existed!", MB_ICONERROR);
                ExitProcess(Code);
            }
        }
    }

    double expont = 0.0, init = 0.0;
    char text[] = "�Ҳ���װb��������ѧ�ģ�Ϊ�˿��С�\n"
        "����̩�չ�ʽ������һ��������ֵ��\n"
        "Ŀǰ���Լ��� a ^ x��";
    HWND HideWindow = FindWindow("ConsoleWindowClass", NULL);
    if (HideWindow)
    {
        ShowWindow(HideWindow, SW_HIDE);
        MessageBox(NULL, text, "��ûװb", MB_OK | MB_ICONINFORMATION);
        ShowWindow(HideWindow, SW_RESTORE);
        printf("������ a ^ x ��ָ�����֡�\n");
        /* �ϰ汾 C/C++��scanf("%lf", &expont) */
        scanf_s("%lf", &expont);
        printf("������ a ^ x �ĵ������֡�\n");
        /* �ϰ汾 C/C++��scanf("%lf", &init) */
        scanf_s("%lf", &init);
        Taylor(expont, init);
        MessageBox(NULL, "���������\nע�⣺�����еģ�ֻҪ������ķ�Χ�ڽ��ܾ��С�", "Complete", MB_OK | MB_ICONINFORMATION);
    }
    return 0;
}