#include <string>
#include <assert.h>
#include <iostream>

using namespace std;

class Game {
    virtual string result() = 0;
};

class FakeFootballGame: public Game {
public:
    string result() {
        return "1:1";
    }
};

int main() {
    FakeFootballGame fakeGame = FakeFootballGame();
    string fakeResult = fakeGame.result();

    assert(fakeResult == "1:1");

    cout << "Test passed" << endl;
}