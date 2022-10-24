//commits history looks how it looks since on laboratory desktops there is no git installed and commit was done by uploading the file

#include <iostream>
#include <string>

using namespace std;

class Person {
    public:
        string name;
        string surname;
        int age;

        Person(string _name, string _surname, int _age) {
            name = _name;
            surname = _surname;
            age = _age;
        }

        void introduce() {
            cout << name << ' ' << surname << endl;
        }
};

class Cat {
    public:
        int age;
        string name;
        string ownerName;
        
        Cat(string _name, int _age, string _ownerName) {
            name = _name;
            age = _age;
            ownerName = _ownerName;
        }
        
        void getOwnerName() {
            cout << "Owner: " << ownerName << endl;
        }

};

int main() {
    Person person = Person("name", "surname", 21);
    Cat garfield = Cat("Garfield", 2, person.name);
    
    person.introduce();
    garfield.getOwnerName();
    
    return 0;
}
