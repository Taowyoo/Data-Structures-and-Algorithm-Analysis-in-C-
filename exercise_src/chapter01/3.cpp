/*
 * File: 3.cpp
 * File Created: 2021-01-11 14:57:18 -08:00
 * Author: Taowyoo (caoyxsh@outlook.com)
 * Brief: My solution for exercise 1.3
 * -----
 * Last Modified: 2021-01-11 14:57:29 -08:00
 * Modified By: Taowyoo (caoyxsh@outlook.com>)
 * -----
 * Copyright 2020 - 2021
 */

#include <random>
#include <string>
using std::string;
// objects for generating random double
std::random_device rd;  //Will be used to obtain a seed for the random number engine
std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
std::uniform_real_distribution<> dis(-1000000.0, 1000000.0);
/**
 * @brief Get a random double number
 * 
 * @return double Random double number
 */
double getDouble()
{
    return dis(gen);
}
void printDigit(size_t num){
    printf("%d",num);
}
void printUInt(size_t num)
{
    if (num >= 10)
        printUInt(num / 10);
    printDigit(num % 10);
}

void printDouble(double num, size_t precision = 6)
{
    // process negtive number
    if (num < 0.0)
    {
        printf("-");
        num = -num;
    }
    // get integer part
    size_t integer = static_cast<size_t>(num);
    printUInt(integer);
    // get fractional part
    printf(".");
    double fractional = num - integer;
    for (size_t i = 0; i < precision; i++)
    {
        fractional *= 10;
        size_t digit = static_cast<size_t>(fractional);
        printDigit(digit);
        fractional -= digit;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    for (size_t i = 0; i < 10; i++)
    {
        auto dd = getDouble();
        printf("Original: %f\n", dd);
        printDouble(dd);
    }
    printf("Original: %f\n", 500.0);
        printDouble(500);
    printf("Original: %f\n", -100.0);
    printDouble(-100);
    printf("Original: %f\n", 0.00567);
    printDouble(0.00567);

    return 0;
}
