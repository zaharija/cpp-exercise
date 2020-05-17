#pragma once
#include "BasicRobots.h"

class VaxBot : public TalkingRobot, public WalkingRobot
{
	std::vector<std::string> Ability;
public:
	explicit VaxBot(const std::string& Name);
	~VaxBot();
	std::vector<std::string> GetCapabilities() override;
};

class SgiBot : public HearingRobot, public SeeingRobot, public TalkingRobot
{
	std::vector<std::string> Ability;
public:
	explicit SgiBot(const std::string& Name);
	~SgiBot();
	std::vector<std::string> GetCapabilities() override;
};

class T101 : public HearingRobot, public KillingRobot, public SeeingRobot, public TalkingRobot, public ThinkingRobot, public WalkingRobot
{
	std::vector<std::string> Ability;
public:
	explicit T101(const std::string& Name);
	~T101();
	std::vector<std::string> GetCapabilities() override;
};

