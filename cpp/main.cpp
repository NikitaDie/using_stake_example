#include <iostream>

#include "./templates.cpp"

int main(){

    /*Point<double> a{2.3, 3};


    std::cout << "a = " << a << std::endl;

    Stack<int, 3> stack{};
    stack.push(45);
    stack.push(23);
    stack.push(12);
    stack.push(67);
    stack.show();

    int item{ stack.pop() };
    std::cout << item << '\n';
    stack.show();

    std::cout << stack.peak() << '\n';
    stack.show();*/

    Stack<Point<int>*, 10> stack{};

    Point<int>* p_a = new Point<int>{2, 3};

    stack.push(p_a);

    stack.show();

    stack.push( new Point<int>{1, 3});

    stack.show();

    return 0;
}