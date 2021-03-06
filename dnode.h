#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <iostream>

#ifndef DNODE_H
#define DNODE_H
using namespace std;

template <class T>
class dnode {
    public:
      dnode(const T& a = T(), dnode *p = NULL, dnode *n = NULL){
        datafield = a;
        previousptr = p;
        nextptr = n;
      }

      T& data(){
          return datafield;
      }

      const T& data()const{
          return datafield;
      }
    
      dnode *previous(){
        return previousptr;
      }

      dnode *next(){
          return nextptr;
      }
    
      void set_data(int d){
        cout << "d: " << d << endl;
        datafield = d;
        cout << "datafield: " << datafield << endl;
      }

      void set_previous(dnode * p){
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
