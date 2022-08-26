//------------------------------------------------------------------------
// Filename: 
//     Philosopher-4chairs.cpp
// PROGRAM DISCRIPTION
//     Philosopher class implementation file.  This program uses mutex   
//     locks and semaphores to implement the philosopher problem.
//     At most four philosophers can be sitting and eating.
//------------------------------------------------------------------------

#include <iostream>

#include "Philosopher-4chairs.h"

// locks and semaphores

static Semaphore FourChairs("FourChairs", NUM_OF_PHILOSOPHERS - 1);
static Mutex Chopstick1("Chopstick1");
static Mutex Chopstick2("Chopstick2");
static Mutex Chopstick3("Chopstick3");
static Mutex Chopstick4("Chopstick4");
static Mutex Chopstick5("Chopstick5");
static Mutex *Chopstick[NUM_OF_PHILOSOPHERS] = 
    { &Chopstick1, &Chopstick2, &Chopstick3, &Chopstick4, &Chopstick5 };

// -----------------------------------------------------------------------
// FUNCTION  Filler():                                              
//    This function fills a strstream with spaces.                 
// -----------------------------------------------------------------------

strstream *Filler(int n)
{
     int  i;
     strstream *Space;

     Space = new strstream;
     for (i = 0; i < n; i++)
          (*Space) << ' ';
     (*Space) << '\0';
     return Space;
}

//------------------------------------------------------------------------
// Philosopher::Philosopher()
//      constructor
//------------------------------------------------------------------------

Philosopher::Philosopher(int Number, int iter)
            :No(Number), Iteration(iter) 
{
     ThreadName.seekp(0, ios::beg);
     ThreadName << "Philosopher" << Number << '\0';
};

//------------------------------------------------------------------------
// Philosopher::ThreadFunc()
//      implement a Philosopher thread
//------------------------------------------------------------------------

void Philosopher::ThreadFunc() 
{
     Thread::ThreadFunc();
     strstream *Space;
     int i;
        
     Space = Filler(No*2);
     for (i=0; i < Iteration; i++) {
          Delay();
          FourChairs.Wait();       // allows 4 to sit down
               Chopstick[No]->Lock();
               Chopstick[(No + 1) % NUM_OF_PHILOSOPHERS]->Lock();
               cout << Space->str() << ThreadName.str() 
                    << " begin eating." << endl;             
               Delay();
               cout << Space->str() << ThreadName.str()
                    << " finish eating." << endl;            
               Chopstick[No]->Unlock();      
               Chopstick[(No+1)%NUM_OF_PHILOSOPHERS]->Unlock();                         
          FourChairs.Signal();     // release the chair
     }
     Exit();
}

// end of Philosopher.cpp file 
