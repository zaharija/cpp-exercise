#include <iostream>
#include "Robot.h"

Robot::Robot(const std::string& Name) { this->Name = Name; }
Robot::~Robot() = default;

std::ostream& operator << (std::ostream& OStream, Robot& Robot)
{
	OStream << Robot.Name << ": ";
	for ( std::string type : Robot.GetCapabilities() )
	{
		OStream << type << " ";
	}
	return OStream;
}