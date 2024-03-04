#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

// 1-3 = 1000 size
// 4-6 = 31k size
// 7-9 = 1M size

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

    for (int num : nums) {
        std::cout << num << ", ";
    }

    std::cout << "\nSize: " << nums.size();

    return 0;
}
