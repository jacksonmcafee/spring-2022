#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream>

#include <new>                  // Needed for bad-alloc exception

#include <cstdlib>              // Needed for the exit function

using namespace std;

// ***************************************************************
// * Template Assignment simplevector.h                          *
// * Description:  Contains the basic definition of the          *
// * SimpleVector Template class.  The method names and          *
// * signatures must not be modified. You will add your          *
// * Method implementation to the end of this file where         *
// * indicated.                                                  *
// * Author: Dr. David Gaitros                                   *
// * Last Modified:  March 7th, 2021.                            *
// ***************************************************************

template < class T >
    class SimpleVector {
        const int DEFAULTVECTORSIZE = 100;
        private:
            T * aptr; // To point to the allocated array
        int arraysize; // Number of elements in the array
        void memError(); // Handles memory allocation errors
        void subError(); // Handles subscripts out of range
        public:
            // Default constructor - Already written, 
            SimpleVector();

        // Constructor declaration
        SimpleVector(int);

        // Copy Constructor declaration
        SimpleVector(const SimpleVector & );

        // Destructor - check to see if the size > zero.
        ~SimpleVector();

        // Accessor to return the array size
        int size() const {
            return arraysize;
        }

        // Accessor to return a specific element
        T getElementAt(int sub);

        // Overload [] operator declaration
        T & operator[](const int & );
    };
// ***************************************************************
// * Add your method implementation here.                        *
// ***************************************************************

// default constructor
template < class T >
    SimpleVector < T > ::SimpleVector() {
        arraysize = DEFAULTVECTORSIZE;
        // assigns aptr array of memory locs of type T
        aptr = new T[arraysize];
    }

// constructor
template < class T >
    SimpleVector < T > ::SimpleVector(int size) {
        arraysize = size;
        // assigns aptr array of memory locs of type T
        aptr = new T[arraysize];
    }

// copy constructor
template < class T >
    SimpleVector < T > ::SimpleVector(const SimpleVector & passedVector) {
        arraysize = passedVector.arraysize;
        // assigns aptr array of memory locs of type T
        aptr = new T[arraysize];

        // copies all values from passedVector onto base vector
        if (aptr) {
            for (int i = 0; i < arraysize; i++) {
                aptr[i] = passedVector.aptr[i];
            }
        } else {
            // throws memError if memory isn't allocated (!aptr)
            memError();
        }
    }

// destructor
template < class T >
    SimpleVector < T > ::~SimpleVector() {
        // deletes aptr if array exists beyond size 0
        if (arraysize > 0) {
            delete[] aptr;
        }
    }

// getElementAt function
template < class T >
    T SimpleVector < T > ::getElementAt(int sub) {
        // throws subError() if element doesn't exist
        if (sub >= arraysize || sub < 0) {
            subError();
        }
        return aptr[sub];
    }

// [] operator overload
template < class T >
    T & SimpleVector < T > ::operator[](const int & sub) {
        return aptr[sub];
    }

// memError and subError declaration
template < class T >
    void SimpleVector < T > ::memError() {
        cout << "Memory allocation failed." << endl;
    }

template < class T >
    void SimpleVector < T > ::subError() {
        cout << "Element given does not exist in this vector." << endl;
    }

#endif //SIMPLEVECTOR_H
