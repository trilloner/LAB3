#include <iostream>
#include "BlockingQueue.h"
#include <thread>
#include <chrono>
//#include "Time.h"
#include "Queue.h"
using namespace std;


void Oper(){
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout<< "Any operations"<<endl;
}


int main() {
    auto start = std::chrono::high_resolution_clock::now();

    chrono::high_resolution_clock now;
/*    BlockingQueue<int> que;

    bool temp;

    thread first([&]{
        que.Put(5);
    });
    thread second([&]{
        que.Put(5);
    });
    thread third([&]{
        que.Put(5);
    });
    first.join();
    second.join();
    third.join();

cout << que.Size();*/

    Queue<int> tt;
    cout<<endl;
    tt.insert(3);
    tt.insert(4);
    tt.insert(45);
    if(!tt.empty())
        cout<<"not empty"<<endl;
    cout << tt.getFront()<<endl;
    cout<< tt.getBack()<<endl;
    tt.display();
    tt.popFront();
    tt.display();

    thread
    auto end= std::chrono::high_resolution_clock::now();
    std::chrono::duration<float >duration=end-start;
    std::cout<<"Duration: "<< duration.count() << std::endl;
    return 0;
}
