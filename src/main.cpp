#include "utils.h"
#include <string>
#include <iostream>
#include <unistd.h>


int main()
{
    std::setlocale(LC_ALL, "en_US.UTF-8");
    std::string alphabetz = "";
    int n = 0;
    std::string key = "";

    std::cout << "Available key options: d p n y N" << std::endl;
    std::cout << "Enter key: -";
    std::cin >> key;
    if (utils::setupPassAlphabet(key) != "1")
    	alphabetz = utils::setupPassAlphabet(key);
    else {
    	std::cout << "Wrong key! Shutting down..." << std::endl;
    	exit(1);
    }
    	
    std::cout << "Enter pass length: ";
    std::cin >> n;
    if (n > 0)
    	std::cout << utils::randomPass(n, alphabetz);
    else {
    	std::cout << "Password length must be a number over 0! Shutting down..." << std::endl;
    	exit(1);
    }
}
