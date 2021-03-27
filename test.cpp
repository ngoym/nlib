#include <iostream>
#include <stdlib.h>
#include "Array.h"

using namespace std;

void test_array(){
    Array<int> arr(5);
    cout << "Size of array : " << arr.used << endl;
    cout << "Empty array   : " << arr.is_empty() << endl;
    cout << "Capacity      : " << arr.capacity() << endl;
    arr.push(1);
    arr.push(2);
    arr.push(3);
    arr.push(4);
    arr.push(5);
    arr.push(6);
    cout << "Size of array : " << arr.used << endl;
    cout << "Capacity      : " << arr.capacity() << endl;
    cout << "array at 2: " << arr.at(2) << endl;
    arr.print();
    cout << "Size of array : " << arr.used << endl;
    arr.pop();
    arr.print();
    cout << "Size of array : " << arr.used << endl;
    arr.insert(6,6);
    arr.print();
    cout << "Size of array : " << arr.used << endl;
    arr.pop();
    arr.insert(0,0);
    arr.print();
    cout << "Size of array : " << arr.used << endl;
    arr.delete_at(0);
    arr.print();
    cout << "Size of array : " << arr.used << endl;
    cout << "Index with element = 0: " << arr.find(0) << endl;
    cout << "Index with element = 3: " << arr.find(3) << endl;
    arr.push(1);
    arr.push(3);
    arr.push(3);
    arr.push(-1);
    arr.print();
    cout << "Size of array : " << arr.used << endl;
    arr.remove(3);
    arr.print();
    cout << "Size of array : " << arr.used << endl;
    arr.pop();
    arr.print();
    cout << "Size of array : " << arr.used << endl;

    Array<float> farr;
    farr.at(10);
}

int main(){
    test_array();
    system("pause");
    return 0;
}

