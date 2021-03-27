#ifndef NLIB_LIST_H
#define NLIB_LIST_H
#include <iostream>
#include <cassert>

// linked list
template <typename T>
struct List
{
    struct node
    {
        T data;
        node* next;
        node* prev;
    };
    
    node * start;
    node * tail;
    int _size;

    List(){
        start = tail = nullptr;
        _size = 0;
    }
    ~List(){
        node * cur;
        while (start != nullptr){
            cur = start;
            start = start->next;
            free(cur);
        }
    }
    int size(){
        return _size;
    }
    bool is_empty(){
        assert(_size >= 0);
        if (_size == 0){
            return true;
        }
        else {
            return false;
        }
    }
    T at(int index){    
        if (index > _size){
            cerr << "Index out range. " << "Requested index is " << index << ", but list size is " << _size << endl;
            return 0;
        }
        node* nav;   
        if ((_size / 2) > index){
            // search from the head
            int count = 0;
            nav = start;
            while(nav != nullptr){
                if (count == index){
                    return nav->data;
                }
                nav = nav->next;
                count++;
            }
        }
        else {
            // search from the tail
            nav = tail;
            int count = 0;
            int target = _size - index;
            while (nav != nullptr){
                if (count == target){
                    return nav->data;
                }
                nav = nav->prev;
                count++;
            }             
        }
    }
    void push_back(T val){
        node* new_node = new node;
        new_node->next = nullptr;
        new_node->prev = nullptr;
        new_node->data = val;
        new_node->prev = tail;
        
        if (tail){
            tail->next = new_node;
            tail = new_node;
        }
        else{
            tail = new_node;
            start = new_node;
            tail->prev = start;
        }
        _size++;
    }
    void push_front(T val){
        node* new_node = new node;
        new_node->prev = nullptr;
        new_node->next = nullptr;
        new_node->data = val;
        new_node->next = start;
        start = new_node;
        _size++;
    }
    T pop_front(void){
        assert(_size > 0);
        node* tmp = start;
        if (start->next)
            start = start->next;
        else
            start->next = nullptr;
        start->prev = nullptr;
        T to_return = tmp->data;
        free(tmp);
        _size--;
        if (_size == 0){
            start = tail = nullptr;
        }
        return to_return;
    }
    T pop_back(void){
        assert(_size > 0);
        node* tmp = tail;
        if (tail->prev)
            tail = tail->prev;
        else 
            tail->prev = nullptr;
        tail->next = nullptr;
        T to_return = tmp->data;
        free(tmp);
        _size--;
        if (_size == 0){
            start = tail = nullptr;
        }
        return to_return;
    }
    void reverse(void){
        node* tmp = start;
        start = tail;
        tail = tmp;
    }
    T front(void){
        return start->data;
    }
    T back(void){
        return tail->data;
    }
    void erase(int index){
        if (index > _size){
            cerr << "Index out range. " << "Requested index is " << index << ", but list size is " << _size << endl;
            return;
        }
        if (index == 1 && _size == 2 || _size == 1){
            pop_front();
            return;
        }
        if (index == _size){
            pop_back();
            return;
        }
        node* nav;   
        if ((_size / 2) >= index){
            // search from the head
            int count = 0;
            nav = start;
            while(nav != nullptr){
                if (count == index){
                    node* tmp = nav->prev;
                    if (tmp){
                        tmp->next = nav->next;
                        nav->next->prev = tmp;
                    }
                    free(nav);
                    _size--;
                    return;
                }
                nav = nav->next;
                count++;
            }
        }
        else {
            // search from the tail
            nav = tail;
            int count = 0;
            int target = _size - index;
            while (nav != nullptr){
                if (count == target){
                    node* tmp = nav->prev;
                    if (tmp) {
                        tmp->next = nav->next;
                        nav->next->prev = tmp;
                    }
                    free(nav);
                    _size--;
                    return;
                }
                nav = nav->prev;
                count++;
            }             
        }
    }
    void remove_value(T val){
        node* nav = start;
        T data;
        while(nav != nullptr){
            data = nav->data;
            if (data == val){
                node* tmp = nav->prev;
                if (tmp){
                    tmp->next = nav->next;
                    nav->next->prev = tmp;
                }
                free(nav);
                _size--;
                if (_size == 0){
                    start = tail = nullptr;
                }
                return;
            }
            nav = nav->next;
        }
    }
    void insert(int index, T val){
        if (index > _size){
            cerr << "Index out range. " << "Requested index is " << index << ", but list size is " << _size << endl;
            return;
        }
        if (index == 0 || _size == 0){
            push_front(val);
            return;
        }
        if (index > _size){
            push_back(val);
            return;
        }
        node* nav;   
        if (ceil(_size / 2) > index){
            // search from the head
            int count = 0;
            nav = start;
            while(nav != nullptr){
                if (count == index){
                    node* new_node = new node;
                    new_node->next = nullptr;
                    new_node->prev = nullptr;
                    new_node->data = val;
                    new_node->next = nav->next;
                    nav->next = new_node;
                    new_node->prev = nav;
                    _size++;
                    return;
                }
                nav = nav->next;
                count++;
            }
        }
        else {
            // search from the tail
            nav = tail;
            int count = 0;
            int target = _size - index;
            while (nav != nullptr){
                if (count == target){
                    node* new_node = new node;
                    new_node->next = nullptr;
                    new_node->prev = nullptr;
                    new_node->data = val;
                    new_node->next = nav;
                    new_node->prev = nav->prev;
                    nav->prev = new_node;
                    _size++;
                    return;
                }
                nav = nav->prev;
                count++;
            }             
        }
    }
    void print(char c='f'){
        node* nav = start;
        while(nav != nullptr){
            cout << nav->data << " , ";
            if (c == 'f')
                nav = nav->next;
            else
                nav = nav->prev;
        }
        cout << " " << endl;
    }
};


#endif