#include <stdio.h>

#include "bst.h"

int verify_ints(int a, int b) {
    if (a != b) {
        printf("Expected %d, received %d\n", a, b);
        return 0;
    }
    return 1;
}

int verify_size(int i, size_t sz) {
    return verify_ints(i, (int)sz);
}

void print_array(size_t len, int a[]) {
    printf("[");
    size_t pos = 0;
    if (pos != len) {
        printf("%d", a[pos++]);
    }
    while (pos != len) {
        printf(", %d", a[pos++]);
    }
    printf("]");
}

int verify_arrays(size_t n1, int a[], size_t n2, int b[]) {
    if (n1 != n2) {
        printf("Expected list of length %zu, received list of length %zu\n", n1, n2);
        return 0;
    }
    int ret = 1;
    for (size_t i = 0; i < n1; ++i) {
        if (a[i] != b[i]) {
            ret = 0;
        }
    }
    if (!ret) {
        printf("Expected ");
        print_array(n1, a);
        printf(", received ");
        print_array(n2, b);
        puts("");
    }
    return ret;
}

int compare_ints(const void *a, const void *b) {
    return *((int*)a) - *((int*)b);
}

BST_DEFINE(int)

int main(void) {
    BST_int *b = BST_int_construct(compare_ints);
    if (NULL == b) {
        fprintf(stderr, "could not construct BST\n");
    }
    verify_size(0, b->size(b));
    verify_arrays(0, NULL, b->size(b), b->list(b));
    if (-1 == b->add(b, 5)) {
        fprintf(stderr, "error while adding to BST\n");
    }
    verify_ints(1, b->contains(b, 5));
    verify_size(1, b->size(b));
    verify_arrays(1, (int [1]){5}, b->size(b), b->list(b));
    for (int i = 10; i >= 0; --i) {
        if (-1 == b->add(b, i)) {
            fprintf(stderr, "error while adding to BST\n");
        }
    }
    verify_size(11, b->size(b));
    verify_arrays(11, (int [11]){0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, b->size(b), b->list(b));
    for (int i = 0; i < 11; ++i) {
        verify_ints(1, b->contains(b, i));
    }
    verify_ints(0, b->contains(b, 11));
    b->destruct(b);
    return 0;
}
