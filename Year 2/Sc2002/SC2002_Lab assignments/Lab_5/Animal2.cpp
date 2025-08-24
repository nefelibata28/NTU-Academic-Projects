
#include "Animal.cpp.h"

#include <iostream>
#include <string>

//Question 3.2 inheritance: creating animal subclasses

using namespace std ;
enum COLOR { Green, Blue, White, Black, Brown } ;
class Animal {
    public :
        Animal() : _name("unknown") {
            cout << "constructing Animal object "<< _name << endl ;
        }

        Animal(string n, COLOR c) : _name(n), _color(c) {
        cout << "constructing Animal object " << _name << " with color " << _color << endl;
    }

        ~Animal() {
            cout << "destructing Animal object "<< _name << endl ;
        }
        void speak() const {
            cout << "Animal speaks "<< endl ;
        }
        void move() const { }

    private :
        string _name;
        COLOR _color ;
    };

  class Mammal: public Animal


        void eat() const{
            cout<< "Mammal eat"<<endl;
        }

int main() {
        Animal a;
        a.speak() ;

        Animal b("Tiger", Brown);  // Creating an Animal object with the overloaded constructor
        b.speak();
        cout << "Program exiting …. "<< endl ;
        return 0;
}
