#include "doctest.h"
#include "sources/Point.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Ninja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/OldNinja.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"

using namespace ariel;

TEST_CASE("Point checks")
{
    // create 3 new points
    Point a_point(1.7, 6);
    Point b_point(1.7, 6.0);
    CHECK_NOTHROW(Point());
    // distance checks
    CHECK(a_point.distance(b_point) == b_point.distance(a_point));
    CHECK_NOTHROW(a_point.distance(a_point));
    // print
    CHECK_NOTHROW(a_point.print());
    // moveTowards
    CHECK_NOTHROW(a_point.moveTowards(a_point, b_point, 2.7));
}

//Cowboy

TEST_CASE("Cowboy checks - is alive")
{
    // create new cowboy
    Point a(32.3, 44);
    Cowboy *tom = new Cowboy("Tom", a);
    // is alive
    CHECK(tom->isAlive() == true);
}

TEST_CASE("Cowboy checks - distance")
{
    // create 2 new cowboy
    Point a(32.3, 44);
    Cowboy *tom = new Cowboy("Tom", a);
    Cowboy *danny = new Cowboy("Danny", a);
    // distance
    CHECK_NOTHROW(tom->distance(danny));
    CHECK(tom->distance(danny) == danny->distance(tom));
    CHECK_NOTHROW(tom->distance(tom));
}

TEST_CASE("Cowboy checks - hit")
{
    // create new cowboy
    Point a(32.3, 44);
    Cowboy *tom = new Cowboy("Tom", a);
    // hit
    CHECK_NOTHROW(tom->hit(5));
}

TEST_CASE("Cowboy checks - getName , getLocation")
{
    // create new cowboy
    Point a(32.3, 44);
    Cowboy *tom = new Cowboy("Tom", a);
    // gets
    CHECK_NOTHROW(tom->getName());
    CHECK_NOTHROW(tom->getLocation());
}

TEST_CASE("Cowboy checks - print")
{
    // create new cowboy
    Point a(32.3, 44);
    Cowboy *tom = new Cowboy("Tom", a);
    // print
    CHECK_NOTHROW(tom->print());
}

TEST_CASE("Cowboy checks - shoot")
{
    // create 2 new cowboy
    Point a(32.3, 44);
    Cowboy *tom = new Cowboy("Tom", a);
    Cowboy *danny = new Cowboy("Danny", a);
    // shoot
    CHECK_NOTHROW(tom->shoot(danny));
    CHECK_NOTHROW(danny->shoot(tom));
    //can't shoot at himself
    CHECK_THROWS(tom->shoot(tom));
}

TEST_CASE("Cowboy checks - hasboolets , reload")
{
    // create 2 new cowboy
    Point a(32.3, 44);
    Cowboy *tom = new Cowboy("Tom", a);
    Cowboy *danny = new Cowboy("Danny", a);
    // hasboolets
    CHECK(tom->hasboolets() == true);
    for(int i=0; i< 6; ++i){
        tom->shoot(danny);
    }
    CHECK(tom->hasboolets() == false);
    CHECK_NOTHROW(danny->reload());
    CHECK(tom->hasboolets() == true);
}

//Ninja

TEST_CASE("Ninja checks - is alive")
{
    // create 3 new Ninjas
    Point a(32.3, 44);
    YoungNinja *tom = new YoungNinja("Tom", a);
    TrainedNinja *tom2 = new TrainedNinja("Tom2", a);
    OldNinja *tom3 = new OldNinja("Tom3", a);
    // is alive
    CHECK(tom->isAlive() == true);
    CHECK(tom2->isAlive() == true);
    CHECK(tom3->isAlive() == true);
}

TEST_CASE("Ninja checks - distance")
{
    // create 3 new Ninjas
    Point a(32.3, 44);
    YoungNinja *tom = new YoungNinja("Tom", a);
    TrainedNinja *tom2 = new TrainedNinja("Tom2", a);
    OldNinja *tom3 = new OldNinja("Tom3", a);
    // distance
    CHECK_NOTHROW(tom->distance(tom2));
    CHECK_NOTHROW(tom3->distance(tom));
    CHECK(tom->distance(tom2) == tom2->distance(tom));
    CHECK_NOTHROW(tom->distance(tom));
}

