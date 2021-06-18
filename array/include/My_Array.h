#ifndef MY_ARRAY_H
#define MY_ARRAY_H
//dynamic array -- vector in C++
typedef int elemType;
static const int MinCapacity = 16;
static const int GrowthFactor = 2;
static const int ShrinkFactor = 4;

class MyArray
{
public:
    MyArray(int capacity);
    ~MyArray();
    int size() const;
    int capacity() const;
    bool is_empty() const;
    elemType at(int index) const;//peek the index
    void push(elemType item);
    void insert(int index, elemType item);
    void prepend(elemType item);//insert on the front
    elemType pop();
    void remove(int index);
    int find(elemType item) const;
private:
    elemType *arr;
    int _size{0};
    int _capacity{MinCapacity};
    void ResizeCapacity(int new_capacity);
    void ResizeForSize(int new_size);
};

#endif