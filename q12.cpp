// 12. Program to convert infix expression to prefix expression

#include <iostream>
using namespace std;

class Infix {

    char expression[30];
    char stack[30];
    int top, k;
    char output[30];

  public:
    Infix(char expression[]) {
        int i;
        for (i = 0; expression[i] != '\0'; i++) {
            this->expression[i] = expression[i];
        }
        this->expression[++i] = '\0';
        top = -1;
        k = 0;
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
    void toPreFix() {
        toPostFix();
        for (int i = k - 1; i >= 0; i--) {
            cout << output[i];
        }
    }
    void toPostFix() {
        pushToStack('N');
        for (int i = 0; expression[i] != '\0'; i++) {
            if (isalpha(expression[i])) {
                output[k++] = expression[i];
            } else if (expression[i] == '(') {
                pushToStack('(');
            } else if (expression[i] == ')') {
                while (stack[top] != 'N' && stack[top] != '(') {
                    char c = stack[top];
                    popFromStack();
                    output[k++] = c;
                }
                if (stack[top] == '(') {
                    char c = stack[top];
                    popFromStack();
                }
            } else {
                while (stack[top] != 'N' && precedenceOf(expression[i]) <= precedenceOf(stack[top])) {
                    char c = stack[top];
                    popFromStack();
                    output[k++] = c;
                }
                pushToStack(expression[i]);
            }
        }
        while (stack[top] != 'N') {
            char c = stack[top];
            popFromStack();
            output[k++] = c;
        }
    }
};

int main() {
    cout << "\n\t\tINFIX TO PREFIX CONVERSION";
    cout << "\n\t\t---------------------------";
    char infixExpression[20];
    cout << "\nEnter the Expresssion:- ";
    cin >> infixExpression;
    Infix infix(infixExpression);
    cout << "\nThe prefix form is : ";
    infix.toPreFix();
}