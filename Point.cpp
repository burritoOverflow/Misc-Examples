#include <iostream>
#include <math.h>
#include <cmath>
#include <tuple>

class Point
{
private:
    int x, y;

public:
    // default constructor creates a point at the origin
    Point() : x(0), y(0){};
    Point(int x, int y) : x(x), y(y){};

    Point &operator=(const Point &p)
    {
        return *this;
    }

    // accessor functions
    int getX() const
    {
        return this->x;
    }

    int getY() const
    {
        return this->y;
    }

    // mutator functions
    void setX(int x)
    {
        this->x = x;
    }

    void setY(int y)
    {
        this->y = y;
    }

    std::string strCoordinateRepresentation()
    {
        std::string strX = std::to_string(this->x);
        std::string strY = std::to_string(this->y);

        return "(" + strX + ", " + strY + ")";
    }

    // scales both coordinates by the value; negative values are allowed
    void translate(int t)
    {
        this->x += t;
        this->y += t;
    }

    // since points are represented as integers, we'll truncate the result of
    // the calculation here. Probably not the ideal approach.
    void rotate(double theta)
    {
        double xPrime = (this->x * cos(theta)) - (this->y * sin(theta));
        double yPrime = (this->x * sin(theta)) + (this->y * cos(theta));

        // truncate and store the result of the calculation
        this->x = std::round(xPrime);
        this->y = std::round(yPrime);
    }

    // Convert to polar coordinates; returns a tuple
    std::tuple<double, double> convertToPolarCoordinates()
    {
        double r = sqrt(pow(this->x, 2) + pow(this->y, 2));
        double theta = atan(this->y / this->x);

        return std::make_tuple(r, theta);
    }
};

double distanceBetweenTwoPoints(const Point p1, const Point p2)
{
    double xDistance = pow(p1.getX() - p2.getX(), 2);
    double yDistance = pow(p1.getY() - p2.getY(), 2);

    return sqrt(xDistance - yDistance);
}

int main()
{
    Point p(12, 31);
    p.translate(12);
    std::cout << p.strCoordinateRepresentation() << std::endl;

    Point p2 = p;

    std::cout << distanceBetweenTwoPoints(p, p2) << std::endl;

    p.setX(78);

    std::cout << p2.strCoordinateRepresentation() << std::endl;
    p2.rotate(20);
    std::cout << p2.strCoordinateRepresentation() << std::endl;

    auto polarCoords = p2.convertToPolarCoordinates();

    double r, theta;

    std::tie(r, theta) = polarCoords;

    std::cout << r << std::endl;
    std::cout << theta << std::endl;
}
