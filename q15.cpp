// 15. To search for an element in the linked list

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
    int search(int element) {
        if (!head) return -1;
        Node* currentNode = head;
        int index = 0;
        while (currentNode) {
            if (currentNode->val == element) {
                return index;
            }
            index++;
            currentNode = currentNode->next;
        }
        return -1;
    }
};

int main() {
    int e, n;
    SinglyLinkedList list;
    cout << "\n\t\tSEARCH FOR AN ELEMENT IN A LINKED LIST";
    cout << "\n\t\t--------------------------------------";
    cout << "\nEnter the number of elements : ";
    cin >> n;
    cout << "\nEnter the elements of the linked list seperated by space : ";
    for (int i = 0; i < n; i++) {
        cin >> e;
        list.push(e);
    }
    cout << "\nEnter the element to search : ";
    cin >> e;
    int found = list.search(e);
    found < 0 ? cout << "\nElement is not found!\n" : cout << "\nElement is found at position " << found + 1 << "\n";
}