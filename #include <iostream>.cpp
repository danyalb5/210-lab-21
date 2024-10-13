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
