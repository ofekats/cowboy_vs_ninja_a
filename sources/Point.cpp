#include "Point.hpp"

using namespace ariel;

Point::Point(double x_poi, double y_poi)
: _x_point(x_poi), _y_point(y_poi){
}

double Point::distance(Point diff){
    return 1;
}

void Point::print(){
}

Point Point::moveTowards(Point scr, Point dst, double dis){
    return Point();
}