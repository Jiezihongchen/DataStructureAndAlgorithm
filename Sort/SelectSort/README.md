每趟从待排序部分中选择最小的元素，令其与待排序部分的第一个元素元素交换。

```c++
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define random(x) rand()%(x)
using namespace std;
void selectSort(int nums[], int n) {
    int index;
    for (int i = 0; i < n-1; i++) {
        index = i;
        for (int j = i + 1; j < n; j++)
            if (nums[j] < nums[index]) index = j;
        swap(nums[i], nums[index]);
    }
}
int main() {
    // 随机数生成
    int nums[20];
    srand((int)time(0));
    for (int i = 0; i < 20; i++) nums[i] = random(255);
    // 自定义函数排序
    selectSort(nums, 20);
    for (int i = 0; i < 20; i++) cout << nums[i] << " ";
    cout << "\n";
    // 库函数排序
    sort(nums, nums+20);
    for (int i = 0; i < 20; i++) cout << nums[i] << " ";
    return 0;
}
```

![selectionSort](README.assets/selectionSort.gif)