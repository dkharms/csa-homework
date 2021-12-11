#include "book.h"

book::book() {

}

book::book(std::string name, std::string author) {
    this->name_ = name;
    this->author_ = author;
}

std::string book::name() {
    return name_;
}

std::string book::author() {
    return author_;
}
