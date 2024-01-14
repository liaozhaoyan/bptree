//
// Created by 廖肇燕 on 2024/1/14.
//

#include <stdio.h>
#include <stdlib.h>
#include "bplustree.h"

#define START_ON 1000001

int test(struct bplus_tree *tree, int loop) {
    int i;
    int ret;
    data_t ds;

    for (i = START_ON; i < loop + START_ON; i ++) {
        snprintf(ds.s, DATA_SIZE, "hello %d", i);
        ret = bplus_tree_put(tree, i, &ds);
        if (ret != 0) {
            printf("bad put\n");
            return -1;
        }
    }

    for (i = START_ON; i < loop + START_ON; i ++) {
        ret = bplus_tree_get(tree, i, &ds);
        if (ret != 0) {
            printf("bad get, %d\n", ret);
            continue;
        }
//        printf("%d: %s\n", i, ds.s);
    }

    for (i = START_ON; i < loop + START_ON; i ++) {
        ret = bplus_tree_put(tree, i, NULL);
        if (ret != 0) {
            printf("bad delete\n");
            return -1;
        }
    }
    return 0;
}

int main(int argc, char* argv[]) {
    struct bplus_tree *tree = NULL;
    int loop = atoi(argv[1]);
    if (loop < 10) {
        loop = 10;
    }

    tree = bplus_tree_init("fox.index", 4096);
    test(tree, loop);
    bplus_tree_deinit(tree);
    return 0;
}
