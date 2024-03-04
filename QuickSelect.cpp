#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "QuickSelect.hpp"

// Function to find the median of three elements
void median3(std::vector<int>& a, std::vector<int>::iterator left, std::vector<int>::iterator right);

// Function to perform insertion sort on the subarray
void insertionSort(std::vector<int>& a, std::vector<int>::iterator left, std::vector<int>::iterator right);

// Function to perform the Hoare partition
std::vector<int>::iterator hoarePartition(std::vector<int>& a, std::vector<int>::iterator low, std::vector<int>::iterator high);

// Recursive quickSelect function
void recursive_quickSelect(std::vector<int>& nums, std::vector<int>::iterator left, std::vector<int>::iterator right);

// QuickSelect function
int quickSelect(std::vector<int>& nums, int& duration);

int main() {
    std::ifstream inputFile("input9.txt"); // Replace "input1.txt" with the actual file name

    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    std::vector<int> nums;
    int num;

    while (inputFile >> num) {
        nums.push_back(num);
    }
    
    // nums = {8,1,4,9,0,3,5,2,7,6,9};
    int time;
    int median = quickSelect(nums, time);

// std::cout << "THE FINAL SORTED VECTOR " << std::endl;
//     int a =0;

//     for (int num : nums) {

//         if(a < 20) 
//             std::cout << num << " ";
//         a++;
//         if (a == 500)
//             std::cout << std::endl;
//     }

    std::cout << "\n\nThe median is " << median << std::endl;
    std::cout << "The time for quickSelect is " << time << " milliseconds";

    return 0;
}

// // Function to find the median of three elements
// void median3(std::vector<int>& a, std::vector<int>::iterator left, std::vector<int>::iterator right) {
//     // std::cout << "STARTING median3 with left being " << *left << "and right being " << *(right) << std::endl;

//     auto center = (left + std::distance(left, right) / 2) ;

//         //right = right-1; // TRUE LAST ELEMENT

//         if (*left >= *center) {
//         if (*center >= *right) {
//             std::iter_swap(center, right);
//             //return right;
//         } else if (*left <= *right) {
//             std::iter_swap(left, right);
//             //return left;
//         } else {
//             //return right;
//         }
//     } else {
//         if (*left >= *right) {
//             std::iter_swap(left, right);
//             //return left;
//         } else if (*center <= *right) {
//             std::iter_swap(center, right);
//             //return center;
//         } else {
//             //return right;
//         }
//     }
    
// /*
//     // std::cout << "THE CENTER IS " << *center << " and the last element is " << *right << std::endl;

//     if (*center < *left) {
//         // std::cout << "CENTER (" << *center << ") < LEFT (" << *left << ")" << std::endl;

//         std::iter_swap(left, center);
//         // for (int num : a) {
//         //     std::cout << num << " ";
//         // }
//         // std::cout << std::endl << std::endl;
//     }
//     if (*right < *left) {
//         // std::cout << "RIGHT (" << *right << ") < LEFT (" << *left << ")" << std::endl;

//         std::iter_swap(left, right);
//         // for (int num : a) {
//         //     std::cout << num << " ";
//         // }
//         // std::cout << std::endl << std::endl;
//     }
//     if (*right < *center) {
//         // std::cout << "RIGHT (" << *right << ") < CENTER (" << *center << ")" << std::endl;

//         std::iter_swap(center, right);
//         // for (int num : a) {
//         //     std::cout << num << " ";
//         // }
//         // std::cout << std::endl << std::endl;
//     }

//     // std::cout << "SWAP CENTER (" << *center << ") and RIGHT - 1 (" << *(right-1) << ")" << std::endl;
//     std::iter_swap(center, right - 1); // Place pivot at right-1

//     // std::cout << "AFTER SWAP WHICH PLACES PIVOT FOR HoareParition is at RIGHT-1" << std::endl;
//     // for (int num : a) {
//     //     std::cout << num << " ";
//     // }
//     // std::cout << std::endl;

//     return (right -1);
// */
// }


// // Function to perform insertion sort on the subarray
// void insertionSort(std::vector<int>& a, std::vector<int>::iterator left, std::vector<int>::iterator right) {
//     std::cout << " INSERTION SORTING" << std::endl;

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
//     int pivot = *high;

