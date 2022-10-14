#include "utils.h"
#include <algorithm>
#include <chrono>
#include <random>
#include <string>
#include <iterator>
#include <algorithm>
#include <functional>

#define DO_ONCE            \
    ([]() {                \
        static char o = 0; \
        return !o && ++o;  \
    }())

std::mt19937 rng;
int utils::random(int min, int max) {
    if (min >= max) return 1;
    if (DO_ONCE)
        rng.seed((unsigned int)std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(rng);
}

std::string utils::randomPass(uint32_t length, std::string addToChar) {
    if (length > 0) {
        std::string generatedPass = "";
        for (uint32_t i = 0; i < length; i++)
            generatedPass += addToChar[utils::random(0, sizeof(addToChar) - 1)];
        return generatedPass;
    }
    else return "1";
}

std::string utils::setupPassAlphabet(std::string keyString) {
    std::string genAlphabet = "abcdefghijklmnopqrstuvwxyz";
    if (keyString.find("p") != std::string::npos || keyString.find("n") != std::string::npos || keyString.find("y") != std::string::npos || keyString.find("N") != std::string::npos) {
        if (keyString.find("N") != std::string::npos) {
            genAlphabet = "1234567890";
            return genAlphabet;
        }
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

/*int utils::testSetupPassAlphabet(std::string keyString, int expected) {
    int output = 0;
    std::string outputStr = setupPassAlphabet(keyString);
    if (outputStr == "abcdefghijklmnopqrstuvwxyz") output = 1;
    else if (outputStr == "abcdefghijklmnopqrstuvwxyz1234567890") output = 0;
    else if (outputStr == "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") output = 0;
    else if (outputStr == "abcdefghijklmnopqrstuvwxyz!@#$%^&*?/<>") output = 0;
    else if (outputStr == "abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*?/<>") output = 0;
    else if (outputStr == "1234567890") output = 0;
    else output = 1;
    if (output == expected) return 0;
    else return 1;
}

int utils::testRandomPass(uint32_t length, int expected) {
    int output = 0;
    std::string outputStr = randomPass(length, "abcdefghijklmnopqrstuvwxyz");
    if (outputStr != "1") output = 0;
    if (output == expected) return 0;
    else return 1;
}*/
