#include <stdio.h>

void disp(int a[], int i) {
    if (i >= 0) {
        printf("%d\t", a[i]);
        i--;
        disp(a, i);
    }
}

int main() {
    int a[5] = {1, 5, 9, 3, 5};
    int n = sizeof(a) / sizeof(a[0]);
    disp(a, n - 1); 
    return 0;
}
