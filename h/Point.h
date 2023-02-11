#pragma once
#include <iostream>

template<class T>
class Point
{
private:
    T x;
    T y;

public:
    Point(const T& new_x, const T& new_y);

    Point(const Point& obj) = default;

    void setX(const T& new_x);

    void setY(const T& new_y);

    const T& getX() const;

    const T& getY() const;

    template<typename S>
    friend std::ostream& operator<<(std::ostream& out, const Point<S>& p);

    template<typename S>
    friend std::istream& operator>>(std::istream& in, Point<S>& p);
};