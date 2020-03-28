#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "dnode.h"
#include "node_iterator.h"


#ifndef DLIST_H
#define DLIST_H
using namespace std;
template <class T>
class dlist{
    public:
      typedef node_iterator<T> iterator;

      dlist(){
        head = tail = NULL;
      }
      void front_insert(T item);
      void rear_insert(T item);
      void front_remove();
      void rear_remove();
      void show();
      void reverse_show();

      // FUNCTIONS TO PROVIDE ITERATORS
        // iterator begin(){
        //     // return iterator(head);
        // }
        
        // iterator end(){
        //     // return iterator(NULL);
        // }

        // iterator r_begin(){
        //     // return iterator(tail);
        // }

        // iterator r_end(){
        //     // return iterator(NULL);
        // }

    private:
      dnode <T> * head;
      dnode <T> * tail;
      int size(){
        const dnode<T> *cursor;
        int i = 0;
        for(cursor = head; cursor != NULL; cursor = cursor -> next())
            ++i;
        return i;
      }
      // size_type node_count; // Number of nodes on the list

    };

template <class T>
void dlist<T>::rear_insert(T item){
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
void dlist<T>::front_insert(T item){
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
void dlist<T>::rear_remove(){
    tail = tail -> previous();
    tail -> set_next(NULL);
}

template <class T>
void dlist<T>::front_remove(){
    head = head -> next();
    head -> set_previous(NULL);
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
#endif