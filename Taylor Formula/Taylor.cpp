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

    double expont = 0.0;
    char text[] = "我不是装b，假期现学的，为了考研。\n"
                  "运用泰勒公式来计算一个函数的值。\n"
                  "目前只能计算 e ^ x。";
    HWND HideWindow = FindWindow("ConsoleWindowClass", NULL);
    if (HideWindow)
    {
        ShowWindow(HideWindow, SW_HIDE);
        MessageBox(NULL, text, "我没装b", MB_OK | MB_ICONINFORMATION);
        ShowWindow(HideWindow, SW_RESTORE);
        printf("请输入 e ^ x 的指数部分。\n");
        /* 老版本 C/C++：scanf("%lf", &expont) */
        scanf_s("%lf", &expont);
        Taylor(expont);
        MessageBox(NULL, "计算结束。\n注意：误差还是有的，只要在允许的范围内接受就行。", "Complete", MB_OK | MB_ICONINFORMATION);
    }
    return 0;
}