#include <iostream>
//#include "List.h"
#include "Lists/ArrayList.h"
#include "Lists/l2.h"
#include "Lists/list2.h"
#include <string>
#include "Library/Book.h"

using namespace std;

int main() {
    /*List head;
    head.add(1);
    head.add(5);
    head.show();
    cout<< endl;*/
    ArrayList temp;
    temp.Insert(14,1);
    temp.Insert(25,2);
    temp.PrintList();

    List<int> intList; //creates order linked list
    intList.insertNewNode(12);
    intList.insertNewNode(45);
    intList.insertNewNode(5);
    intList.insertNewNode(14);
    intList.print();
    string f1= "IVAN";
    string f2= "ALEX";
    string f3 = "JOHN";
    Book*first= new Book();
    Book*second= new Book();
    Book*third= new Book();

    first->SetBook("Harry","Rol",145,"dfgdfgd",90);
    second->SetBook("John","Role",15,"dfgfddfgd",56);
    third->SetBook("Alex","Rl",157,"dfgdfgfghfd",10);

    List<string> name;
    name.insertNewNode(f2);
    name.insertNewNode(f3);
    name.insertNewNode(f1);
    name.print();
    List<Book> books;
    books.insertNewNode(*first);
    books.insertNewNode(*second);
    books.insertNewNode(*third);
    books.print();
    return 0;
}