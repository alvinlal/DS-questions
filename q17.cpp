// 17. CAP to implement stack using linked list

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

class Stack {
  public:
    Node* first = nullptr;
    Node* last = nullptr;
    int max, top;

    Stack(int max) {
        top = -1;
        this->max = max;
    }

    bool push(int val) {
        if (top == max - 1) return false;
        Node* newNode = new Node(val);
        if (!first) {
            first = last = newNode;
            top++;
            return true;
        }
        newNode->next = first;
        first = newNode;
        top++;
        return true;
    }
    bool pop() {
        if (!first) return false;
        if (top < 0) return false;
        if (first == last) {
            first = last = nullptr;
            top--;
            return true;
        }
        first = first->next;
        top--;
        return true;
    }
    void traverse() {
        Node* currentNode = first;
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
    Stack stack(5);
    while (1) {
        cout << "\n\t\tSTACK USING LINKED LIST";
        cout << "\n\t\t----------------";
        cout << "\n1.Push";
        cout << "\n2.Pop";
        cout << "\n3.exit";
        cout << "\nEnter your choice : ";
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "\nEnter the element to push : ";
            cin >> e;
            bool pushed = stack.push(e);
            if (!pushed) {
                cout << "\nStack overflow, can't push. Pop some elements before pushing.";
                break;
            }
            cout << "\nSuccessfully pushed the element " << e << ", the stack is now : ";
            stack.traverse();
            break;
        }
        case 2: {
            bool poped = stack.pop();
            if (!poped) {
                cout << "\nStack underflow, can't pop. Push some elements before poping.";
                break;
            }
            cout << "\nSuccessfully poped, the stack is now : ";
            stack.traverse();
            break;
        }
        case 3: {
            exit(0);
        }
        default: {
            cout << "\nInvaid choice!";
        }
        }
    }
}