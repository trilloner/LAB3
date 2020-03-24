//
// Created by bo_10 on 3/24/2020.
//


class List {
private:
    typedef struct Node {
        int data;
        Node* next;
    }*NodePtr;
    NodePtr head;
    NodePtr curr;
public:
    List();
    void add(int x);
    void show();
    void search_index(int index);
    int search_number(int number);

};








