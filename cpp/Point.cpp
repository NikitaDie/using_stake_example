#include "../h/Point.h"

template<typename T>
Point<T>::Point(const T& new_x, const T& new_y) : 
    x{new_x}, 
    y{new_y}
{}

template<typename T>
void Point<T>::setX(const T& new_x){
    x = new_x;
}

template<typename T>
void Point<T>::setY(const T& new_y){
    y = new_y;
}

template<typename T>
const T& Point<T>::getX() const{
    return x;
}

template<typename T>
const T& Point<T>::getY() const{
    return y;
}

template<typename S>
std::ostream& operator<<(std::ostream& out, const Point<S>& p)
{
    out << "(" << p.x << "; " << p.y << ")";

    return out;
}

template<typename S>
std::istream& operator>>(std::istream& in, Point<S>& p)
{
    in >> p.x;
    in >> p.y;

    return in;
}