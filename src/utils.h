#pragma once
#include <string>
#include <iostream>


namespace utils {
	int random(int min, int max);
	std::string randomPass(uint32_t length, std::string addToChar);
	std::string setupPassAlphabet(std::string keyString);

	int testSetupPassAlphabet(std::string keyString, int expected);
	int testRandomPass(uint32_t length, int expected);
}