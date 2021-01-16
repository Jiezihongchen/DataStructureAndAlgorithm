# 数塔问题

------

# 最大连续子序列和

------

# 最长不下降子序列(LIS)

```c++
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int n, nums[255], dp[255] = {1}, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++) {
            if (nums[i] >= nums[j]) dp[i] = max(dp[j] + 1, dp[i]);
            ans = max(dp[i], ans);
        }
    cout << ans << endl;
    return 0;
}
```

------

# 最长公共子序列(LCS)

------

# 最长回文子串

------

# 背包问题

## 1. 01背包问题

## 2. 完全背包问题