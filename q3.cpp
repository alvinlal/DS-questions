// 3. Sparse matrix

#include <iostream>
using namespace std;

class SparseMatrix {
    int **array, i, j, m = 0, n = 0, zeroCounter = 0, nonZeroCounter = 0;

  public:
    SparseMatrix(int rowCount, int columnCount) {
        m = rowCount;
        n = columnCount;
        array = new int*[rowCount];
        for (i = 0; i < rowCount; i++) {
            array[i] = new int[columnCount];
        }
    }
    ~SparseMatrix() {
        delete[] array;
    }
    void getElements() {
        cout << "\nEnter the array elements: ";
        for (i = 0; i < m; i++) {
            cout << "\nEnter row " << i + 1 << " : ";
            for (j = 0; j < n; j++) {
                cin >> array[i][j];
            }
        }
    }
    void displayElements() {
        for (i = 0; i < m; i++) {
            cout << "\n";
            for (j = 0; j < n; j++) {
                cout << array[i][j] << " ";
            }
        }
    }
    bool isSparse() {
        if (m == 0 || n == 0) {
            return false;
        } else {
            for (i = 0; i < m; i++) {
                for (j = 0; j < n; j++) {
                    array[i][j] == 0 ? zeroCounter++ : nonZeroCounter++;
                }
            }
            return zeroCounter > nonZeroCounter;
        }
    }
    void dispLinear() {
        int flag = 0;
        if (!isSparse()) {
            cout << "\nThe matrix is not a sparse matrix\n";
        } else {
            cout << "\n\nThe linear form of the matrix is: ";
            for (i = 0; i < m; i++) {
                for (j = 0; j < n; j++) {
                    if (array[i][j] != 0) {
                        flag == 0 && cout << "\nRow\t";
                        cout << i + 1 << " ";
                        flag = 1;
                    }
                }
            }
            flag = 0;
            for (i = 0; i < m; i++) {
                for (j = 0; j < n; j++) {
                    if (array[i][j] != 0) {
                        flag == 0 && cout << "\nColumn  ";
                        cout << j + 1 << " ";
                        flag = 1;
                    }
                }
            }

            flag = 0;
            for (i = 0; i < m; i++) {
                for (j = 0; j < n; j++) {
                    if (array[i][j] != 0) {
                        flag == 0 && cout << "\nValues  ";
                        cout << array[i][j] << " ";
                        flag = 1;
                    }
                }
            }
        }
    }
};

int main() {
    int m, n, choice;

    while (1) {
        cout << "\n\t\tSPARSE OR NOT";
        cout << "\n\t\t-------------";
        cout << "\n1.Check sparse matrix or not";
        cout << "\n2.Get linear form of a sparse matrix";
        cout << "\n3.Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "\nEnter the order of the matrix(row by column): ";
            cin >> m >> n;
            SparseMatrix a(m, n);
            a.getElements();
            cout << "\nThe entered matrix is:\n";
            a.displayElements();
            a.isSparse() ? cout << "\n\nThe matrix is a sparse matrix" : cout << "\n\nThe matrix is not a sparse matrix";
            break;
        }
        case 2: {
            cout << "\nEnter the order of the matrix(row by column): ";
            cin >> m >> n;
            SparseMatrix a(m, n);
            a.getElements();
            cout << "\nThe entered matrix is:\n";
            a.displayElements();
            a.dispLinear();
            break;
        }
        case 3: {
            exit(0);
        }
        default: {
            cout << "wrong choice";
        }
        }
    }
}