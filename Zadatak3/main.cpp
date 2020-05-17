#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "BST.h"

std::vector<std::string> getText(std::string fileName);
void printFirst(BST &tree, std::vector<std::string> firstText);
void printSecond(BST &tree, std::vector<std::string> secondText);
void printTest(BST &tree);

int main(int argc, char *argv[]) {
	//Set command line arguments to first.txt second.txt;
	BST first, second, test;
	printTest(test);
	std::cout << std::endl;
	printFirst(first, getText(argv[1]));
	std::cout << std::endl;
	printSecond(second, getText(argv[2]));

	return 0;
}

std::vector<std::string> getText(std::string fileName) {
	std::ifstream file(fileName);
	std::vector<std::string> text;
	std::string input;
	while (getline(file, input)) {
		text.push_back(input);
	}
	file.close();
	return text;
}

void printFirst(BST &tree, std::vector<std::string> firstText) {
	for (std::string text : firstText)
	{
		std::cout << text << std::endl;
		tree.AddLeaf(text.size(), text);
	}
	std::cout << std::endl;
	tree.PrintInOrder();
}

void printSecond(BST &tree, std::vector<std::string> secondText) {
	std::vector<std::string> editedText;
	int i = 0;
	for (std::string &n : secondText) {
		std::cout << n << std::endl;
		for (char &m : n) {
			m = toupper(m);
		}
		if (i < n.size()) {
			i = n.size();
		}
	}
	for (std::string n : secondText) {
		int l = n.size();
		std::string s = "";
		for (int j = 0; j < i - l; j++) {
			s += "0";
		}
		editedText.push_back(s + n);
	}
	for (std::string text : editedText)
	{
		tree.AddLeaf(std::stoull(text, 0, 16), text);
	}
	std::cout << std::endl;
	tree.PrintPreOrder();
}

void printTest(BST &tree) {
	std::vector<std::string> m = { "9", "4", "3", "6", "5", "7", "17", "22", "20" };
	for (std::string x : m) {
		tree.AddLeaf(std::stoi(x), x);
	}
	tree.PrintPreOrder();
}