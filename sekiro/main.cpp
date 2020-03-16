

#define ADDLEN 8



#include <iostream>


#include <Windows.h>
#include <TlHelp32.h>
#include <tchar.h>

#include "proinfo.h"




using std::cout;
using std::endl;


long long unsigned powe(long long unsigned num, unsigned i) {

	long long p = num;
	if (num == 0 || i < 0) {
		cout << "calculator error!" << endl;
		system("pause");
		exit(-1);
	}

	if (i == 0) {
		return 1;
	}
	

	for (unsigned j = 0; j < i - 1; ++j) {
		num = num * p;
	}
	return num;
}

void spread(long long unsigned addr, unsigned i, unsigned char* outp) {

	//unsigned temp = addr;
	unsigned cont = -1;
	for (unsigned k = 0; k < 16; ++k) {
		if (addr / powe(0x10, k) == 0) {
			cont = k;
			break;
		}

	}
	if (cont == -1) {
		cout << "math error!" << endl;
		system("pause");
		exit(-1);
	}
	if (cont % 2 == 0) {
		cont = cont / 2;
	}
	else {
		cont = (cont + 1) / 2;
	}
	for (unsigned j = cont; j < i - 1; ++j) {
		outp[j] = 0x0;
		//cout << std::hex << (unsigned)outp[j] << endl;
	}
	//cout << sizeof(addr) << endl;
	if (cont == i) {
		for (unsigned j = 0; j < cont - 1; ++j) {
			outp[j] = addr / powe(0x100, j) - (addr / powe(0x100, j + 1)) * 0x100;
			//cout << std::hex << (unsigned)outp[j] << endl;

		}
		outp[i - 1] = addr / powe(0x100, cont - 1);
	}
	else {
		for (unsigned j = 0; j < cont; ++j) {
			outp[j] = addr / powe(0x100, j) - (addr / powe(0x100, j + 1)) * 0x100;
			//cout << std::hex << (unsigned)outp[j] << endl;

		}
	}

	//outp[i - 1] = addr / powe(0x100, cont - 1);
	//cout << (unsigned)outp[i - 1] << endl;
	//return 0;
}



