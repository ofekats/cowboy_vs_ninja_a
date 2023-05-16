#pragma once
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"

namespace ariel
{
    class Team
    {
    public:
        Team(Character * leader);
        virtual void add(Character *chara);
        virtual void attack(Team *enemy_team);
        virtual int stillAlive();
        virtual void print();

    private:
        Character *_leader;
    };
}