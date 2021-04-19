// 8. Insertion Sort
#include <iostream>
using namespace std;

int main() {
    cout << "\n\t\tINSERTION SORT";
    cout << "\n\t\t--------------";
    int* array;
    int n, j;
    cout << "\nEnter the number of elements : ";
    cin >> n;
    cout << "\nEnter the elements seperated by space : ";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    for (int i = 1; i < n; i++) {
        int currentValue = array[i];
        for (j = i - 1; j >= 0 && array[j] > currentValue; j--) {
            array[j + 1] = array[j];
        }
        array[j + 1] = currentValue;
    }
    cout << "\nThe array after sorting is : ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}