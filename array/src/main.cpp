#include <iostream>
#include "My_Array.h"

using namespace std;

int main()
{
    MyArray arr(32);
    cout << "capacity is: " <<arr.capacity() << endl;
    cout << "size is: " << arr.size() << endl;
    if(arr.is_empty())
        cout << "empty!" << endl;
    for(int i = 1; i < 34; i ++)
    {
        arr.push(i);
        cout << arr.at(i - 1) << " ";
    }
    cout << endl;
    cout << "capacity is: " <<arr.capacity() << endl;
    cout << "size is: " << arr.size() << endl;
    cout << "index is: " << arr.find(32) << endl;
    arr.prepend(22);
    cout << "the first number: " <<arr.at(0) << endl;
    cout << "size is: " << arr.size() << endl;
    cout << arr.pop() << endl;
    cout << "size is: " << arr.size() << endl;
    for(int i = 20; i > 0; i--)
        arr.remove(2);
    for(int i = 1; i < arr.size(); i ++)
    {
        cout << arr.at(i - 1) << " ";
    }
    cout << endl;
    cout << "capacity is: " <<arr.capacity() << endl;
    cout << "size is: " << arr.size() << endl;
}