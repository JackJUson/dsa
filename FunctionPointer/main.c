#include <stdio.h>
#include <stdlib.h>

int firstCmp(int val1, int val2);
int secondCmp(int val1, int val2);
int process(int *a, int n, int(*fp)(int, int));

int main(int argc, char *argv[]) {

    int marksA[] = {67, 34, 81, 44, 19};
    int ans1 = process(marksA, 5, firstCmp);
    printf("ans1 is %d\n\n", ans1);

    int ans2 = process(marksA, 5, firstCmp);
    printf("ans2 is %d\n\n", ans2);

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
