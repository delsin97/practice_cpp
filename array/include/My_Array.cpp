#include "My_Array.h"
#include <iostream>

MyArray::MyArray(int capacity)
{
    if(capacity < 1)
    {
        std::cout << "Cannot make array of that size" << std::endl;
        exit(EXIT_FAILURE);
    }
    if(capacity > MinCapacity)
        _capacity = capacity;
    _size = 0;
    arr = new elemType[_capacity];
}

MyArray::~MyArray()
{
    delete arr;
}

int MyArray::size() const
{
    return _size;
}

int MyArray::capacity() const
{
    return _capacity;
}

bool MyArray::is_empty() const
{
    return _size == 0;
}

elemType MyArray::at(int index) const
{
    return *(arr + index);
}

void MyArray::push(elemType item)
{
    if(_size == _capacity)
        ResizeCapacity(_capacity * 2);
    *(arr + _size) = item;
    _size += 1;
}

void MyArray::ResizeCapacity(int new_capacity)
{
    _capacity = new_capacity;
    elemType *new_arr = new elemType[new_capacity];
    for(int i = 0; i < _size; i++)
    {
        new_arr[i] = arr[i];
    }
    delete []arr;
    arr = new_arr;
}

void MyArray::ResizeForSize(int new_size)
{
    if(new_size > _capacity)
        ResizeCapacity(_capacity * GrowthFactor);
    else if(_size < _capacity / ShrinkFactor)
        ResizeCapacity(_capacity / GrowthFactor);
    _size = new_size;
}

void MyArray::insert(int index, elemType item)
{
    if(index < 0 || index >= _size)
    {
        std::cout << "Index out of bounds." << std::endl;
        exit(EXIT_FAILURE);
    }
    ResizeForSize(_size + 1);
    for(int i = _size; i > index; i--)
        arr[i] = arr[i-1];
    arr[index] = item;
}

void MyArray::prepend(elemType item)
{
    insert(0, item);
}

elemType MyArray::pop()
{
    if(!_size)
    {
        std::cout << "no element in the array." << std::endl;
        exit(EXIT_FAILURE);
    }
    elemType elem = *(arr + _size - 1);
    *(arr + _size) = 0;
    ResizeForSize(_size - 1);
    if(_size < _capacity / 4 && _size > MinCapacity)
        ResizeCapacity(_capacity / 2);
    return elem;
}

void MyArray::remove(int index)
{
    if(index < 0 || index > _size)
    {
        std::cout << "index out of range" << std::endl;
        exit(EXIT_FAILURE);
    }
    for(int i = index; i < _size; i++)
        *(arr + i) = *(arr + i + 1);
    *(arr + _size) = 0;
    ResizeForSize(_size - 1);
    if(_size < _capacity / 4 && _size > MinCapacity)
        ResizeCapacity(_capacity / 2);
}

int MyArray::find(elemType item) const
{
    for(int i = 0; i < _size; i++)
        if(item == *(arr + i))
            return i;
    return -1;
}



