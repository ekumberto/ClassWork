#include <iostream>
#include <Windows.h>
#include <string>
#include <algorithm>

using namespace std;

class Bird {
public:
    float weight;
    float height;
    string color;
    string GEO;
};

class HomeParrot : public Bird {
public:
    string name;
    bool isSpeak;
    bool trained;

    HomeParrot(string geo, float parrotWeight) {
        GEO = geo;
        weight = parrotWeight;
        trained = true;
    }

    void Say(string word) {
        cout << word << endl;
    }

    void Speak() {
        if (trained) {
            cout << "Hi i like traning" << endl;
        }
        else {
            Say("How are you");
        }
    }
};

class Chicken : public Bird {
public:
    bool trained;

    Chicken(string geo, float chickenWeight) {
        GEO = geo;
        weight = chickenWeight;
        trained = true;
    }

    void Cluck() {
        cout << "Koko Koko!" << endl;
    }

    void DoAction() {
        Jump();
        Cluck(); 
    }

private:
    void Jump() {
        cout << "Jumping chiken" << endl;
    }
};

class Swallow : public Bird {
public:
    Swallow(string geo, float swallowWeight) {
        GEO = geo;
        weight = swallowWeight;
    }

    void Fly() {
        cout << "Wow i can fly fast!" << endl;
    }

    void DoAction() {
        Fly();
    }
};

int main() {
    HomeParrot vasya("Home", 0.5);  
    Chicken chicken("Barn", 1.2);   
    Swallow swallow("Street", 0.1); 

    cout << "Vasya's GEO: " << vasya.GEO << ", Weight: " << vasya.weight << endl;
    cout << "Chicken's GEO: " << chicken.GEO << ", Weight: " << chicken.weight << endl;
    cout << "Swallow's GEO: " << swallow.GEO << ", Weight: " << swallow.weight << endl;

    vasya.Speak();

    chicken.DoAction();
    swallow.DoAction();

    return 0;
}

