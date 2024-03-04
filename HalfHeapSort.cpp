#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "HalfHeapSort.hpp"

// // Declaration of leftChild function
// int leftChild(int i);

// void percDown(std::vector<int>& heap, std::vector<int>::size_type hole);

// void buildHeap(std::vector<int>& heap);

// int halfHeapSort(std::vector<int>& nums, int& duration);

// // Definition of leftChild function
// int leftChild(int i) {
//     return 2 * i + 1;
// }

// // Array index stores 
// // The value 

// void percDown(std::vector<int>& heap, std::vector<int>::size_type hole) {
//     int child;
//     int tmp = std::move(heap[hole]);

//     for (; leftChild(hole) < heap.size(); hole = child) {
//         child = leftChild(hole);

//         // Parent is bigger than both left child and right child AND the left child and
//         // right child equal each other
//         if( heap[child] == heap[child+1] && heap[hole] > heap[child] && heap[hole] > heap[child+1]){
//             // Move the parent down to the left child
//             heap[hole] = std::move(heap[child]);
//             break;
//         } else {
//             // If the index is not out of bounds and the left child is bigger than the right child
//             if (child != heap.size() - 1 && heap[child] > heap[child + 1]) 
//                 ++child;    // Increase index to the right child
//             if (tmp > heap[child]) 
//                 heap[hole] = std::move(heap[child]);    // Move the parent down to the left or right child
//             else
//                 break;
//         }
//     }
//     // 
//     heap[hole] = std::move(tmp);
//     // If the hole's left child and right child are equal (and the hole's value is greater than theirs), 
//     // swap it with the left child.
// }

// void buildHeap(std::vector<int>& heap) {
//     for (int i = (heap.size()-1) / 2 ; i >= 0; --i){ //heap.size()-1
//         percDown(heap, i);
//     }
//     // if (!heap.empty()) {
//     //     // Move the first element to the back of the vector
//     //     heap.push_back(heap.front());

//     //     // Remove the first element
//     //     heap.erase(heap.begin());
//     // }
// }

// int halfHeapSort(std::vector<int>& nums, int& duration) {
//     auto start = std::chrono::high_resolution_clock::now();

//     buildHeap(nums);

//     std::cout << "\n Build array: ";
//     int a=0;
//         for (int num : nums) {
//         // std::cout << num << " ";
//         // a++;
//         if (a == 0){
//             std::cout << "The first num is " << num << std::endl;
//             a++;
//         }
//     }
//     std::cout << std::endl;

//     std::swap(nums[0], nums[nums.size()-1]);

//     int endIndex = (nums.size()-2) / 2;

//     // Sort only until the second largest element
//     for (int j = nums.size(); j > endIndex; --j) {
//         std::swap(nums[0], nums[j]);
//         nums.pop_back();
//         percDown(nums, 0);
//     }

//     auto end = std::chrono::high_resolution_clock::now();

//     auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
//     duration = diff.count();

//     return nums[0]; // Return the new maximum element
// }
// 28, 28, 21 = 25.7
// 348, 344, 400 = 364
// 
int main() {
    std::ifstream inputFile("input9.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    std::vector<int> nums;
    int num;

    while (inputFile >> num) {
        nums.push_back(num);
    }

    int time;
    int newMax = halfHeapSort(nums, time);

    // std::cout << "\nSorted array: ";

    // std::cout << "Index 0 " << nums[0] << std::endl;
    // int a=0;
    //     for (int num : nums) {
    //     std::cout << num << " ";
    //     a++;
    //     if (a == 500)
    //         std::cout << std::endl;
    // }
    // std::cout << std::endl;
    std::cout << "\n\nThe new maximum element is " << newMax << std::endl;
    std::cout << "The time for HalfHeapSort is " << time << " milliseconds";

    return 0;
}
