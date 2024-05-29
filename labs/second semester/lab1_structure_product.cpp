#include <iostream>
#include <string>
using namespace std;

struct Product {
    int id;
    string name;
    int quantity;
    double price;
    Product* next;
};

bool Already_In_List(Product* head, int id) {
    Product* tmp = head;
    while (tmp != NULL) {
        if (tmp->id == id) {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

void AddFirst(Product*& head, int id, const string& name, int quantity, double price) {
    if (Already_In_List(head, id)) {
        cout << "Element with this id already in list\n";
        return;
    }
    Product* newProduct = new Product;
    newProduct->id = id;
    newProduct->name = name;
    newProduct->quantity = quantity;
    newProduct->price = price;
    newProduct->next = head;
    head = newProduct;
}

void AddLast(Product*& head, int id, const string& name, int quantity, double price) {
    if (Already_In_List(head, id)) {
        cout << "Element with this id already in list\n";
        return;
    }
    Product* newProduct = new Product;
    newProduct->id = id;
    newProduct->name = name;
    newProduct->quantity = quantity;
    newProduct->price = price;
    newProduct->next = NULL;
    if (head == NULL) {
        head = newProduct;
    }
    else {
        Product* tmp = head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newProduct;
    }
}

void AddAfter(Product* head, int targetId, int id, const string& name, int quantity, double price) {
    if (Already_In_List(head, id)) {
        cout << "Element with this id already in list\n";
        return;
    }
    Product* tmp = head;
    while (tmp != NULL) {
        if (tmp->id == targetId) {
            Product* newProduct = new Product;
            newProduct->id = id;
            newProduct->name = name;
            newProduct->quantity = quantity;
            newProduct->price = price;
            newProduct->next = tmp->next;
            tmp->next = newProduct;
            return;
        }
        tmp = tmp->next;
    }
    cout << "Target element not found\n";
}

void AddBefore(Product*& head, int targetId, int id, const string& name, int quantity, double price) {
    if (Already_In_List(head, id)) {
        cout << "Element with this id already in list\n";
        return;
    }
    if (head == NULL || head->id == targetId) {
        AddFirst(head, id, name, quantity, price);
        return;
    }
    Product* tmp = head;
    while (tmp->next != NULL) {
        if (tmp->next->id == targetId) {
            Product* newProduct = new Product;
            newProduct->id = id;
            newProduct->name = name;
            newProduct->quantity = quantity;
            newProduct->price = price;
            newProduct->next = tmp->next;
            tmp->next = newProduct;
            return;
        }
        tmp = tmp->next;
    }
    cout << "Target element not found\n";
}

void DeleteById(Product*& head, int id) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    if (head->id == id) {
        Product* tmp = head;
        head = head->next;
        delete tmp;
        return;
    }
    Product* tmp = head;
    while (tmp->next != NULL) {
        if (tmp->next->id == id) {
            Product* toDelete = tmp->next;
            tmp->next = tmp->next->next;
            delete toDelete;
            return;
        }
        tmp = tmp->next;
    }
    cout << "Element not found\n";
}

void PrintList(const Product* head) {
    if (head == NULL) {
        cout << "The list is empty\n";
        return;
    }
    const Product* tmp = head;
    while (tmp != NULL) {
        cout << "Tovar id: " << tmp->id << ", name: " << tmp->name << ", quantity: " << tmp->quantity << ", price: " << tmp->price << endl;
        tmp = tmp->next;
    }
}

int main() {
    Product* head = NULL;

    AddFirst(head, 1, "Soy Sauce", 10, 1.5);
    AddLast(head, 2, "Rice", 20, 2.0);
    AddAfter(head, 1, 3, "Salmon", 15, 2.5);
    AddBefore(head, 2, 4, "Cream Cheese", 5, 3.0);

    PrintList(head);
    cout << "===================================" << endl;

    // Îøèáêè 
    AddFirst(head, 1, "Soy Sauce", 5, 1.0);  
    AddLast(head, 2, "Rice", 10, 1.8);  
    AddAfter(head, 1, 3, "Salmon", 10, 2.2);  
    AddBefore(head, 2, 4, "Cream Cheese", 7, 2.5); 

    DeleteById(head, 3);
    PrintList(head);
    cout << "===================================" << endl;

    DeleteById(head, 3);  // Îøèáêà 
    DeleteById(head, 1);
    PrintList(head);

    return 0;
}
