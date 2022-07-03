#include "hasher.h"

using namespace hasher;

hasher::HaserStringStream::HaserStringStream(std::stringstream& ss)
	:ss_(ss)
{
	StringValidityTest(ss_.str());
	final_hash_ = Haser();
}

int hasher::HaserStringStream::Give_Hash() {
	return final_hash_;
}

int hasher::HaserStringStream::Haser() {
	int hash = 1;
	for (const auto& ch : ss_.str()) {
		char32_t cht(ch);
		hash *= halper(cht);
	}
	if (hash < 0) {
		hash = hash * -1;
	}
	return hash;
}

int hasher::HaserStringStream::halper(int val) {
	if (val <= 100) {
		val += 100;
	}
	if (val % 10 > 5) {
		val *= (val * 52) % 1000;
	}
	else {
		val *= (val * 48) % 1000;
	}
	return val;
}

void hasher::HaserStringStream::StringValidityTest(std::string_view strv) {
	if (strv.find_first_of(" \"#&$%^*()_+-=!@|\\\';:/?.,><[]{}~") != std::string::npos) {
		throw std::invalid_argument("Unauthorized characters present.");
	}
	if (strv.length() > 16) {
		throw std::invalid_argument("To long line.");
	}
	else if (strv.length() <= 4) {
		throw std::invalid_argument("To short line.");
	}
}