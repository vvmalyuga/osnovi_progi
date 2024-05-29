#include <iostream>

using namespace std;

// Структура для представления элемента списка
struct tovar {
    int id; // Идентификатор товара
    int price;  // Цена товара
    tovar* next; // Указатель на следующий элемент списка
};

// Функция добавления нового элемента в начало списка
void addFirst(tovar*& head, int id, int price)
{
    tovar* newtovar = new tovar; // Создаем новый элемент структуры tovar
    newtovar->id = id; // Заполняем поле id нового элемента
    newtovar->price = price;   // Заполняем поле price нового элемента
    newtovar->next = head; // Устанавливаем указатель на текущую голову списка
    head = newtovar; // Новый элемент становится головой списка
}

// Функция добавления нового элемента перед указанным элементом
void addBefore(tovar*& head, int idkey, int id, int price) {
    tovar* newtovar = new tovar;
    newtovar->id = id;
    newtovar->price = price;

    if (head == NULL) { // Если список пуст
        cout << "This list is empty\n"; // Выводим сообщение об этом
        return; // Возвращаемся из функции
    }

    tovar* tmp = head;
    while (tmp->next != NULL && tmp->next->id != idkey) {
        tmp = tmp->next;
    }
    if (tmp->next->id == idkey) {
        newtovar->next = tmp->next;
        tmp->next = newtovar;
    }
    else cout << "No elements with provided id in list\n"; // Если не найден элемент с таким id, выводим сообщение
}

// Функция добавления нового элемента после элемента с определенным id
void addAfter(tovar*& head, int idkey, int id, int price) {
    tovar* newtovar = new tovar; // Создаем новый элемент структуры tovar
    newtovar->id = id; // Устанавливаем id нового элемента
    newtovar->price = price;   // Устанавливаем цену нового элемента

    if (head == NULL) { // Если список пуст
        cout << "This list is empty\n"; // Выводим сообщение об этом
        return; // Возвращаемся из функции
    }

    tovar* tmp = head; // Указатель для обхода списка, начинаем с головы
    while (tmp->next != NULL && tmp->id != idkey) { // Пока не дошли до конца списка и не найден элемент с id
        tmp = tmp->next; // Переходим к следующему элементу
    }
    if (tmp->id == idkey) { // Если найден элемент с указанным id
        newtovar->next = tmp->next; // Новый элемент указывает на следующий элемент после найденного
        tmp->next = newtovar; // Вставляем новый элемент после найденного
    }
    else cout << "No elements with provided id in list\n"; // Если не найден элемент с таким id, выводим сообщение
}

// Функция удаления элемента из списка
void delFromList(tovar*& head, int idkey) {
    if (head == NULL) { // Если список пуст
        cout << "This list is empty\n"; // Выводим сообщение об этом
    }
    tovar* tmp = head;

    // Случай 1: удаляемый элемент первый в списке
    if (tmp->id == idkey) {
        head = tmp->next;
        return;
    }
    // Cлучай 2: удаляемый элемент расположен между двумя другими элементами (или последний в списке)
    while (tmp->next != NULL && tmp->next->id != idkey) {
        tmp = tmp->next;
    }
    if (tmp->next->id == idkey) {
        tmp->next = tmp->next->next;
    }
    else cout << "No elements with provided id in list\n";
}

// Функция печати содержимого списка
void printList(tovar*& head) {
    if (head == NULL) { // Если список пуст
        cout << "This list is empty\n"; // Выводим сообщение об этом
    }
    tovar* tmp = head; // Указатель для обхода списка, начинаем с головы
    while (tmp != NULL) { // Пока не дошли до конца списка
        cout << "Tovar id: " << tmp->id << endl; // Выводим id текущего элемента
        tmp = tmp->next; // Переходим к следующему элементу
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