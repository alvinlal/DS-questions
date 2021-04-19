// 7. Selection sort

#include <iostream>
using namespace std;


int main() {
    cout << "\n\t\tSELECTION SORT";
    cout << "\n\t\t--------------";
    int* array;
    int n;
    cout << "\nEnter the number of elements : ";
    cin >> n;
    cout << "\nEnter the elements seperated by space : ";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    for (int i = 0; i < n; i++) {
        int lowest = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[lowest]) {
                lowest = j;
            }
        }
        if (lowest != i) {
            int temp = array[i];
            array[i] = array[lowest];
            array[lowest] = temp;
        }
    }
    cout << "\nThe array after sorting is : ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}