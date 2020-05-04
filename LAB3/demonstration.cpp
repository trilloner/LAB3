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
inline void demo(){
    Queue<int> test;
    TheadQueue<int>test2;
    cout<< "Select type of Queue:"<< endl;
    cout<< "1. Queue"<< endl;
    cout <<"2. Threading Queue"<<endl;
    cout<< "0. Exit"<<endl;
    int que,opt;
    while(1){
        cin>>que;
        while(1){
         if(que>=3){
            cout<<"Select 0 or 1 or 2. Try again" << endl;
            cin>>que;
            }
         else
             break;
        }
        switch(que){

            case 1:{
                tryAgain:
                cout<< "Select option:"<<endl;
                cout<< "1.Add number"<<endl;
                cout<< "2.Delete number"<<endl;
                cout<< "3.Get first number"<<endl;
                cout<< "4.Get last number"<<endl;
                cout<< "5.Get size"<<endl;
                cout<< "6.Display numbers"<<endl;
                cout<< "0. Exit"<<endl;

                cin>>opt;
                while(1){
                    if(opt<0 || opt>6){
                        cout<<"Select  1 - 6. Try again" << endl;
                        cin>>opt;
                    }
                    else
                        break;
                }
                switch (opt){
                    case 1:{
                        cout<<"1.Random"<<endl;
                        cout<< "2. User"<<endl;
                        int ql;
                        cin>>ql;
                        if(ql==1) {
                            test.insert(rand() % 129);
                            cout << "Added";
                            goto tryAgain;

                        }
                        else if(ql==2) {
                            int user;
                            cout << "Input: ";
                            cin >> user;
                            test.insert(user);
                            goto tryAgain;

                        }
                        goto tryAgain;

                    }
                    case 2:{
                        if(test.isEmpty()){
                            cout<<"Queue is empty. Add numbers. Press 0"<<endl;
                            goto tryAgain;
                        }
                        else{
                            test.popFront();
                            cout<< "Deleted"<<endl;
                            goto tryAgain;

                        }

                    }
                    case 3:{
                        if(test.isEmpty()){
                            cout<<"Queue is empty. Add numbers. Press 0"<<endl;
                            goto tryAgain;
                        }
                        else{
                            cout<< "First  element: "<< test.getFront()<<endl;
                        }
                        goto tryAgain;

                    }
                    case 4:{
                        if(test.isEmpty()){
                            cout<<"Queue is empty. Add numbers. Press 0"<<endl;
                            goto tryAgain;
                        }
                        else{
                            cout<< "Last element: "<< test.getBack()<<endl;
                        }
                        goto tryAgain;
                    }
                    case 5:{
                        cout<< "Size: "<<test.getSize()<<endl;
                        goto tryAgain;
                    }
                    case 6:{
                        if(test.isEmpty()){
                            cout<<"Queue is empty. Add numbers. Press 0"<<endl;
                            goto tryAgain;
                        }
                        else{
                            test.display();
                        }
                        goto tryAgain;
                    }
                    default:{
                    return;
                    }
                }

            }
            case 2:{
                tryAgain2:
                cout<< "Select option:"<<endl;
                cout<< "1.Add number"<<endl;
                cout<< "2.Delete number"<<endl;
                cout<< "3.Get first number"<<endl;
                cout<< "4.Get last number"<<endl;
                cout<< "5.Get size"<<endl;
                cout<< "6.Display numbers"<<endl;
                cout<< "0. Exit"<<endl;
                cin>>opt;
                while(1){
                    if(opt<0 || opt>6){
                        cout<<"Select  1 - 6. Try again" << endl;
                        cin>>opt;
                    }
                    else
                        break;
                }
                switch (opt){
                    case 1:{
                        cout<<"1.Random"<<endl;
                        cout<< "2. User"<<endl;
                        int ql;
                        cin>>ql;
                        if(ql==1) {
                            const int randNum= rand() % 129;
                            thread first([&]{test2.insert(randNum);});
                            first.join();
                            cout << "Added";
                            goto tryAgain2;

                        }
                        else if(ql==2) {
                             int user;
                            cout << "Input: ";
                            cin >> user;
                            const int tt =user;
                            thread first([&]{test2.insert(tt);});
                            first.join();
                            goto tryAgain2;
                        }
                        goto tryAgain2;

                    }
                    case 2:{
                        if(test.isEmpty()){
                            cout<<"Queue is empty. Add numbers. Press 0"<<endl;
                            goto tryAgain2;
                        }
                        else{
                            thread first([&]{test2.popFront();});
                            first.join();
                            cout<< "Deleted"<<endl;
                            goto tryAgain2;
                        }

                    }
                    case 3:{
                        if(test.isEmpty()){
                            cout<<"Queue is empty. Add numbers. Press 0"<<endl;
                            goto tryAgain;
                        }
                        else{
                            thread first([&]{
                                cout<< "First  element: "<< test2.getFront() <<endl;
                            });
                            first.join();

                        }
                        goto tryAgain;

                    }
                    case 4:{
                        if(test.isEmpty()){
                            cout<<"Queue is empty. Add numbers. Press 0"<<endl;
                            goto tryAgain;
                        }
                        else{
                            thread first([&]{
                                cout<< "Last  element: "<< test2.getBack() <<endl;
                            });
                            first.join();

                        }
                        goto tryAgain;
                    }
                    case 5:{
                        thread first([&]{
                            cout<< "Size: "<< test2.getSize() <<endl;
                        });
                        first.join();

                        goto tryAgain;
                    }
                    case 6:{
                        if(test.isEmpty()){
                            cout<<"Queue is empty. Add numbers. Press 0"<<endl;
                            goto tryAgain;
                        }
                        else{
                            thread first([&]{
                                test2.display() ;
                                cout<<endl;
                            });
                            first.join();
                        }
                        goto tryAgain;
                    }
                    default:{
                       return;
                    }
                }

            }
        }
        return;
    }




}