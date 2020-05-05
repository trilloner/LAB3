#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../LAB3/Queue.h"
#include "../LAB3/TheadQueue.h"
#include <thread>
#include <chrono>
#include <iostream>
TEST_CASE("Testing queue"){
    Queue<int> test;
    std::cout<<"Testing int value"<<std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock now;

    REQUIRE(test.isEmpty());
    REQUIRE(test.getSize()==0);
    SECTION("Testing multiple items int"){
        test.insert(1);
        test.insert(2);
        test.insert(3);
        REQUIRE(test.getSize()==3);
        REQUIRE(test.getFront()==1);
        REQUIRE(test.getBack()==3);
        test.popFront();
        REQUIRE(test.getSize()==2);
        REQUIRE(test.getFront()==2);
        REQUIRE(test.getBack()==3);
        test.popFront();
        REQUIRE(test.getSize()==1);
        REQUIRE(test.getFront()==3);
        REQUIRE(test.getBack()==3);
        test.popFront();
        REQUIRE(test.getSize()==0);
        REQUIRE(test.isEmpty());
    }
    auto end= std::chrono::high_resolution_clock::now();
    std::chrono::duration<float>duration=end-start;
    std::cout<<"Duration: "<< duration.count() << std::endl;
}
TEST_CASE("Testing char"){
    Queue<char> test;
    std::cout<<"Testing char value"<<std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock now;
    REQUIRE(test.isEmpty());
    REQUIRE(test.getSize()==0);
    SECTION("Testing multiple items char"){
        test.insert('a');
        test.insert('b');
        test.insert('c');
        REQUIRE(test.getSize()==3);
        REQUIRE(test.getFront()=='a');
        REQUIRE(test.getBack()=='c');
        test.popFront();
        REQUIRE(test.getSize()==2);
        REQUIRE(test.getFront()=='b');
        REQUIRE(test.getBack()=='c');
        test.popFront();
        REQUIRE(test.getSize()==1);
        REQUIRE(test.getFront()=='c');
        REQUIRE(test.getBack()=='c');
        test.popFront();
        REQUIRE(test.getSize()==0);
        REQUIRE(test.isEmpty());
    }
    auto end= std::chrono::high_resolution_clock::now();
    std::chrono::duration<float >duration=end-start;
    std::cout<<"Duration: "<< duration.count() << std::endl;
}
TEST_CASE("Testing float"){
    Queue<float> test;
    std::cout<<"Testing float value"<<std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock now;

    REQUIRE(test.isEmpty());
    REQUIRE(test.getSize()==0);
    SECTION("Testing multiple items float"){
        test.insert(1.1);
        test.insert(1.2);
        test.insert(1.3);
        REQUIRE(test.getSize()==3);
        REQUIRE(test.getFront()==1.1f);
        REQUIRE(test.getBack()==1.3f);
        test.popFront();
        REQUIRE(test.getSize()==2);
        REQUIRE(test.getFront()==1.2f);
        REQUIRE(test.getBack()==1.3f);
        test.popFront();
        REQUIRE(test.getSize()==1);
        REQUIRE(test.getFront()==1.3f);
        REQUIRE(test.getBack()==1.3f);
        test.popFront();
        REQUIRE(test.getSize()==0);
        REQUIRE(test.isEmpty());
    }
    auto end= std::chrono::high_resolution_clock::now();
    std::chrono::duration<float>duration=end-start;
    std::cout<<"Duration: "<< duration.count() << std::endl;
}

TEST_CASE("Testing thread safe queue int"){
    TheadQueue<int> test;
    std::cout<<"Testing safe thread queue with int"<<std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock now;

    REQUIRE(test.isEmpty());
    REQUIRE(test.getSize()==0);
    SECTION("Testing with threads"){
        std::thread th([&]{
           test.insert(34);
        });
        std::thread th2([&]{
            test.insert(56);
        });
        std::thread th3([&]{
            test.insert(6);
        });

        th.join();
        th2.join();
        th3.join();
        REQUIRE(test.getSize()==3);
        REQUIRE_FALSE(test.isEmpty());
        std::thread th4([&]{
            test.popFront();
        });
        std::thread th5([&]{
            test.popFront();
        });
        std::thread th6([&]{
            test.popFront();
        });
        th5.join();
        th6.join();
        th4.join();
        REQUIRE(test.getSize()==0);
        REQUIRE(test.isEmpty());
    }
    auto end= std::chrono::high_resolution_clock::now();
    std::chrono::duration<float>duration=end-start;
    std::cout<<"Duration: "<< duration.count() << std::endl;


}
TEST_CASE("Testing thread safe queue char"){
    TheadQueue<char> test;
    std::cout<<"Testing safe thread queue with char"<<std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock now;

    REQUIRE(test.isEmpty());
    REQUIRE(test.getSize()==0);
    SECTION("Testing with threads"){
        std::thread th([&]{
            test.insert('a');
        });
        std::thread th2([&]{
            test.insert('b');
        });
        std::thread th3([&]{
            test.insert('c');
        });

        th.join();
        th2.join();
        th3.join();
        REQUIRE(test.getSize()==3);
        REQUIRE_FALSE(test.isEmpty());
        std::thread th4([&]{
            test.popFront();
        });
        std::thread th5([&]{
            test.popFront();
        });
        std::thread th6([&]{
            test.popFront();
        });
        th5.join();
        th6.join();
        th4.join();
        REQUIRE(test.getSize()==0);
        REQUIRE(test.isEmpty());
    }
    auto end= std::chrono::high_resolution_clock::now();
    std::chrono::duration<float>duration=end-start;
    std::cout<<"Duration: "<< duration.count() << std::endl;
}
TEST_CASE("Testing thread safe queue float"){
    TheadQueue<float> test;
    std::cout<<"Testing safe thread queue with float"<<std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock now;

    REQUIRE(test.isEmpty());
    REQUIRE(test.getSize()==0);
    SECTION("Testing with threads"){
        std::thread th([&]{
            test.insert(5.4);
        });
        std::thread th2([&]{
            test.insert(5.6);
        });
        std::thread th3([&]{
            test.insert(6.3);
        });

        th.join();
        th2.join();
        th3.join();
        REQUIRE(test.getSize()==3);
        REQUIRE_FALSE(test.isEmpty());
        std::thread th4([&]{
            test.popFront();
        });
        std::thread th5([&]{
            test.popFront();
        });
        std::thread th6([&]{
            test.popFront();
        });
        th5.join();
        th6.join();
        th4.join();
        REQUIRE(test.getSize()==0);
        REQUIRE(test.isEmpty());
    }
    auto end= std::chrono::high_resolution_clock::now();
    std::chrono::duration<float>duration=end-start;
    std::cout<<"Duration: "<< duration.count() << std::endl;


}


