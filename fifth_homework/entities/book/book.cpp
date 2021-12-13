#include "book.h"
#include <iostream>
book::book(std::string name, std::string author) {
    this->name = name;
    this->author = author;
}

std::string book::get_name() {
    return name;
}

std::string book::get_author() {
    return author;
}

void book::output(std::fstream &output_stream) {
    output_stream << "    " << name << " " << author << '\n';
}
