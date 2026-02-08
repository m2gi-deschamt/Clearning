#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
using namespace std;

enum Gender {
    MALE,
    FEMALE
};

class Player {
private:
    string name;
    int age;
    Gender gender;

public:
    Player(string name, int age, Gender gender);
    void display();
    int getAge() const;
    string getName() const;
    Gender getGender() const;
    bool operator<(const Player& other) const {
        return name < other.name;
    }
};
#endif