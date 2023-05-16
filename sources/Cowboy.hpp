#pragma once
#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
    public:
        Cowboy(string name, Point poi);//int hit, , int bullets);
        void shoot(Character *chara);
        bool hasboolets();
        void reload();

        //virtual
        virtual ~Cowboy() = default;
        virtual bool isAlive() override;
        virtual double distance(Character *chara) override;
        virtual void hit(int num) override;
        virtual string getName() override;
        virtual Point getLocation() override;
        virtual string print() override;

    private:
        int _num_of_bullets;
    };
}