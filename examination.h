#pragma once
#include <map>;
#include <string>
#include <vector>

class Examination
{
public:
	Examination() {}
private:
	void filling_cont() {
		//придумать как заполнить!!!
	}
	//		0 - 9	 A - Z	  a - z
	//char 48 - 57. 65 - 90. 97 - 122
	bool Repeat_Test() {
		//ѕроверить на повторы!!!
	}
private:
	std::vector<int> hash_composition;
	std::map<std::string, int> base;
};