#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include "InPlaceMergeSort.hpp"
 

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
    // Sort the vector in-place using merge sort
    int median = inPlaceMergeSort(nums, time);

/*
int a;
        for (int num : nums) {
        std::cout << num << " ";
        a++;
        if (a == 500)
            std::cout << std::endl;
    }
*/

    std::cout << "\nThe median is " << median << std::endl;
    std::cout << "The time for InPlaceMergeSort is " << time << " milliseconds";


    return 0;
}




/*

NOT CORRECT


*/



/*
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>

template<class Iter>
void merge_sort(Iter first, Iter last)
{
    if (last - first > 1)
    {
        Iter middle = first + (last - first) / 2;
        merge_sort(first, middle);
        merge_sort(middle, last);
        std::inplace_merge(first, middle, last);
    }
}

// Function to find the median
double findMedian(std::vector<int>& arr) {
    int size = arr.size();
    
    merge_sort(arr.begin(), arr.end());

    if (size % 2 == 0) {
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    } else {
        return arr[size / 2];
    }
}

int main()
{
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

    std::cout << "Original array: ";
    for (int num : nums) {
        std::cout << num << " ";
    }

    double median = findMedian(nums);

    std::cout << "\nSorted array: ";
    for (int num : nums) {
        std::cout << num << " ";
    }

    std::cout << "\n\nThe median is: " << median;

    inputFile.close();

    return 0;
}
*/

