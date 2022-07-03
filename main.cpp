
#include <string_view>
#include <iostream>

#include "hasher.h"
#include "examination.h"


int main() {
	using namespace std::literals;
	std::string hash_variable;
	//std::cin >> hash_variable;
	hash_variable = "qwe123qwe";
	std::stringstream str(hash_variable);
	try {
		hasher::HaserStringStream hash(str);
		std::cout << hash.Give_Hash() << std::endl;
	}
	catch (std::invalid_argument& ia) {
		std::cerr << "No valid." << ' ' << ia.what() << std::endl;
		return 0;
	}
}