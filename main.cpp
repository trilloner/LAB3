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
  /*BlockingQueue<int> que;

    bool temp;

    thread first([&]{
        que.Take();
    });

    thread second([&]{
        que.Put(6);
    });
    thread third([&]{
        cout << que.Back();
    });
    thread ff([&]{
        que.Put(23);
    });

    first.join();
    second.join();
    third.join();
    ff.join();
    cout<< endl;
    cout << que.Size();
*/
   Queue<int> tt;
    cout<<endl;
    thread first([&]{
        tt.popFront();
    });
    thread second([&]{
        tt.insert(4);
    });
    cout << tt.getSize() << "-siz";
    thread third([&]{

        tt.display();
    });
    thread fr([&]{
        tt.insert(2);
    });
    thread ff([&]{
        tt.display();
    });




    first.join();
    second.join();
    third.join();
    fr.join();
    ff.join();

//tt.display();
    tt.insert(3);

    tt.insert(45);
    if(!tt.isEmpty())
        cout<<"not empty"<<endl;
    cout << tt.getFront()<<endl;
    cout<< tt.getBack()<<endl;
    tt.display();
    tt.display();
    cout << tt.getSize();

    auto end= std::chrono::high_resolution_clock::now();
    std::chrono::duration<float >duration=end-start;
    std::cout<<"Duration: "<< duration.count() << std::endl;
    return 0;
}
