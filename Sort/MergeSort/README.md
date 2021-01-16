```c++
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define random(x) rand()%(x)
using namespace std;
void merge_(int nums[], int low, int mid, int high) {
    int i = low, j = mid + 1;
    int temp[30];
    for(int k=low; k<=high; k++) temp[k] = nums[k];
    for (int k=low; k<=high; k++) {
        if(i>mid) nums[k] = temp[j++];
        else if(j>high) nums[k] = temp[i++];
        else if(temp[i]<temp[j]) nums[k] = temp[i++];
        else nums[k] = temp[j++];
    }
}
// 自顶向下
void mergeSortI(int nums[], int low, int high) {
    if(low>=high) return;
    int mid = (low+high)/2;
    mergeSortI(nums, low, mid);
    mergeSortI(nums, mid+1, high);
    merge_(nums, low, mid, high);
}
// 自底向上
void mergeSortII(int nums[], int n) {
    for(int step=1; step<n; step=step*2) {
        for(int i=0; i<n-step; i=i+2*step) {
            merge_(nums, i, i+step-1, min(i+2*step-1,n-1));
        }
    }
}
int main() {
    // 随机数生成
    int nums[20];
    srand((int)time(0));
    for(int i=0; i<20; i++) nums[i] = random(255);
    // 自定义函数排序
    mergeSortI(nums, 0, 19);
    //mergeSortII(nums, 20);
    for(int i=0; i<20; i++) cout << nums[i] << " ";
    cout << "\n";
    // 库函数排序
    sort(nums, nums+20);
    for(int i=0; i<20; i++) cout << nums[i] << " ";
    return 0;
}
```

