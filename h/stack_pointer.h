#pragma once
#include "../h/stack.h"

template<typename T, int step>
class Stack<T*, step>
{
private:
    int count;
    T** arr;
    int capacity;

    bool isNotAllocated() const;

    bool isFool() const;

    void freeMemory();

    void relocateMemory();

public:

    Stack();

    Stack(const Stack& obj);

    Stack(Stack&& obj);

    Stack& operator=(const Stack& obj);

    Stack& operator=(Stack&& obj);

    void push(T* value);

    const T& pop();

    const T& peak() const;

    bool isEmpty() const;

    int getCount() const;

    int getCapacity() const;

    void show() const;

    ~Stack();
};