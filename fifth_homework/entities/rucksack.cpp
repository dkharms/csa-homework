#include <mutex>
#include <queue>
#include "record/record.h"

class rucksack {
    std::mutex adding_record_mutex;
    std::mutex getting_record_mutex;
    std::queue<record *> records;

    void add_record(record *new_record) {
        adding_record_mutex.lock();
        records.push(new_record);
        adding_record_mutex.unlock();
    }

    record *get_record() {
        getting_record_mutex.lock();
        record *next_record = records.front();
        records.pop();
        getting_record_mutex.unlock();

        return next_record;
    }
};