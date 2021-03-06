# 线性表

线性表是具有相同数据类型的n个数据元素的有限序列。除第一个元素外，每个元素有且仅有一个直接前驱。除最后一个元素外，每个元素有且仅有一个直接后继。

线性表是一种逻辑结构，表示元素之间一对一的相邻关系。而顺序表和链表是指存储结构，两者属于不同层面的概念。

## 1. 顺序表

顺序表是用一组<u>**地址连续**</u>的存储单元依次存储线性表中的数据元素，从而使得<u>**逻辑相邻**</u>的两个元素在<u>**物理位置**</u>上也相邻。

顺序表的主要特点是<u>**随机访问**</u>，通过首地址和元素序号可以在时间O(1)内找到指定的元素。由于物理相邻，插入和删除操作需要移动大量元素。

### 1.1 有序数组的二分查找

```c++
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define random(x) rand()%(x)
using namespace std;
// 递归的二分查找
int binarySearchI(int nums[], int low, int high, int target) {
    if (low > high) return low;
    int mid = (low + high) / 2;
    if (target == nums[mid]) return mid;
    else if(target < nums[mid]) return binarySearchI(nums, low, mid-1, target);
    else return binarySearchI(nums, mid+1, high, target);
}
// 迭代的二分查找
int binarySearchII(int nums[], int low, int high, int target) {
    while (low < high) {
    	int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;
        else if(nums[mid] > target) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}
int main() {
    // 随机数生成
    int nums[20];
    srand((int)time(0));
    for(int i = 0; i < 20; i++) nums[i] = random(255);
    sort(nums, nums+20);
    int target = nums[10];
    cout << binarySearchI(nums, 0, 19, target) << "\n";
    cout << binarySearchII(nums, 0, 19, target) << "\n";
    return 0;
}
```

## 2. 链表

链式存储线性表时，不需要使用地址连续的存储单元，即不要求逻辑相邻的元素在物理位置也相邻。链表通过“链”建立起数据元素之间的逻辑关系，因此插入和删除操作不需要移动元素，而只需修改指针，但也会失去顺序表可随机存取的优点。

### 2.1. 单链表

```c++
struct Node {
    ElemType data;
    Node* next;
};
```

在单链表第一个结点之前附加一个结点，成为<u>**头结点**</u>。头结点的指针域指向线性表的第一个元素结点。

单链表的前插操作可以转化为后插操作，然后交换数据域。

单链表的删除操作可以通过删除后继结点来实现，实质是将后继结点的值赋予自身，然后删除后继结点。

### 2.2. 双链表

```c++
struct Node {
	ElemType data;
	Node* prior;
	Node* next;
};
```

在实际的软件开发中，<u>**从链表中删除一个数据无外乎两种情况**</u>：

1. 删除结点中“值等于某个给定值”的结点。
2. 删除给定指针指向的结点。

对于第一种情况，不管单链表还是双链表，为了查找到值等于给定值的结点，都需要从头结点开始一个一个依次遍历对比，直到找到值等于给定值的结点，然后进行删除操作，时间复杂度为O(n)。

对于第二种情况，假设已经找到要删除的结点，但删除某个结点需要知道其前驱结点，而单链表并不支持<u>**直接**</u>获取前驱结点，删除操作的时间复杂度为O(n)。而双链表的删除操作的时间复杂度为O(1)。这是用空间换时间的设计思想。

### 2.3. 循环单链表

循环单链表和单链表的区别在于表中最后一个结点的指针不是NULL，而改为指向头结点，因此循环单链表的判空条件是头结点的指针是否等于头指针。

因为循环单链表是一个环，所以在任何一个位置上的插入和删除操作都是等价的，无须判断是否是表尾。

### 2.4. 循环双链表

头结点的prior指针要指向表尾结点。

当表为空表，头结点的prior指针和next指针都指向头结点。

------

# 栈

栈是只允许在一段进行插入或删除操作的线性表。栈的操作特性可以明显地概括为<u>**后进先出**</u>（Last in First out， LIFO）。

------

# 队列

队列也是一种操作受限的线性表，只允许在表的一端进行插入，而在表的另一端进行删除。向队列中插入元素成为入队或进队，删除元素成为出队或离队。队列的操作特性是<u>**先进先出**</u>（First in First out，FIFO）。

## 1. 循环队列

将顺序队列臆造为一个环状的空间，即把存储队列元素的表从逻辑上视为一个环，称为循环队列。在数组中可以通过<u>**除法取余运**</u>算来实现。

## 2. 双端队列

双端队列是指允许两端都可以进行入队和出队操作的队列，两端分别成为前端和后端。

------

# 应用

## 1. 基于链表实现LRU缓存淘汰

缓存是一种提高数据读取性能的技能，在硬件设计、软件开发中都有着非常广泛的应用，比如常见的CPU缓存、数据库缓存、浏览器缓存等。当缓存被用满时，有三种常见的淘汰策略：<u>**先进先出策略FIFO**</u>（First in First Out）、<u>**最少使用策略LFU**</u>（Least Frequently Used）、<u>**最近最少使用策略LRU**</u>（Least Recently Used）。

策略：维护一个有序单链表，越靠近链表尾部的结点是越早之前访问的。当有一个新的数据被访问时，从链表头开始顺序遍历链表。

1. 如果此前数据已经被缓存在链表中，遍历得到这个数据对应的结点，并将其从原来的位置删除，然后再插入到链表的头部。
2. 如果该数据没有在缓存链表中，分两种情况

* 此时缓存未满，直接将此结点插入到链表的头部。
* 此时缓存已满，则链表尾部结点删除，将新的数据结点插入到链表的头部。

优化：用Hash Table记录每个数据的位置，将缓存访问的时间复杂度降到O(1)。

## 2. 递归反转链表

## 3. 约瑟夫问题

N个人围成一圈，从第一个开始报数，第M个将被杀掉，最后剩下一个，其余人都将被杀掉。模拟杀人过程，输出杀人顺序。