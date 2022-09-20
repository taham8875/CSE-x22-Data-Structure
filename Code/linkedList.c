#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int listLength(struct node **head)
{
    struct node *current = *head;
    int count = 0;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void insert(struct node **head, int data, int position)
{

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode)
    {
        printf("Memory error");
        return;
    }

    newNode->data = data;

    struct node *temp = *head;
    int index = 0;
    if (position == 0)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        for (int i = 0; (i < position) && (temp->next != NULL); i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteNode(struct node **head, int position)
{
    if (*head == NULL)
    {
        printf("Empty list");
    }

    struct node *temp = *head;
    if (position == 0)
    {
        *head = (*head)->next;
        free(temp);
        return;
    }
    else
    {

        for (int i = 0; (i < position) && (temp->next != NULL); i++)
        {

            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            printf("Position does not exist");
        }
        else
        {
            struct node *afterTemp = temp->next;
            temp->next = (temp->next)->next;
            free(afterTemp);
            return;
        }
    }
}

void deleteList(struct node **head)
{
    struct node *temp = *head;
    struct node *afterTemp = temp->next;
    while (afterTemp != NULL)
    {
        free(temp);
        temp = afterTemp;
        afterTemp = afterTemp->next;
    }
    free(temp);
    *head = NULL;
}

void printLinkedList(struct node **head)
{
    struct node *temp = *head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct node *head = NULL;
    insert(&head, 5, 0);
    insert(&head, 9, 1);
    insert(&head, 3, 2);
    insert(&head, 4, 3);
    insert(&head, 10, 4);
    insert(&head, 6, 5);
    printf("linked list : ");
    printLinkedList(&head);
    printf("length of linked list : %d\n", listLength(&head));
    deleteNode(&head, 0);
    deleteNode(&head, 1);
    deleteNode(&head, 2);
    printf("linked list : ");
    printLinkedList(&head);
    printf("length of linked list : %d\n", listLength(&head));
    deleteList(&head);
    printf("linked list is deleted.\n");
    printf("length of linked list : %d\n", listLength(&head));
}