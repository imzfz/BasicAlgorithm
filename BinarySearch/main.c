/**
 * 二分查找
 */
#include <stdio.h>
#define N 10

//普通二分查找
int search(int *p, int n, int target){
    int low = 0, high = n, mid = 0;
    int pos = 0;
    while(low <= high){
        mid = low + ((high - low) >> 1);
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

//递归二分
int bsearch_intern(int *p, int low, int high, int target){
    int mid = low + ((high - low) >> 1);
    int pos = 0;

    if(low > high){
        return -1;
    }

    if(p[mid] > target){
        high = mid - 1;
        bsearch_intern(p, low, high, target);
    }
    else if(p[mid] < target){
        low = mid + 1;
        bsearch_intern(p, low, high, target);
    }
    else{
        pos = mid;
        return pos;
    }
    return pos;
}

//递归二分
int bsearch(int *p, int n, int  target){
    int pos = 0;
    pos = bsearch_intern(p, 0, n, target);
    return pos;
}

//查找第一等于target元素的位置
int bsearch_first_equal(int *p, int n, int target){
    int low = 0, high = n, pos = 0;
    int mid = 0;

    while(low <= high){
        mid = low + ((high - low) >> 1);
        if(p[mid] < target){
            low = mid + 1;
        }
        else if(p[mid] > target){
            high = mid - 1;
        }
        else{
            high = mid - 1;
            if(p[high] == p[mid]){
                continue;
            }
            pos = mid;
            return pos;
        }
    }
    return pos;
}

//查找最后一个等于target元素的位置
int bsearch_last_equal(int *p, int n, int target){
    int low = 0, high = n, pos = 0;
    int mid = 0;

    while(low <= high){
        mid = low + ((high - low) >> 1);
        if(p[mid] < target){
            low = mid + 1;
        }
        else if(p[mid] > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
            if(p[low] == p[mid]){
                continue;
            }
            pos = mid;
            return pos;
        }
    }
    return pos;
}

//查找第一大于target元素的位置
int bsearch_first_greater(int *p, int n, int target){
    int low = 0, high = n, pos = 0;
    int mid = 0;

    while(low <= high){
        mid = low + ((high - low) >> 1);
        if(p[mid] < target){
            low = mid + 1;
        }
        else if(p[mid] > target){
            high = mid - 1;
            if(p[high] <= target){
                return mid;
            }
        }
        else{
            low = mid + 1;
            if(p[low] > target){
                pos = low;
            }
            else{
                continue;
            }
            return pos;
        }
    }
    return pos;
}

//查找最后一个小于target元素的位置
int bsearch_last_lower(int *p, int n, int target){
    int low = 0, high = n, pos = 0;
    int mid = 0;

    while(low <= high){
        mid = low + ((high - low) >> 1);
        if(p[mid] < target){
            low = mid + 1;
            if(p[low] >= target){
                return mid;
            }
            else{
                continue;
            }
        }
        else if(p[mid] > target){
            high = mid - 1;
        }
        else{
            high = mid - 1;
            if(p[high] < target){
                pos = high;
            }
            else{
                continue;
            }
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
//    int p[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int p[N] = {1, 1, 3, 3, 3, 4, 4, 8, 8, 10};
//    pos = search(p, N - 1, 10);
//    pos = bsearch(p, N - 1, 5);
//    pos = bsearch_first_equal(p, N - 1, 1);
//    pos = bsearch_last_equal(p, N - 1, 4);
//    pos = bsearch_first_greater(p, N - 1, 7);
    pos = bsearch_last_lower(p, N - 1, 9);
    output(pos);
    return 0;
}