#include <stdio.h>
#include <stdlib.h>

void	*my_malloc(size_t size) {
	// Simuler un échec de malloc en retournant NULL
	return NULL;
}

#define malloc my_malloc

int main() {
	void *ptr = malloc(10);
	if (ptr == NULL) {
		printf("malloc a échoué!\n");
	} else {
		printf("malloc a réussi!\n");
		free(ptr);
	}
	return 0;
}
