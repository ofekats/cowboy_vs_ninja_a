#include "Cowboy.hpp"
#include "Character.hpp"
#include "Point.hpp"
#include <iostream>

using namespace std;
using namespace ariel;

Cowboy::Cowboy(string name, Point poi)//, int hit, , int bullets)
: Character(name, poi), _num_of_bullets(0) {
}

void Cowboy::shoot(Character *chara){
}

bool Cowboy::hasboolets(){
    return true;
}

void Cowboy::reload(){
}

// virtual
// virtual Cowboy::~Cowboy(){}
bool Cowboy::isAlive(){
    return true;
}

double Cowboy::distance(Character *chara){
    return 0;
}

void Cowboy::hit(int num){
}

string Cowboy::getName(){
    return "name";
}

Point Cowboy::getLocation(){
    return Point();
}

string Cowboy::print(){
    return "print";
}