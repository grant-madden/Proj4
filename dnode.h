#include <iomanip>
#include <cstdlib>
#include <cstdio>
#ifndef DNODE_H
#define DNODE_H
using namespace std;

template <class T>
class dnode {
    public:
      dnode(T d = 0, dnode * p = NULL, dnode * n = NULL){
        datafield = d;
        previousptr = p;
        nextptr = n;
      }

      T data(){
        return datafield;
      }

      dnode * previous(){
        return previousptr;
      }

      dnode * next(){
        return nextptr;
      }

      void set_data(T d){
        datafield = d;
      }

      void set_previos(dnode * p){
        previousptr = p;
      }

      void set_next(dnode * n){
        nextptr = n;
      }

    private:
      T datafield;
	    dnode *previousptr;
	    dnode *nextptr;
    };


#endif
