/*
 * File: 5.cpp
 * File Created: 2021-01-11 16:14:37 -08:00
 * Author: Taowyoo (caoyxsh@outlook.com)
 * Brief: My solution for Exercise 1.5
 * -----
 * Last Modified: 2021-01-11 16:14:46 -08:00
 * Modified By: Taowyoo (caoyxsh@outlook.com>)
 * -----
 * Copyright 2020 - 2021
 */

#include <bitset>
#include <string>
#include <iostream>
#include <algorithm>
using std::cout;

size_t count1sInBinary(size_t num){
    if(!num) return 0;
    return num&1?count1sInBinary(num>>1)+1:count1sInBinary(num>>1);
}

int main(int argc, char const *argv[])
{
    size_t number = 1415927;
    std::bitset<32> b2(number);
    std::string bit_str = b2.to_string();
    cout<< "Number       : " << number <<'\n';
    cout<< "Binary format: " << bit_str<<'\n';
    cout<< "Number of 1 s: " << count1sInBinary(number)<<", my solution"<<'\n';
    cout<< "Number of 1 s: " << std::count(bit_str.begin(),bit_str.end(),'1')<<", count the string"<<'\n';
    return 0;
}

