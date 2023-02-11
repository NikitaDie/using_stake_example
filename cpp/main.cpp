#include <iostream>

#include "./templates.cpp"

int main(){

    //Point<double> a{2.3, 3};


    //std::cout << "a = " << a << std::endl;

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
    stack.show();

    return 0;
}