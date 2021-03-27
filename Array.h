#ifndef NLIB_ARRAY_H
#define NLIB_ARRAY_H
#include <iostream>

using namespace std;

#define DEFAULT_BLOCK_SIZE 1024

struct node{
    int pos;
    node * next;
};

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
        else{
            cerr << "Failed to allocate memory." << endl;
        }
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
        else{
            cerr << "Failed to allocate memory." << endl;
        }
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
        else {
            cerr << "Index out of bounds. Requested index is " << i << ", but array size is " << used << endl;
            return 0;
        }
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
        else{
            cerr << "Nothing to pop. Array is empty" << endl;
            return 0;
        }
    }
    void insert(T item, size_t pos){
        if (used + 1 >= _size){
            alloc(DEFAULT_BLOCK_SIZE);
        }
        if (pos >= used){
            array[used] = item;
            used++;
        }
        else{
            for(size_t i = used; i > pos; i--){
                array[i] = array[i-1];
            }
            array[pos] = item;
            used++;
        }
    }
    void delete_at(size_t pos){
        if (pos < used){
            for (size_t i = pos; i < used; i++){
                array[i] = array[i+1];
            }
            used--;
        }
    }
    int find(T item){
        int to_return = -1;
        for (int i = 0; i < used; i++){
            if (array[i] == item){
                to_return = i;
                break;
            }
        }
        return to_return;
    }
    void remove(T item){
        // Use a linked list to store positions to delete in order 
        // to keep this operation O(N) + a small constant.
        node *cur = NULL, *start = NULL;
        bool first = true;
        for (int i = 0; i < used; i++){
            if (array[i] == item){
                node *tmp = new node;
                tmp->pos = i;
                tmp->next = NULL;
                if (start == NULL){
                    start = tmp;
                    cur = tmp;
                    tmp = NULL;
                }
                else{
                    cur->next = tmp;
                    cur = tmp;
                }
            }
        }
        int counter = 1;
        while(start != NULL){
            if (first) {
                delete_at(start->pos);
                first = false;
            }
            else {
                delete_at(start->pos - counter);
                counter++;
            }
            cur = start;
            start = start->next;
            if (cur != NULL)
                free(cur);
        }
    }
};

#endif