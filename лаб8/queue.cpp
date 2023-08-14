#include "queue.h"

Queue::Queue() : front(nullptr), rear(nullptr), size(0) {}

Queue::~Queue() {
    clear();
}

void Queue::enqueue(int data) {
    Node* node = new Node(data);

    if (isEmpty()) {
        front = node;
    } else {
        rear->next = node;
    }

    rear = node;
    size++;
}

int Queue::dequeue() {
    if (isEmpty()) {
        std::cerr << "Queue is empty." << std::endl;
        return -1;
    }

    Node* nodeToDelete = front;
    int data = nodeToDelete->data;

    if (front == rear) {
        front = rear = nullptr;
    } else {
        front = front->next;
    }

    delete nodeToDelete;
    size--;
    return data;
}

bool Queue::isEmpty() const {
    return front == nullptr;
}

int Queue::getSize() const {
    return size;
}

void Queue::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::deleteFirstNegative() {
    Node* node = front;
    Node* prev = nullptr;

    while (node != nullptr && node->data >= 0) {
        prev = node;
        node = node->next;
    }

    if (node != nullptr) {
        if (prev != nullptr) {
            prev->next = node->next;
        } else {
            front = node->next;
        }

        if (rear == node) {
            rear = prev;
        }

        delete node;
        size--;
    }
}

void Queue::print() const {
    Node* node = front;

    while (node != nullptr) {
        std::cout << node->data << " ";
        node = node->next;
    }

    std::cout << std::endl;
}