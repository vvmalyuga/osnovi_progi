#include <iostream>
using namespace std;

class vect {
public:
    int dim;
    double* values;
    static int count;
    int num;

    vect(int dim = 2, double val = 0);
    vect(double x, double y);
    vect(double x, double y, double z);
    ~vect();

    vect operator+(const vect& v) const;
    vect operator-(const vect& v) const;
    vect operator-() const;
    double operator*(const vect& v) const;
    vect operator^(const vect& v) const;

    void display() const;
};

int vect::count = 0;

vect::vect(int dim, double val) : dim(dim), num(++count) {
    values = new double[dim];
    for (int i = 0; i < dim; ++i) {
        values[i] = val;
    }
    cout << "Vector " << num << " created." << endl;
}

vect::vect(double x, double y) : dim(2), num(++count) {
    values = new double[dim];
    values[0] = x;
    values[1] = y;
    cout << "Vector " << num << " created." << endl;
}

vect::vect(double x, double y, double z) : dim(3), num(++count) {
    values = new double[dim];
    values[0] = x;
    values[1] = y;
    values[2] = z;
    cout << "Vector " << num << " created." << endl;
}

vect::~vect() {
    delete[] values;
    cout << "Vector " << num << " destroyed." << endl;
}

vect vect::operator+(const vect& v) const {
    if (dim != v.dim) {
        cout << "Cannot add vectors with different dimensions." << endl;
        exit(EXIT_FAILURE);
    }
    vect result(dim);
    for (int i = 0; i < dim; ++i) {
        result.values[i] = values[i] + v.values[i];
    }
    cout << "Performed vector addition." << endl;
    return result;
}

vect vect::operator-(const vect& v) const {
    if (dim != v.dim) {
        cout << "Cannot subtract vectors with different dimensions." << endl;
        exit(EXIT_FAILURE);
    }
    vect result(dim);
    for (int i = 0; i < dim; ++i) {
        result.values[i] = values[i] - v.values[i];
    }
    cout << "Performed vector subtraction." << endl;
    return result;
}

vect vect::operator-() const {
    vect result(dim);
    for (int i = 0; i < dim; ++i) {
        result.values[i] = -values[i];
    }
    cout << "Performed vector negation." << endl;
    return result;
}

double vect::operator*(const vect& v) const {
    if (dim != v.dim) {
        cout << "Cannot compute dot product for vectors with different dimensions." << endl;
        exit(EXIT_FAILURE);
    }
    double dotProduct = 0;
    for (int i = 0; i < dim; ++i) {
        dotProduct += values[i] * v.values[i];
    }
    cout << "Performed vector dot product." << endl;
    return dotProduct;
}

vect vect::operator^(const vect& v) const {
    if (dim != 3 || v.dim != 3) {
        cout << "Vector cross product is only defined for 3D vectors." << endl;
        exit(EXIT_FAILURE);
    }
    vect result(0, 0, 0);
    result.values[0] = values[1] * v.values[2] - values[2] * v.values[1];
    result.values[1] = values[2] * v.values[0] - values[0] * v.values[2];
    result.values[2] = values[0] * v.values[1] - values[1] * v.values[0];
    cout << "Performed vector cross product." << endl;
    return result;
}

void vect::display() const {
    cout << "Vector " << num << ": [";
    for (int i = 0; i < dim; ++i) {
        cout << values[i];
        if (i < dim - 1) cout << ", ";
    }
    cout << "]" << endl;
}

class matr {
public:
    int dim;
    double* values;
    static int count;
    int num;

    matr(int dim = 2, double val = 0);
    ~matr();

    matr operator+(const matr& m) const;
    matr operator-(const matr& m) const;
    matr operator-() const;
    matr operator*(const matr& m) const;
    matr operator*(double k) const;
    matr& operator=(const matr& m);

    void display() const;
};

int matr::count = 0;

matr::matr(int dim, double val) : dim(dim), num(++count) {
    values = new double[dim * dim];
    for (int i = 0; i < dim * dim; ++i) {
        values[i] = val;
    }
    cout << "Matrix " << num << " created." << endl;
}

matr::~matr() {
    delete[] values;
    cout << "Matrix " << num << " destroyed." << endl;
}

matr matr::operator+(const matr& m) const {
    matr result(dim);
    for (int i = 0; i < dim * dim; ++i) {
        result.values[i] = values[i] + m.values[i];
    }
    cout << "Performed matrix addition." << endl;
    return result;
}

matr matr::operator-(const matr& m) const {
    matr result(dim);
    for (int i = 0; i < dim * dim; ++i) {
        result.values[i] = values[i] - m.values[i];
    }
    cout << "Performed matrix subtraction." << endl;
    return result;
}

matr matr::operator-() const {
    matr result(dim);
    for (int i = 0; i < dim * dim; ++i) {
        result.values[i] = -values[i];
    }
    cout << "Performed matrix negation." << endl;
    return result;
}

matr matr::operator*(const matr& m) const {
    matr result(dim);
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            result.values[i * dim + j] = 0;
            for (int k = 0; k < dim; ++k) {
                result.values[i * dim + j] += values[i * dim + k] * m.values[k * dim + j];
            }
        }
    }
    cout << "Performed matrix multiplication." << endl;
    return result;
}

matr matr::operator*(double k) const {
    matr result(dim);
    for (int i = 0; i < dim * dim; ++i) {
        result.values[i] = values[i] * k;
    }
    cout << "Performed matrix scaling." << endl;
    return result;
}

matr& matr::operator=(const matr& m) {
    if (this != &m) {
        delete[] values;
        dim = m.dim;
        values = new double[dim * dim];
        for (int i = 0; i < dim * dim; ++i) {
            values[i] = m.values[i];
        }
    }
    cout << "Performed matrix assignment." << endl;
    return *this;
}

void matr::display() const {
    cout << "Matrix " << num << ":" << endl;
    for (int i = 0; i < dim; ++i) {
        cout << "[ ";
        for (int j = 0; j < dim; ++j) {
            cout << values[i * dim + j] << " ";
        }
        cout << "]" << endl;
    }
}

int main() {
    // Создание векторов на плоскости
    vect v1(1.0, 2.0);
    vect v2(3.0, 4.0);

    // Создание векторов в трехмерном пространстве
    vect v3(1.0, 2.0, 3.0);
    vect v4(4.0, 5.0, 6.0);

    // Выполнение операций с векторами
    cout << "Results of operations with vectors:" << endl;
    (v1 + v2).display();
    (v1 - v2).display();
    (-v1).display();
    cout << "Dot product: " << (v1 * v2) << endl;

    // Создание матриц размерности 2 и 3
    matr m1(2);
    matr m2(2);
    matr m3(3);
    matr m4(3);

    // Выполнение операций с матрицами
    cout << "\nResults of operations with matrices:" << endl;
    (m1 + m2).display();
    (m1 - m2).display();
    (-m1).display();
    (m1 * m2).display();
    (m1 * 2.0).display();

    return 0;
}
