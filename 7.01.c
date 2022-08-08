#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

struct ListNode* createlist();
struct ListNode* deleteeven(struct ListNode* head);
void printlist(struct ListNode* head)
{
    struct ListNode* p = head;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode* head;
	printf("请输入正整数，输入-1，结束输入");
    head = createlist();
    head = deleteeven(head);
    printlist(head);

    return 0;
}

struct ListNode* createlist()
{
    struct ListNode* head, * tail, * temp;      
    head = (struct ListNode*)malloc(sizeof(struct ListNode));   
    head->next = NULL;
    tail = head;

    int data;
    scanf("%d", &data);
    while (data != -1)
    {
        temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->next = NULL;     
        temp->data = data;
        tail->next = temp;   
        tail = temp;
        scanf("%d", &data);
    }

    return head;
}

struct ListNode* deleteeven(struct ListNode* head)
{
    struct ListNode* current = head;   // 当前节点

    if (!head)
    {
        return NULL;
    }

    while (current->next)
    {
        if (current->next->data % 2 == 0)
        {
            struct ListNode* temp = current->next;
            current->next = temp->next;
            free(temp);
        }
        else
        {
            current = current->next;
        }
    }
    head = head->next;
    return head;
}


