#include <iostream>
#include <cmath>
using namespace std;

class vect {
private:
    int dim;
    double* b;
public:
    static int count;
    int num;

    vect() {
        dim = 0;
        b = nullptr;
        num = ++count;
        cout << "Vect default constructor. Object number: " << num << endl;
    }

    vect(int dim, double initValue) {
        this->dim = dim;
        b = new double[dim];
        for (int i = 0; i < dim; i++) {
            b[i] = initValue;
        }
        num = ++count;
        cout << "Vect parameterized constructor. Object number: " << num << endl;
    }

    ~vect() {
        delete[] b;
        cout << "Vect destructor. Object number: " << num << endl;
    }

    vect operator+(const vect& other) const;
    vect operator-(const vect& other) const;
    vect operator-() const;
    double operator*(const vect& other) const;
    vect operator*(double scalar) const;
    vect& operator=(const vect& other);

    friend ostream& operator<<(ostream& os, const vect& v);
};

int vect::count = 0;

vect vect::operator+(const vect& other) const {
    vect result(dim, 0);
    for (int i = 0; i < dim; i++) {
        result.b[i] = b[i] + other.b[i];
    }
    cout << "Vector addition. Result object number: " << result.num << endl;
    return result;
}

vect vect::operator-(const vect& other) const {
    vect result(dim, 0);
    for (int i = 0; i < dim; i++) {
        result.b[i] = b[i] - other.b[i];
    }
    cout << "Vector subtraction. Result object number: " << result.num << endl;
    return result;
}

vect vect::operator-() const {
    vect result(dim, 0);
    for (int i = 0; i < dim; i++) {
        result.b[i] = -b[i];
    }
    cout << "Unary vector negation. Result object number: " << result.num << endl;
    return result;
}

double vect::operator*(const vect& other) const {
    double result = 0;
    for (int i = 0; i < dim; i++) {
        result += b[i] * other.b[i];
    }
    cout << "Vector dot product. Result value: " << result << endl;
    return result;
}

vect vect::operator*(double scalar) const {
    vect result(dim, 0);
    for (int i = 0; i < dim; i++) {
        result.b[i] = b[i] * scalar;
    }
    cout << "Vector-scalar multiplication. Result object number: " << result.num << endl;
    return result;
}

vect& vect::operator=(const vect& other) {
    if (this != &other) {
        delete[] b;
        dim = other.dim;
        b = new double[dim];
        for (int i = 0; i < dim; i++) {
            b[i] = other.b[i];
        }
    }
    cout << "Vector assignment. Object number: " << num << endl;
    return *this;
}

ostream& operator<<(ostream& os, const vect& v) {
    os << "[";
    for (int i = 0; i < v.dim; i++) {
        os << v.b[i];
        if (i < v.dim - 1) os << ", ";
    }
    os << "]";
    return os;
}

class matr {
private:
    int dim;
    double* a;
public:
    static int count;
    int num;

    matr() {
        dim = 0;
        a = nullptr;
        num = ++count;
        cout << "Matr default constructor. Object number: " << num << endl;
    }

    matr(int dim, double initValue) {
        this->dim = dim;
        a = new double[dim * dim];
        for (int i = 0; i < dim * dim; i++) {
            a[i] = initValue;
        }
        num = ++count;
        cout << "Matr parameterized constructor. Object number: " << num << endl;
    }

    ~matr() {
        delete[] a;
        cout << "Matr destructor. Object number: " << num << endl;
    }

    matr operator+(const matr& other) const;
    matr operator-(const matr& other) const;
    matr operator-() const;
    matr operator*(const matr& other) const;
    matr operator*(double scalar) const;
    matr& operator=(const matr& other);
    vect operator*(const vect& v) const;

    friend ostream& operator<<(ostream& os, const matr& m);
};

int matr::count = 0;

matr matr::operator+(const matr& other) const {
    matr result(dim, 0);
    for (int i = 0; i < dim * dim; i++) {
        result.a[i] = a[i] + other.a[i];
    }
    cout << "Matrix addition. Result object number: " << result.num << endl;
    return result;
}

matr matr::operator-(const matr& other) const {
    matr result(dim, 0);
    for (int i = 0; i < dim * dim; i++) {
        result.a[i] = a[i] - other.a[i];
    }
    cout << "Matrix subtraction. Result object number: " << result.num << endl;
    return result;
}

matr matr::operator-() const {
    matr result(dim, 0);
    for (int i = 0; i < dim * dim; i++) {
        result.a[i] = -a[i];
    }
    cout << "Unary matrix negation. Result object number: " << result.num << endl;
    return result;
}

matr matr::operator*(const matr& other) const {
    matr result(dim, 0);
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            result.a[i * dim + j] = 0;
            for (int k = 0; k < dim; k++) {
                result.a[i * dim + j] += a[i * dim + k] * other.a[k * dim + j];
            }
        }
    }
    cout << "Matrix multiplication. Result object number: " << result.num << endl;
    return result;
}

matr matr::operator*(double scalar) const {
    matr result(dim, 0);
    for (int i = 0; i < dim * dim; i++) {
        result.a[i] = a[i] * scalar;
    }
    cout << "Matrix-scalar multiplication. Result object number: " << result.num << endl;
    return result;
}

matr& matr::operator=(const matr& other) {
    if (this != &other) {
        delete[] a;
        dim = other.dim;
        a = new double[dim * dim];
        for (int i = 0; i < dim * dim; i++) {
            a[i] = other.a[i];
        }
    }
    cout << "Matrix assignment. Object number: " << num << endl;
    return *this;
}

vect matr::operator*(const vect& v) const {
    vect result(dim, 0);
    for (int i = 0; i < dim; i++) {
        result.b[i] = 0;
        for (int j = 0; j < dim; j++) {
            result.b[i] += a[i * dim + j] * v.b[j];
        }
    }
    cout << "Matrix-vector multiplication. Result object number: " << result.num << endl;
    return result;
}

ostream& operator<<(ostream& os, const matr& m) {
    for (int i = 0; i < m.dim; i++) {
        for (int j = 0; j < m.dim; j++) {
            os << m.a[i * m.dim + j] << " ";
        }
        os << endl;
    }
    return os;
}

int main() {
    cout << "Testing vector operations:\n";
    vect v1(3, 1.0);
    vect v2(3, 2.0);
    vect v3 = v1 + v2;
    cout << "v1 + v2 = " << v3 << endl;

    v3 = v1 - v2;
    cout << "v1 - v2 = " << v3 << endl;

    double dotProduct = v1 * v2;
    cout << "v1 * v2 = " << dotProduct << endl;

    v3 = v1 * 3.0;
    cout << "v1 * 3.0 = " << v3 << endl;

    cout << "\nTesting matrix operations:\n";
    matr m1(2, 1.0);
    matr m2(2, 2.0);
    matr m3 = m1 + m2;
    cout << "m1 + m2 =\n" << m3;

    m3 = m1 - m2;
    cout << "m1 - m2 =\n" << m3;

