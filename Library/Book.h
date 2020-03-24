//
// Created by bo_10 on 3/24/2020.
//

#ifndef LAB1_BOOK_H
#define LAB1_BOOK_H

#include <iostream>
#include <string>

class Book {
private:
    std::string name;
    std::string author;
    int data;
    int pages;
    std::string anotatsion;
public:
    Book();
    friend std::ostream &operator<<(std::ostream &os, const Book &dt);
    void SetBook(std::string name, std::string author, int number_stor, std::string anotatsion,int data);
    std::string GetInfoBook();
    std::string GetName();
};
#endif //LAB1_BOOK_H
