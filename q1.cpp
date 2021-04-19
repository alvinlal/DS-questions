// 1. Array implementation
#include <iostream>
using namespace std;

class Array {
    int size = 0;
    int* array = nullptr;
    int capacity = 0;

    void ReAlloc(int newCapacity) {
        int* newBlock = new int[newCapacity];       // allocate new block of memory
        if (newCapacity < size) size = newCapacity; // if we are downsizing , let the less size be the new size
        for (size_t i = 0; i < size; i++) {
            newBlock[i] = array[i];
        }
        delete[] array;         // free old space
        array = newBlock;       // point array to new space
        capacity = newCapacity; // update capacity
    }

  public:
    Array(int size) {
        ReAlloc(size);
    }
    Array() {
        ReAlloc(2); // allocate space for 2 ints by default
    }
    ~Array() {
        delete[] array;
    }
    int Size() {
        return size;
    }
    int& operator[](int index) {
        return array[index];
    }
    const int& operator[](int index) const {
        return array[index];
    }
    void push(int value) {
        if (size >= capacity) ReAlloc(capacity + capacity / 2); // if array is full , reallocate half the size of current capacity
        array[size++] = value;
    }
    int pop() {
        return array[size--];
    }
    int remove(int pos) {
        int removed = array[pos - 1];

        for (int i = pos - 1; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
        pop();
        return removed;
    }
    void insert(int pos, int value) {
        push(0);
        for (int i = size - 1; i >= pos; i--) {
            array[i] = array[i - 1];
        }
        array[pos - 1] = value;
    }
    void print() {
        cout << "[ ";
        for (int i = 0; i < size; i++) {
            if (i == size - 1) {
                cout << array[i];
            } else {
                cout << array[i] << ", ";
            }
        }
        cout << " ]";
    }
};

int main() {
    int choice, size, element, pos;
    Array array;
    while (1) {
        cout << "\n\t\tARRAY IMPLEMENTATION";
        cout << "\n\t\t----------------";
        cout << "\n1.Push an element (insert to the end)";
        cout << "\n2.Pop an element (delete from the end)";
        cout << "\n3.Remove an element (delete an element from middle)";
        cout << "\n4.Insert an element (insert an element in the middle)";
        cout << "\n5.exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "\nEnter the element to push: ";
            cin >> element;
            array.push(element);
            cout << "\nSuccessfully inserted " << element << " to the array, the array is now ";
            array.print();
            break;
        }
        case 2: {
            if (array.Size() == 0) {
                cout << "\nArray is empty, can't pop";
                break;
            }
            int removed = array.pop();
            cout << "\nSuccessfull removed " << removed << " from the array, the array is now ";
            array.print();
            break;
        }
        case 3: {
            if (array.Size() == 0) {
                cout << "\nArray is empty, can't remove";
                break;
            }
        enter:
            cout << "\nEnter the index of the element to remove : ";
            cin >> pos;
            if (pos > array.Size() || pos < 1) {
                cout << "\nPlease enter a valid choice";
                goto enter;
                break;
            }
            int removed = array.remove(pos);
            cout << "\nSuccessfull removed " << removed << " from the array, the array is now ";
            array.print();
            break;
        }
        case 4: {
        enter2:
            cout << "\nEnter the position to insert to : ";
            cin >> pos;
            if (pos > array.Size() || pos < 1) {
                cout << "\nPlease enter a valid choice";
                goto enter2;
                break;
            }
            cout << "\nEnter the element to insert : ";
            cin >> element;
            array.insert(pos, element);
            cout << "\nSuccessfully inserted " << element << " to the array, the array is now ";
            array.print();
            break;
        }
        case 5: {
            cout << "\nbye\n";
            exit(0);
        }
        default: {
            cout << "\nInvalid choice";
        }
        }
    }
}