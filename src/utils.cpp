#include "utils.h"
#include <algorithm>
#include <chrono>
#include <random>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>

std::string utils::randomPass(uint32_t length, std::string inputAlphabet) {
    if (length > 0) {
        std::string generatedPass = "";
        for (uint32_t i = 0; i < length; i++) {
            int random = rand() % inputAlphabet.size();
            generatedPass.append(inputAlphabet, random, 1);
        }
        return generatedPass;
    }
    else return "1";
}

std::string utils::setupPassAlphabet(std::string keyString) {
    std::string genAlphabet = "";
    if (keyString.find("d") != std::string::npos || keyString.find("p") != std::string::npos || keyString.find("n") != std::string::npos || keyString.find("y") != std::string::npos || keyString.find("N") != std::string::npos) {
    	if (keyString.find("d") != std::string::npos) {
            genAlphabet = "abcdefghijklmnopqrstuvwxyz";
            return genAlphabet;
        }
        if (keyString.find("N") != std::string::npos) {
            genAlphabet = "1234567890";
            return genAlphabet;
        }
        genAlphabet += "abcdefghijklmnopqrstuvwxyz";
        if (keyString.find("n") != std::string::npos)
            genAlphabet += "1234567890";
        if (keyString.find("p") != std::string::npos)
            genAlphabet += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        if (keyString.find("y") != std::string::npos)
            genAlphabet += "!@#$%^&*?/<>";
        return genAlphabet;
    }
    else {
        return "1";
    }
}
