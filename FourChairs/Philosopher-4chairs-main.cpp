//------------------------------------------------------------------------
// Filename:
//     Philosopher-4chairs-main.cpp
// PROGRAM DISCRIPTION
//     Main program, this program uses mutex locks and semaphores to
//     implement the philosopher problem.  It allows at most four
//     philosophers to sit down and eat.
//------------------------------------------------------------------------

#include <iostream>
#include <stdlib.h>

#include "Philosopher-4chairs.h"

//------------------------------------------------------------------------
// main() function
//------------------------------------------------------------------------

int main(int argc, char *argv[])
{
     Philosopher *Philosophers[NUM_OF_PHILOSOPHERS];
     int i, Iteration;

     if (argc != 2) {
     	cout << "Use " << argv[0] << " #-of-iterations." << endl;
          exit(0);
    	}
     else
          Iteration = abs(atoi(argv[1]));

     // create all the philosopher threads and fire them up
     for (i = 0; i < NUM_OF_PHILOSOPHERS; i++) {
     	Philosophers[i]= new Philosopher(i, Iteration);
          Philosophers[i]->Begin();
     }

    	// wait for philosopher thread
     for (i = 0; i < NUM_OF_PHILOSOPHERS; i++)
     	Philosophers[i]->Join();

     Exit();   // main thread exits
     
     return 0;
}
 
