#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "HalfSelectionSort.hpp"


int main() {
    std::ifstream inputFile("input6.txt"); // Replace "input1.txt" with the actual file name

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
    int median = halfSelectionSort(nums, time);

    // Print the numbers

    // int a = 0;
    // for (int num : nums) {
    //     std::cout << num << " ";
    //     a++;
    //     if (a == 500)
    //         std::cout << std::endl;
    // }


    std::cout << "\n\nThe median is " << median << std::endl;
    std::cout << "The time for HalfSelectionSort is " << time << " milliseconds";

    inputFile.close();

    return 0;
}


/*
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

int halfSelectionSort(std::vector<int>& nums, int duration) {
    // Exit if vector is greater than 50000
    if (nums.size() > 50000) {
        return -1;
    }

    int min_index, halfway;

    halfway = nums.size() / 2;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < halfway+1; i++) {
        min_index = i;

        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] < nums[min_index])
                min_index = j;
        }

        if (min_index != i)
            std::swap(nums[min_index], nums[i]);
    }
    auto end = std::chrono::high_resolution_clock::now();

    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    duration = diff.count();
    return duration;
}


int main() {
    std::ifstream inputFile("input1.txt"); // Replace "input1.txt" with the actual file name

    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    std::vector<int> nums;
    int num;

    while (inputFile >> num) {
        nums.push_back(num);
    }

    int temp;
    int time = halfSelectionSort(nums, temp);

    // Print the numbers
    int a = 0;
    for (int num : nums) {
        std::cout << num << " ";
        a++;
        if (a == 500)
            std::cout << std::endl;
    }

    if(nums.size() % 2 == 0){
        std::cout << "\n\nThe median is " << nums[500] << std::endl;
    } else {
        std::cout << "\nThe median is " << nums[(nums.size()/2) + 1] << std::endl;
    }

    std::cout << "The time for StandardSort is " << time << " microseconds";

    inputFile.close();

    return 0;
}
*/