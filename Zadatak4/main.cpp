#include <iostream>
#include <Windows.h>
#include <fstream>
#include <vector>
#include <string>
#include "Functions.h"


std::vector<std::string> getText(std::string fileName);
std::string getFunctions(std::string s);
void createXml(std::vector<std::string> resDll, std::vector<std::string> resName, std::vector<std::string> resResult);

int main()
{
	//Run as x64 to find dll;
	std::vector<std::string> xml = getText("func.xml");
	std::vector<std::string> dll;
	std::string str = "123";
	int BufferLength = 3;
	LPSTR Buffer = const_cast<char *>(str.c_str());

	for (std::string s : xml) {
		if (s.find("<dll>") != std::string::npos) {
			dll.push_back(getFunctions(s));
		}
		if (s.find("<name>") != std::string::npos) {
			dll.push_back(getFunctions(s));
		}
	}

	int flag = 0;
	std::vector<std::string> resDll;
	std::vector<std::string> resName;
	std::vector<std::string> resResult;
	for (int i = 0; i < dll.size(); i++)
	{
		if (i % 2 == 0) {
			std::wstring s = std::wstring(dll[i].begin(), dll[i].end());
			if (LoadLibrary(s.c_str()) != NULL) {
				flag = 1;
				std::string edited = "<dll>" + dll[i] + "</dll>";
				resDll.push_back(edited);
			}
			else {
				std::string edited = "<dll>" + dll[i] + "</dll>";
				resDll.push_back(edited);
				edited = "<result>ERROR: No such DLL.</result>";
				resResult.push_back(edited);
			}
		}
		else if (flag == 1) {
			if (dll[i] == "Foo") {
				flag = 0;
				if (Foo(Buffer, BufferLength)) {
					std::string edited = "<name>" + dll[i] + "</name>";
					resName.push_back(edited);
					edited = "<result>ooF</result>";
					resResult.push_back(edited);
				}
				else {
					std::string edited = "<name>" + dll[i] + "</name>";
					resName.push_back(edited);
					edited = "<result>ERROR: Guru Meditation</result>";
					resResult.push_back(edited);
				}
			}
			else if (dll[i] == "Bar") {
				flag = 0;
				if (Bar()) {
					std::string edited = "<name>" + dll[i] + "</name>";
					resName.push_back(edited);
					edited = "<result>???</result>";
					resResult.push_back(edited);
				}
				else {
					std::string edited = "<name>" + dll[i] + "</name>";
					resName.push_back(edited);
					edited = "<result>ERROR: Guru Meditation</result>";
					resResult.push_back(edited);
				}
			}
			else {
				flag = 0;
				std::string edited = "<name>" + dll[i] + "</name>";
				resName.push_back(edited);
				edited = "<result>ERROR: No such function.</result>";
				resResult.push_back(edited);
			}
		}
		else {
			std::string edited = "<name>" + dll[i] + "</name>";
			resName.push_back(edited);
		}
	}

	createXml(resDll, resName, resResult);
	std::cout << "Xml Created!" << std::endl;
}

std::vector<std::string> getText(std::string fileName) {
	std::ifstream file(fileName);
	std::vector<std::string> text;
	std::string input;
	while (getline(file, input)) {
		text.push_back(input);
	}
	return text;
}

std::string getFunctions(std::string s) {
	int flag = 0;
	std::string func = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (flag) {
			func += s[i];
		}
		if (s[i] == '>') {
			flag = 1;
		}
		if (s[i + 1] == '<') {
			flag = 0;
		}
	}
	return func;
}

void createXml(std::vector<std::string> resDll, std::vector<std::string> resName, std::vector<std::string> resResult) {
	std::ofstream xml("results.xml");
	xml << "<results>" << std::endl;
	for (int i = 0; i < resDll.size(); i++)
	{
		xml << "<function>" << std::endl;
		xml << resDll[i] << std::endl;
		xml << resName[i] << std::endl;
		xml << resResult[i] << std::endl;
		xml << "</function>" << std::endl;
	}
	xml << "</results>" << std::endl;
	xml.close();
}