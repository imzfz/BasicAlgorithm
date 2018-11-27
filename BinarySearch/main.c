/**
 * 普通二分查找
 */
#include <stdio.h>
#define N 10

int search(int *p, int n, int target){
    int low = 0, high = n, mid = 0;
    int pos = 0;
    while(low <= high){
        mid = (low + high) / 2;
        if(p[mid] > target){
            high = mid - 1;
        }
        else if(p[mid] < target){
            low = mid + 1;
        }
        else{
            pos = mid;
            return pos;
        }
    }
    return pos;
}

void output(int n){
    printf("The target position is %d", n);
}

int main() {
    int pos;
    int p[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    pos = search(p, N - 1, 10);
    output(pos);
    return 0;
}