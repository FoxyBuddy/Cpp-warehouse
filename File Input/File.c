#include <stdio.h>
#include <windows.h>
#include <string.h>
/*�ҵĴ����ʹ�÷�������Դ��vs�ܹ���ֱ���ã�DEVC++����C/C++��׼��ע�ʹ����е�ָʾ��
���ִ���Ľ��Ϳ������ĵ���ע�͡�*/
typedef struct blsy
{
	char name[9];
	char type[9];
	char diffculty[3];
} ShouYue;
/* nameΪ���֣�typeΪ���࣬diffcultyΪ�Ѷȣ�ʹ�ýṹ����д��һ���ļ� */

int FileWrite();

int main()
{
	char title[] = "��������sb";
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
			MessageBox(NULL, "����˫��������̣��ֵܣ�", "Program Already Existed!", MB_ICONERROR);
			CloseHandle(m_hMutex);
			return 0;
		}
	}

	HWND HideWindow;
	HideWindow = FindWindow("ConsoleWindowClass", NULL);

	if (HideWindow)
	{
		ShowWindow(HideWindow, SW_HIDE);
		/* ����ǰֻ��ʾ�Ի������� cmd ���ƴ��ڣ��رնԻ������ʾ cmd��Ψһ�Ĳ����� cmd ���ڲ��ἤ���Ҫ�ֶ��㡣��*/
		int a = 0;
		a = MessageBox(NULL, "������ǲ߻����������Լʲô�趨��\n�����ǡ��Կ�ʼ��", "Open Minding", MB_YESNO | MB_ICONQUESTION);
		if (a == IDYES)
		{
			MessageBox(NULL, "���ڿ�ʼ��", "Open Minding", MB_OK);
			ShowWindow(HideWindow, SW_RESTORE);
			FileWrite();
		}
		else
		{
			MessageBox(NULL, "�����ˡ�", "Sorry", MB_OK | MB_ICONEXCLAMATION);
			ExitProcess(0);
		}
	}
	return 0;
}

/*DEVC++�Ⱦ�C/C++��׼��������
�ں���int FileWrite()�и������´��룬�������벻�䣺
	ShouYue syxc = {"", "", ""};
	FILE* fp = NULL;
	fp = fopen("D:\\syxc.txt", "wb+");
	if (fp != 0)
	{
	printf("�����趨����Լ��ʲô����Max��4�����ֻ�8����ĸ��");
	gets(syxc.name);
	fflush(stdin);
	printf("�����趨����Լ�ķ����ǣ���Max��4�����ֻ�8����ĸ��");
	gets(syxc.type);
	fflush(stdin);
	printf("�����趨����Լ���Ѷ��ǣ���Max��2λ���֣�");
	gets(syxc.diffculty);
	fflush(stdin);
	MessageBox(NULL, "�趨��������Ľ�����nt�߻�����֧�֣�", "Thanks!", MB_OK | MB_ICONINFORMATION);
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
	ShouYue syxc = { " ", " ", " " }; /* ��ʼ������սṹ����ڴ� */
	FILE* fp = NULL;
	FILE** fp1 = &fp;
	errno_t err = fopen_s(fp1, "D:\\syxc.txt", "wb+");
	if (fp != 0)
	{
		printf("�����趨����Լ��ʲô����Max��4�����ֻ�8����ĸ��\n");
		gets_s(syxc.name, 9);
		fflush(stdin);
		printf("�����趨����Լ�ķ����ǣ���Max��4�����ֻ�8����ĸ��\n");
		gets_s(syxc.type, 9);
		fflush(stdin);
		printf("�����趨����Լ���Ѷ��ǣ���Max��2λ���֣�\n");
		gets_s(syxc.diffculty, 3);
		fflush(stdin);
		MessageBox(NULL, "�趨��������Ľ�����nt�߻�����֧�֣�", "Thanks!", MB_OK | MB_ICONINFORMATION);
		fprintf(fp, "%s, %s, %s", syxc.name, syxc.type, syxc.diffculty);/* ���� fwrite �������룡ֻ�������� fprintf�ˡ�*/
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