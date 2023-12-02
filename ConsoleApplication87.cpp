#include <iostream>
#include <string>

using namespace std;

class Entry {
private:
    string title;
    string description;
public:
    Entry getEntry() {
        Entry newEntry;
        newEntry.title = this->title;
        newEntry.description = this->description;
        return newEntry;
    }
};

class Minutes {
    Entry array[60];
};

class Hours {
private:
    Minutes minutes[60];
};

class Day {
private:
    Hours hours[24];
};


class Time : public Entry {
private:
    int hours;
    int minutes;
    string outPutTime;
public:
    Time(int hours, int minutes) {
        if (hours >= 0 && hours <= 24) {
            this->hours = hours;
        }
        if (minutes >= 0 && minutes <= 60) {
            this->minutes = minutes;
        }
        outPutTime = hours + ":" + minutes;
    }
};


class Month {
private:
    string month[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    Day day[30];

public:
    string ngd;

    Month(int number = 0) {
        this->ngd = month[number];
    }
};

class Year {
private:
    int year;

public:
    Year(int year) {
        this->year = year;
    }
    void setYear(int year) {
        this->year = year;
    }
    int getYear() {
        return this->year;
    }
};

class Book {
private:
    Year year;

public:
    void createReminder() {
        int year, month, day, hours, minutes;
        string title, description;
        cout << "Enter the year: ";
        cin >> year;
        cout << "Enter the month (1-12): ";
        cin >> month;
        cout << "Enter the day: ";
        cin >> day;
        cout << "Enter the hours (0-24): ";
        cin >> hours;
        cout << "Enter the minutes: ";
        cin >> minutes;
        cout << "Enter the title: ";
        getline(cin, title);
        cout << "Enter the description: ";
        getline(cin, description);
        cout << "Reminder created for: " << year << "-" << month << "-" << day << " " << hours << ":" << minutes << endl;
        cout << "Title: " << title << endl;
        cout << "Description: " << description << endl;
    }

    void showInfo() {
        cout << this->year.getYear();
    }
};

int main() {
    Book myBook;
    myBook.createReminder();

    return 0;
}