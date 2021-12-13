#include <iostream>
#include <vector>
#include <thread>
#include <cmath>
#include "entities/rucksack/rucksack.h"
#include "entities/library/library.h"

void print_error(std::string message) {
    std::cout << "\e[31m[ERROR]\e[0m " << message << '\n';
}

void print_success(std::string message) {
    std::cout << "\e[92m[SUCCESS]\e[0m " << message << '\n';
}

void print_warning(std::string message) {
    std::cout << "\e[93m[WARNING]\e[0m " << message << '\n';
}

void find_place_for_book(rucksack *r, std::vector<row *> *v) {
    book *b = r->get_book();
    for (int i = 0; i < v->size(); ++i) {
        for (int j = 0; j < v->at(i)->amount(); ++j) {
            closet *c = v->at(i)->get_closet(j);
            if (!c->full()) {
                bool is_added = c->add_book(b);
                if (is_added) {
                    return;
                }
            }
        }
    }
}

void thread_task(rucksack *r, std::vector<row *> *l) {
    while (!r->empty()) {
        find_place_for_book(r, l);
    }
}

void fill_rucksack_random(rucksack *r) {
    for (int i = 0; i < r->amount(); ++i) {
        book *b = new book(std::to_string(random()), std::to_string(random()));
        r->add_book(b);
    }
}

void fill_rucksack(rucksack *r, std::fstream &input_stream) {
    for (int i = 0; i < r->amount(); ++i) {
        std::string name, author;
        input_stream >> name >> author;
        book *b = new book(name, author);
        r->add_book(b);
    }
}

void get_input(int &rows, int &closets, int &books, std::fstream &input_stream) {
    input_stream >> rows >> closets >> books;
}

rucksack *init(std::vector<row *> *rows, std::string arg) {
    int rows_amount, closets_amount, books_amount;
    std::fstream input_stream(arg, std::fstream::in);

    if (!input_stream.is_open() && arg != "-r") {
        print_error("Wrogn file...");
        throw std::exception();
    }

    if (arg != "-r") {
        get_input(rows_amount, closets_amount, books_amount, input_stream);
    } else {
        rows_amount = rand() % 20;
        closets_amount = rand() % 20;
        books_amount = rand() % 20;
    }

    print_warning("Creating library with this parameters");
    std::cout << rows_amount << " " << closets_amount << " " << books_amount << '\n';

    print_warning("Filling rucksack with tasks...");
    rucksack *r = new rucksack(rows_amount * closets_amount * books_amount);
    for (int i = 0; i < rows_amount; ++i) {
        rows->push_back(new row(closets_amount, books_amount));
    }

    if (arg == "-r") {
        fill_rucksack_random(r);
    } else {
        fill_rucksack(r, input_stream);
    }

    return r;
}

void run_task(rucksack *r, std::vector<row *> *rows) {
    int threads_amount = static_cast<int>(log10(r->amount())) + 1;
    std::vector<std::thread> threads;
    for (int i = 0; i < threads_amount; ++i) {
        threads.push_back(std::thread(thread_task, r, rows));
    }

    for (int i = 0; i < threads_amount; ++i) {
        threads[i].join();
    }
}

void finish(rucksack *r, std::vector<row *> *rows) {
    std::fstream output_stream("../output.txt", std::fstream::out);

    for (int i = 0; i < rows->size(); ++i) {
        row *current_row = rows->at(i);
        current_row->output(output_stream);
    }

    for (int i = 0; i < rows->size(); ++i) {
        delete rows->at(i);
    }

    delete r;
}

int main(int argc, char *argv[]) {
    srand(time(nullptr));
    std::vector<row *> rows;
    print_success("Starting program...");
    rucksack *r = init(&rows, argv[1]);

    print_success("Starting tasks execution...");
    run_task(r, &rows);

    print_success("Finishing task...");
    finish(r, &rows);
}
