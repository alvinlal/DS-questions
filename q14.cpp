// 14. Linked list implementation

#include <iostream>
using namespace std;

class Node {
  public:
    Node* next = nullptr;
    int val = 0;
    Node(int val) {
        this->val = val;
    }
};

class SinglyLinkedList {
    Node* head = nullptr;
    Node* tail = nullptr;
    int length = 0;

  public:
    void push(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }
    bool pop() {
        if (!head) return false;
        Node* current = head;
        Node* newTail = current;
        while (current->next) {
            newTail = current;
            current = current->next;
        }
        newTail->next = nullptr;
        delete tail;
        tail = newTail;
        length--;
        if (length == 0) {
            head = nullptr;
            tail = nullptr;
        }
        return true;
    }
    bool shift() {
        if (!head) return false;
        Node* current = head;
        head = current->next;
        delete current;
        length--;
        if (length == 0) {
            head = nullptr;
            tail = nullptr;
        }
        return true;
    }
    void unshift(int val) {
        Node* newHead = new Node(val);
        if (!head) {
            head = newHead;
            tail = head;
        } else {
            newHead->next = head;
            head = newHead;
        }
        length++;
    }
    Node* get(int index) {
        if (index < 0 || index >= length) {
            return nullptr;
        }
        int counter = 0;
        Node* current = head;
        while (counter != index) {
            current = current->next;
            counter++;
        }
        return current;
    }
    bool insert(int index, int val) {
        if (index < 0 || index > length) {
            return false;
        }
        if (index == 0) {
            unshift(val);
            return true;
        }
        if (index == length) {
            push(val);
            return true;
        }

        Node* newNode = new Node(val);
        Node* prevNode = get(index - 1);
        Node* temp = prevNode->next;
        prevNode->next = newNode;
        newNode->next = temp;
        length++;
        return true;
    }
    bool remove(int index) {
        if (index < 0 || index >= length) {
            return false;
        }
        if (index == length - 1) {
            pop();
            return true;
        }
        if (index == 0) {
            shift();
            return true;
        }

        Node* previousNode = get(index - 1);
        Node* removed = previousNode->next;
        previousNode->next = removed->next;
        length--;
        return true;
    }

    void traverse() {
        Node* current = head;
        while (current) {
            cout << current->val << " -> ";
            current = current->next;
        }
        cout << "NULL";
    }
};

int main() {
    int choice, e, index;
    SinglyLinkedList list;
    while (1) {
        cout << "\n\t\tLINKED LIST IMPLEMENTATION";
        cout << "\n\t\t-------------------------";
        cout << "\n1.Push (insert a node to the end)";
        cout << "\n2.Pop (delete a node from the end)";
        cout << "\n3.Shift (delete a node from the beginning)";
        cout << "\n4.UnShift (insert a node to the beginning)";
        cout << "\n5.Remove (delete a node)";
        cout << "\n6.Insert (insert a node)";
        cout << "\n7.exit";
        cout << "\nEnter your choice:";
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "\nEnter the element to  push : ";
            cin >> e;
            list.push(e);
            cout << "\nSuccessfully pushed " << e << ", the list is now : ";
            list.traverse();
            break;
        }
        case 2: {
            bool poped = list.pop();
            if (!poped) {
                cout << "\nList is empty, can't pop";
                break;
            }
            cout << "\nSuccessfully poped, the list is now :";
            list.traverse();
            break;
        }
        case 3: {
            bool shifted = list.shift();
            if (!shifted) {
                cout << "\nCan't shift , the list is empty";
                break;
            }
            cout << "\nSuccessfully shifted, the list is now : ";
            list.traverse();
            break;
        }
        case 4: {
            cout << "\nEnter the element to  unShift : ";
            cin >> e;
            list.unshift(e);
            cout << "\nSuccessfully unShifted " << e << ", the list is now : ";
            list.traverse();
            break;
        }
        case 5: {
            cout << "\nEnter the index of the element to remove : ";
            cin >> index;
            bool removed = list.remove(index);
            if (!removed) {
                cout << "\nCan't remove, the list is empty";
                break;
            }
            cout << "\nSuccessfully removed, the list is now : ";
            list.traverse();
            break;
        }
        case 6: {
            cout << "\nEnter the index to where element is to be inserted : ";
            cin >> index;
            cout << "\nEnter the element to insert : ";
            cin >> e;
            bool inserted = list.insert(index, e);
            if (!inserted) {
                cout << "\nCan't insert, invalid index";
                break;
            }
            cout << "\nSuccessfully inserted, the list is now : ";
            list.traverse();
            break;
        }
        case 7: {
            exit(0);
        }
        default: {
            cout << "Invalid choice!";
        }
        }
    }
}
