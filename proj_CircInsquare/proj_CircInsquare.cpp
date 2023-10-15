#include <iostream>
using namespace std;

class Circle
{
protected:
    double rad;
public:
    Circle(double u_rad) : rad(u_rad) {}
    double getArea() const
    {
        return 3.14159 * (rad * rad);
    }
};
class Square
{
protected:
    double side;
public:
    Square(double u_side) : side(u_side) {}
    double getArea() const
    {
        return side * side;
    }
};

class CircleInSquare : public Square, public Circle
{
public:
    CircleInSquare(double u_side, double u_rad) : Square(u_side), Circle(u_rad) {}
    double getSquareArea() const
    {
        return Square::getArea();
    }
    double getCircleArea() const
    {
        return Circle::getArea();
    }
    void isInSquare() const
    {
        if (Circle::getArea() >= Square::getArea())
        {
            cout << "Circle doesn't fit inside the square.";
        }
        else
        {
            cout << "Circle fits inside the square.";
        }
    }
};

int main()
{
    double side = 9, rad = 3;

    CircleInSquare obj(side, rad);
    cout << "Square: " << obj.getSquareArea() << endl;
    cout << "Circle: " << obj.getCircleArea() << endl;

    obj.isInSquare();
}