// 6. Binary Search
#include <iostream>
using namespace std;


int main() {
    cout << "\n\t\tBINARY SEARCH";
    cout << "\n\t\t-------------";
    int* array;
    int n, e, l, h, mid;
    cout << "\nEnter the number of elements : ";
    cin >> n;
    array = new int[n];
    cout << "\nEnter the elements in ascending order seperated by space : ";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    cout << "\nEnter the element to search : ";
    cin >> e;
    l = 0;
    h = n - 1;
    while (l <= h) {
        mid = (l + h) / 2;
        if (array[mid] == e) {
            break;
        } else if (e < array[mid]) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    l > h ? cout << "\nThe element was not found!\n" : cout << "\nThe element was found at position " << mid + 1 << "\n";
}