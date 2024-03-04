#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include "StandardSort.hpp"


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

    int time;

    //auto start = std::chrono::high_resolution_clock::now();
    int median = standardSort(nums, time);
    //auto end = std::chrono::high_resolution_clock::now();


    // int a;
    // // Print the numbers
    // for (int num : nums) {
    //     std::cout << num << " ";
    //     a++;
    //     if(a==500)
    //         std::cout << std::endl;
    // }


    std::cout << "\nThe median is " << median << std::endl;
    std::cout << "The time for standardSort is " << time << " milliseconds";

    inputFile.close();

    return 0;
}
