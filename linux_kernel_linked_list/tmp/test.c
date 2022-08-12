#include <stdio.h>

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#define my_offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)1000)->MEMBER)

struct test {
    int a;
    int b;
    int c;
};

int main()
{
    printf("sizeof(int): %ld\n", sizeof(int));

    printf("--- offsetof -------------\n");
    printf("-------- a: %ld\n", offsetof(struct test, a));
    printf("-------- b: %ld\n", offsetof(struct test, b));
    printf("-------- c: %ld\n", offsetof(struct test, c));

    printf("--- my_offsetof -------------\n");
    printf("-------- a: %ld\n", my_offsetof(struct test, a));
    printf("-------- b: %ld\n", my_offsetof(struct test, b));
    printf("-------- c: %ld\n", my_offsetof(struct test, c));

    return 0;
}
