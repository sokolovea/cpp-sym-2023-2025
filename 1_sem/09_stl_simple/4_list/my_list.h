#pragma once
#include <iostream>

struct MyList {
    int value;
    MyList* ptr = nullptr;
};

MyList* init() {
    MyList* head = nullptr;
    return head;
}

long getLength(MyList* head) {
    long length = 0;
    while (head != nullptr) {
        head = head->ptr;
        length++;
    }
    return length;
}

MyList* push(MyList* head, int value) {
    MyList* newHead = new MyList;
    newHead->value = value;
    newHead->ptr = head;
    return newHead;
}

bool pop(MyList*& head, int& value) {
    if (head == nullptr) {
        return false;
    }
    value = head->value;
    MyList* oldHead = head;
    head = head->ptr;
    delete oldHead;
    return true;
}

void print(MyList* head) {
    int index = 0;
    while (head != nullptr) {
        std::cout <<"MyList[" << index << "] = " << head->value << std::endl;
        head = head->ptr;
        index++;
    }
}
