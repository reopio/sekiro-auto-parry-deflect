

#include "proinfo.h"


using std::cout;
using std::endl;

void pinfo::get_wpro() {

	HWND h = FindWindowA(NULL, this->w_name);

	if (h == NULL) {
		cout << "cannot find window!" << endl;
		system("pause");
		exit(-1);

	}
	
	GetWindowThreadProcessId(h, &(this->pid));

	CloseHandle(h);


}


int pinfo::get_main_module_address() {

	//cout << this->main_module_name[0] << endl;
	//wprintf(main_module_name);

	HANDLE hsnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE, this->pid);
	MODULEENTRY32 me = { 0 };
	me.dwSize = sizeof(MODULEENTRY32);

	if (Module32First(hsnapshot, &me)) {
		do {
			if (_tcscmp(me.szModule, this->main_module_name) == 0) {
				this->main_module_address = (uintptr_t)me.modBaseAddr;
				//cout << std::hex << this->main_module_address << endl;
				CloseHandle(hsnapshot);
				return 0;
			}
		} while (Module32Next(hsnapshot, &me));
	}
	CloseHandle(hsnapshot);

	cout << "cannot find main module address!" << endl;
	system("pause");

	exit(-1);

	return -1;
}


uintptr_t pinfo::get_sig_address(uschar* sig) {

	unsigned char buffer[81920];

	unsigned char* acc_sig = sig->st;
	//cout << std::hex << (unsigned)acc_sig[0] << endl;
	//cout << std::hex << (unsigned)acc_sig[1] << endl;
	//cout << std::hex << (unsigned)acc_sig[2] << endl;

	HANDLE acc_hnd = this->hnd;

	DWORD oldprotect; 

	unsigned len = sig->st_len, buf_l = 81920 - len;
	//std::cout <<std::dec<< len << endl;
	//std::cout <<std::dec<< buf_l << endl;
	

	uintptr_t b_address = this->main_module_address, sig_addr;

	VirtualProtectEx(this->hnd, (LPVOID*)(this->main_module_address), 0x7FFE80C56FFE, PROCESS_ALL_ACCESS, &oldprotect);
	///cout << 1 << endl;
	for (unsigned i = 0x0; i < 0x666533D1; ++i) {
		ReadProcessMemory(acc_hnd, (LPVOID)b_address, buffer, sizeof(buffer), 0);
		b_address = b_address + 81920;
		for (unsigned j = 0; j < buf_l; ++j) {
			for (unsigned k = 0; k < len; ++k) {
				//cout << acc_sig[k] << endl;
				if (acc_sig[k] != buffer[j + k]) {
					break;
				}

				if (acc_sig[k] == buffer[j + k]) {
					if (k + 1 == len) {
						sig_addr = b_address + j - 81920;
						VirtualProtectEx(this->hnd, (LPVOID)(this->main_module_address), 0x7FFE80C56FFE, oldprotect, &oldprotect);
						//CloseHandle(acc_hnd);
						//cout << std::hex << b_address << endl;
						return sig_addr;
					}
				}
			}
		}
	}

	cout << "cannot find signature!" << endl;

	CloseHandle(acc_hnd);

	system("pause");

	exit(-1);


	return -1;

}


void pinfo::set_all() {

	this->get_wpro();

	this->get_main_module_address();

	this->hnd = OpenProcess(PROCESS_ALL_ACCESS, FALSE, this->pid);

	//std::cout << sizeof(this->sig_1) << endl;

	this->sig_addr1 = this->get_sig_address(sig_1);

	//std::cout << std::hex << (uintptr_t)sig_addr1 << std::endl;

	this->sig_addr2 = this->get_sig_address(sig_2);

	//std::cout << std::hex << sig_addr2 << std::endl;
}

