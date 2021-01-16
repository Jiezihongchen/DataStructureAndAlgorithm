# 快速排序

```c++
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define random(x) rand()%(x)
using namespace std;
int partition_(int nums[], int low, int high) {
    int temp = nums[low];
    while(low<high) {
        while(nums[high]>=temp&&low<high) high--; nums[low]=nums[high];
        while(nums[low]<=temp&&low<high) low++; nums[high]=nums[low];
    }
    nums[low] = temp;
    return low;
}
void quickSort(int nums[], int low, int high) {
    if(low>=high) return;
    int part = partition_(nums, low, high);
    quickSort(nums, low, part-1);
    quickSort(nums, part+1, high);
}
int main() {
    // 随机数生成
    int nums[20];
    srand((int)time(0));
    for(int i=0; i<20; i++) nums[i] = random(255);
    // 自定义函数排序
    quickSort(nums, 0, 19);
    for(int i=0; i<20; i++) cout << nums[i] << " ";
    cout << "\n";
    // 库函数排序
    sort(nums, nums+20);
    for(int i=0; i<20; i++) cout << nums[i] << " ";
    return 0;
}
```

------

# 三向排序

```c++
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define random(x) rand()%(x)
using namespace std;
void quickSort(int nums[], int low, int high) {
    if(low>=high) return;
    int lt = low, mid = low + 1, gt = high;
    int temp = nums[low];
    while(mid<=gt) {
        if(nums[mid]==temp) mid++;
        else if(nums[mid]<temp) {
            swap(nums[mid], nums[lt]);
            mid++;lt++;
        } else {
            swap(nums[gt], nums[mid]);
            gt--;
        }
    }
    quickSort(nums, low, lt-1);
    quickSort(nums, gt+1, high);
}
int main() {
    // 随机数生成
    int nums[20];
    srand((int)time(0));
    for(int i=0; i<20; i++) nums[i] = random(255);
    // 自定义函数排序
    quickSort(nums, 0, 19);
    for(int i=0; i<20; i++) cout << nums[i] << " ";
    cout << "\n";
    // 库函数排序
    sort(nums, nums+20);
    for(int i=0; i<20; i++) cout << nums[i] << " ";
    return 0;
}
```

------

# 应用

------

## 1. 荷兰旗

------

## 2. 用快排思想在O(n)内查找第k大元素