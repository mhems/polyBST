#ifndef BST_H
#define BST_H

#include <stdlib.h>
#include <string.h>

/**
 * Function for comparing two values
 * Return > 0 iff a < b
 *          0 iff a == b
 *        < 0 iff a > b
 */
typedef int (*compare_t)(const void *a, const void *b);

#define BST_DEFINE(TYPE)                                                \
                                                                        \
    typedef struct _BST_##TYPE {                                        \
        TYPE *node;                                                     \
        struct _BST_##TYPE *left, *right;                               \
        compare_t comp;                                                 \
                                                                        \
        size_t (*size)(const struct _BST_##TYPE *);                     \
        int (*add)(struct _BST_##TYPE *, const TYPE);                   \
        int (*contains)(const struct _BST_##TYPE *, const TYPE);        \
        TYPE* (*list)(const struct _BST_##TYPE *);                      \
        void (*destruct)(struct _BST_##TYPE *);                         \
    } BST_##TYPE;                                                       \
                                                                        \
    size_t size(const struct _BST_##TYPE *BST) {                        \
        int sum = 0;                                                    \
        if (NULL != BST->node) {                                        \
            ++sum;                                                      \
            if (NULL != BST->left) {                                    \
                sum += size(BST->left);                                 \
            }                                                           \
            if (NULL != BST->right) {                                   \
                sum += size(BST->right);                                \
            }                                                           \
        }                                                               \
        return sum;                                                     \
    }                                                                   \
                                                                        \
    struct _BST_##TYPE *BST_##TYPE##_construct(compare_t);              \
                                                                        \
    int add(struct _BST_##TYPE *BST, const TYPE elem) {                 \
        if (NULL == BST->node) {                                        \
            BST->node = (TYPE*)malloc(sizeof(TYPE));                    \
            if (NULL == BST->node) {                                    \
                return -1;                                              \
            }                                                           \
            memcpy(BST->node, &elem, sizeof(TYPE));                     \
            return 1;                                                   \
        }                                                               \
        int result = BST->comp(&elem, BST->node);                       \
        if (result != 0) {                                              \
            if (result < 0) {                                           \
                if (NULL == BST->left) {                                \
                    if (NULL == (BST->left = BST_##TYPE##_construct(BST->comp))) { \
                        return -1;                                      \
                    }                                                   \
                }                                                       \
                return add(BST->left, elem);                            \
            } else {                                                    \
                if (NULL == BST->right) {                               \
                    if (NULL == (BST->right = BST_##TYPE##_construct(BST->comp))) { \
                        return -1;                                      \
                    }                                                   \
                }                                                       \
                return add(BST->right, elem);                           \
            }                                                           \
        } else {                                                        \
            return 0;                                                   \
        }                                                               \
    }                                                                   \
                                                                        \
    int contains(const struct _BST_##TYPE *BST, const TYPE elem) {      \
        if (NULL == BST->node) {                                        \
            return 0;                                                   \
        }                                                               \
        int result = BST->comp(&elem, BST->node);                       \
        if (result == 0) {                                              \
            return 1;                                                   \
        } else if (result < 0) {                                        \
            return BST->left != NULL && contains(BST->left, elem);      \
        } else {                                                        \
            return BST->right != NULL && contains(BST->right, elem);    \
        }                                                               \
    }                                                                   \
                                                                        \
    void accum_list(const struct _BST_##TYPE *BST, TYPE *list, int *pos) { \
        if (NULL != BST->left) {                                        \
            accum_list(BST->left, list, pos);                           \
        }                                                               \
        if (NULL != BST->node) {                                        \
            list[*pos] = *BST->node;                                    \
            ++*pos;                                                     \
        }                                                               \
        if (NULL != BST->right) {                                       \
            accum_list(BST->right, list, pos);                          \
        }                                                               \
    }                                                                   \
                                                                        \
    TYPE *list(const struct _BST_##TYPE *BST) {                         \
        TYPE *list = (TYPE*)malloc(sizeof(TYPE) * size(BST));           \
        int pos = 0;                                                    \
        accum_list(BST, list, &pos);                                    \
        return list;                                                    \
    }                                                                   \
                                                                        \
    void destruct(struct _BST_##TYPE *BST) {                            \
        if (NULL != BST->left) {                                        \
            destruct(BST->left);                                        \
        }                                                               \
        if (NULL != BST->right) {                                       \
            destruct(BST->right);                                       \
        }                                                               \
        free(BST->node);                                                \
        free(BST);                                                      \
    }                                                                   \
                                                                        \
    struct _BST_##TYPE *BST_##TYPE##_construct(compare_t comp) {        \
        struct _BST_##TYPE *BST;                                        \
        if (NULL == (BST = (struct _BST_##TYPE *)malloc(sizeof(struct _BST_##TYPE)))) { \
            return NULL;                                                \
        }                                                               \
        BST->node = NULL;                                               \
        BST->left = NULL;                                               \
        BST->right = NULL;                                              \
        BST->comp = comp;                                               \
        BST->size = size;                                               \
        BST->add = add;                                                 \
        BST->contains = contains;                                       \
        BST->list = list;                                               \
        BST->destruct = destruct;                                       \
        return BST;                                                     \
    }

#endif /* BST_H */
