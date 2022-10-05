#include <stdio.h>
#include <stdlib.h>

int firstCmp(int val1, int val2);
int secondCmp(int val1, int val2);

int main(int argc, char *argv[]) {

    return 0;
}

int firstCmp(int val1, int val2) {
    if (val1 < val2)
        return -1;
    else if (val1 > val2)
        return 1;
    else
        return 0;
}

int secondCmp(int val1, int val2) {
    if (val1 < val2)
        return 1;
    else if (val1 > val2)
        return -1;
    else
        return 0;
}

int process(int *a, int n, int(*fp)(int, int)) {
    int cur = a[0];
    for (int i = 1; i < n; i++) {
        if (fp(cur, a[i]) < 0) {
            cur = a[i];
        }
    }
    return cur;
}
