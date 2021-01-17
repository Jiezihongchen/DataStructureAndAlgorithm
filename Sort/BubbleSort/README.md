冒泡排序的本质在于<u>**交换**</u>，每次通过交换的方式把当前剩余元素的最大值移动到一端。

```c++
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define random(x) rand()%(x)
using namespace std;
void bubbleSort(int nums[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (nums[j] > nums[j+1]) swap(nums[j], nums[j + 1]);
}
int main() {
    // 随机数生成
    int nums[20];
    srand((int)time(0));
    for (int i = 0; i < 20; i++) nums[i] = random(255);
    // 自定义函数排序
    bubbleSort(nums, 20);
    for (int i = 0; i < 20; i++) cout << nums[i] << " ";
    cout << "\n";
    // 库函数排序
    sort(nums, nums + 20);
    for (int i = 0; i < 20; i++) cout << nums[i] << " ";
    return 0;
}
```

![bubbleSort](README.assets/bubbleSort.gif)