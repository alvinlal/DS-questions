// 21. CAP to swap two nodes in a list

#include <iostream>
using namespace std;


class Node {
  public:
    Node* next = nullptr;
    int val = 0;
    Node(int val) : val(val) {
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
    bool swap(int index1, int index2) {
        if (index1 == index2) {
            return true;
        }
        if (index1 < 0 || index2 < 0 || index1 >= length || index2 >= length) {
            return false;
        }
        if (!head) {
            return false;
        }
        Node* firstNode = get(index1);
        Node* secondNode = get(index2);
        int temp = firstNode->val;
        firstNode->val = secondNode->val;
        secondNode->val = temp;
        return true;
    }
    void traverse() {
        Node* current = head;
        while (current) {
            std::cout << current->val << " -> ";
            current = current->next;
        }
        std::cout << "NULL";
    }
};

int main() {
    int n, e, index1, index2;
    SinglyLinkedList list;
    cout << "\n\t\tSWAP TWO NODES IN A LINKED LIST";
    cout << "\n\t\t-------------------------------";
    cout << "\nEnter the number of elements in the list : ";
    cin >> n;
    cout << "\nEnter the elements in the first list seperated by space : ";
    for (int i = 0; i < n; i++) {
        cin >> e;
        list.push(e);
    }
    cout << "\nEnter index's of first and second element to swap seperated by space : ";
    cin >> index1 >> index2;
    list.swap(index1, index2);
    cout << "\nThe list after swapping is : ";
    list.traverse();
    cout << "\n";
}