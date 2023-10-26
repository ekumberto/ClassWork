#include <iostream>
#include <cmath>

using namespace std;

class Point {
public:
    int x;
    int y;
    int thickness = 1;
    string color;

    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
        this->color = "black";
    }
};

class Line : public Point {
public:
    Point p1;
    Point p2;
    int length;

    Line(Point p1, Point p2) {
        if (p1.x > p2.x) {
            this->p1 = p2;
            this->p2 = p1;
        }
        else if (p1.x < p2.x) {
            p1 = p1;
            p2 = p2;
        }
        else {
            if (p1.y > p2.y) {
                p1 = p2;
                p2 = p1;
            }
            else {
                p1 = p1;
                p2 = p2;
            }
        }

        int newX = p2.x - p1.x;
        int newY = p2.y - p1.y;
        length = sqrt(newX * newX + newY * newY);
    }
};

class Figure {
public:
    Line line1;
    Line line2;
    Line line3;

    Figure(Line line1, Line line2, Line line3) {
        this->line1 = line1;
        this->line2 = line2;
        this->line3 = line3;
    }

    int poschirarPloshy() {
        return (line1.length * line2.length) / 2;
    }

    void printYgol() {
        int ygol1 = 90;
        int ygol2 = 0;
        int ygol3 = 0;

        for (int i = 1; i <= 89; ++i) {
            if (line1.length * i >= line2.length) {
                ygol2 = i;
                ygol3 = 180 - ygol1 - ygol2;
                break;
            }
        }

        cout << "Ygol 1: " << ygol1 << " v gradysah" << endl;
        cout << "Ygol 2: " << ygol2 << " v gradysah" << endl;
        cout << "Ygol 3: " << ygol3 << " v gradysah" << endl;
    }
};

int main() {
    Point point1{ 5, 20 };
    Point point2{ 15, 8 };
    Line line1{ point1, point2 };
    Point point3{ 3, 0 };
    Line line2{ point2, point3 };
    Figure figure{ line1, line2, Line(point3, point1) };
    cout << "Length line1: " << line1.length << endl;
    cout << "Length line2: " << line2.length << endl;
    int area = figure.poschirarPloshy();
    cout << "Plosha: " << area << endl;
    figure.printYgol();
    return 0;
}