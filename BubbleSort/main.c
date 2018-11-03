/**
 * 冒泡排序
 */

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
        //如果没有交换过，则说明已经有序
        if(!flag) break;
    }
}

void output(int *p, int n){
    printf("%s", "result is ");
    for(int i = 0; i < n; ++i){
        printf("%d ", p[i]);
    }
}

void timeTested(int *p){
    time_t t_start, t_end;
    t_start = time(NULL);
    sort(p, N);
    t_end	= time(NULL);
    printf("sort time is %f\n", difftime(t_end, t_start));
}

int main() {
    int p[N];

    srand((unsigned int) time(NULL));
    for(int i = 0; i < N; ++i){
        p[i] = rand() % (N-1);
    }
    timeTested(p);
    output(p, N);
    printf("\n");
    return 0;
}