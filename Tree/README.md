# 基本术语和概念

1. 考虑结点K。根A到结点K的唯一路径上的任意结点，称为结点K的祖先，而K是这些结点的子孙。路径上最接近结点K的结点E称为K的双亲，而K为结点E的孩子。根A是树中唯一没有双亲的结点。有相同双亲的结点称为兄弟。
2. 树中一个结点的孩子个数称为该<u>**结点的度**</u>，树中结点的最大度数称为<u>**数的度**</u>。
3. 度大于0的结点称为<u>**分支结点**</u>，又称<u>**非终端结点**</u>。度为0的结点称为<u>**叶子结点**</u>，又<u>**称终端节点**</u>。
4. <u>**结点的层次**</u>从树根开始定义，根结点是第1层。双亲在同一层的结点互为堂兄弟。<u>**结点的深度**</u>是从根结点开始自顶向下逐层累加的。<u>**结点的高度**</u>是从叶结点开始自底向上逐层累加的。
5. 森林是m棵互不相交的树的集合。只要把树的根节点删去就成了森林。

------

# 二叉树遍历

二叉树的遍历是指按某条搜索路径访问树中每个结点，使得每个结点均被访问一次，而且仅被访问一次。常见的遍历次序有先序、中序、后序和层次遍历，其中<u>**序指的是根结点在何时被访问**</u>。

```c++
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int N = 9;
vector<int> preRes, inRes;
struct node {
    int data;
    int layer;
    node* left;
    node* right;
};
// 创建结点
node* createNode(int data) {
    node* Node = new node;
    Node->data = data;
    Node->left = Node->right = NULL;
    return Node;
}
// 插入结点
void insertNode(node* &root, int data) {
    if(root==NULL) {
        root = createNode(data);
    } else {
        if (data==root->data) return;
        else if(data<root->data) insertNode(root->left, data);
        else insertNode(root->right, data);
    }
}
// 建立二叉树
node* createBinaryTree(int nums[], int n) {
    node* root = NULL;
    for(int i=0; i<n; i++) insertNode(root, nums[i]);
    return root;
}
// 先序遍历
void preOrder(node* root) {
    if(root==NULL) return;
    preRes.push_back(root->data);
    //cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
// 中序遍历
void inOrder(node* root) {
    if(root==NULL) return;
    inOrder(root->left);
    inRes.push_back(root->data);
    //cout << root->data << " ";
    inOrder(root->right);
}
// 后序遍历
void postOrder(node* root) {
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    //cout << root->data << " ";
}
// 层次遍历
void layerOrder(node* root) {
    queue<node*> q;
    q.push(root);
    root->layer = 1;
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left!=NULL) {
            temp->left->layer = temp->layer+1;
            q.push(temp->left);
        }
        if(temp->right!=NULL) {
            temp->right->layer = temp->layer+1;
            q.push(temp->right);
        }
    }
}

node* reCreate(int preLeft, int preRight, int inLeft, int inRight) {
    if(preLeft>preRight) return NULL;
    node* root = new node;
    root->data = preRes[preLeft];
    // 寻找先序遍历头结点在中序遍历中的位置
    int index = 0;
    for(vector<int>::iterator it=inRes.begin(); it!=inRes.end(); it++, index++) {
        if((*it)==preRes[preLeft]) break;
    }
    // 左子树结点个数
    int leftNumber = index - inLeft;
    root->left = reCreate(preLeft+1, preLeft+leftNumber, inLeft, index-1);
    root->right = reCreate(preLeft+leftNumber+1, preRight, index+1, inRight);
    return root;
}
// 使用先序遍历和中序遍历构建二叉树
void reCreateBinaryTree(node* root) {
    preRes.clear();
    preOrder(root);
    cout << "original preRes:" << " ";
    for(vector<int>::iterator it=preRes.begin(); it!=preRes.end(); it++) cout << *it << " "; cout << endl;
    inRes.clear();
    inOrder(root);
    cout << "original inRes:" << " ";
    for(vector<int>::iterator it=inRes.begin(); it!=inRes.end(); it++) cout << *it << " "; cout << endl;

    node* reRoot = reCreate(0, N-1, 0, N-1);

    preRes.clear();
    preOrder(reRoot);
    cout << "recreated preRes:" << " ";
    for(vector<int>::iterator it=preRes.begin(); it!=preRes.end(); it++) cout << *it << " "; cout << endl;
    inRes.clear();
    inOrder(reRoot);
    cout << "recreated inRes:" << " ";
    for(vector<int>::iterator it=inRes.begin(); it!=inRes.end(); it++) cout << *it << " "; cout << endl;
}
// 搜索结点
void searchNode(node* root, int data) {
    if(root==NULL) {
        cout << "search failed" << endl;
        return;
    }
    if(data==root->data) cout << "search succeeded" << endl;
    else if(data<root->data) searchNode(root->left, data);
    else searchNode(root->right, data);
}
// 寻找最大权值结点
node* findMax(node* root) {
    while(root->right!=NULL) root = root->right;
    return root;
}
// 寻找最小权值结点
node* findMin(node* root) {
    while(root->left!=NULL) root = root->left;
    return root;
}
// 删除结点
void deleteNode(node* &root, int data) {
    if(root==NULL) return;
    if(root->data==data) {
        if(root->left==NULL&&root->right==NULL) {
            root = NULL;
        } else if(root->left!=NULL) {
            node* pre = findMax(root->left);
            root->data = pre->data;
            deleteNode(root->left, pre->data);
        } else {
            node* next = findMin(root->right);
            root->data = next->data;
            deleteNode(root->right, next->data);
        }
    } else if(root->data>data) {
        deleteNode(root->left, data);
    } else {
        deleteNode(root->right, data);
    }
}
int main() {
    int nums[] = {7, 21, 36, 9, 1, 13, 28, 6, 18};
    node* root = createBinaryTree(nums, N);
    //preOrder(root); cout << endl;
    //inOrder(root); cout << endl;
    //postOrder(root); cout << endl;
    //reCreateBinaryTree(root);
    //searchNode(root, 36);
    //deleteNode(root, 7);
    return 0;
}
```

