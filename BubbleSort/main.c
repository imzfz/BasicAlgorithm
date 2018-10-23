#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

void sort(int *p, int n) {
    int tmp = 0;
    int flag = 0;
    for (int i = 0; i < n; ++i) {
        flag = 0;
        for (int j = 0; j < n - i - 1; ++j) {
            if (p[j] > p[j+1]) {
                tmp = p[j];
                p[j] = p[j+1];
                p[j+1] = tmp;
                flag = 1;
            }
        }
        if(!flag) break;
    }
}

void print(int *p, int n){
    printf("%s", "result is ");
    for(int i = 0; i < n; ++i){
        printf("%d ", p[i]);
    }
}

int main() {
//    int p[10] = {1, 65, 34, 76, 23, 5, 75, 9, 34, 3};
    int p[100000];
    time_t t_start, t_end;

    srand((unsigned int) time(NULL));
    for(int i = 0; i < N; ++i){
        p[i] = rand() % 9999;
    }
    t_start = time(NULL);
    sort(p, N);
    t_end	= time(NULL);
    print(p, N);
    printf("\n");
    printf("sort time is %f\n", difftime(t_end, t_start));
    return 0;
}