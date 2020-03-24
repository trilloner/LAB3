//
// Created by bo_10 on 3/24/2020.
//
#include "CircularList.h"
#include <iostream>
using std::cout;
using std::endl;
void circular_list::create_node(int value)
{
    struct node* temp;
    temp = new(struct node);
    temp->info = value;
    if (last == nullptr)
    {
        last = temp;
        temp->next = last;
    }
    else
    {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

bool circular_list::check(int x) {
    return x > 10;
}
int circular_list::check_bool() {
    struct node*s;
    s = new node;
    cout << "Circular Link List: " << endl;
    while (s != last)
    {
        if (check(s->info) == true)
            return s->info;
        s = s->next;
    }
    return -1;
}

void circular_list::add_begin(int value)
{
    if (last == nullptr)
    {
        cout << "First Create the list." << endl;
        return;
    }
    struct node* temp;
    temp = new(struct node);
    temp->info = value;
    temp->next = last->next;
    last->next = temp;
}

void circular_list::add_after(int value, int pos)
{
    if (last == nullptr)
    {
        cout << "First Create the list." << endl;
        return;
    }
    struct node* temp, *s;
    s = last->next;
    for (int i = 0; i < pos - 1; i++)
    {
        s = s->next;
        if (s == last->next)
        {
            cout << "There are less than ";
            cout << pos << " in the list" << endl;
            return;
        }
    }
    temp = new(struct node);
    temp->next = s->next;
    temp->info = value;
    s->next = temp;
    if (s == last)
    {
        last = temp;
    }
}


void circular_list::search_element(int value)
{
    struct node* s;
    int counter = 0;
    s = last->next;
    while (s != last)
    {
        counter++;
        if (s->info == value)
        {
            cout << "Element " << value;
            cout << " found at position " << counter << endl;
            return;
        }
        s = s->next;
    }
    if (s->info == value)
    {
        counter++;
        cout << "Element " << value;
        cout << " found at position " << counter << endl;
        return;
    }
    cout << "Element " << value << " not found in the list" << endl;
}


void circular_list::display_list()
{
    struct node*s;
    if (last == nullptr)
    {
        cout << "List is empty, nothing to display" << endl;
        return;
    }
    s = last->next;
    cout << "Circular Link List: " << endl;
    while (s != last)
    {
        cout << s->info << "->";
        s = s->next;
    }
    cout << s->info << endl;
}
