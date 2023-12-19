#include <iostream>

using namespace std;

class Weapon {
protected:
    unsigned short damage;
    unsigned short weight;
    unsigned short numberOfCartridgesInTheClip;
    unsigned short numberOfClips;
    unsigned short accuracy; // 0.1 -> 0.9
    double rateOfFire; // 0.1 -> 0.9
public:
    unsigned short getDamage() { return this->damage; }
    unsigned short getWeight() { return this->weight; }
    unsigned short getnumberOfCartridgesTheClip() { return this->numberOfCartridgesInTheClip; }
    unsigned short genumberOfClips() { return this->numberOfClips; }
    unsigned short getaccuracy(){return this->accuracy}
};

class Empty : public Weapon {
public:
    Empty() {
        damage = 5;
        weight = 0;
        numberOfCartridgesInTheClip = 1000;
        numberOfClips = 0;
        accuracy = 0.6;
        rateOfFire = 0.9;
    }
    void setDamage(unsigned short damage) { this->damage = damage; }
    unsigned short getDamage() { return this->damage; }
};

class Glock : public Weapon {
    Glock() {
        damage = 20; 
        weight = 2;
        numberOfCartridgesInTheClip = 15;
        numberOfClips = 3;
        accuracy = 0.7;
        rateOfFire = 0.6;
    }
};

class AK47 : public Weapon {
    AK47() {
        damage = 40;
        weight = 4;
        numberOfCartridgesInTheClip = 30;
        numberOfClips = 4;
        accuracy = 0.6;
        rateOfFire = 0.7;
    }
};

class M4A1 : public Weapon {
    M4A1() {
        damage = 35;
        weight = 4;
        numberOfCartridgesInTheClip = 20;
        numberOfClips = 5;
        accuracy = 0.8;
        rateOfFire = 0.8;
    }
};

class ShortGun : public Weapon {
    ShortGun() {
        damage = 50; 
        weight = 6;
        numberOfCartridgesInTheClip = 2;
        numberOfClips = 6;
        accuracy = 0.5;
        rateOfFire = 0.4;
    }
};

class Character {
protected:
    unsigned short hp = 100;
    unsigned short speed = 255;
    unsigned short armor = 0;
    unsigned short stamina = 0;
    Weapon weapon = getW();
public:
    Weapon getW() {
        Empty e;
        Glock g;
        AK47 a;
        M4A1 m;
        ShortGun s;

        int randNum = rand() % 5; 

        switch (randNum) {
        case 0: return e;
        case 1: return g;
        case 2: return a;
        case 3: return m;
        case 4: return s;
        default: return e; 
        }
    }
    void shoot(Character& target) {
        double accuracyMultiplier = (rand() % 3 + 7) / 10.0; 
        unsigned short totalDamage = this->weapon.getDamage() * accuracyMultiplier;
        target.takeDamage(totalDamage);
    }

    void takeDamage(unsigned short damage) {
        if (damage > this->armor) {
            this->hp -= (damage - this->armor);
        }

        if (this->hp < 0) {
            this->hp = 0;
        }
    }
};

class Bot : public Character {};

class Player : public Character {
protected:
    string name;

public:
    void setName(string name) { this->name = name; }
    string getName() { return this->name; }
};

int main() {
    Player player;
    Bot bot;
    player.shoot(bot);
    bot.shoot(player);
    return 0;
}