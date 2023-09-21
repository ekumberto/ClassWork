#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

string newList[] = { "Katya", "Liza", "Cap", "Shelbi", "Liva", "Parker", "Chelik", "Ryan", "Sophia", "Tylo",
                    "Shuma", "Victor", "Windy", "Pavon", "Yatik", "Zane", "Vasya", "Piter", "Volodya", "Anton",
                    "Artem", "Maks", "Misha", "Mike", "Maha", "Bogdan"};
class Student {
public:
    string name;
    int mathAssessment;
    int physicAssessment;
    Student() {
        name = newList[rand() % 26];
        mathAssessment = rand() % 11;
        physicAssessment = rand() % 11;
    }
    int GetAverageAssessment() {
        return (mathAssessment + physicAssessment) / 2;
    }
};
class SchoolClass {
public:
    Student allStudent[26];
    SchoolClass() {
        for (int i = 0; i < 26; i++) {
            allStudent[i] = Student(); 
        }
    }
    Student BestStudent() {
        Student bestStudent = allStudent[0];
        for (int i = 1; i < 26; i++) {
            if (allStudent[i].GetAverageAssessment() > bestStudent.GetAverageAssessment()) {
                bestStudent = allStudent[i];
            }
        }
        return bestStudent;
    }
    int Classochenka() {
        int totalAverage = 0;
        for (int i = 0; i < 26; i++) {
            totalAverage += allStudent[i].GetAverageAssessment();
        }
        return totalAverage / 26;
    }
};
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(nullptr));
    SchoolClass school;
    Student bestStudent = school.BestStudent();
    cout << "Лучший Студент: Имя: " << bestStudent.name << ", Оценка: "
        << bestStudent.GetAverageAssessment() << endl;
    int classAverage = school.Classochenka();
    cout << "Средняя оценка: " << classAverage << endl;
    return 0;
}