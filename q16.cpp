// 16. CAP to sort a numeric list

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
    void bubbleSort() {
        if (!head) return;
        int swapped;
        Node* cur;
        do {
            swapped = 0;
            cur = head;
            while (cur->next != NULL) {
                if (cur->val > cur->next->val) {
                    swap(cur, cur->next);
                    swapped = 1;
                }
                cur = cur->next;
            }
        } while (swapped);
    }
    void swap(Node* node1, Node* node2) {
        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
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
    int e, n;
    SinglyLinkedList list;
    cout << "\n\t\tSORT A NUMERIC LIST";
    cout << "\n\t\t-------------------";
    cout << "\nEnter the number of elements : ";
    cin >> n;
    cout << "\nEnter the elements of the linked list seperated by space : ";
    for (int i = 0; i < n; i++) {
        cin >> e;
        list.push(e);
    }
    list.bubbleSort();
    cout << "\nThe list after sorting is : ";
    list.traverse();
    cout << "\n";
}