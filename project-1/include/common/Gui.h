#include <iostream>

#include "./CollectionsManager.h"

class Gui {
private:
    CollectionsManager collectionsManager;
public:
    Gui();
    void showMainMenu();
    void showCollections();
    void addCollection();
    void deleteCollection();
    void showSingleCollection();
    void runMemoization();
};