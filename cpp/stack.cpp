#include "../h/stack.h"

template<typename T, int step>
bool Stack<T, step>::isNotAllocated() const 
{
    return this->arr == nullptr;
}

template<typename T, int step>
bool Stack<T, step>::isFool() const
{
    return this->count == this->capacity;
}

template<typename T, int step>
void Stack<T, step>::relocateMemory()
{
     if (this->arr == nullptr)
        {
            this->arr = new T[step];
            this->capacity = step;

            return;
        }

        this->capacity = this->count + step;

        T* temp = new T[this->capacity];
        for (int i{}; i < this->count; ++i)
            temp[i] = this->arr[i];

        delete[] this->arr;
        this->arr = temp;
}

template<typename T, int step>
Stack<T, step>::Stack() :
    count{ 0 },
    arr{ nullptr },
    capacity{ 0 }
{}

template<typename T, int step>
Stack<T, step>::Stack(const Stack<T, step> &obj) :
    count{ obj.count },
    arr{ new T[obj.capacity] },
    capacity{ obj.capacity }
{
    for (int i{}; i < obj.count; ++i)
        this->arr[i] = obj.arr[i];
}

template<typename T, int step>
Stack<T, step>::Stack(Stack<T, step> &&obj) :
    count{ obj.count },
    arr{ obj.arr },
    capacity{ obj.capacity }
{
    obj.arr = nullptr;
}

template<typename T, int step>
Stack<T, step>& Stack<T, step>:: operator=(const Stack<T, step> &obj)
{
    if (this == &obj)
        return *this;
    
    if (this->arr != nullptr)
        delete[] this->arr;

    this->count = obj.count;
    this->arr = new T[obj.capacity];
    this->capacity = obj.capacity;
    

    return *this;
}

template<typename T, int step>
Stack<T, step>& Stack<T, step>::operator=(Stack<T, step> &&obj)
{
    if (this == &obj)
        return *this;

    if (this->arr!= nullptr)
        delete[] this->arr;

    this->count = obj.count;
    this->arr = obj.arr;
    this->capacity = obj.capacity;

    obj.arr = nullptr;

    return *this;
}

template<typename T, int step>
void Stack<T, step>::push(const T &value)
{
    if (this->isNotAllocated() || this->isFool()) 
        this->relocateMemory();

    this->arr[this->count] = value;

    ++this->count;
}

template<typename T, int step>
const T& Stack<T, step>::pop()
{
    if (!isEmpty())
    {
        --this->count;
        return this->arr[count];
    }

    return T{}; // TODO: throw exception
}

template<typename T, int step>
const T& Stack<T, step>::peak() const
{
    if (!isEmpty())
        return this->arr[this->count - 1];

    return T{}; // TODO: throw exception
}

template<typename T, int step>
bool Stack<T, step>::isEmpty() const
{
    return this->count == 0;
}

template<typename T, int step>
int Stack<T, step>::getCount() const
{
    return this->count;
}

template<typename T, int step>
int Stack<T, step>::getCapacity() const
{
    return this->capacity;
}

template<typename T, int step>
void Stack<T, step>::show() const
{
    std::cout << "apacity = " << this->capacity << std::endl;
    std::cout << "count = " << this->count << std::endl;
    std::cout << "arr: ";

    for (int i{}; i < this->count; ++i){
        std::cout << this->arr[i] << " ";
    }

    std::cout << std::endl << std::endl;
}

template<typename T, int step>
Stack<T, step>::~Stack()
{
    if (this->arr != nullptr)
        delete[] this->arr;
}