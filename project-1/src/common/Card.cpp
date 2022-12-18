#include <iostream>

#include "../../include/common/Card.h"

Card::Card(string _firstConcept, string _secondConcept) {
    this->concepts.push_back(_firstConcept);
    this->concepts.push_back(_secondConcept);
}

vector<string> Card::conceptsList() {
    return this->concepts;
}

string Card::currentConcept(int currentConceptIndex) {
    return this->concepts.at(currentConceptIndex);
}

void Card::printCurrentConcept(int currentConceptIndex) {
    cout << this->concepts.at(currentConceptIndex) << endl;
}