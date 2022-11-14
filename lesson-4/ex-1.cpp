#include <iostream>

using namespace std;

class PhysicalMetrics {
    public:
        int width, height, depth, weight;
        PhysicalMetrics() {
            width = 1;
            height = 1;
            depth = 1;
            weight = 1;
        }

        PhysicalMetrics(int _width, int _height, int _depth, int _weight) {
            width = _width;
            height = _height;
            depth = _depth;
            weight = _weight;
    }
};

class Furniture {
    public:
        PhysicalMetrics metrics;
        string baseMaterial;
        float price;

        Furniture() {
            price = 0;
            baseMaterial = "metal";
            metrics = PhysicalMetrics(100, 100, 100, 100);
        }

        virtual void printProductInfo();

        virtual float pricePerKilogram();

        virtual Furniture changePrice(float newPrice);
};

class Wardrobe: public Furniture {
    public:
        Wardrobe(float _price, string _baseMaterial, int _width, int _height, int _depth, int _weight): Furniture() {
            price = _price;
            baseMaterial = _baseMaterial;
            metrics = PhysicalMetrics(_width, _height, _depth, _weight);
        }

        Wardrobe changedPrice(float newPrice) {
            return Wardrobe(newPrice, baseMaterial, metrics.width, metrics.height, metrics.depth, metrics.weight);
        }

        void printProductInfo() {
            cout << "Info" << endl;
        }

        float pricePerKilogram() {
            return price / metrics.weight;
        }
};

int main() {
    Wardrobe wardrobe = Wardrobe(10.99, "wood", 100, 100, 100, 100);
    wardrobe.printProductInfo();

    return 0;
}