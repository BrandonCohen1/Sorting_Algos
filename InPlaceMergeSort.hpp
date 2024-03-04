#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

#ifndef INPLACEMERGESORT_HPP
#define INPLACEMERGESORT_HPP

// Recursive part of inplace merge 
void inplace_sort(std::vector<int>::iterator first, std::vector<int>::iterator last) {

    // Base case, 1 element
    if (std::distance(first, last) <= 1) {
        return;
    }

    // Iterator to the middle of the array
    auto middle = first + std::distance(first, last) / 2;

    // Recursive calls to beginning of vector ot the middle and then
    // middle to the last
    inplace_sort(first, middle);
    inplace_sort(middle, last);

    // Merge the two halves using std::inplace_merge
    std::inplace_merge(first, middle, last);
}

int inPlaceMergeSort(std::vector<int>& nums, int& duration) {
    // Start time
    auto start = std::chrono::high_resolution_clock::now();

    // Call recursive inplace merge sort
    inplace_sort(nums.begin(), nums.end());
    
    // End time
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the elapsed time
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    duration = diff.count();

    // Return median
    if(nums.size() % 2 == 0){
        return nums[(nums.size()/2) - 1];
    } else {
        return nums[nums.size()/2];
    }
} 

#endif