#include <iomanip>
#include <cstdlib>
#include <cstdio>
#ifndef DLIST_H
#define DLIST_H
using namespace std;
#include "dnode.h."

template <class T>
class dlist{
    public:
      dlist(){
        head = tail = NULL;
      }
      front_insert();
      rear_insert();
      front_remove();
      rear_remove();
    private:
      T type;
      dnode <int> * head;
      dnode <int> * tail;
    };

#endif