int main() {

	cout << "====================================================================================" << endl;
	cout << "只狼自动弹反修改器（格挡时一直都会弹反），好好享受一下作为大神的快感吧（滑稽）" << endl << endl << endl;
	cout << "sekiro auto parry!" << endl << endl << endl;
	system("pause");
	system("cls");
	cout << "====================================================================================" << endl;
	cout << "如果不会使用请参照我的bilibili视频：" << endl << endl;
	cout << "https://www.bilibili.com/video/av95829323/" << endl << endl << endl << endl;
	cout << "if you don't know how to use, please refer to my steam guides. My steam profile url is:" << endl << endl;
	cout << "https://steamcommunity.com/profiles/76561198156638534/" << endl << endl << endl << endl;
	cout << "请确保游戏已经在运行！" << endl << endl;
	cout << "please make sure your game is running!" << endl << endl << endl << endl;
	system("pause");
	system("cls");
	cout << "正在修改......" << endl;
	cout << "moding..." << endl;

	
	



	char window_name[] = "Sekiro";

	wchar_t m_name[] = L"sekiro.exe";

	//DWORD *player_pointer=VirtualAllocEx()

	uschar sig_1, sig_2;

	unsigned char csig_1[] = {
		0x48, 0x8B, 0x85, 0x88, 0x00, 0x00, 0x00,
		0x48, 0x85, 0xC0, 0x74, 0x07, 0x0F, 0xB6,
		0x80
	},
		csig_2[] = {
		0x89, 0x90, 0x0C, 0x0B, 0x00, 0x00
	},
		jmp_code1[] = {
		0x53, 0x48, 0xBB,

		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,


		0x48, 0x39, 0x33, 0x0F, 0x85, 0x02, 0x00,
		0x00, 0x00, 0xB1, 0x01, 0x5B, 0x48, 0x8B,
		0x85, 0x88, 0x00, 0x00, 0x00,
		0x48, 0x85, 0xC0, 0x74, 0x07, 0x0F, 0xB6,
		0x80,
		0xC4, 0x01, 0x00, 0x00, 0x48, 0x8B, 0x55,
		0xB8,
		0xC3
	},
		jmp_code2[] = {
		
		0x48, 0x8B, 0x88, 0xF8, 0x1F, 0x00, 0x00, 
		0x48, 0x8B, 0x01,
		
		0x53, 0x51, 0x48, 0xB9,

		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

		0x48, 0x8B, 0x58,
		0x08, 0x48, 0x8B, 0x5B, 0x30, 0x81, 0x7B,
		0x08, 0x63, 0x00, 0x30, 0x00, 0x74, 0x14,
		0x90, 0x90, 0x90, 0x59, 0x5B, 0x89,
		0x90, 0x0C, 0x0B, 0x00, 0x00,

		0x90, 0x90, 0x90, 0x90,
		0x90, 0x90, 0x90, 0x90,
		0xC3,

		0x81, 0x7B, 0x0C, 0x30, 0x00, 0x30, 0x00,
		0x74, 0x02, 0xEB, 0xE4,
		0x48, 0x89, 0x01, 0x31, 0xD2, 0xEB,
		0xDD
	},
		nop[] = {
			0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
			0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
			0x90, 0x90, 0x90, 0x90, 0x90, 0x90
	},
		callf[] = {
		0x53,
		0x48, 0xBB,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,

		0xFF, 0xD3, 0x5B,

		0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
		0x90
	},
		callf2[] = {
		0x53, 
		0x48, 0xBB,


		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

		0xFF, 0xD3,

		0x5B,

		0x90, 0x90
	},
		add1[ADDLEN] = { 0 }, add2[ADDLEN] = { 0 }, add3[ADDLEN] = { 0 };





	//cout << std::hex << (unsigned)csig_1[3] << endl;
	sig_1.st = csig_1;
	sig_2.st = csig_2;
	//cout << std::hex<< (unsigned)sig_1.st[1] << endl;
	//cout << std::hex<< (unsigned)csig_1[1] << endl;
	sig_1.st_len = sizeof(csig_1);
	sig_2.st_len = sizeof(csig_2);


	//std::cout << sizeof(sig_1) << endl;
	pinfo sekiro;

	sekiro.w_name = window_name;

	sekiro.main_module_name = m_name;

	sekiro.sig_1 = &sig_1;

	sekiro.sig_2 = &sig_2;

	sekiro.set_all();

	//BYTE Address[] = {0x100000000};
	//DWORD oldprotect;
	//VirtualProtectEx(sekiro.hnd, (LPVOID*)(sekiro.main_module_address), 0x7FFE80C56FFE, PROCESS_ALL_ACCESS, &oldprotect);
	////////////////////////////////////////////////
	uintptr_t* player_ptr = (uintptr_t*)VirtualAllocEx(sekiro.hnd, NULL, 8, 0x1000, 0x40),
		* jmp_addr = (uintptr_t*)VirtualAllocEx(sekiro.hnd, NULL, 4096, 0x1000, 0x40),
		* jmp2_addr = (uintptr_t*)VirtualAllocEx(sekiro.hnd, NULL, 4096, 0x1000, 0x40);

	if (!(player_ptr && jmp_addr && jmp2_addr)) {
		cout << "memory error!" << endl;
		system("pause");
		exit(-1);
	}
	//cout << std::hex << player_ptr << endl;
	//WriteProcessMemory(sekiro.hnd, player_ptr, ptr, sizeof(ptr), 0);

	//WriteProcessMemory(sekiro.hnd, jmp_addr, jmp_code1, sizeof(jmp_code1), 0);
	//cout << std::hex << jmp_addr << endl;
	//cout << std::hex << player_ptr << endl;
	//uintptr_t play_ptr = 0x123456;
	spread((long long unsigned)player_ptr, ADDLEN, add1);

	for (unsigned i = 0; i < 8; ++i) {
		jmp_code1[i + 3] = add1[i];
	}
	//cout << std::hex << (unsigned)add1[0] << endl;
	//cout << std::hex << (unsigned)add1[1] << endl;
	//cout << std::hex << (unsigned)add1[2] << endl;
	//cout << std::hex << (unsigned)add1[3] << endl;
	//cout << std::hex << (unsigned)add1[4] << endl;
	//cout << std::hex << (unsigned)add1[5] << endl;
	//cout << std::hex << (unsigned)add1[6] << endl;
	//cout << std::hex << (unsigned)add1[7] << endl;
	///////WriteProcessMemory(sekiro.hnd, (LPVOID)(jmp_addr + 0x3), jmp_code1, sizeof(jmp_code1), 0);
	
	WriteProcessMemory(sekiro.hnd, jmp_addr, jmp_code1, sizeof(jmp_code1), 0);
	
	
	/////WriteProcessMemory(sekiro.hnd, (jmp_addr + 0xb), jmp_code2, sizeof(jmp_code2), 0);


	//cout<<std::hex << (LPVOID)sekiro.sig_addr1 << endl;
	//cout << std::hex << jmp_addr << endl;

	//WriteProcessMemory(sekiro.hnd, (LPVOID)sekiro.sig_1, callf, sizeof(callf), 0);
	//WriteProcessMemory(sekiro.hnd, (LPVOID)(sekiro.sig_1 + 0x1), nop, sizeof(nop), 0);
	spread((long long unsigned)jmp_addr, ADDLEN, add2);

	for (unsigned i = 0; i < 8; ++i) {
		callf[i + 3] = add2[i];
	}
	//VirtualProtectEx(sekiro.hnd, (LPVOID*)sekiro.sig_addr1, sizeof(callf), PROCESS_ALL_ACCESS, &oldprotect);
	WriteProcessMemory(sekiro.hnd, (LPVOID)sekiro.sig_addr1, callf, sizeof(callf), 0);
	//cout << std::hex << sekiro.sig_1 << endl;
	//VirtualProtectEx(sekiro.hnd, (LPVOID*)sekiro.sig_addr1, sizeof(callf), oldprotect, &oldprotect);
	for (unsigned i = 0; i < 8; ++i) {
		jmp_code2[i + 14] = add1[i];
	}
	WriteProcessMemory(sekiro.hnd, (LPVOID)jmp2_addr, jmp_code2, sizeof(jmp_code2), 0);


	spread((long long unsigned)jmp2_addr, ADDLEN, add3);
	for (unsigned i = 0; i < 8; ++i) {
		callf2[i + 3] = add3[i];
	}
	WriteProcessMemory(sekiro.hnd, (LPVOID)(sekiro.sig_addr2 - 0xA), callf2, sizeof(callf2), 0);
	/*
	DWORD i = 0x90;
	DWORD *player_pointer = (DWORD*)VirtualAllocEx(sekiro.hnd, NULL, 8, 0x1000, 0x40);
	WriteProcessMemory(sekiro.hnd, player_pointer, &i, 1, 0);
	cout << std::hex << player_pointer << endl;
	*/
	CloseHandle(sekiro.hnd);
	system("cls");
	cout << "修改成功，若要恢复原来的样子，请重启游戏！" << endl << endl << endl;
	cout << "successfully modified. Now you are a master, enjoy it! If you want to recover, please restart the game!" << endl << endl << endl;
	system("pause");


	return 0;
}


