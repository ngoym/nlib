#include <iostream>
#include <stdlib.h>
#include "Array.h"
#include "List.h"

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

void test_list(){
    List<int> list;
    cout << "List size : " << list.size() << endl;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_front(0);
    list.push_back(5);
    cout << "Value at index 3 : " << list.at(3) << endl;
    list.print();
    list.pop_front();
    list.pop_front();
    cout << "Poped front " << endl;
    list.print();
    list.pop_back();
    cout << "Poped back " << endl;
    list.print();
    list.reverse();
    cout << "Reversed list" << endl;
    list.print('r');
    cout << "Front value : " << list.front() << endl;
    cout << "Back value : " << list.back() << endl;
    list.reverse();
    list.print();
    cout << "Back value after reversing : " << list.back() << endl;
    list.erase(6);
    list.erase(2);
    cout << "erased index 2" << endl;
    list.print();
    list.erase(2);
    cout << "erased index 2" << endl;
    list.print();
    list.erase(1);
    cout << "erased index 2" << endl;
    list.print();
    cout << "List is empty : " << list.is_empty() << endl;
    list.insert(0,1);
    list.print();
    list.remove_value(1);
    cout << "List is empty : " << list.is_empty() << endl;
    list.print();
}

int main(){
    //test_array();
    test_list();
    system("pause");
    return 0;
}

