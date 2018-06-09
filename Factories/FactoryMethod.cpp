#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>


enum class PointType
{
    cartesian,
    polar
};

// NOthing in the API clearly describes what needs to be done here.
// It's not the best way to achieve this.

// class Point
// {
// public:
//     float x, y;

//     Point(const float a, const float b, PointType type = PointType::cartesian)
//         : x{x}, y{y}
//     {
//         if (type == PointType::cartesian)
//         {
//             x = a;
//             y = b;
//         }
//         else
//         {
//             x = a * cos(a);
//             y = b * sin(b);
//         }

//     }


// };


// The parameter names and the name of the factory method suggest what the API is expecting.

class Point
{
    //Private is optional, but a good idea to do it.
    Point(const float x, const float y)
      : x{x}, y{y}
    {
    }

public:
    float x, y;

    // Name of the method and the parameter names indicate what 
    // kind of initialization is being done
    static Point NewCartesian(const float x, const float y)
    {
        return {x, y};
    }
    
    static Point NewPolar(const float r, const float theta)
    {
        return {r*cos(theta), r*sin(theta)};
    }

    friend std::ostream& operator <<(std::ostream& os, const Point obj)
    {
        return os
            << "x: " << obj.x << "  "
            << "y: " << obj.y << std::endl;
    }

};

int main()
{
    // Will not work since the constructor is private.
    // Point p{1, 2};

    auto c = Point::NewCartesian(1, 2);
    std::cout << c << std::endl;

    auto p = Point::NewPolar(5, M_PI_4);
    std::cout << p << std::endl;

    return 0;
}