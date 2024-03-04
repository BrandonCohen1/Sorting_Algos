#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>

#ifndef MERGESORT_HPP
#define MERGESORT_HPP

// Merge sort function (recursive part)
void mergesort(std::vector<int>& nums) {

    // Base case
    if (nums.size() <= 1) {
        return;
    }

    // Middle of the vector
    int middle = nums.size() / 2;
    
    // Create two new vectors from beginning to middle and middle to end
    std::vector<int> left(nums.begin(), nums.begin() + middle);
    std::vector<int> right(nums.begin() + middle, nums.end());

    // Recursive calls
    mergesort(left);
    mergesort(right);

    // Merge the two halves using std::merge
    std::merge(left.begin(), left.end(), right.begin(), right.end(), nums.begin());
}

int mergeSort(std::vector<int>& nums, int& duration){
    // Start time
    auto start = std::chrono::high_resolution_clock::now();

    // Call recusrive mergesort
    mergesort(nums);

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