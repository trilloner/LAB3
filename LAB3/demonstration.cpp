//
// Created by bo_10 on 5/4/2020.
//
#include <iostream>
#include "Queue.h"
#include <thread>
#include "TheadQueue.h"
using namespace std;
/**
 * Console Interface
 */
inline void demo() {
    cout << "Testing thread queue" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout<< "Preparing threads..." << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout<< "Init thread queue" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    TheadQueue<int> test;
    cout << "Now will be added 30 elements and deleting 10 items by 4 threads" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    thread fifth([&]{
        for (int i = 0; i <5 ; ++i) {
            test.popFront();
        }
    });
    thread second([&]{
          for (int i=0; i<10; i++){
              test.insert(i);
          }
      });

    std::thread third([&]{
          for (int i=10; i<20; i++){
              test.insert(i);
          }
      });

    std::thread fourth ([&]{
    for (int i=20; i<30; i++){
            test.insert(i);
        }
    });

  fourth.join();
  third.join();
  second.join();
  fifth.join();

    cout << "Now will be returned front and back elements" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    std::thread front ([&]{
        test.getFront();
    });
    std::thread back ([&]{
        test.getBack();
    });
    front.join();
    back.join();
    cout << "Now will be displayed queue" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    test.display();

}