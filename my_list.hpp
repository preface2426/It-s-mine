#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class List {
private:
    std::vector<std::string> data_;

public:
    // Constructor
    explicit List(std::string* data, int size);

    // Copy constructor
    List(const List& other);

    // Copy assignment
    List& operator=(const List& other);

    // Insert all elements from another List
    List& operator+=(const List& other);

    // Merge two Lists
    friend List operator+(const List& lhs, const List& rhs);

    // Output the stored std::string objects
    friend std::ostream& operator<<(std::ostream& os, const List& list);
};
// Constructor
List::List(std::string* data, int size=1) {
    for (int i = 0; i < size; ++i) {
        if (std::find(data_.begin(), data_.end(), data[i]) == data_.end()) {
            data_.push_back(data[i]);
        }
    }
}

// Copy constructor
List::List(const List& other) : data_(other.data_) {}

// Copy assignment
List& List::operator=(const List& other) {
    if (this != &other) {
        data_ = other.data_;
    }
    return *this;
}

// Insert all elements from another List
List& List::operator+=(const List& other) {
    for (const auto& str : other.data_) {
        if (std::find(data_.begin(), data_.end(), str) == data_.end()) {
            data_.push_back(str);
        }
    }
    return *this;
}

// Merge two Lists
List operator+(const List& lhs, const List& rhs) {
    List result(lhs);
    result += rhs;
    return result;
}

// Output the stored std::string objects
std::ostream& operator<<(std::ostream& os, const List& list) {
    os << '[';
    for (size_t i = 0; i < list.data_.size(); ++i) {
        os << list.data_[i];
        if (i < list.data_.size() - 1) {
            os << ", ";
        }
    }
    os << ']';
    return os;
}
#endif // LIST_H