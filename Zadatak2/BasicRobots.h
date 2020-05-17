#pragma once
#include "Robot.h"

class HearingRobot : virtual public Robot
{
public:
	explicit HearingRobot(const std::string &Name);
	virtual ~HearingRobot();
};
class KillingRobot : virtual public Robot
{
public:
	explicit KillingRobot(const std::string &Name);
	virtual ~KillingRobot();
};
class SeeingRobot : virtual public Robot
{
public:
	explicit SeeingRobot(const std::string &Name);
	virtual ~SeeingRobot();
};
class TalkingRobot : virtual public Robot
{
public:
	explicit TalkingRobot(const std::string &Name);
	virtual ~TalkingRobot();
};
class ThinkingRobot : virtual public Robot
{
public:
	explicit ThinkingRobot(const std::string &Name);
	virtual ~ThinkingRobot();
};
class WalkingRobot : virtual public Robot
{
public:
	explicit WalkingRobot(const std::string &Name);
	virtual ~WalkingRobot();
};