#include "AdvancedRobots.h"

VaxBot::VaxBot(const std::string &Name) : TalkingRobot(Name), WalkingRobot(Name), Robot(Name), 
	Ability({ "Talking", "Walking" }) {};
VaxBot::~VaxBot() = default;
std::vector<std::string> VaxBot::GetCapabilities() { return this->Ability; };

SgiBot::SgiBot(const std::string &Name) : HearingRobot(Name), SeeingRobot(Name), TalkingRobot(Name), Robot(Name), 
	Ability({"Hearing", "Seeing", "Talking"}) {};
SgiBot::~SgiBot() = default;
std::vector<std::string> SgiBot::GetCapabilities() { return this->Ability; };

T101::T101(const std::string &Name) : HearingRobot(Name), SeeingRobot(Name), TalkingRobot(Name), KillingRobot(Name), ThinkingRobot(Name), WalkingRobot(Name), Robot(Name),
	Ability({ "Hearing", "Seeing", "Talking", "Killing", "Thinking", "Walking" }) {};
T101::~T101() = default;
std::vector<std::string> T101::GetCapabilities() { return this->Ability; };