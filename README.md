# EECS348-project


##Arithmetic Expression Evaluator
This program evaluates arithmetic expressions provided by the user. It supports basic arithmetic operations (+, -, *, /, %, ^), handles negative and positive numbers, and manages the precedence of operations with the use of parentheses.

###Features:
1.Basic Arithmetic Operations: Supports addition (+), subtraction (-), multiplication (*), division (/), modulus (%), and exponentiation (^).
2.Parentheses for Operation Precedence: You can use parentheses to specify the order of operations.
3.Error Handling: The program identifies and displays messages for invalid expressions or characters.

###Usage in Visual Studio:
1.Open Visual Studio:

2.Create a New Project:

Go to File > New > Project.
Choose Empty Project from the available templates.
Name your project and choose a suitable location to save it.
Add the Source Code:

3.Right-click on the Source Files folder in Solution Explorer.
Select Add > New Item.
Choose C++ File (.cpp), give it a name, and click Add.
Now, copy and paste the provided code into this new file.

4.Build and Run:

5.Enter the Arithmetic Expression:
Once the console window opens, you'll be prompted to enter your arithmetic expression. For example:
Enter an arithmetic expression: (2+3) * 4^2
The program will then display the result or an error message if the expression is invalid.

###Functions:
1.isOperator(char c): Checks if a character is an arithmetic operator.
2.precedence(char op): Determines the precedence of an operator.
3.applyOperator(double a, double b, char op): Computes the result of an operation for two numbers.
4.evaluateExpression(const char* expression): Evaluates an entire arithmetic expression and returns the result.


###Notes:
This program uses the stack data structure from the C++ Standard Library to manage operators and values during the evaluation.
Floating point numbers are supported, and the program can handle decimal values.
Unary + and - are supported. For example, expressions like +5 or -3^2
