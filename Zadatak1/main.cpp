#include <iostream>
#include <string>
#include <vector>
#include <numeric>

int checkInput(char *input[]);
std::vector<int> createNumberArray(int length);
std::vector<std::string> createTrain(std::vector<int> &na, int lengthOfTrain);

int main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cerr << "Error: Found no arguments!" << std::endl;
		return -1;
	}
	if (checkInput(&argv[1]) != 0) {
		std::cerr << "Error: Argument must be a number between 1 and 10!" << std::endl;
		std::cerr << "Error: Got -> " << argv[1] << std::endl;
		return -1;
	}
	int lengthOfTrain = std::stoi(argv[1]);
	std::vector<int> na = createNumberArray(lengthOfTrain);
	std::vector<std::string> sv = createTrain(na, lengthOfTrain);
	for (std::string s : sv) {
		std::cout << s << std::endl;
	}
	
}

int checkInput(char *input[]) {
	const std::string value = *input;
	const int size = value.size();
	if (size == 1) {
		int x = (int)value[0];
		if (x < 49 || x > 57) {
			return -1;
		}
		return 0;
	}
	else if (size == 2) {
		int x = (int)value[0];
		if (x < 49 || x > 57) {
			return -1;
		}

		int y = (int)value[1];
		if (x != 49 || y != 48) {
			return -1;
		}
		return 0;
	}
	return -1;
}

std::vector<int> createNumberArray(int length) {
	std::string l = "";
	for (int i = 0; i < length; i++)
	{
		l += "9";
	}

	std::vector<int> numArray(std::stoi(l));

	std::iota(numArray.begin(), numArray.end(), 0);

	return numArray;
}

std::vector<std::string> createTrain(std::vector<int> &na, int lengthOfTrain) {
	int i = 0;

	for (int n : na)
	{
		int len = std::to_string(n).length();
		if (len < lengthOfTrain) {
			i++;
		}
	}

	na.erase(na.begin(), na.begin() + i);
	std::vector<std::string> sv;
	for (int n : na)
	{
		int flag = 1;
		std::string s = std::to_string(n);
		int len = s.length();
		for (int j = 0; j < len; j++) {
			if (s[j] == '0' || s[j] == '5' || s[j] == '6' || s[j] == '7' || s[j] == '8' || s[j] == '9') {
				flag = 0;
				break;
			}
			else if (s[j] == '3') {
				if (j != 0) {
					if (j != len - 1) {
						if (s[j - 1] == '1' && s[j + 1] == '1') {
							s[j] = 'R';
						}
						else {
							flag = 0;
							break;
						}
					}
					else {
						flag = 0;
						break;
					}
				}
				else {
					flag = 0;
					break;
				}
			}
			else if (s[j] == '4') {
				if (s[j + 1] == '1' || s[j + 1] == '2') {
					s[j] = 'T';
				}
				else {
					flag = 0;
					break;
				}
			}
		}
		if (flag) {
			sv.push_back(s);
		}
	}
	return sv;
}