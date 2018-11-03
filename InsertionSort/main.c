/**
 * 插入排序
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

void sort(int *p, int n){
    if(n <= 1) return;

    for(int i = 1; i < n; ++i){
        int val = p[i];
        int j = i - 1;
        for(; j >= 0; --j){
            if(val < p[j]){
                p[j+1] = p[j];
                //元素后移
            }
            else{
                break;
            }
        }

        p[j+1] = val;
        //插入元素
    }
}

void output(int *p, int n){
    printf("result is : ");
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
    int num[N];

    srand((unsigned int) time(NULL));
    for(int i = 0; i < N; ++i){
//        num[i] = rand() % (N-1);
        printf("%d ", num[i]);
    }

    timeTested(num);
    //100000个数字排序时间大概是冒泡的1/4
    output(num, N);
    printf("\n");
    return 0;
}