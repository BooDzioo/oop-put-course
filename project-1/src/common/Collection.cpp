#include "../../include/common/Collection.h"

Collection::Collection(
    string _name,
    string _firstLanguage,
    string _secondLanguage
) {
    this->name = _name;
    this->languages.push_back(_firstLanguage);
    this->languages.push_back(_secondLanguage);

    this->readCards();
}

vector<Card> Collection::cardsList() {
    return this->cards;
}

string Collection::currentLanguage() {
    return this->languages.at(this->currentLanguageIndex);
}

void Collection::readCards() {
    while(true) {
        string firstConcept, secondConcept;
        int shouldAddNext;

        cout << "Podaj slowo w jezyku " << this->languages.at(0);
        cin >> firstConcept;
        cout << "Podaj slowo w jezyku " << this->languages.at(1);
        cin >> secondConcept;

        Card newCard = Card(firstConcept, secondConcept);
        this->cards.push_back(newCard);

        cout << "Dodac nastepne slowo? Wcisnij 0 zeby zakonczyc dodawanie lub cokolwiek innego zeby kontynuowac" << endl;
        cin >> shouldAddNext;

        if(shouldAddNext == 0) return;
    }
}

void Collection::performMemoization() {
    for(int i = 1; i <= this->cards.size(); i++) {
        string input;

        cout << i << "." << endl;
        cout << "[" << this->currentLanguage() << "] " << this->cards.at(i-1).currentConcept(this->currentLanguageIndex) << endl;

        cin >> input;

        this->toggleCurrentLanguage();
        cout << "[" << this->currentLanguage() << "] " << this->cards.at(i-1).currentConcept(this->currentLanguageIndex) << endl;
    }
}

void Collection::toggleCurrentLanguage() {
    if(this->currentLanguageIndex == 0) {
        this->currentLanguageIndex = 1;
    } else {
        this->currentLanguageIndex = 0;
    }
}

void Collection::printSummary() {
    cout << "Nazwa: " << this->name << endl;
    cout << "Jezyki: " << this->languages[0] << ", " << this->languages[1] << endl;
}

void Collection::printEntities() {
    cout << "printEntities" << this->cards.size() << endl;
    for(int i = 1; i <= this->cards.size(); i++) {
        vector<string> concepts = this->cards[i-1].conceptsList();

        cout << i << "." << endl;
        cout << "[" << this->languages.at(0) << "]: " << concepts.at(0) << endl;
        cout << "[" << this->languages.at(1) << "]: " << concepts.at(1) << endl;
    }
}