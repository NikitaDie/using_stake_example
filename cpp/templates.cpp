#include <iostream>

#include "../h/Point.h"
#include "./Point.cpp"

#include "../h/stack.h"
#include "./stack.cpp"

template 
class Point<int>;

template 
class Point<double>;

template 
class Stack<int, 5>;

template 
class Stack<double, 5>;

template 
class Stack<std::string, 5>;

/*template
class Stack<Point<int>, 5>;*/