#include <iostream>
#include <cmath>

// ����������� ����� "�����"
class Point {
protected:
    int x, y; // ���������� �����
public:
    Point(int _x, int _y) : x(_x), y(_y) {}

    virtual void draw() const = 0; // ����� ����������
    virtual void erase() const = 0; // ����� ������
    virtual void move(int dx, int dy) = 0; // ����� �����������
    virtual void rotate(double angle) = 0; // ����� ���������
    virtual ~Point() {} // ����������� ���������� ��� ����������� �������� ��������
};

// ����� "�����", ����������� �� ������ "�����"
class Line : public Point {
protected:
    int x2, y2; // �������� ���������� �����
public:
    Line(int _x1, int _y1, int _x2, int _y2) : Point(_x1, _y1), x2(_x2), y2(_y2) {}

    void draw() const override {
        std::cout << "Drawing a line from (" << x << ", " << y << ") to (" << x2 << ", " << y2 << ")." << std::endl;
    }

    void erase() const override {
        std::cout << "Erasing a line from (" << x << ", " << y << ") to (" << x2 << ", " << y2 << ")." << std::endl;
    }

    void move(int dx, int dy) override {
        x += dx;
        y += dy;
        x2 += dx;
        y2 += dy;
        std::cout << "Moving line by (" << dx << ", " << dy << ")." << std::endl;
    }

    void rotate(double angle) override {
        double radians = angle * M_PI / 180.0;
        int new_x2 = round((x - x2) * cos(radians) - (y - y2) * sin(radians) + x2);
        int new_y2 = round((x - x2) * sin(radians) + (y - y2) * cos(radians) + y2);
        x2 = new_x2;
        y2 = new_y2;
        std::cout << "Rotating line by " << angle << " degrees." << std::endl;
    }
};

// ����� "�������", ����������� �� ������ "�����"
class Square : public Point {
protected:
    int side_length; // ����� ������� ��������
public:
    Square(int _x, int _y, int _side_length) : Point(_x, _y), side_length(_side_length) {}

    void draw() const override {
        std::cout << "Drawing a square with side length " << side_length << " at (" << x << ", " << y << ")." << std::endl;
    }

    void erase() const override {
        std::cout << "Erasing a square with side length " << side_length << " at (" << x << ", " << y << ")." << std::endl;
    }

    void move(int dx, int dy) override {
        x += dx;
        y += dy;
        std::cout << "Moving square by (" << dx << ", " << dy << ")." << std::endl;
    }

    void rotate(double angle) override {
        std::cout << "Rotating square by " << angle << " degrees." << std::endl;
    }
};

// ����� "��������������", ����������� �� "��������"
class Parallelogram : public Square {
public:
    Parallelogram(int _x, int _y, int _side_length) : Square(_x, _y, _side_length) {}

    void draw() const override {
        std::cout << "Drawing a parallelogram with side length " << side_length << " at (" << x << ", " << y << ")." << std::endl;
    }

    void erase() const override {
        std::cout << "Erasing a parallelogram with side length " << side_length << " at (" << x << ", " << y << ")." << std::endl;
    }
};

// �������� ����������� �������� ����������:
void testLateBinding(Point& point) {
    point.draw(); // ����� ����� ������� ��������������� ������ ������ draw() � ����������� �� ���� �������
}

int main() {
    Line line(0, 0, 3, 3);
    line.draw(); // ������ �����

    Square square(5, 5, 3);
    square.draw(); // ������ �������

    Parallelogram parallelogram(10, 10, 4);
    parallelogram.draw(); // ������ ��������������

    // �������� �������� ����������
    testLateBinding(line); // ��������� ������� ���������� ��� �����
    testLateBinding(square); // ��������� ������� ���������� ��� ��������
    testLateBinding(parallelogram); // ��������� ������� ���������� ��� ���������������

    // ������������ ������ ������ �������
    line.move(2, 2);
    line.rotate(45);
    square.move(2, 2);

    return 0;
}
