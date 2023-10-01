#include <iostream>
#include <stack>
#include <cmath>
#include <cstring>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

double applyOperator(double a, double b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '%':
            return fmod(a, b);
        case '^':
            return pow(a, b);
        default:
            return 0.0;
    }
}

double evaluateExpression(const char* expression) {
    stack<double> values;
    stack<char> operators;
    
    int length = strlen(expression);
    
    for (int i = 0; i < length; i++) {
        if (expression[i] == ' ')
            continue; // Ignore spaces
        
        if ((isdigit(expression[i]) || expression[i] == '.') || 
            (expression[i] == '-' && (i == 0 || expression[i-1] == '(' || isOperator(expression[i-1]))) ||
            (expression[i] == '+' && (i == 0 || expression[i-1] == '(' || isOperator(expression[i-1])))) {
            // Handle numbers, negative numbers, and positive numbers
            double num = 0;
            int sign = 1;
            
            if (expression[i] == '-' || expression[i] == '+') {
                if (expression[i] == '-') {
                    sign = -1;
                }
                i++;
                if (i == length || (!isdigit(expression[i]) && expression[i] != '.')) {
                    values.push(0);  // Push a 0 for unary operation
                    operators.push(sign == 1 ? '+' : '-');
                    continue;
                }
            }
            
            while (i < length && (isdigit(expression[i]) || expression[i] == '.')) {
                if (expression[i] == '.')
                    break;
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            
            if (i < length && expression[i] == '.') {
                double fraction = 0.1;
                i++;
                
                while (i < length && isdigit(expression[i])) {
                    num += (expression[i] - '0') * fraction;
                    fraction *= 0.1;
                    i++;
                }
            }
            
            values.push(num * sign);
            i--; // Move back one position to account for the last digit processed
        } else if (expression[i] == '(') {
            operators.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();
                
                if (values.size() < 2) {
                    cout << "Invalid expression!" << endl;
                    return 0.0;
                }
                
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                
                values.push(applyOperator(a, b, op));
            }
            
            if (!operators.empty() && operators.top() == '(')
                operators.pop(); // Pop the opening parenthesis
        } else if (isOperator(expression[i])) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(expression[i])) {
                char op = operators.top();
                operators.pop();
                
                if (values.size() < 2) {
                    cout << "Invalid expression!" << endl;
                    return 0.0;
                }
                
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                
                values.push(applyOperator(a, b, op));
            }
            
            operators.push(expression[i]);
        } else {
            cout << "Invalid character in expression: " << expression[i] << endl;
            return 0.0;
        }
    }
    
    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();
        
        if (values.size() < 2) {
            cout << "Invalid expression!" << endl;
            return 0.0;
        }
        
        double b = values.top();
        values.pop();
        double a = values.top();
        values.pop();
        
        values.push(applyOperator(a, b, op));
    }
    
    if (values.size() != 1) {
        cout << "Invalid expression!" << endl;
        return 0.0;
    }
    
    return values.top();
}

int main() {
    cout << "Enter an arithmetic expression: ";
    string input;
    getline(cin, input);
    
    const char* expression = input.c_str();
    double result = evaluateExpression(expression);
    
    cout << "Result: " << result << endl;
    
    return 0;
}
