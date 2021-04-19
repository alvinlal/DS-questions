// 13. Implementation of circular queue

#include <iostream>
using namespace std;

class CircularQueue {

    int rear, front, max;
    int* queue;

  public:
    CircularQueue(int max) {
        queue = new int[max];
        front = -1;
        rear = -1;
        this->max = max;
    }
    bool enqueue(int item) {
        if (front == -1 && rear == -1) {
            front = rear = 0;
            queue[rear] = item;
        } else if (front == (rear + 1) % max) {
            return false;
        } else {
            rear = (rear + 1) % max;
            queue[rear] = item;
        }
        return true;
    }
    bool dequeue() {
        if (front == -1) {
            return false;
        } else if (front == rear) {
            queue[front] = -1;
            front = rear = -1;
        } else {
            queue[front] = -1;
            front = (front + 1) % max;
        }
        return true;
    }
    void print() {
        cout << "[ ";
        for (int i = 0; i < max; i++) {
            if (i == max - 1) {
                cout << queue[i];
            } else {
                cout << queue[i] << ", ";
            }
        }
        cout << " ]";
    }
};
int main() {
    int choice, e;
    CircularQueue circularQueue(5);
    while (1) {
        cout << "\n\t\tCIRCULAR QUEUE IMPLEMENTATION";
        cout << "\n\t\t-------------------------";
        cout << "\n1.Enqueue";
        cout << "\n2.dequeue";
        cout << "\n3.exit";
        cout << "\nEnter your choice:";
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "\nEnter the element to enqueue: ";
            cin >> e;
            bool enqueued = circularQueue.enqueue(e);
            if (!enqueued) {
                cout << "\nQueue is full.";
                break;
            }
            cout << "\nSuccessfully enqueued " << e << ", to the queue, the queue is now ";
            circularQueue.print();
            break;
        }
        case 2: {
            bool dequeued = circularQueue.dequeue();
            if (!dequeued) {
                cout << "\nQueue is empty.";
                break;
            }
            cout << "\nSuccessfully dequeued, the queue is now ";
            circularQueue.print();
            break;
        }
        case 3: {
            exit(0);
            break;
        }
        }
    }
}