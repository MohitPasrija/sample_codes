#include<stdio.h>
#include<malloc.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

void push(node** head, int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void insert_end(node** head, int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    
    if(*head == NULL)
    {
       temp->next = *head;
        *head = temp;     
        return;
    }
    node* temp2 = *head;
    while(temp2->next!=NULL)
    {
        temp2 = temp2->next;   
    }
    temp2->next = temp;
}

void delete_at_beg(node** head)
{
    node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_at_end(node** head)
{
    node* temp = *head;
    node* temp2 = NULL;
    
    while(temp->next)
    {
        temp2 = temp;
        temp = temp->next;
    }
    
    temp2->next = NULL;
    free(temp);
}

void print(node* head)
{
    node* temp = head;
    while(temp)
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main()
{
    node* head = NULL;
    push(&head, 2);
    insert_end(&head,6);
    push(&head, 3);
    insert_end(&head,7);
    push(&head, 4);
    insert_end(&head,5);
    print(head);
    delete_at_beg(&head);
    print(head);
    delete_at_end(&head);
    print(head);
    delete_at_beg(&head);
    print(head);
}