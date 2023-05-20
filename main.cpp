#include "main.h"

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

    UserEquipment User1;

    
    srand(time(NULL));
    for (int i = 0; i < cnt1; i++)
    {
        int step_x = 0;
        int step_y = 0;
        
        while (step_x == 0 && step_y == 0) {
            step_x = random_num();
            step_y = random_num();
        }

        User1.move(step_x, step_y);
        User1.Convert_to_geo();
    }

    vector <Coordinates> path = User1.get_path();


    cout << "PATH: " << endl;
    for (int i = 0; i < cnt1; i++) {
        Coordinates temp = path[i];

        int x = temp.get_x();
        int y = temp.get_y();


        double Lat = temp.get_Lat();
        double Lon = temp.get_Lon();


        cout << "(" << x << ", " << y << "), ";
        cout << "(" << Lat << ", " << Lon << ")\n";


    }
    cout << "\n";

    cout << "Length path: " << User1.path_length() << endl;

    return 0;
}


