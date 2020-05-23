#include <iostream>
#include <chrono>
#include "demonstration.cpp"
using namespace std;


int main() {
    auto start = std::chrono::high_resolution_clock::now();
    chrono::high_resolution_clock now;
    demo();
    auto end= std::chrono::high_resolution_clock::now();
    std::chrono::duration<float >duration=end-start;
    std::cout<<"Duration: "<< duration.count() << std::endl;
    return 0;
}
