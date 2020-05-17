#pragma once
#include <iostream>
#include <Windows.h>

extern bool __declspec(dllexport) Foo(LPSTR Buffer, UINT BufferLength) {
	std::string txt = "ooF";
	int len = txt.length();
	if (len <= BufferLength) {
		Buffer = const_cast<char *>(txt.c_str());
		return true;
	}
	return false;
};
extern bool __declspec(dllexport) Bar() { return false; };

