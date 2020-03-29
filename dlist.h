#ifndef DLIST_H
#define DLIST_H

#include "dnode.h"
#include "iterator.h"
#include "cstdlib"
using namespace std;


template <class T>
class dlist{
    public:
        typedef node_iterator<T> iterator;
        dlist(){
            head = tail = NULL;
        }

        void front_insert(const T &other); 
        void rear_insert(const T &other);
        void front_remove();
        void rear_remove();

        iterator begin(){
            return iterator(head);
        }
        iterator r_begin(){
            return iterator(tail);
        }
        iterator end(){
            return iterator(NULL);
        }
        iterator r_end(){
            return iterator(NULL);
        }
        void insert_before(const iterator &position, const T& data);
        void show();
        void reverse_show();

    private: 
        dnode<T> *head;
        dnode<T> *tail;
        int size();
};

template <class T>
void dlist<T>::front_insert(const T &item){
    if (head == NULL){
      dnode<T> * newItem = new dnode<T> (item, NULL, NULL);
        head = tail = newItem;
    }
    else if (head -> next() == NULL){
        dnode<T> * newItem = new dnode<T> (item, NULL, head);
        head -> set_previous(newItem);
        tail = head;
        head = newItem;
        
    }
    else {
        
        dnode<T> * newItem = new dnode<T> (item, NULL, head);
        head -> set_previous(newItem);
        head = newItem;
    }
   
}

template <class T>
void dlist<T>::rear_insert(const T& item){
    dnode<T> * newItem = new dnode<T> (item, NULL, NULL);
    if (head == NULL){
      
        head = tail = newItem;
    }
    else if (head -> next() == NULL){

        head -> set_next(newItem);
        tail = newItem;
        tail -> set_previous(head);
    }
    else {
        dnode<T> * cursor = head;
        while (cursor -> next() != NULL){
            cursor = cursor -> next();
        }
        cursor -> set_next(newItem);
        tail = newItem;
        tail -> set_previous(cursor);
    }
}

template <class T>
void dlist<T>::front_remove(){
    dnode<T> *rm_ptr = head;
    if (head == NULL) return;

    else if(size() == 1){ // one item list 
        tail = head = NULL;
    }
    else{
        head = head -> next();
        head -> set_previous(NULL);
    }
    delete rm_ptr;
}

template <class T>
void dlist<T>::rear_remove(){
    dnode<T> *rm_ptr = tail;
    if (tail == NULL) return;
  
    else if(size() == 1){
        tail = head = NULL;
    }
    else{
        tail = tail -> previous();
        tail -> set_next(NULL);
    }
    delete rm_ptr;
}

template <class T>
void dlist<T>::show(){
    if (head == NULL){
    cout << "No data entered" << endl;
  }
  else if (head -> next() == NULL)
  {
    cout << head -> data() << endl;
  }
  else {
    dnode<T> * cursor = head;
     cout << "Data: " << endl;
    while (cursor -> next() != NULL){
      cout << cursor -> data() << ", ";
      cursor = cursor -> next();
    }
      cout << cursor -> data() << endl;
    
  }
}

template <class T>
void dlist<T>::reverse_show(){
    if (head == NULL){
    cout << "No data entered" << endl;
  }
  else if (head -> next() == NULL)
  {
    cout << head -> data() << endl;
  }
  else {
    dnode<T> * cursor = head;
     cout << "Data: " << endl;
    while (cursor -> next() != NULL){
      cursor = cursor -> next();
    }
    while (cursor -> previous() != NULL){
      cout << cursor -> data() << ", ";
      cursor = cursor -> previous();
    }
      cout << cursor -> data() << endl;
    
  }
  
    
}

template <class T>
int dlist<T>::size(){
    dnode<T> *cursor;
    int i = 0;
    for(cursor = head; cursor != NULL; cursor = cursor -> next())
        i++;
    return i;
}

template <class T>
void dlist<T>::insert_before(const iterator &position, const T& data){

    dnode<T> *newData = new dnode<T> (data, NULL, NULL);  
    if (head == NULL) {
        head = tail = newData;
    }
    else{
        dnode<T> *cursor = position.current;
        dnode<T> *prev = cursor -> previous();

        if (cursor == head) { 
            newData -> set_next(head);
            head -> set_previous(newData);
            head = newData;
        }
        else {
            prev -> set_next (newData);
            newData -> set_previous (prev);
            newData -> set_next (cursor);
            cursor -> set_previous (newData);
        }
    }
}

#endif