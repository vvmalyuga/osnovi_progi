#include <iostream>
using namespace std;

class vect {
public:
    int dim;          // Размерность вектора
    double* values;   // Значения вектора
    static int count; // Статический счетчик объектов
    int num;          // Номер объекта

    // Конструкторы
    vect(int dim = 2, double val = 0); // Конструктор для вектора на плоскости по умолчанию
    vect(double x, double y); // Конструктор для вектора на плоскости с явным указанием координат
    vect(double x, double y, double z); // Конструктор для вектора в трехмерном пространстве с явным указанием координат

    // Деструктор
    ~vect();

    // Операторы
    vect operator+(const vect& v);
    vect operator-(const vect& v);
    vect operator-();
    double operator*(const vect& v);

    // Метод для отображения вектора
    void display();
};

int vect::count = 0;

// Реализация конструкторов
vect::vect(int dim, double val) : dim(dim) {
    count++;
    num = count;
    values = new double[dim];
    for (int i = 0; i < dim; ++i) {
        values[i] = val;
    }
    cout << "Vector " << num << " created." << endl;
}

vect::vect(double x, double y) : dim(2) {
    count++;
    num = count;
    values = new double[dim];
    values[0] = x;
    values[1] = y;
    cout << "Vector " << num << " created." << endl;
}

vect::vect(double x, double y, double z) : dim(3) {
    count++;
    num = count;
    values = new double[dim];
    values[0] = x;
    values[1] = y;
    values[2] = z;
    cout << "Vector " << num << " created." << endl;
}

// Реализация деструктора
vect::~vect() {
    delete[] values;
    cout << "Vector " << num << " destroyed." << endl;
}

// Реализация операторов
vect vect::operator+(const vect& v) {
    vect result(dim);
    for (int i = 0; i < dim; ++i) {
        result.values[i] = values[i] + v.values[i];
    }
    cout << "Performed vector addition." << endl;
    return result;
}

vect vect::operator-(const vect& v) {
    vect result(dim);
    for (int i = 0; i < dim; ++i) {
        result.values[i] = values[i] - v.values[i];
    }
    cout << "Performed vector subtraction." << endl;
    return result;
}

vect vect::operator-() {
    vect result(dim);
    for (int i = 0; i < dim; ++i) {
        result.values[i] = -values[i];
    }
    cout << "Performed vector negation." << endl;
    return result;
}

double vect::operator*(const vect& v) {
    double dotProduct = 0;
    for (int i = 0; i < dim; ++i) {
        dotProduct += values[i] * v.values[i];
    }
    cout << "Performed vector dot product." << endl;
    return dotProduct;
}

// Реализация метода отображения
void vect::display() {
    cout << "Vector " << num << ": [";
    for (int i = 0; i < dim; ++i) {
        cout << values[i];
        if (i < dim - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    // Создание векторов на плоскости
    vect v1(1.0, 2.0);
    vect v2(3.0, 4.0);

    // Создание векторов в трехмерном пространстве
    vect v3(1.0, 2.0, 3.0);
    vect v4(4.0, 5.0, 6.0);

    // Выполнение операций
    cout << "Results of operations in 2D:" << endl;
    (v1 + v2).display();
    (v1 - v2).display();
    (-v1).display();
    cout << "Dot product: " << (v1 * v2) << endl;

    cout << "\nResults of operations in 3D:" << endl;
    (v3 + v4).display();
    (v3 - v4).display();
    (-v3).display();
    cout << "Dot product: " << (v3 * v4) << endl;

    return 0;
}
