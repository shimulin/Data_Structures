//Disjoint Sets
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000
#define int long

int parent[MAX];
int height[MAX];

int find(int x) {   
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]) ;
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) {
        return;
    }

    if (height[x] < height[y]) {
        parent[x] = y;
    } else if (height[y] < height[x]) {
        parent[y] = x;
    } else {
        parent[y] = x;
        parent[x]++;
    }
}


int main() {
    int times;
    scanf("%ld", &times);

    while (times--) {
        int num, ops_num;
        scanf("%ld %ld", &num, &ops_num);

        for (int i = 0; i < (num + 1); i++) {
            parent[i] = i;
            height[i] = 0;
        }

        while (ops_num--) {
            int x, y, n;
            char ops[6];
            scanf("%s", ops);

            switch (ops[0]) {
                case 'u':
                    scanf("%ld %ld", &x, &y);
                    merge(x, y);
                    break;
                case 's':
                    scanf("%ld %ld", &x, &y);
                    if (find(x) == find(y)) {
                        printf("true\n");
                    }
                    else {
                        printf("false\n");
                    }
                    break;
                case 'f':
                    scanf("%ld", &n);
                    printf("%ld\n", find(n));
                    break;
                default:
                    break;
            }

            // if (ops[0] == 'u') {
            //     scanf("%ld %ld", &x, &y);
            //     merge(x, y);
            // }
            // else if (ops[0] == 's') {
            //     scanf("%ld %ld", &x, &y);
            //     if (find(x) == find(y)) {
            //         printf("true\n");
            //     }
            //     else {
            //         printf("false\n");
            //     }
            // }
            // else {
            //     scanf("%ld", &n);
            //     int answer = find(n);
            //     printf("%ld\n", answer);
            // }
        }
    }
    return 0;
}
