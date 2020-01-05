#include<studio.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

void push(node* head, int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void print(node* head)
{
    node* temp = head;
    while(temp->next!=NULL)
    {
        print("%d\t",temp->data);
        temp = temp->next;
    }
}


int main()
{
    node* head = NULL;
    push(head, 2);
    push(head, 3);
    push(head, 4);
    print();
}

