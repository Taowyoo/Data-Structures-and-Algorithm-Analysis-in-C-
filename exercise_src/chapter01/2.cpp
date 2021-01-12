/*
 * File: 2.cpp
 * File Created: 2021-01-10 12:00:57 -08:00
 * Author: Taowyoo (caoyxsh@outlook.com)
 * Brief: My solution for word puzzle problem
 * -----
 * Last Modified: 2021-01-11 12:02:31 -08:00
 * Modified By: Taowyoo (caoyxsh@outlook.com>)
 * -----
 * Copyright 2020 - 2021
 */

#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include "../util/pprint.hpp"
using std::vector;
using std::string;


void solve(vector<vector<char>>& puzzle,vector<string>& words);

int main(int argc, char const *argv[])
{
    vector<vector<char>> puzzle = {
        {'t','h','i','s',},
        {'w','a','t','s',},
        {'o','a','h','g',},
        {'f','g','d','t',}
    };
    vector<string> words = {"this","two","fat","that"};
    pprint::PrettyPrinter printer;
    printf("Puzzle:\n");
    printer.print(puzzle);
    printf("Words:\n");
    printer.print(words);
    solve(puzzle, words);
    return 0;
}

void solve(vector<vector<char>>& puzzle,vector<string>& words){
    assert(!puzzle.empty());
    assert(!puzzle[0].empty());
    // horizontal
    printf("Horizontal results:\n");
    for (size_t i = 0; i < puzzle.size(); i++)
    {
        string str(puzzle[i].begin(),puzzle[i].end());
        for(string& word: words){
            auto begin = str.find(word);
            if(begin != string::npos){
                auto end = begin + word.size() - 1;
                printf("Found %s from (%d,%d) to (%d,%d)\n",word.c_str(),i,begin,i,end);
            }
        }
    }
    // vertical
    printf("Vertical results:\n");
    for (size_t j = 0; j < puzzle[0].size(); j++)
    {
        string str;
        for (size_t i = 0; i < puzzle.size(); i++)
        {
            str += puzzle[i][j];
        }
        for(string& word: words){
            auto begin = str.find(word);
            if(begin != string::npos){
                auto end = begin + word.size() - 1;
                printf("Found %s from (%d,%d) to (%d,%d)\n",word.c_str(),begin,j,end,j);
            }
        }
    }
    // diagonal
    printf("Diagonal results:\n");
    for(int x = 0; x < puzzle.size(); x++){
        int i = x;
        int j = 0;
        string str;
        while(i< puzzle.size() && j < puzzle[0].size()){
            str += puzzle[i++][j++];
        }
        for(string& word: words){
            auto begin = str.find(word);
            if(begin != string::npos){
                int sz = word.size() - 1;
                printf("Found %s from (%d,%d) to (%d,%d)\n",
                word.c_str(),
                x+begin,begin,
                x+begin+sz,begin+sz);
            }
        }
    } 
    for(int y = 1; y < puzzle[0].size(); y++){
        int i = 0;
        int j = y;
        string str;
        while(i< puzzle.size() && j < puzzle[0].size()){
            str += puzzle[i++][j++];
        }
        for(string& word: words){
            auto begin = str.find(word);
            if(begin != string::npos){
                int sz = word.size() - 1;
                printf("Found %s from (%d,%d) to (%d,%d)\n",
                word.c_str(),
                begin,y+begin,
                begin+sz,y+begin+sz);
            }
        }
    } 
}