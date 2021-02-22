#include <stdio.h>
#include <windows.h>
#include "calc.h"

int main()
{
	char title[] = "������Լ";
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
			MessageBox(NULL, "����˫��������̣��ֵܣ�", "Program Already Existed!", MB_OK|MB_ICONERROR);
			CloseHandle(PreventDouble);
			return 0;
		}
	}

	
	HWND HideWindow;
	HideWindow = FindWindow("ConsoleWindowClass", NULL);
	if (HideWindow)
	{
		ShowWindow(HideWindow, SW_HIDE);
		/* ����ǰֻ��ʾ�Ի������� cmd ���ƴ��ڣ��رնԻ������ʾ cmd��Ψһ�Ĳ����� cmd ���ڲ��ἤ���Ҫ�ֶ��㡣��*/
		MessageBox(NULL, "���Ǵ�һ��ѧ�ڽ׳˼������Ľ��װ棬��Ȼ����֧������ʵ���Ľ׳����㡣\n���ȷ���Կ�ʼ���㡣", "New Version", MB_OK | MB_ICONINFORMATION);
		ShowWindow(HideWindow, SW_RESTORE);
	}

	int input = 0;
	printf("����n!�ĳ�ʼֵ��Max��2,147,483,647��\n");
	/* DEVC++ �ȱ�������scanf("%d", &input);*/
	scanf_s("%d", &input);
	calc(input);

	MessageBox(NULL, "���������", "OK", MB_OK| MB_ICONINFORMATION);
	ExitProcess(0);
}