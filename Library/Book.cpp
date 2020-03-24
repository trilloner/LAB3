//
// Created by bo_10 on 3/24/2020.
//
#include "Book.h"
#include <string>
using std::string ;
Book::Book() {
    name = "";
    author = "";
    data = NULL;
    pages = NULL;
    anotatsion = "";
}
std::string Book:: GetName() {
    return name;
}
void Book::SetBook(std::string name, std::string author, int number_stor, std::string anotatsion,int data) {
    this->name = name;
    this->author = author;
    this->pages = number_stor;
    this->anotatsion = anotatsion;
    this->data = data;
}
/*std::string GetInfoBook() {
    return "\n Book Name: " + name + "\n Book Author: " + author + "\n Pages: " + to_string(pages) + "\n Anotatsion: " + anotatsion +"\n Data: "+ to_string(data)  ;
}*/

std::ostream& operator<<(std::ostream& os, const Book& dt)
{
    os << dt.name << '/' << dt.author << '/' << dt.pages << '/' << dt.anotatsion<< '/' << dt.data ;
    return os;
}
