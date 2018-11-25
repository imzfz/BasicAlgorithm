/**
 * 快速排序
 */
#include <stdio.h>
#define N 10

/**
 * 分区函数
 * @param p 数组
 * @param begin 开始位置
 * @param end 结束位置
 * @return 分区点
 */
int partition(int *p, int begin, int end) {
    int i = begin, temp = 0;
    for (int index = begin; index <= end; ++index) {
        //以end位置作为哨兵
        if (p[index] < p[end]) {
            temp = p[index];
            p[index] = p[i];
            p[i] = temp;
            ++i;
        }
    }

    temp = p[end];
    p[end] = p[i];
    p[i] = temp;

    return i;
}

/**
 * 递归快排
 * @param p 待排序数组
 * @param begin 开始位置
 * @param end 结束位置
 */
void quick_sort(int *p, int begin, int end) {
    int mid;
    if (begin >= end) {
        return;
    }

    mid = partition(p, begin, end);
    quick_sort(p, begin, mid - 1);
    quick_sort(p, mid + 1, end);

}

void sort(int *p, int n) {
    quick_sort(p, 0, n - 1);
}

void output(int *p, int n){
    for(int i = 0; i < n; ++i){
        printf("%d ", p[i]);
    }
}

int main() {
//    int p[N] = {11, 75, 23, 57, 1, 4, 3, 24, 75, 44};
    int p[N] = {11, 8, 3, 9, 7, 1, 2, 5, 5, 4};
    sort(p, N);
    output(p, N);
    return 0;
}