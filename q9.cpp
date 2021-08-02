// 9. Stack operations
#include <iostream>
using namespace std;

class Stack {

    int top, max;
    int* stack;

  public:
    Stack(int max) {
        stack = new int[max];
        top = -1;
        this->max = max;
    }
    ~Stack() {
        delete[] stack;
    }
    bool push(int item) {
        if (top >= max - 1) {
            return false;
        }
        stack[++top] = item;
        return true;
    }
    bool pop() {
        if (top < 0) {
            return false;
        }
        top--;
        return true;
    }
    void print() {
        cout << "[ ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << "]";
    }
};

int main() {
    int choice, e;
    Stack stack(10);
    while (1) {
        cout << "\n\t\tSTACK OPERATIONS";
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
            stack.print();
            break;
        }
        case 2: {
            bool poped = stack.pop();
            if (!poped) {
                cout << "\nStack underflow, can't pop. Push some elements before poping.";
                break;
            }
            cout << "\nSuccessfully poped, the stack is now : ";
            stack.print();
            break;
        }
        case 3: {
            exit(0);
        }
        default: { cout << "\nInvaid choice!"; }
        }
    }
}