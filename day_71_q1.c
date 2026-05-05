#include <stdio.h>
#include <string.h>

#define MAX 100

int table[MAX];

// Initialize table
void init(int m) {
    for (int i = 0; i < m; i++)
        table[i] = -1;
}

// Insert
void insert(int key, int m) {
    int i = 0;
    int idx;

    while (i < m) {
        idx = (key % m + i * i) % m;

        if (table[idx] == -1) {
            table[idx] = key;
            return;
        }
        i++;
    }
}

// Search
void search(int key, int m) {
    int i = 0;
    int idx;

    while (i < m) {
        idx = (key % m + i * i) % m;

        if (table[idx] == key) {
            printf("FOUND\n");
            return;
        }

        if (table[idx] == -1) {
            printf("NOT FOUND\n");
            return;
        }

        i++;
    }

    printf("NOT FOUND\n");
}

// Driver
int main() {
    int m, q;
    scanf("%d", &m);   // table size
    scanf("%d", &q);   // number of operations

    init(m);

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key, m);
        }
    }

    return 0;
}