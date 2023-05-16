#pragma once
#include "Point.hpp"
#include <string>

using namespace std;

namespace ariel
{
    class Character
    {
    public:
        Character(string name, Point poi, int hit=0)
        :_location(poi), _hit_points(hit), _name(name){}

        virtual ~Character() = default;
        virtual bool isAlive() =0;
        virtual double distance(Character *chara) =0;
        virtual void hit(int num) =0;
        virtual string getName() =0;
        virtual Point getLocation() =0;
        virtual string print() =0;
    private:
        Point _location;
        int _hit_points;
        string _name;
    };
}