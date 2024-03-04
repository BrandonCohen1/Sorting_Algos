#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

#ifndef HALFHEAPSORT_HPP
#define HALFHEAPSORT_HPP

// Find left child
int leftChild(int i) {
    return 2 * i;
}

void percDown(std::vector<int>& heap, std::vector<int>::size_type hole) {
    int child;
    int tmp = std::move( heap[0] );

    for (; leftChild(hole) <= heap.size()-1; hole = child) {
        child = leftChild(hole);

            // If the index is not out of bounds and the left child is bigger than the right child
            if (child != heap.size() - 1 && heap[child] > heap[child + 1]) 
                ++child;                                // Increase index to the right child
            if (tmp > heap[child]) 
                //std::swap(heap[hole], heap[child]);
                heap[hole] = std::move(heap[child]);    // Move the parent down to the left or right child
            else
                break;
    }
    // Update hole
    heap[hole] = std::move(tmp);
}

void buildHeap(std::vector<int>& heap) {
    // Build the heap
    for (int i = (heap.size()/ 2); i > 0; --i){
        // Move index i into 0th position before calling percDown
        heap[0] = heap[i];
        percDown(heap, i);
    }
}


int halfHeapSort(std::vector<int>& nums, int& duration) {

    // Start Time
    auto start = std::chrono::high_resolution_clock::now();

    int size = nums.size()/2;
    if(nums.size()%2 == 0){
        size--;     // If size is even
    }
    
    // Move the first element to the back of the vector because nums[0] can be garbage at any point
    nums.push_back(nums[0]);

    // Build the heap with a vector of integers
    buildHeap(nums);

    // Sort only until the second largest element
    for (int j = 0 ; j < size; j++) {
        // Swap the smallest element and remove from vector => deleteMin
        std::swap(nums[1], nums.back());
        nums.pop_back();

        // PercDown but first save the value that was previously swapped with the minimum to preserve heap
        nums[0] = nums[1];
        percDown(nums, 1);
    }

    // End Time
    auto end = std::chrono::high_resolution_clock::now();

    // Compute the elapsed time
    auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    duration = diff.count();

    return nums[1]; // Return the median element
}

#endif