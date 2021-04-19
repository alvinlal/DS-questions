// 4. polynomial implementation

#include <iostream>
using namespace std;

class Polynomial {
    int *array, degree;

  public:
    Polynomial(int degree) {
        array = new int[degree + 1];
        this->degree = degree;
    }
    ~Polynomial() {
        delete[] array;
    }

    void getCoefficients() {
        for (int i = degree; i >= 0; i--) {
            cin >> array[i];
        }
    }
    Polynomial add(Polynomial& other) {
        int maxDegree = degree >= other.degree ? degree : other.degree;
        Polynomial sum(maxDegree);
        for (int i = 0; i <= degree; i++) {
            sum.array[i] = array[i];
        }
        for (int i = 0; i <= other.degree; i++) {
            sum.array[i] += other.array[i];
        }
        return sum;
    }
    Polynomial multiply(Polynomial& other) {
        Polynomial prod(degree + other.degree);
        for (int i = 0; i <= degree; i++) {
            for (int j = 0; j <= other.degree; j++) {
                prod.array[i + j] = prod.array[i + j] + array[i] * other.array[j];
            }
        }
        return prod;
    }
    void print() {
        int power = degree;
        for (int i = degree; i >= 0; i--, power--) {
            if (power > 1) {
                printWithSign(array[i]);
                cout << "x^" << power << " ";
            } else if (power == 1) {
                printWithSign(array[i]);
                cout << "x ";
            } else {
                printWithSign(array[i]);
            }
        }
    }
    void printWithSign(int value) {
        if (value >= 0) {
            cout << "+" << value;
        } else
            cout << value;
    }
};

int main() {
    int choice, degree;

    while (1) {
        cout << "\n\t\tPOLYNOMIAL IMPLEMENTATION";
        cout << "\n\t\t-------------------------";
        cout << "\n1.Polynomial addition";
        cout << "\n2.Polynomial multiplication";
        cout << "\n3.Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "\nEnter the degree of the first polynomial : ";
            cin >> degree;
            Polynomial a(degree);
            cout << "\nEnter the coefficients of the first polynomial (put zero if there is no term at that position) : ";
            a.getCoefficients();
            cout << "\nEnter the degree of the second polynomial : ";
            cin >> degree;
            Polynomial b(degree);
            cout << "\nEnter the coefficients of the second polynomial (put zero if there is no term at that position) : ";
            b.getCoefficients();
            Polynomial c = a.add(b);
            cout << "\nThe sum of the two polynomials is : ";
            c.print();
            cout << "\n";
            break;
        }
        case 2: {
            cout << "\nEnter the degree of the first polynomial : ";
            cin >> degree;
            Polynomial a(degree);
            cout << "\nEnter the coefficients of the first polynomial (put zero if there is no term at that position) : ";
            a.getCoefficients();
            cout << "\nEnter the degree of the second polynomial : ";
            cin >> degree;
            Polynomial b(degree);
            cout << "\nEnter the coefficients of the second polynomial (put zero if there is no term at that position) : ";
            b.getCoefficients();
            Polynomial c = a.multiply(b);
            cout << "\nThe product of the two polynomials is : ";
            c.print();
            cout << "\n";
            break;
        }
        case 3: {
            exit(0);
        }
        }
    }
}