#ifndef ITERATOR_H
#define ITERATOR_H

#include "dnode.h"
#include "dlist.h"

template <class T>
class node_iterator{
    public:
    // Constructor
    node_iterator(dnode<T> *init = NULL){current = init;}
    // Equality and Inequality 
    bool operator != (const node_iterator &other){
        return current != other.current;
    }
    bool operator ==(const node_iterator &other){
        return current == other.current;
    }
    T operator * (){return current -> data();}

    // Unary operators
    node_iterator operator ++(){ // prefix
        current = current -> next();
        return *this;
    }
    node_iterator operator ++(int){ //postfix
        node_iterator original(current);
        original = current -> next();
        return original;
    }
    node_iterator operator --(){ // prefix
        current = current -> previous();
        return *this;
    }
    node_iterator operator --(int){ //postfix
        node_iterator original(current);
        original =  current -> previous();
        return original;
    }

    private:   
        dnode<T> *current;
};
#endif