#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 255;
int heap[MAXN], N;
// 向下调整
void downAdjust(int low, int high) {
    int i = low, j = low * 2;
    while (j <= high) {
        if (j + 1 <= high && heap[j] < heap[j + 1]) j = j + 1;
        if (heap[i] < heap[j]) {
            swap(heap[i], heap[j]);
            i = j; j = i * 2;
        } else break;
    }
}
// 建堆
void createHeap() {
    for (int i = N / 2; i >= 1; i--) 
        downAdjust(i, N);
}
// 删除堆顶元素
void deleteTop() {
    heap[1] = heap[N--];
    downAdjust(1, N);
}
// 向上调整
void upAdjust(int low, int high) {
    int i = high, j = high / 2;
    while (j >= low) {
        if (heap[i] > heap[j]) {
            swap(heap[i], heap[j]);
            i = j; j = i / 2;
        } else break;
    }
}
// 插入元素
void insertElem(int data) {
    heap[++N] = data;
    upAdjust(1, N);
}
// 堆排序
void heapSort() {
    createHeap();
    for (int n = N; n >= 2; n--) {
        swap(heap[1], heap[n]);
        downAdjust(1, n - 1);
    }
    for (int i = 1; i <= N; i++)
        cout << heap[i] << " ";
    cout << endl;
}
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> heap[i];
    heapSort();
    return 0;
}