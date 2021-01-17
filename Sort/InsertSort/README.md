```c++
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define random(x) rand()%(x)
using namespace std;
void insertSort(int nums[], int n) {
    for (int i = 1; i < n; i++) {
        if (nums[i] < nums[i-1]) {
            int j = i;
            while (nums[j] < nums[j-1] && j > 0) {
                swap(nums[j], nums[j-1]);
                j--;
            }
        }
    }
}
int main() {
    // 随机数生成
    int nums[20];
    srand((int)time(0));
    for (int i = 0; i < 20; i++) nums[i] = random(255);
    // 自定义函数排序
    insertSort(nums, 20);
    for (int i = 0; i < 20; i++) cout << nums[i] << " ";
    cout << "\n";
    // 库函数排序
    sort(nums, nums + 20);
    for (int i = 0; i < 20; i++) cout << nums[i] << " ";
    return 0;
}
```

![insertionSort](README.assets/insertionSort.gif)