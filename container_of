#include <stdio.h>
#include <stdlib.h>

/* https://radek.io/2012/11/10/magical-container_of-macro/ */

#define container_of(ptr, type, member) ({                      \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - __offsetof(type,member) );})


struct entry {
	int i;
};

struct slisthead {
	struct entry *entries;
};

int main(int argc, char *argv[]) {

	struct entry *e = malloc(sizeof(struct entry));
	e->i = atoi(argv[1]);

	struct slisthead *h = malloc(sizeof(struct slisthead));
	h->entries = e;

	struct slisthead *p = container_of(&e, struct slisthead, entries);
	printf("Value is: %d\n", p->entries->i);

	free(e);
	free(h);

	return EXIT_SUCCESS;
}
