#include "../../include/common/Gui.h"

Gui::Gui() {
    this->collectionsManager = CollectionsManager();
}

void Gui::showMainMenu() {
    int optionNumber;
    
    cout << "1. Pokaz zbiory" << endl;
    cout << "2. Dodaj zbior" << endl;
    cout << "3. Usun zbior" << endl;
    cout << "4. Sczegoly zbioru" << endl;
    cout << "5. Ucz sie zbioru" << endl;
    cin >> optionNumber;

    switch (optionNumber) {
        case 1:
            this->showCollections();
            break;
        case 2:
            this->addCollection();
            break;
        case 3:
            this->deleteCollection();
            break;
        case 4:
            this->showSingleCollection();
            break;
        case 5:
            this->runMemoization();
            break;
        default:
            cout << "Błędna opcja" << endl;
    }

    showMainMenu();
}

void Gui::showCollections() {
    this->collectionsManager.printCollections();
}

void Gui::addCollection() {
    string name, firstLanguage, secondLanguage;

    cout << "Podaj nazwe zbioru i jezyki(2) oddzielone spacja: ";
    cin >> name >> firstLanguage >> secondLanguage;

    this->collectionsManager.addCollection(name, firstLanguage, secondLanguage);
}

void Gui::deleteCollection() {
    int collectionIndex;

    cout << "Podaj id zbioru do usuniecia: ";
    cin >> collectionIndex;

    this->collectionsManager.removeCollection(collectionIndex - 1);
}

void Gui::showSingleCollection() {
    int collectionIndex;

    cout << "Podaj id zbioru: ";
    cin >> collectionIndex;

    this->collectionsManager.collectionsList()[collectionIndex - 1].printEntities();
}

void Gui::runMemoization() {
    int collectionIndex;

    cout << "Podaj id zbioru do uruchomienia: ";
    cin >> collectionIndex;

    this->collectionsManager.collectionsList()[collectionIndex - 1].performMemoization();
}

