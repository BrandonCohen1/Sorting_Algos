#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include "MergeSort.hpp"


int main() {
    std::ifstream inputFile("input8.txt");

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
    int median = mergeSort(nums, time);

    // int a;
    //     for (int num : nums) {
    //     std::cout << num << " ";
    //     a++;
    //     if (a == 500)
    //         std::cout << std::endl;
    // }

    std::cout << "\nThe median is " << median << std::endl;
    std::cout << "The time for MergeSort is " << time << " milliseconds";
    
    return 0;
}