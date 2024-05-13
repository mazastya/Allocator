#include <iostream>
#include <fstream>
#include <vector>

#include <ctime>

#include "Structures.h"
#include "Allocator.h"
#include "Benchmark.h"
#include <memory>

int main() {

    unsigned int start_time_alloc = clock();

    std::allocator<int> myAllocator;
    int* arr = myAllocator.allocate(1000);

    for (int i = 0; i < 100; i++) {
        arr[i] = i;
    }

//    arr[0] = 100;
//    arr[3] = 10;
//    arr[5] = 2;
//    arr[2] = 10;
//    arr[99] = 1;
//    arr[98] = 2;

    myAllocator.deallocate(arr, 100);

    unsigned int end_time_alloc = clock();
    unsigned int alloc_time = end_time_alloc - start_time_alloc;
    std::cout << "standart allocate: " << alloc_time << '\n';

    unsigned int start_time = clock();
    size_t* sizez = new size_t[3]{10, 100, 10};
    size_t* amountz = new size_t[3]{5, 15, 100};
    Allocator<int> all(sizez, amountz, 5);

//    size_t* BigS = new size_t[12]{8000, 8000000, 4000000, 2000000, 1000000, 500000, 250000, 125000, 64000, 32000, 16000, 16000000};
//    size_t* BigA = new size_t[12]{2048, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 1};
//    Allocator<int> Huge_Allocator(BigS, BigA, 12);
//
//    std::ofstream Output_Stream;
//    Output_Stream.open("Test results.txt");

//    Benchmark Speed_Comparison;
//    Speed_Comparison.Compare_Allocator_With_std(Huge_Allocator, Output_Stream);
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    std::cout << "my_allocate: " << search_time;
    return 0;
}
