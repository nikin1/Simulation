#include "Object.h"


double Object::find_distance(int dest_x, int dest_y) {
    int my_x = Coordinate.get_x();
    int my_y = Coordinate.get_y();

    int katet_1 = abs(dest_x - my_x);
    int katet_2 = abs(dest_y - my_y);

    double distance = sqrt(pow(katet_1, 2) + pow(katet_2, 2));

    return distance;
}

void Object::move(int delta_x, int delta_y) {
    int next_x = Coordinate.get_x() + delta_x;
    int next_y = Coordinate.get_y() + delta_y;
    
    if ((next_x <= 500 && next_x >= -500) && (next_y <= 500 && next_y >= -500)) {
        Coordinate.set(next_x, next_y);
    }

    path.push_back(Coordinate);
};


double Object::path_length() {
    return find_distance(0, 0);
}
