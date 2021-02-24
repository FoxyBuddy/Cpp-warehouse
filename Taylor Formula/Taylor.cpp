#include <stdio.h>
#include <math.h>
#include <windows.h>
#include "Taylor.h"

int main()
{
    char title[] = "百里玄策";
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
                MessageBox(NULL, "不能同时打开相同的程序，兄弟！", "Program Already Existed!", MB_ICONERROR);
                ExitProcess(Code);
            }
        }
    }

    char choose = '0';
    char text[] = "我不是装b，假期现学的，为了考研。\n"
        "运用泰勒公式来计算一个函数的值。\n"
                  "由于无法算 ln x，只能算 e ^ x。";
    HWND HideWindow = FindWindow("ConsoleWindowClass", NULL);
    if (HideWindow)
    {
        ShowWindow(HideWindow, SW_HIDE);
        MessageBox(NULL, text, "我没装b", MB_OK | MB_ICONINFORMATION);
        ShowWindow(HideWindow, SW_RESTORE);
        printf("按 1 开始计算 e ^ x，结束按小写 q。\n");
        while (1)
        { 
            /* 老版本 C/C++：scanf("%d", &choose) */
            scanf_s("%c", &choose, 1);
            switch (choose)
            {
            case 10:
                continue;
                break;
            case 49:
                toTaylorExp();
                MessageBox(NULL, "计算结束。\n注意：误差还是有的，只要在允许的范围内接受就行。", "Complete", MB_OK | MB_ICONINFORMATION);
                break;
            case 113:
                MessageBox(NULL, "程序已结束", "Exit", MB_ICONINFORMATION);
                ExitProcess(0);
                break;
            default:
                MessageBox(NULL, "兄弟！这不是个选项！", "Out of Choices", MB_ICONERROR);
                break;
            }
        }
    }
    return 0;
}