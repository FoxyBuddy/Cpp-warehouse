#include <stdio.h>
#include <windows.h>
#include "calc.h"

int main()
{
	char title[] = "百里守约";
	SetConsoleTitle(title);

	HANDLE PreventDouble = CreateMutex(NULL, TRUE, title);
	DWORD returns = GetLastError();
	if (PreventDouble)
	{
		if (ERROR_ALREADY_EXISTS == returns)
		{
			HWND hwnd;
			hwnd = FindWindow("ConsoleWindowClass", NULL);
			if (hwnd)
			{
				ShowWindow(hwnd, SW_HIDE);
			}
			MessageBox(NULL, "不能双开这个进程，兄弟！", "Program Already Existed!", MB_OK|MB_ICONERROR);
			CloseHandle(PreventDouble);
			return 0;
		}
	}

	
	HWND HideWindow;
	HideWindow = FindWindow("ConsoleWindowClass", NULL);
	if (HideWindow)
	{
		ShowWindow(HideWindow, SW_HIDE);
		/* 输入前只显示对话框，隐藏 cmd 控制窗口，关闭对话框后显示 cmd（唯一的不足是 cmd 窗口不会激活，需要手动点。）*/
		MessageBox(NULL, "这是大一上学期阶乘计算器的进阶版，虽然还不支持任意实数的阶乘运算。\n点击确定以开始计算。", "New Version", MB_OK | MB_ICONINFORMATION);
		ShowWindow(HideWindow, SW_RESTORE);
	}

	int input = 0;
	printf("输入n!的初始值（Max：2,147,483,647）\n");
	/* DEVC++ 等编译器：scanf("%d", &input);*/
	scanf_s("%d", &input);
	calc(input);

	MessageBox(NULL, "计算结束。", "OK", MB_OK| MB_ICONINFORMATION);
	ExitProcess(0);
}