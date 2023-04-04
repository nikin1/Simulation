#include <iostream>
#include <math.h>
#include <vector>


using namespace std;


class Coordinates {
private:
    int _x;
    int _y;
public:
    Coordinates() {
        _x = 0;
        _y = 0;
    };


    void set(int new_x, int new_y) {
        _x = new_x;
        _y = new_y;
    };

    int get_x() {
        return _x;
    };

    int get_y() {
        return _y;
    };

};

class Object
{
private:
    Coordinates Coordinate;
    vector <Coordinates> path;
public:
    vector <Coordinates> get_path() {
        return path;
    }


    void move(int delta_x, int delta_y);
    double find_distance(int dest_x, int dest_y);
    double path_length();

};


