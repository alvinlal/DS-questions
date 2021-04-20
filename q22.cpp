// 22. Factorial of a given number using recursion

#include <iostream>
using namespace std;

long factorial(long number) {
    if (number <= 1) {
        return 1;
    }
    return number * factorial(number - 1);
}

int main() {
    long n, result;
    cout << "\n\t\tFACTORIAL OF A NUMBER USING RECURSION";
    cout << "\n\t\t-------------------------------------";
    cout << "\nEnter the number:";
    cin >> n;
    result = factorial(n);
    cout << "\nThe factorial of the number is " << result << "\n";
}
