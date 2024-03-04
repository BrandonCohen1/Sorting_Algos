#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

#ifndef HALFSELECTIONSORT_HPP
#define HALFSELECTIONSORT_HPP

int halfSelectionSort(std::vector<int>& nums, int& duration) {
    // Exit if vector is greater than 50000
    if (nums.size() > 50000) {
        std::cout << "The input was too big for selection sort." << std::endl;
        return -1;
    }

    // Start time
    auto start = std::chrono::high_resolution_clock::now();

    // Stopper to sort only half the array 
    int halfway = (nums.size()-1) / 2;

    // Sort using selection sort
    for (auto i = nums.begin(); i != nums.begin() + halfway+1; i++) {
        // Will hold smallest value found
        auto min_iter = i;

        for (auto j = i + 1; j != nums.end(); ++j) {
            // Change iterator pointing to smallest value
            if (*j < *min_iter)
                min_iter = j;
        }

        // Swap smallest value found with  i
        if (min_iter != i)
            std::iter_swap(i, min_iter);
    }

    // End time
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the elapsed time
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