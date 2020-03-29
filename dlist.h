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
        dlist(){head = tail = NULL;}

   void front_insert(const T &other); 
   void rear_insert(const T &other);
   void front_remove();
   void rear_remove();

   iterator begin() {return iterator(head);}
   iterator r_begin() {return iterator(tail);}
   iterator end() {return iterator(NULL);}
   iterator r_end() {return iterator(NULL);}
   
   void show();
   void reverse_show();

    private: 
        dnode<T> *head;
        dnode<T> *tail;
        int size();
};
#include "dlist.template"
#endif