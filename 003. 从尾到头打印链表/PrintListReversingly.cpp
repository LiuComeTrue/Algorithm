#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;
typedef struct Node {
    int value;
    struct Node* next;
}Node, *List;
void Insert(List head, int x);
void PrintList_ReversePointer(List* head);
void PrintList_Recursively(List node);
void PrintList_Stack(List head);
int main() {
    List head = (List)malloc(sizeof(Node));
    if (head == NULL)
        cout << "申请内存空间失败" << endl;
    head->value = 1;
    head->next = NULL;

    Insert(head, 1);
    Insert(head, 2);
    Insert(head, 3);
    Insert(head, 4);
    List h = head;
    while(h->next != NULL) {
        cout << h->next->value << " ";
        h = h->next;
    }

    cout << "\n递归：" << endl;
    PrintList_Recursively(head->next);

    cout << "\n栈：" << endl;
    PrintList_Stack(head);

    cout << "\n反转指针：" << endl;
    PrintList_ReversePointer(&head);
    return 0;
}
void Insert(List head, int x) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL)
        cout << "申请内存空间失败" << endl;
    node->value = x;
    node->next = NULL;
    while(head->next != NULL)
        head = head->next;
    head->next = node;
    head = head->next;
}
//将链表指针反转
//改变了原链表的结构
void PrintList_ReversePointer(List* head) {
    //如果少于等于两个节点，不需要反转
    if ((*head)->next == NULL || (*head)->next->next == NULL)
        return;
    Node *p;
    Node *q;
    Node *r;
    p = *head;
    q = p->next;
    p = NULL;

    while (q != NULL) {
        r = q->next;

        q->next = p;
        p = q;
        q = r;
    }
    (*head) = p;
    while((*head) != NULL) {
        cout << (*head)->value << " ";
        (*head) = (*head)->next;
    }
}

void PrintList_Recursively(List node) {
    if (node == NULL)
        return;
    PrintList_Recursively(node->next);
    cout << node->value << " ";
}

void PrintList_Stack(List head) {
    stack<List> s;
    while(head->next != NULL) {
        s.push(head->next);
        head = head->next;
    }
    Node *node;
    while(!s.empty()) {
        node = s.top();
        cout << node->value << " ";
        s.pop();
    }
}