------

# 线索二叉树

------

# 平衡二叉树

```c++
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 9;
struct node {
    int data, height;
    node* left;
    node* right;
};
// 获取树高
int getHeight(node* root) {
    return root == NULL ? 0 : root->height;
}
// 平衡因子
int getBalanceFactor(node* root) {
    return getHeight(root->left) - getHeight(root->right);
}
// 更新树高
void updateHeight(node* root) {
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
}
// 左旋
void leftRotation(node* &root) {
    node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
// 右旋
void rightRotation(node* &root) {
    node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
// 创建结点
node* createNode(int data) {
    node* Node = new node;
    Node->left = Node->right = NULL;
    Node->data = data;
    Node->height = 1;
    return Node;
}
// 插入结点
void insertNode(node* &root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return;
    }
    if (data <= root->data) {
        insertNode(root->left, data);
        updateHeight(root);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->left) == 1) {
                rightRotation(root);
            } else if (getBalanceFactor(root->left) == -1) {
                leftRotation(root->left);
                rightRotation(root);
            }
        }
    } else {
        insertNode(root->right, data);
        updateHeight(root);
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->right) == -1) {
                leftRotation(root);
            } else if (getBalanceFactor(root->right) == 1) {
                rightRotation(root->right);
                leftRotation(root);
            }
        }
    }
}
// 建立二叉树
node* createBinaryTree(int nums[], int n) {
    node* root = NULL;
    for(int i = 0; i < n; i++) insertNode(root, nums[i]);
    return root;
}
// 先序遍历
void preOrder(node* root) {
    if(root==NULL) return;
    //cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
// 中序遍历
void inOrder(node* root) {
    if(root==NULL) return;
    inOrder(root->left);
    //cout << root->data << " ";
    inOrder(root->right);
}
int main() {
    int nums[] = {7, 21, 36, 9, 1, 13, 28, 6, 18};
    node* root = createBinaryTree(nums, N);
    //preOrder(root); cout <<endl;
    //inOrder(root);
    return 0;
}
```

------

# 并查集

------

# 哈夫曼树

```c++
#include<iostream>
#include<queue>
using namespace std;
const int MAXN = 255;
int main() {
    priority_queue<int, vector<int>, greater<int>> q;
    int n, x, y , temp, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        q.push(temp);
    }
    while (q.size() > 1) {
        x = q.top(); q.pop();
        y = q.top(); q.pop();
        q.push(x + y);
        ans = ans + x + y;
    }
    cout << ans << endl;
    return 0;
}
```

------

# 哈夫曼编码

## 1. 用贪心算法实现哈夫曼压缩编码

------

# 红黑树