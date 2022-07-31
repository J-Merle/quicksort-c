#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

void quicksort(int* tab, int lo, int hi) {
	// Recursion guards
	if (lo < 0 || hi < 0 || lo >= hi) return;

	// Pick a pivot 
	int pivot_pos = lo+(hi-lo)/2; // Avoid overflow if lo+hi > INT_MAX

	int pivot_value = tab[pivot_pos];

	// Partition the range
	int i = lo -1;
	int j = hi +1;

	while(1) {

		do { i+= 1;} while(tab[i] < pivot_value);
		do { j-= 1;} while(tab[j] > pivot_value);
		if(i>=j) {
			pivot_pos = j;
			break;
		}

		int tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
	}

	// Call quicksort reursively
	quicksort(tab, lo, pivot_pos);
	quicksort(tab, pivot_pos + 1, hi);

}

int main(void) {
	int tab[SIZE] = {0}; 
	time_t t;

	// Seed random generation
	srand((unsigned) time(&t));

	// Array initialization
	for(int i=0; i<SIZE; i++) {
		tab[i] = rand() % 10000;
	}

	quicksort(tab, 0, SIZE - 1);
}

