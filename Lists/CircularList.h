//
// Created by bo_10 on 3/24/2020.
//

#ifndef LAB1_CIRCULARLIST_H
#define LAB1_CIRCULARLIST_H


struct node
{
    int info;
    struct node* next;
}*last;


class circular_list
{
public:
    void create_node(int value);
    void add_begin(int value);
    void add_after(int value, int position);
    void search_element(int value);
    void display_list();
    bool check(int value);
    int check_bool();
    circular_list()
    {
        last = nullptr;
    }
};

#endif //LAB1_CIRCULARLIST_H
