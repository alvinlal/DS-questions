// 11. Convert infix expression to postfix expression
#include <iostream>
using namespace std;


class Infix {

    char expression[30];
    char stack[30];
    int top;

  public:
    Infix(char expression[]) {
        int i;
        for (i = 0; expression[i] != '\0'; i++) {
            this->expression[i] = expression[i];
        }
        this->expression[++i] = '\0';
        top = -1;
    }
    void pushToStack(char item) {
        stack[++top] = item;
    }
    char popFromStack() {
        return stack[top--];
    }
    int precedenceOf(char opr) {
        if (opr == '+' || opr == '-') {
            return 1;
        } else if (opr == '*' || opr == '/') {
            return 2;
        } else if (opr == '^') {
            return 3;
        }
        return -1;
    }
    void toPostFix() {
        pushToStack('N');
        for (int i = 0; expression[i] != '\0'; i++) {
            if (isalpha(expression[i])) {
                cout << expression[i];
            } else if (expression[i] == '(') {
                pushToStack('(');
            } else if (expression[i] == ')') {
                while (stack[top] != 'N' && stack[top] != '(') {
                    char c = stack[top];
                    popFromStack();
                    cout << c;
                }
                if (stack[top] == '(') {
                    char c = stack[top];
                    popFromStack();
                }
            } else {
                while (stack[top] != 'N' && precedenceOf(expression[i]) <= precedenceOf(stack[top])) {
                    char c = stack[top];
                    popFromStack();
                    cout << c;
                }
                pushToStack(expression[i]);
            }
        }
        while (stack[top] != 'N') {
            char c = stack[top];
            popFromStack();
            cout << c;
        }
    }
};

int main() {
    cout << "\n\t\tINFIX TO POSTFIX CONVERSION";
    cout << "\n\t\t---------------------------";
    char infixExpression[20];
    cout << "\nEnter the Expresssion:- ";
    cin >> infixExpression;
    Infix infix(infixExpression);
    cout << "\nThe postfix form is : ";
    infix.toPostFix();
    cout << "\n";
}