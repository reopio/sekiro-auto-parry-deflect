#pragma once

#include <iostream>


#include <Windows.h>
#include <TlHelp32.h>
#include <tchar.h>

struct uschar {

	unsigned char* st;
	int st_len;

};

class pinfo {

public:
	char *w_name; 
	
	wchar_t *main_module_name;

	uschar *sig_1, *sig_2;

	////////////////////

	DWORD pid;

	uintptr_t main_module_address, sig_addr1, sig_addr2;

	HANDLE hnd;

	int get_main_module_address();

	uintptr_t get_sig_address(uschar* sig);




	void set_all();

private:

	void get_wpro();



};