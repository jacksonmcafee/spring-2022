#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int DEFAULTSIZE=100;
template <class T>
class Stack {
public:
    Stack();
    // default constructor, creates stack of size 100

    ~Stack();
    // destructor

    Stack(const int size);
    // constructor, creates stack of size "size"

    Stack(const Stack<T> &item);
    // copy constructor

    bool Full();
    // return true if stack is full

    bool Empty();
    // return true if stack is empty

    T  Top();
    // returns top element, doesn't pop

    bool Push(const T item);
    // puts new item on stack

    bool Pop();
    // pops item off stack and displays to stdout

    friend ostream &operator <<(ostream &os, Stack<T> &s) {
      // checks if stack is empty
      if(s._top == 0) {
        os << "Error! Stack is empty!" << endl;
        return os;
        }
      else {
        os << s._stack[s._top - 1];
        s._stack[s._top] = 0;
        s._top -= 1;
        os << endl;
        return os;
        }
      return os;
    }

    Stack &operator = (const Stack<T> s);

private:
    T * _stack;
    // "stack"

    int _size;
    // elements the stack can hold

    int _top;
    // points to first empty node on stack

    int _maxsize;
    // tracks size that has been allocated

    T dummy;
    // return if Top() throws
};

    // default constructor
    template < class T >
    Stack<T>::Stack() {
	     _size = 0;
	     _top = 0;
	     _maxsize = DEFAULTSIZE;

	     // memory allocation
	     _stack = new T[_maxsize];
     }

    // constructor
    template < class T >
    Stack<T>::Stack(const int size) {
	_size = 0;
	_top = 0;
	_maxsize = size;

	// memory allocation
	_stack = new T[_maxsize];
  }

    // copy constructor
    template < class T >
    Stack<T>::Stack(const Stack<T> &item) {
	_size = item._size;
	_top = item._top;
	_maxsize = item._maxsize;

	// memory allocation
	_stack = new T[_maxsize];

	// populate Stack with item's values
	for(int i = 0; i < _maxsize; i++) {
	    _stack[i] = item._stack[i];
	    }
    }

    // destructor
    template < class T >
    Stack<T>::~Stack() {
	     cout << " " << endl;
    }

    // returns true if stack is full
    template < class T >
    bool Stack<T>::Full() {
    	if(_top == _maxsize) {
	    return true; }
    	else {
	    return false; }
    }

    // returns true is stack is empty
    template < class T >
    bool Stack<T>::Empty() {
  	if(_top == 0) {
	    return true; }
    	else {
	    return false; }
    }

    // returns top element in stack
    template < class T >
    T Stack<T>::Top() {
	     return _stack[_top-1];
    }

    // puts new item on stack
    template < class T >
    bool Stack<T>::Push(const T item) {
      if(_top < _maxsize) {
        _stack[_top] = item;
        _top += 1;
	      return true; }
      else {
        cout << "Stack full, failed to push " << item << endl;
        return false;
      }
    }

    // pops top item off stack and displays to stdout
    template < class T >
    bool Stack<T>::Pop() {
	     if(_top > 0) {
         T temp = _stack[_top-1];
         _top -= 1;
         cout << temp << endl;
         return true;
         }
        else {
          cout << "Nothing to pop!" << endl;
          return false;
        }
    }

    template < class T >
    Stack<T>& Stack<T>::operator = (const Stack<T> s) {
    	// populate Stack with item's values
      while(Empty() != true) {
        Pop();
      }
    	for(int i = 0; i < s._maxsize; i++) {
          Push(s._stack[i]);
    	    }
          return *this;
    }

#endif