//     // std::cout << "STARTING HOARE'S PARTITION" << std::endl;
//     //     for (int num : a) {
//     //         std::cout << num << " ";
//     //     }
//     //     std::cout << std::endl << std::endl;

//     //std::iter_swap(pivot_iter, high);

//     // std::cout << "SWAPPED PIVOT AND HIGH" << std::endl;
//     // for (int num : a) {
//     //     std::cout << num << " ";
//     // }
//     // std::cout << std::endl << std::endl;

//     // Median3 will find the median and place in the back of the arary
//     // Hoare parition will parition around the pivot and then returns the place of the pivot.
//     // Call recursive quickslect, node pivot form hoare partiiotn to know how to make recursive call

//     auto i = low;
//     auto j = high - 1;

//     for( ; ; ) {
//         while (*i < pivot) {
//             i++;
//         }
//         while (pivot < *j) {
//             j--;
//         }

//         if(i < j){ 
//             std::iter_swap(i, j);

//             // std::cout << "SWAP i and j" << std::endl;
//             // for (int num : a) {
//             //     std::cout << num << " ";
//             // }
//             // std::cout << std::endl << std::endl;
//         } else {
//             break;
//         }
//     }
//     //High is the pivot
//     std::iter_swap(i, high);

//     return i;
// }

// // // Recursive quickSelect function
// // void recursive_quickSelect(std::vector<int>& nums, std::vector<int>::iterator left, std::vector<int>::iterator right) {
// //     //int mid = (nums.size()-1) / 2;
// //     int mid = std::distance(left, right) / 2;

// //     std::vector<int>::iterator k = nums.begin() + mid;


// //     if (std::distance(left, right) > 20) {
// //         auto pivot = median3(nums, left, right);

// //         // Place pivot at the end
// //         std::swap(*pivot, *(right - 1));

// //         // Begin partitioning
// //         auto i = hoarePartition(nums, left, right - 1);

// //         // Recurse on the smaller side
// //         if (std::distance(left, i) < std::distance(left, k)) {  // Corrected: Use i < k instead of i >= k
// //             recursive_quickSelect(nums, left, i - 1);
// //         }
// //         // Recurse on the larger side
// //         else if (std::distance(i + 1, right) > std::distance(left, right)) {
// //             recursive_quickSelect(nums, i + 1, right);
// //         } else {
// //             // do nothing
// //         }
// //     } else {
// //         // Do an insertion sort on the subarray
// //         insertionSort(nums, left, right + 1);
// //     }
// // }

// void recursive_quickSelect(std::vector<int>& nums, std::vector<int>::iterator left, std::vector<int>::iterator right) {
//     // std::cout << "STARTING RECURSIVE QUICKSELECT" << std::endl << std::endl;

//     // std::cout << "THE left is " << *left << " and the right is " << *right << std::endl;

//     if (std::distance(left, right) >= 10) {

//         median3(nums, left, right);

//         auto pivot = hoarePartition(nums, left, right);

//         auto i = left;
//         auto j = right - 1;

//         //std::iter_swap(i, right);

//         auto k = nums.begin() + ((nums.size()-1)/2);

//         // std::cout << std::distance(nums.begin(), left) << " " << std::distance(nums.begin(), pivot) << " " << std::distance(nums.begin(), right) << " K:" << std::distance(nums.begin(),k) << std::endl;
//         if (k < pivot) {
//             recursive_quickSelect(nums, left, pivot - 1);
            
//         } else {
//             recursive_quickSelect(nums, pivot + 1, right);
//         }
//     } else {
//         // If the subarray is small, use insertionSort
//         insertionSort(nums, left, right + 1);
//     }
// }

// // QuickSelect function
// int quickSelect(std::vector<int>& nums, int& duration) {
//     auto start = std::chrono::high_resolution_clock::now();
//     auto left = nums.begin();
//     //auto right = nums.end() - 1;
//     auto right = nums.end() - 1;

//     // std::cout << "\nThe last number is" << *right << "\n\n";

//     recursive_quickSelect(nums, left, right);

//     auto end = std::chrono::high_resolution_clock::now();
//     duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

//     if (nums.size() % 2 == 0)
//         return *(nums.begin() + nums.size() / 2 - 1);
//     else
//         return *(nums.begin() + nums.size() / 2);
// }
