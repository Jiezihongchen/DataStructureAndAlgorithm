基本思想：先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，待整个序列中的记录"基本有序"时，再对全体记录进行依次直接插入排序。

```c++
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define random(x) rand()%(x)
using namespace std;
void shellSort(int nums[], int n) {
    int step = n / 2;
    while (step) {
        for (int i = step; i < n; i++) {
            if (nums[i] < nums[i - step]) {
                int index = i;
                while (index >= step && nums[index] < nums[index-step]) {
                    swap(nums[index], nums[index - step]);
                    index -= step;
                }
            }
        }
        step /= 2;
    }
}
int main() {
    // 随机数生成
    int nums[20];
    srand((int)time(0));
    for (int i = 0; i < 20; i++) nums[i] = random(255);
    // 自定义函数排序
    shellSort(nums, 20);
    for (int i = 0; i < 20; i++) cout << nums[i] << " ";
    cout << "\n";
    // 库函数排序
    sort(nums, nums + 20);
    for (int i = 0; i < 20; i++) cout << nums[i] << " ";
    return 0;
}
```

![Sorting_shellsort_anim](README.assets/Sorting_shellsort_anim.gif)