#include "Ninja.hpp"
#include "Character.hpp"

using namespace std;
using namespace ariel;

Ninja::Ninja(string name, Point poi)//, int hit, , int speed)
: Character(name, poi){
    _speed =0;
}

void Ninja::move(Character *chara){
}

void Ninja::slash(Character *chara){
}

// virtual
// virtual Ninja::~Ninja() = default;
bool Ninja::isAlive(){
    return true;
}

double Ninja::distance(Character *chara){
    return 0;
}

void Ninja::hit(int num){
}

string Ninja::getName(){
    return "name";
}
Point Ninja::getLocation(){
    return Point();
}

string Ninja::print(){
    return "print";
}