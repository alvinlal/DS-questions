// 10 . Queue Implementation

#include <iostream>
using namespace std;

class Queue {
    int* queue;
    int front, rear, max;

  public:
    Queue(int max) {
        queue = new int[max];
        front = -1;
        rear = -1;
        this->max = max;
    }
    ~Queue() {
        delete[] queue;
    }
    bool enqueue(int item) {
        if (rear >= max - 1) {
            return false;
        }
        if (front == -1) front = 0;
        queue[++rear] = item;
        return true;
    }
    bool dequeue() {
        if (front == -1) {
            return false;
        }
        if (front >= rear) {
            front = -1;
            rear = -1;
            return true;
        }
        front++;
        return true;
    }
    void print() {
        cout << "[ ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << "]";
    }
};

int main() {
    int choice, e;
    Queue queue(5);
    while (1) {
        cout << "\n\t\tQUEUE IMPLEMENTATION";
        cout << "\n\t\t----------------";
        cout << "\n1.Enqueue";
        cout << "\n2.Dequeue";
        cout << "\n3.exit";
        cout << "\nEnter your choice : ";
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "\nEnter an element to enqueue : ";
            cin >> e;
            int enqueued = queue.enqueue(e);
            if (!enqueued) {
                cout << "\nQueue is full.";
                break;
            }
            cout << "\nSuccessfully enqueued element " << e << ", the queue is now : ";
            queue.print();
            break;
        }
        case 2: {
            int dequeued = queue.dequeue();
            if (!dequeued) {
                cout << "\nQueue is empty, Enqueue some elements before dequeueing.";
                break;
            }
            cout << "\nSuccessfully dequed, the queue is now : ";
            queue.print();
            break;
        }
        case 3: {
            exit(0);
        }
        default: { cout << "\nInvalid choice!"; }
        }
    }
}