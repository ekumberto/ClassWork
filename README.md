#include <iostream>
#include <Windows.h>

using namespace std;

class Student {
public:
    string name;
    int age;

    void sayHi() {
        cout << "Hello, my name is" << name;
    }
};


Student olderStudent(Student students[], int size) {
    Student older = students[0]; 
    for (int i = 1; i < size; ++i) {
        if (students[i].age > older.age) {
            older = students[i]; 
        }
    }
    return older;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Student newList[3]{ {"Vlad", 18},
                        {"Maxim", 16},
                        {"Oleg", 20} };

    Student oldestStudent = olderStudent(newList, 3);

    cout << "Имя старшего студента: " << oldestStudent.name << endl;
    cout << "Возраст старшего студента: " << oldestStudent.age << " лет" << endl;

    return 0;
}
