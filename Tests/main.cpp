#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../LAB3/Queue.h"
#include "../LAB3/TheadQueue.h"
#include "windows.h"
#include <thread>
#include <chrono>
#include <iostream>
#include "assert.h"
TEST_CASE("Testing queue"){
    Queue<int> test;
    std::cout<<"Testing int value"<<std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock now;
    int n=50;
    int i=1;

    REQUIRE(test.isEmpty());
    REQUIRE(test.getSize()==0);
    SECTION("Testing multiple items int"){
        for (i; i<n+1; i++){
            test.insert(i);
        }
        REQUIRE(test.getSize()==n);
        REQUIRE(test.getFront()==i-n);
        REQUIRE(test.getBack()==n);
        test.popFront();
        REQUIRE(test.getSize()==n-1);
        REQUIRE(test.getFront()==i-n+1);
        REQUIRE(test.getBack()==n);
        for(int i=1;i<n;i++){
            test.popFront();
        }
        REQUIRE(test.getSize()==0);
        REQUIRE(test.isEmpty());
    }
    Sleep(1000);
    auto end= std::chrono::high_resolution_clock::now();
    std::chrono::duration<float>duration=end-start;
    std::cout<<"Duration: "<< duration.count() << std::endl;
}
TEST_CASE("Testing char"){
    Queue<char> test;
    std::cout<<"Testing char value"<<std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock now;
    int n=50;
    int i=1;

    REQUIRE(test.isEmpty());
    REQUIRE(test.getSize()==0);
    SECTION("Testing multiple items int"){
        for (i; i<n+1; i++){
            test.insert('a');
        }
        REQUIRE(test.getSize()==n);
        test.insert('b');
        REQUIRE(test.getFront()=='a');
        REQUIRE(test.getBack()=='b');
        test.popFront();
        test.popFront();
        REQUIRE(test.getSize()==n-1);
        REQUIRE(test.getFront()=='a');
        REQUIRE(test.getBack()=='b');
        for(int i=1;i<n;i++){
            test.popFront();
        }
        REQUIRE(test.getSize()==0);
        REQUIRE(test.isEmpty());
    }
    Sleep(1000);
    auto end= std::chrono::high_resolution_clock::now();
    std::chrono::duration<float>duration=end-start;
    std::cout<<"Duration: "<< duration.count() << std::endl;
}
TEST_CASE("Testing float"){
    Queue<float> test;
    std::cout<<"Testing float value"<<std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock now;
    int n=50;
    int i=1;

    REQUIRE(test.isEmpty());
    REQUIRE(test.getSize()==0);
    SECTION("Testing multiple items int"){
        for (i; i<n+1; i++){
            test.insert(i+1.5);
        }
        REQUIRE(test.getSize()==n);
        REQUIRE(test.getFront()==2.5f);
        REQUIRE(test.getBack()==n+1.5f);
        test.popFront();
        REQUIRE(test.getSize()==n-1);
        REQUIRE(test.getFront()==3.5f);
        REQUIRE(test.getBack()==n+1.5f);
        for(int i=1;i<n;i++){
            test.popFront();
        }
        REQUIRE(test.getSize()==0);
        REQUIRE(test.isEmpty());
    }
    Sleep(1000);
    auto end= std::chrono::high_resolution_clock::now();
    std::chrono::duration<float>duration=end-start;
    std::cout<<"Duration: "<< duration.count() << std::endl;
}

TEST_CASE("Testing thread safe queue int"){
    TheadQueue<int> test;
    std::cout<<"Testing safe thread queue with int"<<std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock now;
    int n=50;
    int i=0;
    REQUIRE(test.isEmpty());
    REQUIRE(test.getSize()==0);
    SECTION("Testing with threads"){

        std::thread th([&]{
            for (i; i<n/2; i++){
                test.insert(i);
            }
        });
        std::thread th2([&]{
            for (i; i<n; i++){
                test.insert(i);
            }
        });

        th.join();
        th2.join();

        REQUIRE(test.getSize()==n);
        REQUIRE_FALSE(test.isEmpty());
        std::thread th3([&]{
            for (int i=0; i<n/2; i++){
                test.popFront();
            }
        });
        std::thread th4([&]{
            for (int i=n/2; i<n; i++){
                test.popFront();
            }
        });

        th3.join();
        th4.join();
        REQUIRE(test.getSize()==0);
        REQUIRE(test.isEmpty());
    }
    Sleep(1000);

    auto end= std::chrono::high_resolution_clock::now();
    std::chrono::duration<float>duration=end-start;
    std::cout<<"Duration: "<< duration.count() << std::endl;


}
TEST_CASE("Testing thread safe queue char"){
    TheadQueue<char> test;
    std::cout<<"Testing safe thread queue with char"<<std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock now;
    int n=50;
    int i=0;
    REQUIRE(test.isEmpty());
    REQUIRE(test.getSize()==0);
    SECTION("Testing with threads"){

        std::thread th([&]{
            for (i; i<n/2; i++){
                test.insert('a');
            }
        });
        std::thread th2([&]{
            for (i; i<n; i++){
                test.insert('b');
            }
        });

        th.join();
        th2.join();

        REQUIRE(test.getSize()==n);
        REQUIRE_FALSE(test.isEmpty());
        std::thread th3([&]{
            for (int i=0; i<n/2; i++){
                test.popFront();
            }
        });
        std::thread th4([&]{
            for (int i=n/2; i<n; i++){
                test.popFront();
            }
        });

        th3.join();
        th4.join();
        REQUIRE(test.getSize()==0);
        REQUIRE(test.isEmpty());
    }
    Sleep(1000);

    auto end= std::chrono::high_resolution_clock::now();
    std::chrono::duration<float>duration=end-start;
    std::cout<<"Duration: "<< duration.count() << std::endl;
}
TEST_CASE("Testing thread safe queue float"){
    TheadQueue<float> test;
    std::cout<<"Testing safe thread queue with float"<<std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock now;
    int n=50;
    int i=0;
    REQUIRE(test.isEmpty());
    REQUIRE(test.getSize()==0);
    SECTION("Testing with threads"){

        std::thread th([&]{
            for (i; i<n/2; i++){
                test.insert(i+1.5);
            }
        });
        std::thread th2([&]{
            for (i; i<n; i++){
                test.insert(i+4.5);
            }
        });

        th.join();
        th2.join();

        REQUIRE(test.getSize()==n);
        REQUIRE_FALSE(test.isEmpty());
        std::thread th3([&]{
            for (int i=0; i<n/2; i++){
                test.popFront();
            }
        });
        std::thread th4([&]{
            for (int i=n/2; i<n; i++){
                test.popFront();
            }
        });

        th3.join();
        th4.join();
        REQUIRE(test.getSize()==0);
        REQUIRE(test.isEmpty());
    }
    Sleep(1000);

    auto end= std::chrono::high_resolution_clock::now();
    std::chrono::duration<float>duration=end-start;
    std::cout<<"Duration: "<< duration.count() << std::endl;

}


