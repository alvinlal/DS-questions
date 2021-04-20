// 25. find the length of an array using recursion

#include <iostream>
using namespace std;

int length(char str[], int n) {
    if (str[n] == '\0') {
        return 0;
    }
    return 1 + length(str, n + 1);
}

int main() {
    int n, result, i;
    char str[10];
    cout << "\n\t\tLENGTH OF AN STRING USING RECURSION";
    cout << "\n\t\t-------------------------------------";
    cout << "\nEnter the string : ";
    cin >> str;
    result = length(str, 0);
    cout << "\nThe length of the array is " << result << "\n";
}