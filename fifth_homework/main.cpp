#include <iostream>
#include <thread>
#include <chrono>

#include "entities/library/library.h"
#include "entities/rucksack/rucksack.h"

void fill_rucksack(rucksack *r, uint64_t books_amount) {
    for (int i = 0; i < books_amount; ++i) {
        r->add_book(new book("test", "test"));
    }
}

void find_place_for_book(rucksack *ruck, library *library) {
    book *b = ruck->get_book();
    for (row *r: library->rows) {
        for (closet *c: r->closets) {
            if (!c->full()) {
                c->add_book(b);
                std::cout << "put " << b << " in " << c << '\n';
                return;
            }
        }
    }
}

void find_place(rucksack *ruck, library *library) {
    while (!ruck->empty()) {
        find_place_for_book(ruck, library);
    }
}

void start_work(rucksack *ruck, library *library, int threads_amount) {
    std::vector<std::thread> threads(threads_amount);

    for (int i = 0; i < threads_amount; ++i) {
        threads[i] = std::thread(find_place, ruck, library);
    }

    for (int i = 0; i < threads_amount; ++i) {
        threads[i].join();
    }
}

void test_single() {
    int m = 2;
    int n = 2;
    int k = 10;

    library *l = new library(m, n, k);
    rucksack *r = new rucksack();
    fill_rucksack(r, m * n * k);

    start_work(r, l, 4);
}

void test_multiple() {
    int m = 1000;
    int n = 20;
    int k = 500;

    library *l = new library(m, n, k);
    rucksack *r = new rucksack();
    fill_rucksack(r, m * n * k);
}

int main() {
    test_single();
}