TEST_CASE("Ninja checks - hit")
{
    // create 3 new Ninjas
    Point a(32.3, 44);
    YoungNinja *tom = new YoungNinja("Tom", a);
    TrainedNinja *tom2 = new TrainedNinja("Tom2", a);
    OldNinja *tom3 = new OldNinja("Tom3", a);
    // hit
    CHECK_NOTHROW(tom->hit(5));
    CHECK_NOTHROW(tom2->hit(5));
    CHECK_NOTHROW(tom3->hit(5));
}

TEST_CASE("Ninja checks - getName , getLocation")
{
    // create 3 new Ninjas
    Point a(32.3, 44);
    YoungNinja *tom = new YoungNinja("Tom", a);
    TrainedNinja *tom2 = new TrainedNinja("Tom2", a);
    OldNinja *tom3 = new OldNinja("Tom3", a);
    // gets
    CHECK_NOTHROW(tom->getName());
    CHECK_NOTHROW(tom->getLocation());
    CHECK_NOTHROW(tom2->getName());
    CHECK_NOTHROW(tom2->getLocation());
    CHECK_NOTHROW(tom3->getName());
    CHECK_NOTHROW(tom3->getLocation());
}

TEST_CASE("Ninja checks - print")
{
    // create 3 new Ninjas
    Point a(32.3, 44);
    YoungNinja *tom = new YoungNinja("Tom", a);
    TrainedNinja *tom2 = new TrainedNinja("Tom2", a);
    OldNinja *tom3 = new OldNinja("Tom3", a);
    // print
    CHECK_NOTHROW(tom->print());
    CHECK_NOTHROW(tom2->print());
    CHECK_NOTHROW(tom3->print());
}

TEST_CASE("Ninja checks - move")
{
    // create 3 new Ninjas
    Point a(32.3, 44);
    YoungNinja *tom = new YoungNinja("Tom", a);
    TrainedNinja *tom2 = new TrainedNinja("Tom2", a);
    OldNinja *tom3 = new OldNinja("Tom3", a);
    // move
    CHECK_NOTHROW(tom->move(tom2));
    CHECK_NOTHROW(tom2->move(tom3));
    CHECK_NOTHROW(tom3->move(tom));
    //can't move towards himself
    CHECK_THROWS(tom3->move(tom3));
}

TEST_CASE("Ninja checks - slash")
{
    // create 3 new Ninjas
    Point a(32.3, 44);
    YoungNinja *tom = new YoungNinja("Tom", a);
    TrainedNinja *tom2 = new TrainedNinja("Tom2", a);
    OldNinja *tom3 = new OldNinja("Tom3", a);
    // slash
    CHECK_NOTHROW(tom->slash(tom2));
    CHECK_NOTHROW(tom2->slash(tom3));
    CHECK_NOTHROW(tom3->slash(tom));
    //can't slash himself
    CHECK_THROWS(tom3->slash(tom3));
}

//Cowboy and Ninja

TEST_CASE("Cowboy&Ninja checks - distance")
{
    // create new cowboy and 3 ninjas
    Point a(32.3, 44);
    Cowboy *danny = new Cowboy("Danny", a);
    YoungNinja *tom = new YoungNinja("Tom", a);
    TrainedNinja *tom2 = new TrainedNinja("Tom2", a);
    OldNinja *tom3 = new OldNinja("Tom3", a);
    // distance
    CHECK_NOTHROW(tom->distance(danny));
    CHECK_NOTHROW(tom2->distance(danny));
    CHECK_NOTHROW(tom3->distance(danny));
    CHECK(tom->distance(danny) == danny->distance(tom));
}

TEST_CASE("Cowboy&Ninja checks - shoot")
{
    // create new cowboy and 3 ninjas
    Point a(32.3, 44);
    Cowboy *danny = new Cowboy("Danny", a);
    YoungNinja *tom = new YoungNinja("Tom", a);
    TrainedNinja *tom2 = new TrainedNinja("Tom2", a);
    OldNinja *tom3 = new OldNinja("Tom3", a);
    // shoot
    CHECK_NOTHROW(danny->shoot(tom));
    CHECK_NOTHROW(danny->shoot(tom2));
    CHECK_NOTHROW(danny->shoot(tom3));
}


