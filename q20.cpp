// 20. CAP to split a linked list in to two

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
  public:
    Node* head = nullptr;
    Node* tail = nullptr;
    int length = 0;
    SinglyLinkedList& push(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
        return *this;
    }

    SinglyLinkedList* split(int index) {
        SinglyLinkedList* splittedList = new SinglyLinkedList();
        if (!head) return splittedList;
        Node* pointOfCut = get(index);
        splittedList->head = pointOfCut->next;
        pointOfCut->next = nullptr;
        return splittedList;
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
    int n, e, index;
    SinglyLinkedList list1;
    SinglyLinkedList* list2;
    cout << "\n\t\tSPLIT A LINKED LIST INTO TWO";
    cout << "\n\t\t----------------------------";
    cout << "\nEnter the number of elements in the list : ";
    cin >> n;
    cout << "\nEnter the elements in the first list seperated by space : ";
    for (int i = 0; i < n; i++) {
        cin >> e;
        list1.push(e);
    }
    cout << "\nEnter the index from where you want to split : ";
    cin >> index;
    list2 = list1.split(index);
    cout << "\nThe lists after splitting is : ";
    cout << "\nFirst list : ";
    list1.traverse();
    cout << "\nSecond list : ";
    list2->traverse();
    cout << "\n";
}
