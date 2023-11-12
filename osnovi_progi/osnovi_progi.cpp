#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Animal {
public:
    Animal(string name) : name(name) {}

    virtual void makeSound() const = 0; //  Общие методы
    virtual void eat() const = 0;       // 
    virtual void move() const = 0;      // 

    virtual ~Animal() {}

    const string& getName() const {
        return name;
    }

private:
    string name;
};

class Mammoth : public Animal {
public:
    Mammoth(string name) : Animal(name) {}

    void makeSound() const override {
        cout << getName() << " the Mammoth's sound: Trumpet" << endl;
    }

    void eat() const override {
        cout << getName() << " the Mammoth eats grass and leaves" << endl;
    }

    void move() const override {
        cout << getName() << " the Mammoth walks slowly" << endl;
    }

    void searchFamily() const {                                          // Уникальные методы
        cout << getName() << " the Mammoth is searching for his family" << endl;   //
    }

    void saveEverybody() const {                                 //
        cout << getName() << " the Mammoth saves everybody as usual" << endl;     //   
    }
};

class Tiger : public Animal {
public:
    Tiger(string name) : Animal(name) {}

    void makeSound() const override {
        cout << getName() << " the Tiger's sound: Roar" << endl;
    }

    void eat() const override {
        cout << getName() << " the Tiger eats his enemies" << endl;
    }

    void move() const override {
        cout << getName() << " the Tiger runs and jumps" << endl;
    }

    void playWithIceBaby() const {
        cout << getName() << " the Tiger plays peek-a-boo and asks where is the baby" << endl;
    }

    void pickOnSid() const {
        cout << getName() << " the Tiger picks on Sloth and annoys him for fun" << endl;
    }
};

class Sloth : public Animal {
public:
    Sloth(string name) : Animal(name) {}

    void makeSound() const override {
        cout << getName() << " the Sloth's sound: Snore" << endl;
    }

    void eat() const override {
        cout << getName() << " the Sloth eats leaves and fruits" << endl;
    }

    void move() const override {
        cout << getName() << " the Sloth moves slowly and climbs trees" << endl;
    }

    void actStupid() const {                                                                                   // Уникальные методы
        cout << getName() << " the Sloth acts stupid and plays with Crash and Eddie" << endl;                      // 
    }

    void stink() const {                                                                                 //
        cout << getName() << " the Sloth stinks a lot due to taking mud bathes and not the normal ones" << endl;   // 
    }
};

class Squirrel : public Animal {
public:
    Squirrel(string name) : Animal(name) {}

    void makeSound() const override {
        cout << getName() << " the Squirrel's sound: Scream" << endl;
    }

    void eat() const override {
        cout << getName() << " the Squirrel eats nuts" << endl;
    }

    void move() const override {
        cout << getName() << " the Squirrel climbs and jumps" << endl;
    }

    void beInsane() const {                                                     // Уникальные методы
        cout << getName() << " the Squirrel is losing his mind trying to open the nut" << endl;  // 
    }

    void endTheWorld() const {                                                  // 
        cout << getName() << " the Squirrel has almost ruined the world due his insanity" << endl;    // 
    }
};


int main() {
    Mammoth mammoth("Manny");
    Tiger tiger("Diego");
    Sloth sloth("Sid");
    Squirrel squirrel("Scrat");

    mammoth.makeSound();
    mammoth.eat();
    mammoth.move();
    mammoth.searchFamily();
    mammoth.saveEverybody();

    cout << endl;

    tiger.makeSound();
    tiger.eat();
    tiger.move();
    tiger.playWithIceBaby();
    tiger.pickOnSid();

    cout << endl;

    sloth.makeSound();
    sloth.eat();
    sloth.move();
    sloth.actStupid();
    sloth.stink();

    cout << endl;

    squirrel.makeSound();
    squirrel.eat();
    squirrel.move();
    squirrel.beInsane();
    squirrel.endTheWorld();

    cout << endl;

    return 0;
}
