#include <string>
#include <vector>

using namespace std;

class Card {
private:
    vector<string> concepts;
public:
    Card(string _firstConcept, string _secondConcept);
    vector<string> conceptsList();
    void printCurrentConcept(int currentConceptIndex);
};