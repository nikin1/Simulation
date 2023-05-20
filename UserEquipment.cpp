#include "main.h"


void UserEquipment::Convert_to_geo() {

    // в этой функции мы сопостовляем нашу карту 100 * 100, с долготой и широтой
    const double delta_Longitube = maxLongitude - minLongitude;
    const double delta_Latitube = maxLatitude - minLatitude; 

    // считаем координаты центра. На карте это (0,0)
    const double centerLatitude = (maxLatitude + minLatitude) / 2;
    const double centerLongitude = (maxLongitude + minLongitude) / 2;

    // cout << "centerLatitude: " << centerLatitude << "\t" << "centerLongitude: " << centerLongitude << endl;

    // шаг на карте - это 1.
    const double step = (delta_Longitube) / 100; // because our map 100 x 100


    // наша координата является коэффицентом для умножения на шаг
    int koef_x = Coordinate.get_x();
    int koef_y = Coordinate.get_y();

    
    // насколько мы смешаемся от центра
    double Lat = koef_x * step + centerLatitude;
    double Long = koef_y * step + centerLongitude;

    // cout << "(" << Lat << ", " << Long << ")\n";

    Coordinate.set_geo_value(Lat, Long);
    // Т.к. мы посчитали координаты гео, то обновляем значение объекта класса Coordinate в списке
    path.pop_back();
    path.push_back(Coordinate);
}




