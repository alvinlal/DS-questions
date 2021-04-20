// 23. sum of first n natural numbers using recursion

#include <iostream>
using namespace std;

int sum(int number) {

    if (number == 1) {
        return 1;
    }
    return number + sum(number - 1);
}

int main() {
    int n, result;
    cout << "\n\t\tSUM OF FIRST N NATURAL NUMBERS USING RECURSION";
    cout << "\n\t\t-------------------------------------";
    cout << "\nEnter the limit:";
    cin >> n;
    result = sum(n);
    cout << "\nThe sum of the series is " << result << "\n";
}