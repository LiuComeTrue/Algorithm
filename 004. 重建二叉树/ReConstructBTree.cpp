#include<iostream>
#include<vector>
using namespace std;

struct BinaryTree {
    int value;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(int x){
        this->value = x;
        this->left = NULL;
        this->right = NULL;
    };
};
BinaryTree *ReConstructBTree(int *preStart, int *preEnd, int *inStart, int *inEnd);
void PrePrint(BinaryTree *tree);
void MidPrint(BinaryTree *tree);
int main(){
    int pre[] = {1, 2, 4, 7, 3, 5, 6, 8}; //前序遍历数组
    int in[] = {4, 7, 2, 1, 5, 3, 8, 6};  //中序遍历数组

    //int pre[] = {1} ;
    //int in[] = {1};

    //int pre[] = {1, 2, 3, 4};
    //int in[] = {4, 3, 2, 1};

    //int pre[] = {1, 2, 3, 4};
    //int in[] = {1, 2, 3, 4};

    //int pre[] = {1, 2, 3, 4};
    //int in[] = {1, 2, 3};

    BinaryTree *tree = ReConstructBTree(pre, pre + sizeof(pre) / 4 - 1, in, in + sizeof(in) / 4 - 1);
    PrePrint(tree);
    cout << endl;
    MidPrint(tree);
}
//递归
//前序遍历的第一个数字是根节点的值，在中序遍历数组中找到这个值，左边的为左子树，右边的为右子树
//左右子树的值对应前序遍历数组的值，前序中第一个值为根节点，此根节点为上一节点的左右子节点
//求数组的根节点，再以此根节点将数组分为两个左右子树数组，再递归此两个数组获取根节点，作为前一个根节点的左右子节点
BinaryTree *ReConstructBTree(int *preStart, int *preEnd, int *inStart, int *inEnd) {
    if (preEnd < preStart || inEnd < inStart)
        return NULL;
    if (preEnd - preStart != inEnd - inStart) {
        cout << "前序遍历和中序遍历长度不等" << endl;
        return NULL;
    }
    BinaryTree *root = new BinaryTree(preStart[0]);
    int i = 0;
    int *index = inStart;
    while(index != inEnd) {
        if (*index == preStart[0])
            break;
        index++;
        i++;
    }
    root->left = ReConstructBTree(preStart + 1, preStart + i, inStart, index - 1);
    root->right = ReConstructBTree(preStart + i + 1, preEnd, index + 1, inEnd);
    return root;
}

void PrePrint(BinaryTree *tree) {
    if (tree == NULL)
        return;
    cout << tree->value << " ";
    PrePrint(tree->left);
    PrePrint(tree->right);
}

void MidPrint(BinaryTree *tree) {
    if (tree == NULL)
        return;
    MidPrint(tree->left);
    cout << tree->value << " ";
    MidPrint(tree->right);
}
