//------------------------------------------------------------------------
// Filename: 
//     Philosopher-4chairs.h
// PROGRAM DISCRIPTION
//     Interface file for class Philosopher
//------------------------------------------------------------------------

#ifndef _PHILOSOPHER_H
#define _PHILOSOPHER_H

#include "ThreadClass.h"

// macro defines

#define NUM_OF_PHILOSOPHERS   5

//------------------------------------------------------------------------
// Philosopher class definition
//------------------------------------------------------------------------

class Philosopher: public Thread 
{
     public:
          Philosopher(int Number, int iter);  // constructor
     private:
          int No;     // position of the philosopher
          int Iteration;
          void ThreadFunc();
};

#endif 
