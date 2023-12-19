#include <algorithm>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <vector>

using namespace std;

class Town {
private:
    int floor;
    int apartaments;
    int firstFloor;
public:
    Town(int f, int a) : floor(f), apartaments(a), firstFloor(rand() % 2) {}
    int getfloor() { return floor; }
    int getApartaments() { return apartaments; }
    int getFirst() { return firstFloor; }

};

int main()
{
    vector<Town> group = {
        Town(11, 4),
        Town(8, 10),
        Town(15, 6),
        Town(17, 3),
        Town(4, 5),
        Town(5, 7),
        Town(9, 8),
        Town(12, 5),
        Town(3, 6),
        Town(18, 4),
        Town(5, 9),
        Town(4, 8),
        Town(8, 7),
        Town(6, 6),
        Town(5, 4)  
    };
    auto sortByApartaments = [](const Town& f, const Town& a) {return f.getApartaments() < a.getApartaments();
    };
    sort(group.begin(), group.end(), sortByApartaments);

    for (const auto& town : group) {
        cout << "Этажей: " << town.getfloor()
            << ", Квартир: " << town.getApartaments()
            << ", Квартиры на первом этаже: " << town.getFirst()
            << endl;
    }

    return 0;
}