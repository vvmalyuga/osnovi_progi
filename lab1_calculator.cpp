#include <iostream>
#include <cmath>
using namespace std;



// Арифметические выражения <-------------------------------------->
void sum(int a, int b) {
    cout << "Answer: " << a + b << endl;
}

void multiplie(int a, int b) {
    cout << "Answer: " << a * b << endl;
}

void devide(double a, double b) {
    cout << "Answer: " << a / b << endl;
}

void minuss(int a, int b) {
    cout << "Answer: " << a - b << endl;
}

void power(int a, int b) {
    cout << "Answer: " << pow(a, b) << endl;
}



// функция для арифметических выражений <-------------------------------------->
void operations() {
    int a, b; char c;
repeat: cout << "Enter the expression: ";
    cin >> a >> c >> b;

    //  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); ---- полность очищает ввод и очередь
    if (cin.fail()) {
        cout << "Was entered !!!" << endl; cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); goto repeat;
    }

    switch (c) {
    case '+': sum(a, b); break;
    case '*': multiplie(a, b); break;
    case '/': devide(a, b); break;
    case '-': minuss(a, b); break;
    case '^': power(a, b); break;
    default: cout << "Wrong operation!!!" << endl; cin.clear(); goto repeat;
    }
}



// Факториал <-------------------------------------->
void factorial() {
repeat: cout << "Enter the values: ";
    int a; long long int result = 1; cin >> a;

    if (cin.fail()) {
        cout << "It was not a number that was entered!!!" << endl; cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); goto repeat;
    }

    if (a == 0) {
        cout << "Answer: 1" << endl;
    }
    else {
        for (int i = 1; i <= a; i++) {
            result = result * i;
        }

        cout << "Answer: " << result << endl;
    }
}



// Матрицы <-------------------------------------->
void matrix() {

    char a; int matrix1[3][3]; int matrix2[3][3];

repeat: cout << "Enter the operation: ";
    cin >> a;
    if (a != '+' and a != '-') {
        cout << "An incorrect operation was entered!!!" << endl; cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); goto repeat;
    }

    // Ввод значений матриц
repeat2: cout << "Enter the first matrix: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matrix1[i][j];
            if (cin.fail()) {
                cout << "It was not a number that was entered!!!" << endl; cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); goto repeat2;
            }
        }
    }

repeat3: cout << "Enter the second matrix: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matrix2[i][j];
            if (cin.fail()) {
                cout << "It was not a number that was entered!!!" << endl; cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); goto repeat3;
            }
        }
    }

    switch (a) {
    case '+':
        cout << "Answer: " << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << matrix1[i][j] + matrix2[i][j];

                if (j == 2) {
                    cout << endl;
                }
                else {
                    cout << " ";
                }
            }
        }
        break;

    case '-':
        cout << "Answer: " << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << matrix1[i][j] - matrix2[i][j];

                if (j == 2) {
                    cout << endl;
                }
                else {
                    cout << " ";
                }
            }
        }
        break;
    }
}



// ОСНОВНАЯ ФУНКЦИЯ <-------------------------------------->
int main() {
repeat4: cout << "Choose the operation:\n1.Arithmetic operations\n2.Calculating the factorial\n3.Operations (+, -) with matrixes\n";
    int n; cin >> n;

    switch (n) {
    case 1:
        operations();
        break;
    case 2:
        factorial();
        break;
    case 3:
        matrix();
        break;
    default:
        cout << "An incorrect number was entered!!!" << endl; goto repeat4;
    }

}