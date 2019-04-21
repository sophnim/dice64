#include <stdint.h>
#include <stdlib.h>
#include <time.h>

// generates int64_t random : begin <= x <= end
// call srand(time(NULL)) before call this function
int64_t dice64(int64_t begin, int64_t end)
{	
	uint64_t range = end - begin;
	if (range <= 0) { 
		// if invalid range, return begin
		return begin;
	}

	uint64_t selected = 0;
	uint64_t totalSize = 1000000000000000000LL;
	uint64_t divSize = 10000;
	uint64_t sectionSize = 0;
		
	// select random number between 0 ~ totalSize - 1
	while (true) {
		sectionSize = totalSize / divSize;
		selected += ((uint64_t)(rand() % divSize)) * sectionSize;
		totalSize = sectionSize;
		if (totalSize <= divSize) {
			selected += rand() % divSize;
			break;
		}
	}

	// selected mod range plus begin is randomNumber between begin ~ end 
	return begin + (selected % range);
}
