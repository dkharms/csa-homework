//
// Created by dkharms on 13.12.2021.
//

#ifndef FIFTH_HOMEWORK_ENTITIES_BOOK_BOOK_H_
#define FIFTH_HOMEWORK_ENTITIES_BOOK_BOOK_H_

#include <string>
#include <fstream>

class book {
private:
    std::string name, author;
public:
    book(std::string name, std::string author);

    std::string get_name();
    std::string get_author();

    void output(std::fstream &output_stream);
};

#endif //FIFTH_HOMEWORK_ENTITIES_BOOK_BOOK_H_
