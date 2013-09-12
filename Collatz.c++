// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream

#include "Collatz.h"


// ------------
// cycle_length
// ------------


int cycle_length_values[100000]={0};


int cycle_length (int n) {
	assert(n > 0);
	int valueToStore = n;
	if (n<100000 && cycle_length_values[n] !=0) return cycle_length_values[n];

	else {
		int c = 1;
		while (n > 1) {
			if ((n % 2) == 0)
				n = (n / 2);
			else
				n = (3 * n) + 1;
			++c;
		}
		if (valueToStore < 100000) cycle_length_values[valueToStore] = c;
		assert(c > 0);
		return c;
	}
}



// ------------
// collatz_read
// ------------

bool collatz_read (std::istream& r, int& i, int& j) {

    r >> i;
    if (!r)
        return false;
    r >> j;
    assert(i > 0);
    assert(j > 0);
    return true;}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    assert(i > 0);
    assert(j > 0);
    // <your code>
    int temp;
    int v;
    
    if (j<i) {   
    	temp=j;
		j=i;
		i=temp;
	}
	if ( i < j/2) {
		return collatz_eval(j/2, j);
	}

	else {
		v = cycle_length(j);

		int temp_cycle;

		while (i<j){

			temp_cycle = cycle_length(i);

			if (temp_cycle > v) v= temp_cycle;
			i++;
		}

	}

    
    assert(v > 0);
    return v;
    }

// -------------
// collatz_print
// -------------

void collatz_print (std::ostream& w, int i, int j, int v) {
    assert(i > 0);
    assert(j > 0);
    assert(v > 0);
    w << i << " " << j << " " << v << std::endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (std::istream& r, std::ostream& w) {
    int i;
    int j;
    while (collatz_read(r, i, j)) {
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
