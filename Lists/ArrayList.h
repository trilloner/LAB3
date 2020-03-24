//
// Created by bo_10 on 3/24/2020.
//

#ifndef LAB1_ARRAYLIST_H
#define LAB1_ARRAYLIST_H
using namespace std;

class ArrayList {

public:
    const static int ArrayIncrement = 2;
    ArrayList();
    ~ArrayList();
    void MakeEmpty();
    int listSize() { return nelts; }
    int Find(int y);
    void Insert(double y, int position);
    int FindKth(int position);
    void PrintList();
    int Check_Bool();
    bool Check(int x);
private:

    int ArraySize;// Size of the array.
    int nelts; // Number of elements in the array.
    double* array;// Pointer to the array.

    void MakeSpace();
};
#endif //LAB1_ARRAYLIST_H
