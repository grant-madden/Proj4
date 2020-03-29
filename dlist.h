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

        // Big 3
        ~dlist();
        dlist(const dlist& other);
        void operator =(const dlist& other);

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
        void insert_after(iterator &position, const T& data);
        void remove(iterator &position);
        void show();
        void reverse_show();
        int size();

    private: 
        dnode<T> *head;
        dnode<T> *tail;
        
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
    dnode<T> *cursor = head;
    head = head -> next();
    head -> set_previous(NULL);
    delete cursor;
}

template <class T>
void dlist<T>::rear_remove(){
    dnode<T> *cursor = head;
    tail = tail -> previous();
    tail -> set_next(NULL);
    delete cursor;
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
    int size = 0;
    for(cursor = head; cursor != NULL; cursor = cursor -> next()){
        size++;
    }
    return size;
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

template <class T>
void dlist<T>::insert_after(iterator &position, const T& data){
    dnode<T> *newData = new dnode<T> (data, NULL, NULL);
    if (head == NULL) {
        head = tail = newData;
    }
    else {
        if (head -> next() == NULL){
            head ->set_next(newData);
            tail = newData;
            tail -> set_previous(head);
        }
        else {
            dnode<T> *cursor = position.current;
            dnode<T> *next = cursor -> next();

            next -> set_previous(newData);
            cursor -> set_next(newData);

            newData -> set_next(next);
            newData -> set_previous(cursor);
        }
    }
}

template <class T>
void dlist<T>::remove(iterator &position){
    dnode<T> *cursor = position.current;
    if (cursor == NULL){
      cout << "No data to remove" << endl;
    }
    else if (cursor -> next() == NULL){
        head = tail = NULL;
        delete cursor;
    }
    else {
        if (cursor == head){
          head = cursor -> next();
          head -> set_previous(NULL);
          delete cursor;
        }
        else {
          dnode<T> *previous = cursor -> previous();
          dnode<T> *next = cursor -> next();
          previous -> set_next(next);
          next -> set_previous(previous);
          delete cursor;
        }

    }
}

template <class T>
dlist<T>::~dlist(){
    dnode<T> * tmp;
    while (head != NULL){
        tmp = head;
        head = head -> next();
        delete tmp;
    }
}

template <class T>
dlist<T>::dlist(const dlist& other){
    if(other.head == NULL){ // check for empty list
        head = tail = NULL;
    }
    else {
        head = tail = new dnode<T>(other.head -> data());
        dnode<T> *cursor = head;
        dnode<T> *other_ptr = other.head -> next();

        while(other_ptr != NULL){
            cursor -> set_next(new dnode<T>(other_ptr -> data(), cursor));
            cursor = cursor -> next();
            tail = cursor;
            other_ptr = other_ptr -> next();
        }
    }
    // if (other.head == NULL){
    //     head = NULL;
    // }
    // else {
    //     dnode<T> * nextPointer, * cursor;

    //     head = new dnode<T>(other.head -> data());

    //     nextPointer = other.head -> next();
    //     cursor = head;
    //     while (nextPointer != NULL){
    //         cursor -> set_next(new dnode<T>(nextPointer -> data()));
    //         nextPointer -> set_previous(cursor);
    //         //Move down list
    //         cursor = cursor -> next();
    //         tail = nextPointer;
    //         nextPointer = nextPointer -> next();
            
    //     }  
        
    // }
}

template <class T>
void dlist<T>::operator =(const dlist& other){
    if (this == &other){
        return;
    }
    dnode<T> * deletePtr = head -> next();
    while (deletePtr != NULL){
        delete head;
        head = deletePtr;
        deletePtr = deletePtr -> next();
    }
    delete head;
    head = other.head;
    tail = other.tail;
}
#endif