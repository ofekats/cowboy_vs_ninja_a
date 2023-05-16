#pragma once
#include "Team.hpp"

namespace ariel
{
    class Team2 : public Team
    {
    public:
        Team2(Character * leader);
        virtual void add(Character *chara);
        virtual void attack(Team *enemy_team);
        virtual int stillAlive();
        virtual void print();
    };
}