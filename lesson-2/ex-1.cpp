#include <iostream>

using namespace std;

class Computer {
    public:
    int price, width, height, depth;

    Computer() {
            price = 1000;
            width = 100;
            height = 100;
            depth = 100;
        }

        Computer(int _price, int _width, int _height, int _depth) {
            price = _price;
            width = _width;
            height = _height;
            depth = _depth;
        }
};

int main() {
    Computer test = Computer(1, 5000, 100, 100);
    Computer test2 = Computer();

    return 0;
}