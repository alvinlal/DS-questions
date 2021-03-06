// 18. Queue using linked list

#include <iostream>
using namespace std;


class Node {
  public:
    int val;
    Node* next = nullptr;
    Node(int val) {
        this->val = val;
    }
};

class Queue {
  public:
    Node* frontptr = nullptr;
    Node* rearptr = nullptr;
    int max, front, rear;
    Queue(int max) {
        front = 0;
        rear = 0;
        this->max = max;
    }
    bool enqueue(int val) {
        if (rear == max) return false;
        Node* newNode = new Node(val);
        if (!frontptr) {
            frontptr = newNode;
            rearptr = newNode;
            front++;
            rear++;
            return true;
        }
        rearptr->next = newNode;
        rearptr = newNode;
        rear++;
        return true;
    }
    bool dequeue() {
        if (front >= rear) {
            front = -1;
            rear = 0;
            return false;
        }
        if (!frontptr || !rearptr) {
            return false;
        }
        frontptr = frontptr->next;
        front++;
        return true;
    }
    void traverse() {
        Node* currentNode = frontptr;
        cout << "[ ";
        while (currentNode) {
            cout << currentNode->val << ", ";
            currentNode = currentNode->next;
        }
        cout << "]";
    }
};

int main() {
    int choice, e;
    Queue queue(5);
    while (1) {
        cout << "\n\t\tQUEUE IMPLEMENTATION USING LINKED LIST";
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
            bool enqueued = queue.enqueue(e);
            if (!enqueued) {
                cout << "\nQueue is full.";
                break;
            }
            cout << "\nSuccessfully enqueued element " << e << ", the queue is now : ";
            queue.traverse();
            break;
        }
        case 2: {
            int dequeued = queue.dequeue();
            if (!dequeued) {
                cout << "\nQueue is empty, Enqueue some elements before dequeueing.";
                break;
            }
            cout << "\nSuccessfully dequed, the queue is now : ";
            queue.traverse();
            break;
        }
        case 3: {
            exit(0);
        }
        default: {
            cout << "\nInvalid choice!";
        }
        }
    }
}