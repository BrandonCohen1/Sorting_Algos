#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>

#ifndef STANDARDSORT_HPP
#define STANDARDSORT_HPP

int standardSort(std::vector<int>& nums, int& duration){
    // Start time
    auto start = std::chrono::high_resolution_clock::now();

    // Standard Sort used to sort vector
    std::sort(nums.begin(), nums.end());

    // End time
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the time elapsed
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    duration = diff.count();

    // Return the median
    if(nums.size() % 2 == 0){
        return nums[(nums.size()/2) - 1];
    } else {
        return nums[nums.size()/2];
    }
}

#endif 