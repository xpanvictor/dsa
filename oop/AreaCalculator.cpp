#include <iostream>
using namespace std;

class Circle {
private: int radius;

public: Circle(int r){
    radius = r;
}

void setRadius(int radius) {
    this->radius = radius;
}

int getRadius() {
    return radius;
}

};

class Utility {
public:
    double calculateArea(Circle c) {
        int r = c.getRadius();
        return 3.142 * r * r;
    }
};

int main(){
    // first take in circle radius
    int radius = 0;
    cout << "Enter the radius of the circle in cm: " << endl;
    cin >> radius;

    // princess code here
    Circle obj(radius);
    Utility c1;
    cout << "Area of the circle is " << c1.calculateArea(obj) << "cm2" << endl;
    return 0;
}