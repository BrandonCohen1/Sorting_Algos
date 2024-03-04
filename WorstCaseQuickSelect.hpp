#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "QuickSelect.hpp"
#include "QuickSelect.hpp"

#ifndef WORSTCASEQUICKSELECT_HPP
#define WORSTCASEQUICKSELECT_HPP

std::vector<int> worstCaseQuickSelect (void){
    // Initialize vector that will hold the numbers 
    std::vector<int> nums;

    // Indeces for adding numbers
    int j = 1;          // j adds even numbers starting at 2 after the halfway point of the vector
    int odd = 0;        // i adds odd numbers starting at 1 every other position until halfway of the vector
    int back_nums = 0;  // back_nums adds odd numbers starting at 10001 in between the odd numbers 

    int size = 20000;   // Size of array

    // for (int i = 0; i < size; i++) {
    //     if (i < size/2) {
    //         if (i % 2 == 0) {
    //             nums.push_back( (2 * odd) + 1 );
    //             odd++;
    //         }
    //         else {
    //             nums.push_back((2* back_nums + 1) + size/2);
    //             back_nums++;
    //         }
    //     } else {
    //         // Move this line outside of the conditional
    //         nums.push_back(2 * j);
    //         j++;
    //     } 
    // }

    for (int i = 0; i < size/4; i++) {
        if(0 == i){
            nums.push_back(1);
        } else {
            nums.push_back( 2*i + 2 );
            nums.push_back(2*i + 1);
        }
        // i(1) : 2*1 + 2 = 2*1 + 2 = 4
        // i(1) : 2*1 + 1 = 3
        // i(2) : 2*2 + 2 = 6
        // i(2) : 2*2 + 1 = 5
        // ...
        // i(4999) : 2*4998 + 2 = 10000
        // i(4999) : 2*4998 + 1 = 9999
    }
    for(int i = 10001; i <= size; i++){
        nums.push_back(i);
    }
    nums.push_back(2);


    // for (int i = 0; i < size; ++i) {
    //     if(i < (size/4)){
    //         if (i == 0) {
    //             nums.push_back(1);
    //         } else {
    //             nums.push_back(2 * i + 2);
    //             nums.push_back(2 * i + 1);
    //         }
    //     }

    //     if (i >= size/2) {
    //         nums.push_back(i);
    //     }
    // }

    // nums.push_back(2);
        // i(1) : 2*1 + 2 = 2*1 + 2 = 4
        // i(1) : 2*1 + 1 = 3
        // i(2) : 2*2 + 2 = 6
        // i(2) : 2*2 + 1 = 5
        // ...
        // i(4999) : 2*4998 + 2 = 10000
        // i(4999) : 2*4998 + 1 = 9999



    // for(int i = 0; i < nums.size(); i++){
    //     std::cout << nums[i] << " ";
    // }
    // std::cout << "\nThe size is " << nums.size();

    // 1 4 3 6 5 ...... 2
    // index 0 = 1
    // index 1, 2 = (4, 3)
    // index 2, 4 = (6, 5)
    // index 3, 4 = (8, 7)


    return nums;
}


#endif