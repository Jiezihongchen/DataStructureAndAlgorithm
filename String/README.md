# 简单的模式匹配算法

子串的定位操作通常称为串的模式匹配，求的是子串（常称模式串）在主串中的位置。

<u>**暴力匹配算法**</u>：从主串S的第一个字符起，与模式T的第一个字符比较，若相等，则继续逐个比较后续字符串。否则从主串的下一个字符起，重新和模式的字符比较。以此类推，直至模式T中的每个字符依次和主串S中的一个连续的字符序列相等。

```c++
int index(SString S, SString T) {
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[j]) {
            i++; j++;
        } else {
            i = i - j + 2; j = 1;
        }
    }
    if (j > T.length) return i - T.lenght;
    else return -1;
}
```

分别用指针i和j指示主串S和模式串T中当前正待比较的字符串位置。暴力模式匹配算法的最坏时间复杂度为O(mn)。

------

# Next数组

假设有一个字符串s，下标从0开始，那么它以i号位作为结尾的子串就是s[0……i]。对该子串来说，长度为k+1的前缀和后缀分别是s[0……k]和s[i-k……i]。现在定义一个int类型数组next，其中<u>**next[i]表示使子串s[0……i]的前缀s[0……k]等于后缀s[i-k……i]的最大的k，前缀和后缀可以部分重叠，但不能是s[0……i]本身**</u>。如果找不到相等的前后缀，那么就令next[i]=-1。<u>**next[i]就是所求最长相等前后缀中前缀最后一位的下标**</u>。

```c++
void getNext(char str[], int length) {
    int j = -1;
    next[0] = -1;
    for (int i = 0; i < length; i++) {
        while (j != -1 && str[i] != str[j + 1]) j = next[j];
        if (str[i] == str[j + 1]) j++;
        next[i] = j;
    }
}
```

------

# KMP算法

i指向text的当前欲比较位，j指向pattern中<u>**当前已被匹配**</u>的最后位。<u>**next数组的含义是当j+1位失配时，j应该回退到的位置**</u>。

KMP算法的一般思路：

1. 初始化j=-1，表示pattern当前已被匹配的最后位。
2. 让i遍历文本串text，对每个i，执行3和4来试图匹配text[i]和pattern[j+1]。
3. 不断令j=next[j]，直到j回退为-1，或是text[i]=pattern[j+1]成立。
4. 如果text[i]==pattern[j+1]，则令j++。如果j达到m-1，说明pattern是text的子串，返回true。

```c++
bool KMP(char text[], char pattern[]) {
    int n = strlen(text), m = strlen(pattern);
    getNext(pattern, m);
    int j = -1;
    for (int i = 0; i < n; i++) {
        while (j != -1 && text[i] != pattern[j + 1]) j = next[j];
        if (text[i] == pattern[j + 1]) j++;
        if (j == m - 1) return true;
    }
    return false;
}
```

j++最多执行n次，while循环的j减少最多执行n次，j在整个过程中的变化次数是O(n)级别的，所以for循环的整体时间复杂度是O(n)，获取next数组的时间复杂度是O(m)，kmp算法的时间复杂度是O(m+n)。

------

# 优化next数组

```c++
void getNextval(char str[], int lenght) {
    int j = -1;
    for (int i = 1; i < lenght; i++) {
        while (j != -1 && str[i] != str[j + 1]) j = nextval[j];
        if (str[j + 1] == str[i]) j++;
        if (j == -1 && str[j + 1] != str[i])
            nextval[i] = j;
        else
            nextval[i] = nextval[j];
    }
}
```

优化后的next数组被称为nextval数组，丢失了next数组的最长相等前后缀的含义，可以把nextval[i]的含义理解为当模式串pattern的i+1位发生失配时，i应回退到的最佳位置。

------

# AC自动机

