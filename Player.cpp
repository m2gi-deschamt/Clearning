#include "Player.hpp"

Player::Player(string name, int age, Gender gender) {
    this->name = name;
    this->age = age;
    this->gender = gender;
}

void Player::display() {
    cout << "Name: " << name << ", Age: " << age << ", Gender: ";
    if (gender == MALE) cout << "Male";
    else cout << "Female";
    cout << endl;
}