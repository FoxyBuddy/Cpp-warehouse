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

    char choose = '0';
    char text[] = "�Ҳ���װb��������ѧ�ģ�Ϊ�˿��С�\n"
        "����̩�չ�ʽ������һ��������ֵ��\n"
                  "�����޷��� ln x��ֻ���� e ^ x��";
    HWND HideWindow = FindWindow("ConsoleWindowClass", NULL);
    if (HideWindow)
    {
        ShowWindow(HideWindow, SW_HIDE);
        MessageBox(NULL, text, "��ûװb", MB_OK | MB_ICONINFORMATION);
        ShowWindow(HideWindow, SW_RESTORE);
        printf("�� 1 ��ʼ���� e ^ x��������Сд q��\n");
        while (1)
        { 
            /* �ϰ汾 C/C++��scanf("%d", &choose) */
            scanf_s("%c", &choose, 1);
            switch (choose)
            {
            case 10:
                continue;
                break;
            case 49:
                toTaylorExp();
                MessageBox(NULL, "���������\nע�⣺�����еģ�ֻҪ������ķ�Χ�ڽ��ܾ��С�", "Complete", MB_OK | MB_ICONINFORMATION);
                break;
            case 113:
                MessageBox(NULL, "�����ѽ���", "Exit", MB_ICONINFORMATION);
                ExitProcess(0);
                break;
            default:
                MessageBox(NULL, "�ֵܣ��ⲻ�Ǹ�ѡ�", "Out of Choices", MB_ICONERROR);
                break;
            }
        }
    }
    return 0;
}