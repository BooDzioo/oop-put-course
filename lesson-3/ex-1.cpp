#include <iostream>

using namespace std;

class Person {
    int identificationNumber;
    string name, surname, phoneNumber;

    public:
        Person() {
            name = "Jan";
            surname = "Kowalski";
            identificationNumber = 1234;
            phoneNumber = "123123123";
        }

        Person(string _name, string _surname, string _phoneNumber, int _identificationNumber) {
            name = _name;
            surname = _surname;
            phoneNumber = _phoneNumber;
            identificationNumber = _identificationNumber;
        }

        string contactData() {
            return name + " " + surname + " " + phoneNumber;
        }
};

class Vehicle {
    int productionYear, mileage, weight;
    string color, brand, model;
    Person owner;

    public:
        Vehicle() {
            productionYear = 2022;
            mileage = 0;
            weight = 500;
            color = "black";
            brand = "Honda";
            model = "Civic";
        }

        void printInformationCard() {
            cout << "Brand: " << brand << endl;
            cout << "Model: " << model << endl;
            cout << "Color: " << color << endl;
            cout << "Mileage: " << mileage << " km" << endl;
            cout << "Weight: " << weight << " kg" << endl;
            cout << "Year of production: " << productionYear << endl;
        }

        void changeOwner(string _name, string _surname, string _phoneNumber, int _identificationNumber) {
            owner = Person(_name, _surname, _phoneNumber, _identificationNumber);
        }

        string ownerContactData() {
            return owner.contactData();
        }
};

int main() {
    Vehicle honda = Vehicle();
    honda.printInformationCard();
    cout << honda.ownerContactData() << endl;
    honda.changeOwner("krzysztof", "Ibisz", "123123321", 1235);
    cout << honda.ownerContactData() << endl;

    return 0;
}