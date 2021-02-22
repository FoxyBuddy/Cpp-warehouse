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

    double expont = 0.0, init = 0.0;
    char text[] = "我不是装b，假期现学的，为了考研。\n"
        "运用泰勒公式来计算一个函数的值。\n"
        "目前可以计算 a ^ x。";
    HWND HideWindow = FindWindow("ConsoleWindowClass", NULL);
    if (HideWindow)
    {
        ShowWindow(HideWindow, SW_HIDE);
        MessageBox(NULL, text, "我没装b", MB_OK | MB_ICONINFORMATION);
        ShowWindow(HideWindow, SW_RESTORE);
        printf("请输入 a ^ x 的指数部分。\n");
        /* 老版本 C/C++：scanf("%lf", &expont) */
        scanf_s("%lf", &expont);
        printf("请输入 a ^ x 的底数部分。\n");
        /* 老版本 C/C++：scanf("%lf", &init) */
        scanf_s("%lf", &init);
        Taylor(expont, init);
        MessageBox(NULL, "计算结束。\n注意：误差还是有的，只要在允许的范围内接受就行。", "Complete", MB_OK | MB_ICONINFORMATION);
    }
    return 0;
}