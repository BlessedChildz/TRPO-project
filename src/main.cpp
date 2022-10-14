// pwgen.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
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

    std::cout << "Available key options: p n y N" << std::endl;
    std::cout << "Enter key: -";
    std::cin >> key;
    alphabetz = utils::setupPassAlphabet(key);

    std::cout << "Enter pass length: ";
    std::cin >> n;
    std::cout << utils::randomPass(n, alphabetz);
    
}
