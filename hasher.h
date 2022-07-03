#pragma once
#include <sstream>

namespace hasher {
class HaserStringStream
{
public:
	HaserStringStream(std::stringstream& ss);

	int Give_Hash();

private:
	int Haser();

	int halper(int val);

	void StringValidityTest(std::string_view strv);

private:
	int final_hash_ = 0;
	std::stringstream& ss_;
};
}//hasher