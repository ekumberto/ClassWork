#include <iostream> 

using namespace std;

class Player {
private:
    string name;
    int hp;
    float speed;
    float accuracy; //damage = speed*accuracy
public:
    Player(string name) {
        this->name = name;
        this->hp = 100;
        this->speed = this->hp / 10;
        this->accuracy = rand() % 3;
    }
    void newStep(){ 
        this->accuracy = rand() % 10;}
    void setHP(int hp) { this->hp = hp; }
    int damege() { return this->speed * this->accuracy;}
    int getHP() { return this->hp; }

    string getName() { return this->name; }
};
class Game {
    bool isStart = false;
    int round = 0;
    Player list[4] = { {"Max"},{"Yan"},{"Dima"},{"Oleg"} };
public:
    void Start() {
        if (isStart == false) { isStart = true; }
        this->nextRound();
        srand(unsigned(time(nullptr)));
    }
    void Finish() { if (isStart == true) { isStart = false; } }
    int getRound() {
        cout << this->round;
        return this->round;
    };
    void nextRound() {
        round++;
        cout << "Round " << round << endl;

        for (int x = 0; x < 4; x++) {
            int y;
            do {
                y = rand() % 4;
            } while (y == x);

            int damage = list[x].damege();
            list[y].setHP(list[y].getHP() - damage);
            cout << "Player " << list[x].getName() << endl;
            cout << "hp : " << list[x].getHP() << endl;
        }
    }
};

int main()
{
    Game first;
    first.Start();
    return 0;
}

