// O(N2)

/////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "QuickSelect.hpp"
#include "WorstCaseQuickSelect.hpp"


int main() {

    // int j = 1;
    // int even = 0;
    // int back_nums = 0;

    // for (int i = 0; i < 20000; i++) {
    //     if (i < 10000) {
    //         if (i % 2 == 0) {
    //             nums.push_back( (2 * even) + 1 );
    //             even++;
    //         }
    //         else {
    //             nums.push_back((2* back_nums + 1) + 10000);
    //             back_nums++;
    //         }
    //     } else {
    //         // Move this line outside of the conditional
    //         nums.push_back(2 * j);
    //         j++;
    //     } 
    // }

/*
    std::cout << "PRESORTED:\n";
    int t = 0;
        for (int num : nums) {
            std::cout << num << " ";
            if(10000 == t)
                std::cout << "\n\n" << std::endl;
        }
    std::cout << "\n\n";
*/

    std::vector<int> nums = worstCaseQuickSelect();

    int time;

    int median = quickSelect(nums, time);

    // std::cout << "SORTED ARRAY" << std::endl;
    // int a = 0;
    // for (int num : nums) {
    //     std::cout << num << " ";
    //     a++;
    //     if (a == 500)
    //         std::cout << std::endl;
    // }

    std::cout << std::endl;
    std::cout << "\n\nThe median is " << median << std::endl;
    std::cout << "The time for quickSelect is " << time << " milliseconds";

    return 0;
}

// // Function to find the median of three elements
// std::vector<int>::iterator median3(std::vector<int>& a, std::vector<int>::iterator left, std::vector<int>::iterator right) {
//     auto center = left + std::distance(left, right) / 2;

//     if (*center < *left) {
//         std::iter_swap(left, center);
//     }
//     if (*right < *left) {
//         std::iter_swap(left, right);
//     }
//     if (*right < *center) {
//         std::iter_swap(center, right);
//     }

//     std::iter_swap(center, right - 1); // Place pivot at right-1
//     return (right - 1);
// }

// // Function to perform insertion sort on the subarray
// void insertionSort(std::vector<int>& a, std::vector<int>::iterator left, std::vector<int>::iterator right) {
//     std::cout << "SORTING" << std::endl;

//     for (auto p = left + 1; p <= right; ++p) {
//         int tmp = std::move(*p);
//         auto j = p;

//         for (; j != left && tmp < *(j - 1); --j)
//             *j = std::move(*(j - 1));

//         *j = std::move(tmp);
//     }
// }

// // Function to perform the Hoare partition
// std::vector<int>::iterator hoarePartition(std::vector<int>& a, std::vector<int>::iterator low, std::vector<int>::iterator high) {
//     auto pivot = median3(a, low, high);
//     std::iter_swap(pivot, high);
//     auto i = low;
//     auto j = high-1;

//     while(i<j && j>i){
//         while(i<j){
//             i++;
//         }
//         while(i<j){
//             j++;
//         }
//         std::iter_swap(i, j);
//     }
//     std::iter_swap(i, pivot);

//     return pivot;
// }

// // QuickSelect function
// int quickSelect(std::vector<int>& nums, int& duration) {
//     auto start = std::chrono::high_resolution_clock::now();

//     int k = nums.size() / 2; // Choose the middle element for median

//     auto left = nums.begin();
//     auto right = nums.end() - 1;

//     while (left <= right) {
//         if (std::distance(right, left) > 20) {
//             auto pivot = median3(nums, left, right);
//             auto i = hoarePartition(nums, left, right);

//             if (k < std::distance(nums.begin(), i))
//                 right = i;
//             else if (k > std::distance(nums.begin(), i))
//                 left = i + 1;
//             else {
//                 break;
//             }
//         } else {
//             insertionSort(nums, left, right);
//             break;
//         }
//     }

//     auto end = std::chrono::high_resolution_clock::now();
//     duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

//     if(nums.size() % 2 == 0)
//         return *(nums.begin() + k - 1);
//     else
//         return *(nums.begin() + k);
// }