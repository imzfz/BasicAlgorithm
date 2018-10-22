#include <stdio.h>

void sort(int *p, int n){
    int tmp;
    for(int i = 0; i < n - 1; ++i){
        for(int j = 0; j < n - i - 1; ++j){
            if(p[j] > p[j+1]){
                tmp = p[j];
                p[j] = p[j+1];
                p[j+1] = tmp;
            }
        }
    }
}

void print(int *p, int n){
    for(int i = 0; i < n; ++i){
        printf("%d ", p[i]);
    }
}

int main() {
    int num[10] = {33, 5, 2, 1, 9, 23, 12, 4, 1, 3};
    sort(num, 10);
    print(num, 10);

    return 0;
}

