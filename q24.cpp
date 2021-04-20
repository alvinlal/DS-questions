// 24. Binary search using recursion

#include <iostream>
using namespace std;


int binarySearch(int a[], int l, int h, int e) {
    if (h >= l) {
        int mid = l + (h - l) / 2;
        if (a[mid] == e) return mid;

        if (a[mid] > e) return binarySearch(a, l, mid - 1, e);

        return binarySearch(a, mid + 1, h, e);
    }
    return -1;
}


int main() {
    int n, e, a[10], i, result;
    cout << "\n\t\tBINARY SEARCH USING RECURSION";
    cout << "\n\t\t-----------------------------";
    cout << "\nEnter no of elements in the array : ";
    cin >> n;
    cout << "\nEnter the elements in ascending order : ";
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "\nEnter the element to search : ";
    cin >> e;
    result = binarySearch(a, 0, n - 1, e);
    if (result > 0) {
        cout << "\nThe element is found on postion " << result + 1 << "\n";
    } else
        cout << "\nElement is not found\n";
}