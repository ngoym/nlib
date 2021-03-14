#include <iostream>
#include <stdlib.h>
#include "Array.h"

using namespace std;

int main(){
    Array<int> arr(5);
    cout << "Size of array : " << arr.used << endl;
    cout << "Empty array   : " << arr.is_empty() << endl;
    cout << "Capacity      : " << arr.capacity() << endl;
    arr.push(1);
    arr.push(2);
    arr.push(-1);
    arr.push(4);
    arr.push(5);
    arr.push(5);
    cout << "Size of array : " << arr.used << endl;
    cout << "Capacity      : " << arr.capacity() << endl;
    cout << "array at 2: " << arr.at(2) << endl;
    arr.print();
    arr.pop();
    cout << "Size of array : " << arr.used << endl;
    arr.print();
    arr.pop();
    cout << "Size of array : " << arr.used << endl;
    arr.print();
    arr.pop();
    arr.print();
    cout << "Size of array : " << arr.used << endl;
    arr.pop();
    cout << "Size of array : " << arr.used << endl;
    arr.pop();
    cout << "Size of array : " << arr.used << endl;
    arr.pop();
    arr.print();
    cout << "Size of array : " << arr.used << endl;
    arr.push(10);
    cout << "Size of array : " << arr.used << endl;
    arr.print();
    cout << "Capacity      : " << arr.capacity() << endl;
    system("pause");
    return 0;
}

