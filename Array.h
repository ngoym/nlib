#ifndef NLIB_ARRAY_H
#define NLIB_ARRAY_H
#include <iostream>

using namespace std;

#define DEFAULT_BLOCK_SIZE 128

template <typename T>
struct Array
{
    size_t used;
    size_t _size;
    T* array;

    Array(){
        _size  = 0;
        used  = 0;
        array = 0;
    }
    Array(size_t sz){
        _size = sz;
        used = 0;
        T* tmp = (T*) malloc(sz * sizeof(T));
        if (tmp != nullptr)
            array = tmp;
        // TODO(nym) some error handling here
    }
    ~Array(){
        _size = 0;
        used = 0;
        if (array != nullptr){
            free(array);
        }
    }
    void print(){
        cout << "-------------------------" << endl;
        for (size_t i = 0; i < used; i++)
            cout << array[i] << " ";
        cout << "\n-------------------------" << endl;
    }
    void alloc(size_t mem_sz){
        T* tmp = (T*) realloc(array,mem_sz);
        if (tmp != nullptr){
            array = tmp;
            _size += mem_sz;
        }
        // TODO(nym) some error handling here
    }
    size_t size(){
        return used;
    }
    size_t capacity(){
        return _size;
    }
    bool is_empty(){
        bool to_return = false;
        if (used == 0)
            return true;
        return to_return;
    }
    T at(int i){
        if (i <= used)
            return array[i];
        // TODO(nym) some error handling here
    }
    void push(T item){
        if (is_empty() && _size == 0){
            alloc(DEFAULT_BLOCK_SIZE);
            array[used] = item;
            used++;
        }
        else {
            if (used == _size){
                alloc(DEFAULT_BLOCK_SIZE);
            }
            array[used] = item;
            used++;
        }
    }
    T pop(){
        if (!is_empty()){
            used--;
            return array[used];
        }
        // TODO(nym) some error handling here
    }
};


#endif