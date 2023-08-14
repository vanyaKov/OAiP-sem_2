#pragma once

#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Queue();
    ~Queue();
    void enqueue(int data);
    int dequeue();
    bool isEmpty() const;
    int getSize() const;
    void clear();
    void deleteFirstNegative();
    void print() const;
};
