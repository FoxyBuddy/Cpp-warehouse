#include <stdio.h>
#include <windows.h>
#include <string.h>
/*我的代码的使用方法：开源，vs架构下直接用，DEVC++等老C/C++标准看注释代码中的指示。
部分代码的解释看附加文档和注释。*/
typedef struct blsy
{
	char name[9];
	char type[9];
	char diffculty[3];
} ShouYue;
/* name为名字，type为分类，diffculty为难度，使用结构体来写入一个文件 */

int FileWrite();

int main()
{
	char title[] = "刘禅还是sb";
	SetConsoleTitle(title); 

	HANDLE m_hMutex = CreateMutex(NULL, TRUE, title);
	DWORD dwRet = GetLastError();
	if (m_hMutex)
	{
		if (ERROR_ALREADY_EXISTS == dwRet)
		{
			HWND hwnd;
			hwnd = FindWindow("ConsoleWindowClass", NULL);
			if (hwnd)
			{
				ShowWindow(hwnd, SW_HIDE);
			}
			MessageBox(NULL, "不能双开这个进程，兄弟！", "Program Already Existed!", MB_ICONERROR);
			CloseHandle(m_hMutex);
			return 0;
		}
	}

	HWND HideWindow;
	HideWindow = FindWindow("ConsoleWindowClass", NULL);

	if (HideWindow)
	{
		ShowWindow(HideWindow, SW_HIDE);
		/* 输入前只显示对话框，隐藏 cmd 控制窗口，关闭对话框后显示 cmd（唯一的不足是 cmd 窗口不会激活，需要手动点。）*/
		int a = 0;
		a = MessageBox(NULL, "如果你是策划，你想给守约什么设定？\n按“是“以开始。", "Open Minding", MB_YESNO | MB_ICONQUESTION);
		if (a == IDYES)
		{
			MessageBox(NULL, "现在开始吧", "Open Minding", MB_OK);
			ShowWindow(HideWindow, SW_RESTORE);
			FileWrite();
		}
		else
		{
			MessageBox(NULL, "打扰了。", "Sorry", MB_OK | MB_ICONEXCLAMATION);
			ExitProcess(0);
		}
	}
	return 0;
}

/*DEVC++等旧C/C++标准编译器：
在函数int FileWrite()中复制如下代码，其他代码不变：
	ShouYue syxc = {"", "", ""};
	FILE* fp = NULL;
	fp = fopen("D:\\syxc.txt", "wb+");
	if (fp != 0)
	{
	printf("你想设定的守约叫什么？（Max：4个汉字或8个字母）");
	gets(syxc.name);
	fflush(stdin);
	printf("你想设定的守约的分类是？（Max：4个汉字或8个字母）");
	gets(syxc.type);
	fflush(stdin);
	printf("你想设定的守约的难度是？（Max：2位数字）");
	gets(syxc.diffculty);
	fflush(stdin);
	MessageBox(NULL, "设定结束，你的建议是nt策划最大的支持！", "Thanks!", MB_OK | MB_ICONINFORMATION);
	fprintf(fp, "%s, %s, %s", syxc.name, syxc.type, syxc.diffculty);
	ExitProcess(0);
	}
	else
	{
		MessageBox(NULL, "NO Such Flie Or NO Permission", "NO!!", MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
	return 0;
*/

int FileWrite()
{
	ShouYue syxc = { " ", " ", " " }; /* 初始化并清空结构体的内存 */
	FILE* fp = NULL;
	FILE** fp1 = &fp;
	errno_t err = fopen_s(fp1, "D:\\syxc.txt", "wb+");
	if (fp != 0)
	{
		printf("你想设定的守约叫什么？（Max：4个汉字或8个字母）\n");
		gets_s(syxc.name, 9);
		fflush(stdin);
		printf("你想设定的守约的分类是？（Max：4个汉字或8个字母）\n");
		gets_s(syxc.type, 9);
		fflush(stdin);
		printf("你想设定的守约的难度是？（Max：2位数字）\n");
		gets_s(syxc.diffculty, 3);
		fflush(stdin);
		MessageBox(NULL, "设定结束，你的建议是nt策划最大的支持！", "Thanks!", MB_OK | MB_ICONINFORMATION);
		fprintf(fp, "%s, %s, %s", syxc.name, syxc.type, syxc.diffculty);/* 万恶的 fwrite 总有乱码！只好用万能 fprintf了。*/
		fclose(fp);
		ExitProcess(0);
	}
	else
	{
		MessageBox(NULL, "NO Such Flie Or NO Permission", "NO!!", MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
	return 0;
}