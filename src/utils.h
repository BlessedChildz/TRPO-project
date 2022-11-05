#pragma once
#include <string>
#include <iostream>


namespace utils {
	std::string randomPass(uint32_t length, std::string addToChar);
	std::string setupPassAlphabet(std::string keyString);
}
