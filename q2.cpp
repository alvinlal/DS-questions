// 2. Merge two arrays

#include <iostream>
using namespace std;

class Array {
    int *array1, *array2, *array3;
    int size1, size2, size3;

  public:
    Array(int size1, int size2) {
        this->size1 = size1;
        this->size2 = size2;
        this->size3 = size1 + size2;
        array1 = new int[size1];
        array2 = new int[size2];
        array3 = new int[size3];
    }
    ~Array() {
        delete[] array1;
        delete[] array2;
    }
    void getElements() {
        cout << "\nEnter the elements of the first array seperated by spaces : ";
        for (int i = 0; i < size1; i++) {
            cin >> array1[i];
        }
        cout << "\nEnter the elements of the seccond array seperated by spaces : ";
        for (int i = 0; i < size2; i++) {
            cin >> array2[i];
        }
    }
    void merge() {
        int j = 0;
        for (int i = 0; i < size1; i++) {
            array3[j++] = array1[i];
        }
        for (int i = 0; i < size2; i++) {
            array3[j++] = array2[i];
        }
    }
    void printMerged() {
        cout << "[ ";
        for (int i = 0; i < size3; i++) {
            if (i == size3 - 1) {
                cout << array3[i];
            } else {
                cout << array3[i] << ", ";
            }
        }
        cout << " ]";
    }
};

int main() {
    int size1, size2;
    cout << "\nEnter the size of the first array : ";
    cin >> size1;
    cout << "\nEnter the size of the seccond array : ";
    cin >> size2;
    Array array(size1, size2);
    array.getElements();
    array.merge();
    cout << "\nThe array after merging is : ";
    array.printMerged();
    cout << "\n";
}