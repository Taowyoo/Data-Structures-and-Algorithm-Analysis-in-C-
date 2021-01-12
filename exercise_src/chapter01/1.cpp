/*
 * File: 1.cpp
 * File Created: 2021-01-09 20:39:18 -08:00
 * Author: Taowyoo (caoyxsh@outlook.com)
 * Brief: My solution of exercise 1.1
 * -----
 * Last Modified: 2021-01-09 20:48:21 -08:00
 * Modified By: Taowyoo (caoyxsh@outlook.com>)
 * -----
 * Copyright 2020 - 2021
 */

#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
using std::vector;

/**
 * @brief Use bobble sort with fixed k lenth array to select k-th element
 *        Time cost: O(N*k)
 * 
 * @param arr given arr
 * @param k k-th
 * @return int k-th number
 */
int selectKthElement(vector<int>& arr, int k){
    int N = arr.size();
    k = std::min(k,N);
    vector<int> karr(arr.begin(),arr.begin()+1);
    
    for(int i = 1; i < N; ++i){
        if (i<k)
        {
            karr.emplace_back(arr[i]);
            for(int j = karr.size()-1; j-1 >= 0; j--){
                if(karr[j] < karr[j-1]) std::swap(karr[j] , karr[j-1]);
                else break;
            }
        }
        else{
            if (arr[i]<karr.back())
            {
                karr[karr.size()-1] = arr[i];
                for(int j = karr.size()-1; j-1 >= 0; j--){
                    if(karr[j] < karr[j-1]) std::swap(karr[j] , karr[j-1]);
                    else break;
                }
            }
        }
    }
    return karr.back();
}

/**
 * @brief Use std::sort() to sort whole arr
 *        Time cost: O(N*log(N))
 * 
 * @param arr given arr
 * @param k k-th
 * @return int k-th number
 */
int selectKthElement2(vector<int>& arr, int k){
    std::sort(arr.begin(),arr.end());
    return arr[k-1];
}

void printVector(vector<int>& arr){
    for(int i : arr){
        printf("%d ",i);
    }
    printf("\n");
}
vector<int> generateInput(int N){
    vector<int> ret(N);
    auto gen = [N](){
        return std::rand()%N;
    };
    std::generate(ret.begin(), ret.end(), gen);
    return ret;
}

int main(int argc, char const *argv[])
{
    std::srand(std::time(nullptr));
    vector<int> Ns = {10,100,1000,10000,100000,200000};

    printf("Use bobble sort with fixed k length arr:\n");
    for(int N : Ns){
        vector<int> input = generateInput(N);
        auto start = std::chrono::steady_clock::now();
        selectKthElement(input,input.size()/2);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        printf("%10f s, %10u-th of %10u\n",elapsed_seconds.count(),input.size()/2,input.size());
    }

    printf("Use std::sort() of all number:\n");
    for(int N : Ns){
        vector<int> input = generateInput(N);
        auto start = std::chrono::steady_clock::now();
        selectKthElement2(input,input.size()/2);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        printf("%10f s, %10u-th of %10u\n",elapsed_seconds.count(),input.size()/2,input.size());
    }
    return 0;
}
