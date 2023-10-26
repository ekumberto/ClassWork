#include <iostream>
using namespace std;

class Rectangle {
private:
    int width;
    int height;

public:
    Rectangle(int w, int h) {
        this->width = w;
        this->height = h;
    }

    int getback() {
        return this->width * this->height;
    }
};

class Triangle {
private:
    int width;
    int height;

public:
    Triangle(int w, int h) {
        this->width = w;
        this->height = h;
    }

    int getback() {
        return 0.5 * this->width * this->height;
    }
};

int main(){
    Rectangle rectangle(8, 14);
    Triangle triangle(2, 21);

    cout << "Plosha pryamokytnuka: " << rectangle.getArea() << endl;
    cout << "Plosha trukytnuka: " << triangle.getArea() << endl;

    return 0;
}



