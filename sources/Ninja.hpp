#pragma once
#include "Character.hpp"

namespace ariel
{
    class Ninja: public Character
    {
    public:
        Ninja(string name, Point poi);//, int hit, , int speed);
        void move(Character *chara);
        void slash(Character *chara);

        // virtual
        virtual ~Ninja() = default;
        virtual bool isAlive() override;
        virtual double distance(Character *chara) override;
        virtual void hit(int num) override;
        virtual string getName() override;
        virtual Point getLocation() override;
        virtual string print() override;

    private:
        int _speed;
    };
}