TEST_CASE("Cowboy&Ninja checks - move")
{
    // create new cowboy and 3 ninjas
    Point a(32.3, 44);
    Cowboy *danny = new Cowboy("Danny", a);
    YoungNinja *tom = new YoungNinja("Tom", a);
    TrainedNinja *tom2 = new TrainedNinja("Tom2", a);
    OldNinja *tom3 = new OldNinja("Tom3", a);
    // move
    CHECK_NOTHROW(tom->move(danny));
    CHECK_NOTHROW(tom2->move(danny));
    CHECK_NOTHROW(tom3->move(danny));
}

TEST_CASE("Cowboy&Ninja checks - slash")
{
    // create new cowboy and 3 ninjas
    Point a(32.3, 44);
    Cowboy *danny = new Cowboy("Danny", a);
    YoungNinja *tom = new YoungNinja("Tom", a);
    TrainedNinja *tom2 = new TrainedNinja("Tom2", a);
    OldNinja *tom3 = new OldNinja("Tom3", a);
    // slash
    CHECK_NOTHROW(tom->slash(danny));
    CHECK_NOTHROW(tom2->slash(danny));
    CHECK_NOTHROW(tom3->slash(danny));
}

//Team

TEST_CASE("Teams checks - create Team")
{
    //create 2 leaders
    Point a(32.3,44);
    Cowboy *tom = new Cowboy("Tom", a);
    // create new Team
    Team team_A(tom); 
    //can't be a leader of more then 1 team
    CHECK_THROWS(Team2(tom));
}

TEST_CASE("Teams checks - add")
{
    //create 2 leaders
    Point a(32.3,44),b(1.3,3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    // create 2 new Teams
    Team team_A(tom);
    Team2 team_B(sushi); 
    //create new TrainedNinja
    TrainedNinja *danny = new TrainedNinja("Danny", b);
    //add
    CHECK_NOTHROW(team_A.add(danny));
    //cant be added twice
    CHECK_THROWS(team_A.add(danny));
    //cant be in more then 1 team
    CHECK_THROWS(team_B.add(danny));
    //create new YoungNinja
    YoungNinja *danny2 = new YoungNinja("Danny2", b);
    //add
    CHECK_NOTHROW(team_B.add(danny2));
}

TEST_CASE("Teams checks - attack")
{
    //create 2 leaders
    Point a(32.3,44),b(1.3,3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    // create 2 new Teams
    Team team_A(tom);
    Team2 team_B(sushi); 
    //create new ninjas
    TrainedNinja *danny = new TrainedNinja("Danny", b);
    YoungNinja *danny2 = new YoungNinja("Danny2", b);
    //add
    team_A.add(danny);
    team_B.add(danny2);
    //attack
    CHECK_NOTHROW(team_A.attack(&team_B));
    CHECK_NOTHROW(team_B.attack(&team_A));
    //can't attack it self
    CHECK_THROWS(team_A.attack(&team_A));
    CHECK_THROWS(team_B.attack(&team_B));
}

TEST_CASE("Teams checks - stillAlive")
{
    //create 2 leaders
    Point a(32.3,44),b(1.3,3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    // create 2 new Teams
    Team team_A(tom);
    Team2 team_B(sushi); 
    //create new ninjas
    TrainedNinja *danny = new TrainedNinja("Danny", b);
    YoungNinja *danny2 = new YoungNinja("Danny2", b);
    //add
    team_A.add(danny);
    team_B.add(danny2);
    //stillAlive
    CHECK_NOTHROW(team_A.stillAlive());
    CHECK_NOTHROW(team_B.stillAlive());
}

TEST_CASE("Teams checks - print")
{
    //create 2 leaders
    Point a(32.3,44),b(1.3,3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    // create 2 new Teams
    Team team_A(tom);
    Team2 team_B(sushi); 
    //create new ninjas
    TrainedNinja *danny = new TrainedNinja("Danny", b);
    YoungNinja *danny2 = new YoungNinja("Danny2", b);
    //add
    team_A.add(danny);
    team_B.add(danny2);
    //print
    CHECK_NOTHROW(team_A.print());
    CHECK_NOTHROW(team_B.print());
}
