#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Goat {
private:
    int age;
    string name;
    string color;
    static string names[15];
    static string colors[15];

public:
    Goat() {
        age = rand() % 20 + 1;
        name = names[rand() % 15];
        color = colors[rand() % 15];
    }

    Goat(int a, string n, string c) : age(a), name(n), color(c) {}

    friend ostream& operator<<(ostream& os, const Goat& g) {
        os << g.name << " (" << g.color << ", " << g.age << ")";
        return os;
    }
};

string Goat::names[15] = {"Daisy", "Bella", "Charlie", "Lucy", "Max", "Milo", "Oscar", "Rocky", "Zoe", "Molly", "Buddy", "Toby", "Lola", "Sadie", "Coco"};
string Goat::colors[15] = {"Red", "Blue", "Green", "Yellow", "Black", "White", "Gray", "Purple", "Pink", "Orange", "Brown", "Gold", "Silver", "Mauve", "Cyan"};

class DoublyLinkedList {
private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;
        Node(Goat g, Node* p = nullptr, Node* n = nullptr) : data(g), prev(p), next(n) {}
    };
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_back(Goat g) {
        Node* newNode = new Node(g);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat g) {
        Node* newNode = new Node(g);
        if (!head)
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty" << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) {
            cout << "List is empty" << endl;
            return;
        }
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main() {
    srand(time(0));  // To randomize

    DoublyLinkedList list;
    int size = rand() % 16 + 5;  // Random number between 5 and 20
    for (int i = 0; i < size; ++i) {
        Goat g;
        list.push_back(g);
    }

    cout << "List forward: ";
    list.print();

    cout << "List backward: ";
    list.print_reverse();

    return 0;
}
