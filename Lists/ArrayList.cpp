//
// Created by bo_10 on 3/24/2020.
//

#include <iostream>
#include "ArrayList.h"
#include <assert.h>
using namespace std;
ArrayList::ArrayList() {

    ArraySize = 0;
    nelts = 0;
    array = NULL;
}
ArrayList::~ArrayList() {

    delete[] array;
}
void ArrayList::MakeEmpty()
{
    delete[] array;
    nelts = 0;
    ArraySize = 0;
    array = NULL;
}
int ArrayList::Find(int y)
{
    for (int i = 0; i < nelts; i++) {
        if (array[i] == y) {
            return y;
        }
    }
    return -1;
}

int ArrayList::FindKth(int index) {
    for (int i = 0; i < nelts; i++) {
        if (i == index-1) {
            return array[i];
        }
    }
    return -1;
}
void ArrayList::Insert(double y, int position)
{
    assert(position >= 1 && position <= nelts + 1);
    int ia = position - 1;
    MakeSpace();
    if (ia < nelts) {
        memmove(&array[ia + 1], &array[ia], (nelts - ia) * sizeof(double));
    }
    array[ia] = y;
    nelts++;
}

bool ArrayList::Check(int x) {
    return x > 10;
}

int ArrayList:: Check_Bool() {
    for (int i = 0; i < nelts; i++) {
        if (Check(array[i]) == true) {
            return array[i];
        }
    }
    return -1;
}
void ArrayList::PrintList()
{
    for (int i = 0; i < nelts; i++) {
        cout << i + 1 << ". " << array[i] << endl;
    }
}
void ArrayList::MakeSpace()
{
    if (nelts < ArraySize) return;
    double* tmp;
    tmp = new double[ArraySize + ArrayIncrement];
    assert(tmp != NULL);
    if (nelts > 0) {
        memcpy(tmp, array, nelts * sizeof(double));
        delete[] array;
    }
    ArraySize += ArrayIncrement;
    array = tmp;
}
