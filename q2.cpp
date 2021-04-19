// 2. merge two arrays
#include <iostream>
using namespace std;


int main() {
    cout << "\n\t\tMERGE TWO ARRAYS";
    cout << "\t\t-------------------";
    int array1[100], array2[100], array3[200], size1, size2;
    cout << "\nEnter the size of the first array : ";
    cin >> size1;
    cout << "\nEnter the elements of first array in ascending order seperated by space : ";
    for (int i = 0; i < size1; i++) {
        cin >> array1[i];
    }
    cout << "\nEnter the size of the second array : ";
    cin >> size2;
    cout << "\nEnter the elements of second array in ascending order seperated by space : ";
    for (int i = 0; i < size2; i++) {
        cin >> array2[i];
    }
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < size1 && j < size2) {
        if (array1[i] < array2[j]) {
            array3[k++] = array1[i++];
        } else {
            array3[k++] = array2[j++];
        }
    }
    while (i < size1) {
        array3[k++] = array1[i++];
    }
    while (j < size2) {
        array3[k++] = array2[j++];
    }

    cout << "\nThe array after merging : ";
    for (int i = 0; i < size1 + size2; i++) {
        cout << array3[i] << " ";
    }
    cout << "\n";
}