#include <string>
#include <vector>
#include <iostream>

#include "./Card.h"

using namespace std;

class Collection {
private:
    int currentLanguageIndex = 0;
    string name;
    vector<string> languages;
    vector<Card> cards = {};
public:
    Collection(string _name, string _firstLanguage, string _secondLanguage);
    vector<Card> cardsList();
    void readCards();
    void performMemoization();
    void toggleCurrentLanguage();
    void printSummary();
    void printEntities();
};