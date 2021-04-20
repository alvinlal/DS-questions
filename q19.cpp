// 19. CAP to merge 2 linked list

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
    void merge(SinglyLinkedList& other) {
        if (!head) {
            head = other.head;
            return;
        }
        tail->next = other.head;
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
    int n, e;
    SinglyLinkedList list1, list2;
    cout << "\n\t\tMERGE TWO LINKED LIST";
    cout << "\n\t\t---------------------";
    cout << "\nEnter the number of elements in the first list : ";
    cin >> n;
    cout << "\nEnter the elements in the first list seperated by space : ";
    for (int i = 0; i < n; i++) {
        cin >> e;
        list1.push(e);
    }
    cout << "\nEnter the number of elements in the second list : ";
    cin >> n;
    cout << "\nEnter the elements in the second list seperated by space : ";
    for (int i = 0; i < n; i++) {
        cin >> e;
        list2.push(e);
    }
    list1.merge(list2);
    cout << "\nThe list after merging is : ";
    list1.traverse();
    cout << "\n";
}