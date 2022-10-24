#include <iostream>

using namespace std;

class Tweezer {
    int weight;
    bool isClamped;

    public:
        Tweezer(int _weight) {
            weight = _weight;
            isClamped = false;
        }

        void grab() {
            isClamped = true;
        }

        void release() {
            isClamped = false;
        }

        bool claspStatus() {
            return isClamped;
        }

};

int main() {
    Tweezer test = Tweezer(10);

    cout << test.claspStatus() << endl;
    test.grab();
    cout << test.claspStatus() << endl;

    return 0;
}