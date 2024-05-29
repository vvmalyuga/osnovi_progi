#include <iostream>

using namespace std;

// ��������� ��� ������������� �������� ������
struct tovar {
    int id; // ������������� ������
    int price;  // ���� ������
    tovar* next; // ��������� �� ��������� ������� ������
};

// ������� ���������� ������ �������� � ������ ������
void addFirst(tovar*& head, int id, int price)
{
    tovar* newtovar = new tovar; // ������� ����� ������� ��������� tovar
    newtovar->id = id; // ��������� ���� id ������ ��������
    newtovar->price = price;   // ��������� ���� price ������ ��������
    newtovar->next = head; // ������������� ��������� �� ������� ������ ������
    head = newtovar; // ����� ������� ���������� ������� ������
}

// ������� ���������� ������ �������� ����� ��������� ���������
void addBefore(tovar*& head, int idkey, int id, int price) {
    tovar* newtovar = new tovar;
    newtovar->id = id;
    newtovar->price = price;

    if (head == NULL) { // ���� ������ ����
        cout << "This list is empty\n"; // ������� ��������� �� ����
        return; // ������������ �� �������
    }

    tovar* tmp = head;
    while (tmp->next != NULL && tmp->next->id != idkey) {
        tmp = tmp->next;
    }
    if (tmp->next->id == idkey) {
        newtovar->next = tmp->next;
        tmp->next = newtovar;
    }
    else cout << "No elements with provided id in list\n"; // ���� �� ������ ������� � ����� id, ������� ���������
}

// ������� ���������� ������ �������� ����� �������� � ������������ id
void addAfter(tovar*& head, int idkey, int id, int price) {
    tovar* newtovar = new tovar; // ������� ����� ������� ��������� tovar
    newtovar->id = id; // ������������� id ������ ��������
    newtovar->price = price;   // ������������� ���� ������ ��������

    if (head == NULL) { // ���� ������ ����
        cout << "This list is empty\n"; // ������� ��������� �� ����
        return; // ������������ �� �������
    }

    tovar* tmp = head; // ��������� ��� ������ ������, �������� � ������
    while (tmp->next != NULL && tmp->id != idkey) { // ���� �� ����� �� ����� ������ � �� ������ ������� � id
        tmp = tmp->next; // ��������� � ���������� ��������
    }
    if (tmp->id == idkey) { // ���� ������ ������� � ��������� id
        newtovar->next = tmp->next; // ����� ������� ��������� �� ��������� ������� ����� ����������
        tmp->next = newtovar; // ��������� ����� ������� ����� ����������
    }
    else cout << "No elements with provided id in list\n"; // ���� �� ������ ������� � ����� id, ������� ���������
}

// ������� �������� �������� �� ������
void delFromList(tovar*& head, int idkey) {
    if (head == NULL) { // ���� ������ ����
        cout << "This list is empty\n"; // ������� ��������� �� ����
    }
    tovar* tmp = head;

    // ������ 1: ��������� ������� ������ � ������
    if (tmp->id == idkey) {
        head = tmp->next;
        return;
    }
    // C����� 2: ��������� ������� ���������� ����� ����� ������� ���������� (��� ��������� � ������)
    while (tmp->next != NULL && tmp->next->id != idkey) {
        tmp = tmp->next;
    }
    if (tmp->next->id == idkey) {
        tmp->next = tmp->next->next;
    }
    else cout << "No elements with provided id in list\n";
}

// ������� ������ ����������� ������
void printList(tovar*& head) {
    if (head == NULL) { // ���� ������ ����
        cout << "This list is empty\n"; // ������� ��������� �� ����
    }
    tovar* tmp = head; // ��������� ��� ������ ������, �������� � ������
    while (tmp != NULL) { // ���� �� ����� �� ����� ������
        cout << "Tovar id: " << tmp->id << endl; // ������� id �������� ��������
        tmp = tmp->next; // ��������� � ���������� ��������
    }
}

int main() {
    tovar* head = NULL;

    int id1 = 1;
    int price1 = 11;

    int id2 = 2;
    int price2 = 22;

    int id3 = 3;
    int price3 = 33;

    int id4 = 4;
    int price4 = 44;