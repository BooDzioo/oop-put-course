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
        char shouldAddNext;

        cout << "Podaj slowo w jezyku " << this->languages.at(0) << endl;
        cin >> firstConcept;
        cout << "Podaj slowo w jezyku " << this->languages.at(1) << endl;
        cin >> secondConcept;

        Card newCard = Card(firstConcept, secondConcept);
        this->cards.push_back(newCard);

        cout << "Dodac nastepne slowo? [y/n]" << endl;
        cin >> shouldAddNext;

        if(shouldAddNext != 'y') return;
    }
}

void Collection::performMemoization() {
    for(int i = 1; i <= this->cards.size(); i++) {
        string input;

        cout << i << "." << endl;
        cout << "[" << this->currentLanguage() << "] " << this->cards.at(i-1).currentConcept(this->currentLanguageIndex) << endl;

        cout << "Pokazac druga strone?[y]" << endl;
        cin >> input;

        this->toggleCurrentLanguage();
        cout << "[" << this->currentLanguage() << "] " << this->cards.at(i-1).currentConcept(this->currentLanguageIndex) << endl;

        cout << "Pokazac kolejna karte?[y]" << endl;
        cin >> input;
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
    for(int i = 1; i <= this->cards.size(); i++) {
        vector<string> concepts = this->cards[i-1].conceptsList();

        cout << i << "." << endl;
        cout << "[" << this->languages.at(0) << "]: " << concepts.at(0) << endl;
        cout << "[" << this->languages.at(1) << "]: " << concepts.at(1) << endl;
    }
}