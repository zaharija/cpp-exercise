#pragma once
#include <string>
#include <iostream>
#include <vector>


class Robot
{
public:
	std::string Name;
	Robot(const std::string& Name);
	virtual ~Robot();
	virtual std::vector<std::string> GetCapabilities() = 0;
	friend std::ostream& operator << (std::ostream&, const Robot&);
};

std::ostream& operator << (std::ostream& OStream, Robot& Robot);