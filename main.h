#include <iostream>
#include <math.h>
#include <vector>


using namespace std;


class Coordinates {
private:
    int _x;
    int _y;
    // for lab_5
    double _Lat; 
    double _Lon;

public:
    Coordinates() {
        _x = 0;
        _y = 0;
        _Lat = 0;
        _Lon = 0;
    };

    void set(int new_x, int new_y) {
        _x = new_x;
        _y = new_y;
    };

    void set_geo_value(double new_Lat, double new_Lon) {
        _Lat = new_Lat;
        _Lon = new_Lon;
    }

    int get_x() {
        return _x;
    };

    int get_y() {
        return _y;
    };

    double get_Lat() {
        return _Lat;
    };

    double get_Lon() {
        return _Lon;
    };


};

class Object
{
private:

protected:
    vector <Coordinates> path;
    Coordinates Coordinate;

public:
    vector <Coordinates> get_path() {
        return path;
    }

    void my_push_back() {
        path.push_back(Coordinate);
    };


    void move(int delta_x, int delta_y);
    double find_distance(int dest_x, int dest_y);
    double path_length();

};

class UserEquipment : public Object {

private:
    const double minLatitude = 54.758872; 
    const double maxLatitude = 55.106727; 
    const double minLongitude = 82.753928; 
    const double maxLongitude = 83.209037;


public:
    void Convert_to_geo();

};




