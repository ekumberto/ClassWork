#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>
using namespace std;

class Image {
private:
    unsigned short int width;
    unsigned short int height;
    string name;
    string extension;
    unsigned short int imageWeightInByte;

public:
    string format;
    string comment;
    string tags[100];
    unsigned short int rating;
    Image(unsigned short inputWidth = 1000, unsigned short int inputHeight = 1000) {
        width = inputWidth;
        height = inputHeight;
        format = "";
        comment = "";
        extension = ".jpg";
        name = "Image_01" + extension;
        rating = 0;
        imageWeightInByte = width * height * 3;
    }

    unsigned short int getWidth() {
        return width;
    }
    unsigned short int getImageWeightInbyte() {
        return imageWeightInByte;
    }
    string getName() {
        return name;
    }
    void setWidth(unsigned short int inputWidth) {
        if (inputWidth > 500 && inputWidth < 1000) {
            width = inputWidth;
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Image first{ 640, 1280 };
    cout << "Norm Imya: " << first.getName() << endl;

    first.setNameWithoutDigits("New123");
    cout << "Novoe Imya: " << first.getName() << endl;

    return 0;
}