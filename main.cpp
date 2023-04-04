#include "Object.h"


int random_num() {

    int number = rand() % 2;

    int sign_num = 1 + rand() % 10;
    int sign = (sign_num % 2 == 0) ? 1 : -1;
    number *= sign;

    return number;
}

int main() {

    Object Object;

    int cnt1 = 10;

    
    srand(time(NULL));
    for (int i = 0; i < cnt1; i++)
    {
        int step_x = 0;
        int step_y = 0;
        
        while (step_x == 0 && step_y == 0) {
            step_x = random_num();
            step_y = random_num();
        }

        Object.move(step_x, step_y);        
        // cout << "x: " << step_x << "\n" << "y: " << step_y << endl;
    }

    vector <Coordinates> path = Object.get_path();

    cout << "PATH: " << endl;
    for (int i = 0; i < cnt1; i++) {
        Coordinates temp = path[i];

        int x = temp.get_x();
        int y = temp.get_y();

        cout << "(" << x << ", " << y << "), ";

    }
    cout << "\n";

    cout << "Length path: " << Object.path_length() << endl;

    return 0;
}
