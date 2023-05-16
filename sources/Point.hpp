#pragma once

namespace ariel
{
    class Point
    {
    public:
        Point(double x_poi = 0.0, double y_poi = 0.0);
        double distance(Point diff);
        void print();
        Point moveTowards(Point scr, Point dst, double dis);

    private:
        double _x_point;
        double _y_point;
    };
}