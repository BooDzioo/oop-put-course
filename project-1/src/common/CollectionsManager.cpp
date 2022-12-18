#include "iostream"

#include "../../include/common/CollectionsManager.h"

vector<Collection> CollectionsManager::collectionsList() {
    return this->collections;
}


void CollectionsManager::printCollections() {
    for(int i = 1; i <= this->collections.size(); i++) {
        cout << "Id: " << i << endl;
        this->collections[i-1].printSummary();
    }
}

void CollectionsManager::addCollection(string name, string firstLanguage, string secondLanguage) {
    Collection newCollection = Collection(name, firstLanguage, secondLanguage);
    this->collections.push_back(newCollection);
}

void CollectionsManager::removeCollection(int collectionIndex) {
    this->collections.erase(this->collections.begin() + collectionIndex);
}