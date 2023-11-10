#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    Animal(const string& name, int age) : name(name), age(age) {}

    virtual void makeSound() const = 0; //  Общие методы
    virtual void eat() const = 0;       // 
    virtual void move() const = 0;      // 

    virtual ~Animal() {}

    const string& getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

private:
    string name;
    int age;
};




class Mammoth : public Animal {
public:
    Mammoth(const string& name, int age) : Animal(name, age) {}

    void makeSound() const override {
        cout << "Mammoth's sound: Trumpet" << endl;
    }

    void eat() const override {
        cout << "Mammoth eats grass and leaves" << endl;
    }

    void move() const override {
        cout << "Mammoth walks slowly" << endl;
    }

    void searchFamily() const {                                  // Уникальные методы
        cout << "Mammoth is searching for his family" << endl;   //
    }

    void saveEverybody() const {                                 //
        cout << "Mammoth saves everybody as usual" << endl;     //   
    }
};

class Tiger : public Animal {
public:
    Tiger(const string& name, int age) : Animal(name, age) {}

    void makeSound() const override {
        cout << "Tiger's sound: Roar" << endl;
    }

    void eat() const override {
        cout << "Tiger eats his enemies" << endl;
    }

    void move() const override {
        cout << "Tiger runs and jumps" << endl;
    }

    void playWithIceBaby() const {
        cout << "Tiger plays peek-a-boo and asks where is the baby" << endl;
    }

    void pickOnSid() const {
        cout << "Tiger picks on Sloth and annoys him for fun" << endl;
    }
};

class Sloth : public Animal {
public:
    Sloth(const string& name, int age) : Animal(name, age) {}

    void makeSound() const override {
        cout << "Sloth's sound: Snore" << endl;
    }

    void eat() const override {
        cout << "Sloth eats leaves and fruits" << endl;
    }

    void move() const override {
        cout << "Sloth moves slowly and climbs trees" << endl;
    }

    void actStupid() const {                                                                     // Уникальные методы
        cout << "Sloth acts stupid and plays with Crash and Eddie" << endl;                      // 
    }

    void stink() const {                                                                         //
        cout << "Sloth stinks a lot due to taking mud bathes and not the normal ones" << endl;   // 
    }
};

class Squirrel : public Animal {
public:
    Squirrel(const string& name, int age) : Animal(name, age) {}

    void makeSound() const override {
        cout << "Squirrel's sound: Scream" << endl;
    }

    void eat() const override {
        cout << "Squirrel eats nuts" << endl;
    }

    void move() const override {
        cout << "Squirrel climbs and jumps" << endl;
    }

    void beInsane() const {                                                     // Уникальные методы
        cout << "Squirrel is losing his mind trying to open the nut" << endl;  // 
    }

    void endTheWorld() const {                                                  // 
        cout << "Squirrel has almost ruined the world due his insanity" << endl;    // 
    }
};

int main() {
    Mammoth mammoth("Manny", 35);
    Tiger tiger("Diego", 30);
    Sloth sloth("Sid", 21);
    Squirrel squirrel("Scrat", 100);

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

    return 0;
}
