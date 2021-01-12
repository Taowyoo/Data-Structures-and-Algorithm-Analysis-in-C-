/*
 * File: 4.cpp
 * File Created: 2021-01-11 13:40:20 -08:00
 * Author: Taowyoo (caoyxsh@outlook.com)
 * Brief: My solution for 1.4, only parse #include "***"
 * -----
 * Last Modified: 2021-01-11 13:40:32 -08:00
 * Modified By: Taowyoo (caoyxsh@outlook.com>)
 * -----
 * Copyright 2020 - 2021
 */

#include <iostream>
#include <fstream>
#include <string>
using std::string;
string statement = "#include ";
void processFile(const string &path,std::iostream& out);

int main(int argc, char const *argv[])
{
    string input = "4_test.cpp";
    string ouput = "4_test_result.cpp";
    std::fstream out_stream(ouput, std::ios::out);
    if (!out_stream.is_open())
    {
        std::cout << "failed to open " << ouput << '\n';
    }
    std::cout << "Processing "<< input<< " ..." << '\n';
    processFile(input,out_stream);
    out_stream.close();
    return 0;
}

void processFile(const string &path,std::iostream& out)
{
    std::fstream s(path, std::ios::in);
    if (!s.is_open())
    {
        std::cout << "failed to open " << path << '\n';
    }
    else
    {
        for (std::string line; std::getline(s, line); ) {
            if (line.substr(0,statement.size())==statement)
            {
                auto le = line.find('"',statement.size());
                if(le != string::npos){
                    auto ri = line.find('"',le+1);
                    if(ri != string::npos){
                        // std::cout << line.substr(le+1,ri-le-1) << '\n';
                        processFile(line.substr(le+1,ri-le-1),out);
                        continue;
                    }
                }
            }
            // std::cout << line << '\n';
            out << line << '\n';
        }
    }
    s.close();
}
