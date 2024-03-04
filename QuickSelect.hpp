#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

#ifndef QUICKSELECT_HPP
#define QUICKSELECT_HPP


// Finds median of 3 and places it to the back of the array
void median3(std::vector<int>& a, std::vector<int>::iterator left, std::vector<int>::iterator right) {

    // Pick center of the vector
    auto center = (left + std::distance(left, right) / 2) ;

    // Compare to see what the smallest value is and swap to the back
    if (*left >= *center) {
        if (*center >= *right) {
            std::iter_swap(center, right);
            //return right;
        } else if (*left <= *right) {
            std::iter_swap(left, right);
            //return left;
        } else {
            //return right;
        }
    } else {
        if (*left >= *right) {
            std::iter_swap(left, right);
            //return left;
        } else if (*center <= *right) {
            std::iter_swap(center, right);
            //return center;
        } else {
            //return right;
        }
    }
}

// Performs insertion sort on a specific range within a vector.
void insertionSort(std::vector<int>& a, std::vector<int>::iterator left, std::vector<int>::iterator right) {
    // Iterate through the elements but start at the second element
    for (auto p = left + 1; p <= right; ++p) {
        // Save the current element
        int tmp = std::move(*p);

        // Initialize iterator j to p
        auto j = p;

        // Move elements to the right until the correct position for the current element is found
        for (; j != left && tmp < *(j - 1); j--)
            *j = std::move(*(j - 1));

        // Move temp value to j
        *j = std::move(tmp);
    }
}

// Hoare parition will parition around the pivot and then returns the place of the pivot.
std::vector<int>::iterator hoarePartition(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    // Pivot was already placed at high from median3
    int pivot = *high;

    // Set i and j
    auto i = low;
    auto j = high - 1;

    // For loop will go until i and j cross
    for( ; ; ) {
        // i finds the first value that is greater than the pivot
        while (*i < pivot) {
            i++;
        }
        // j finds the first value that is less than the pivot
        while (pivot < *j ) {
            j--;
        }
        // i and j cross over so swap
        if(i < j){ 
            std::iter_swap(i, j);
            i++;
            j--;
            
            // Condition if j crosses i OR j crosses low or i stops at high which should never happen
            if(j < i || j < low || i == high) {
                break;
            }
        } else {
            break;
        }
    }

    // High was the pivot so now we want to place pivot back to the middle of the vector
    std::iter_swap(i, high);

    // Return the pivot which median3 found
    return i;
}


// Recursive quickselect
void recursive_quickSelect(std::vector<int>& nums, std::vector<int>::iterator left, std::vector<int>::iterator right) {

    // If the subarray size is greater than 10
    if (std::distance(left, right) >= 10) {

        // Find the median using of median of 3 and place the median at the back of the vector
        median3(nums, left, right);

        // Partition all values less than the pivot (value from median of 3) to the left of pivot and then
        // place all the values greater than the pivot to the right
        auto pivot = hoarePartition(nums, left, right);

        // k is the middle of the vector
        auto k = nums.begin() + ((nums.size()-1)/2);

        // If k is to the less of pivot, iterate on the left side of pivot
        if(k == pivot){
            // Finished
        }
        else if (k < pivot) {
            recursive_quickSelect(nums, left, pivot - 1);
            
        } else {
            // else, k is on the right of pivot so recurse on the right side
            recursive_quickSelect(nums, pivot + 1, right);
        }
    } else {
        // If the subarray is 10 elements or less, use insertionSort
        insertionSort(nums, left, right + 1);
    }
}

// QuickSelect function
int quickSelect(std::vector<int>& nums, int& duration) {
    // Start time
    auto start = std::chrono::high_resolution_clock::now();

    // Initalize the beginning and end iterators
    auto left = nums.begin();
    auto right = nums.end() - 1;

    // Call the recursive quickselect
    recursive_quickSelect(nums, left, right);

    // End time
    auto end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    // Return median
    if (nums.size() % 2 == 0)
        return *(nums.begin() + nums.size() / 2 - 1);
    else
        return *(nums.begin() + nums.size() / 2);
}

#endif