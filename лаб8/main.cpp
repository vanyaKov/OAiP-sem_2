#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    int capacity, numElements;
    cout << "Enter capacity of the queue: ";
    cin >> numElements;
    Queue q;

    int choice;
    cin >> choice;
    while (choice != 6) {
    
        switch (choice) {
            case 1:{
                cout << "Enter " << numElements << " elements:" << endl;
                for (int i = 0; i < numElements; i++) {
                    int element;
                    cin >> element;
                    q.enqueue(element);
                }
                break;
            }
                
            case 2:{
                cout << "Queue elements: ";
                q.print();
                break;
            }
            case 3:{
                cout << "Queue size: " << q.getSize() << endl;
                break;
            }

            case 4:{
                q.deleteFirstNegative();
                break;
            }
            case 5:{
                q.clear();
            }
        }
        cin >> choice;
    }
}