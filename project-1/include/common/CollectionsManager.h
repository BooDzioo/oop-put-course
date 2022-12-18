#include <vector>

#include "./Collection.h"

using namespace std;

class CollectionsManager {
private:
    vector<Collection> collections;
public:
    vector<Collection> collectionsList();
    void printCollections();
    void addCollection(string name, string firstLanguage, string secondLanguage);
    void removeCollection(int collectionIndex);
};