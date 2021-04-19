// 5. Linear search
#include <iostream>
using namespace std;

int main() {
    cout << "\n\t\tLINEAR SEARCH";
    cout << "\n\t\t---------------";
    int* array;
    int n, e;
    int found = -1;
    cout << "\nEnter the number of elements : ";
    cin >> n;
    array = new int[n];
    cout << "\nEnter the elements seperated by space : ";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    cout << "\nEnter the element to search : ";
    cin >> e;
    for (int i = 0; i < n; i++) {
        if (array[i] == e) {
            found = i + 1;
            break;
        };
    }
    found < 0 ? cout << "\nThe element is not found!\n" : cout << "\nThe element is found at position " << found << "\n";
}