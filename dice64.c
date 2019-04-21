#include <stdint.h>
#include <stdlib.h>

// generates int64_t random : begin <= x <= end 
int64_t dice64(int64_t begin, int64_t end)
{
	uint64_t range = end - begin;
	if (range == 0 || range < 0) {
		return begin;
	}

	uint64_t selected = 0;
	uint64_t totalSize = 1000000000000000000;
	uint64_t divSize = 10000;
	uint64_t sectionSize = 0;

	while (true) {
		int r = rand(); // 0 ~ RND_MAX(32767)
		sectionSize = totalSize / divSize;
		selected += ((uint64_t)(r % divSize)) * sectionSize;
		totalSize = sectionSize;
		if (totalSize <= divSize) {
			selected += r % divSize;
			break;
		}
	}

	return begin + (selected % range);
}
