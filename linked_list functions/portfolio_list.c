#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList
{
    Node *head;
    Node *tail;
    int size;
} LinkedList;

LinkedList *createLinkedList(void);
int size(LinkedList *list);
int valueAt(LinkedList *list, int index);
void pushFront(LinkedList *list, int value);
int popFront(LinkedList *list);
void pushBack(LinkedList *list, int value);
int popBack(LinkedList *list);
int front(LinkedList *list);
int back(LinkedList *list);
int insert(LinkedList *list, int index, int value);
int erase(LinkedList *list, int index);
int valueNFromEnd(LinkedList *list, int n);
void reverse(LinkedList *list);
void removeValue(LinkedList *list, int value);
void printList(LinkedList *list);
void freeList(LinkedList *list);

int main(void)
{
    LinkedList *list = createLinkedList();
    pushBack(list, 1);
    pushBack(list, 2);
    pushBack(list, 3);
    pushBack(list, 4);
    pushBack(list, 5);
    pushBack(list, 6);
    pushBack(list, 7);

    printList(list);
    printf("Size: %d\n", size(list));
    printf("Value at index 3: %d\n", valueAt(list, 3));
    printf("Value at index 0: %d\n", valueAt(list, 0));
    printf("Value at index 6: %d\n", valueAt(list, 6));

    printf("Pop front: %d\n", popFront(list));

    printList(list);
    printf("Size: %d\n", size(list));

    printf("Pop back: %d\n", popBack(list));

    printList(list);
    printf("Size: %d\n", size(list));

    printf("Front: %d\n", front(list));
    printf("Back: %d\n", back(list));

    insert(list, 3, 10);
    printList(list);
    printf("Size: %d\n", size(list));

    erase(list, 3);
    printList(list);
    printf("Size: %d\n", size(list));
    
    printf("Value at 3rd from end: %d\n", valueNFromEnd(list, 3));

    reverse(list);
    printList(list);

    removeValue(list, 5);
    printList(list);
    printf("Size: %d\n", size(list));

    freeList(list);
    return (0);
}

 LinkedList *createLinkedList(void)
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return (list);
}

int size(LinkedList *list)
{
    return (list->size);
}

int valueAt(LinkedList *list, int index)
{
    if (index < 0 || index >= list->size)
        return (-1);
    Node *current = list->head;
    for (int i = 0; i < index; i++)
        current = current->next;
    return (current->data);
}

void pushFront(LinkedList *list, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
    if (list->size == 0)
        list->tail = newNode;
    list->size++;
}

int popFront(LinkedList *list)
{
    if (list->size == 0)
        return (-1);
    Node *node = list->head;
    int value = node->data;
    list->head = list->head->next;
    free(node);
    list->size--;
    if (list->size == 0)
        list->tail = NULL;
    return (value);
}

void pushBack(LinkedList *list, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (list->size == 0)
        list->head = newNode;
    else
        list->tail->next = newNode;
    list->tail = newNode;
    list->size++;
}

int popBack(LinkedList *list)
{
    if (list->size == 0)
        return (-1);
    int value = list->tail->data;
    if (list->size == 1)
    {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        Node *current = list->head;
        while (current->next != list->tail)
            current = current->next;
        free(list->tail);
        list->tail = current;
        list->tail->next = NULL;
    }
    list->size--;
    return (value);
}

int front(LinkedList *list)
{
    if (list->size == 0)
        return (-1);
    return (list->head->data);
}

int back(LinkedList *list)
{
    if (list->size == 0)
        return (-1);
    return (list->tail->data);
}

int insert(LinkedList *list, int index, int value)
{
    if (index < 0 || index > list->size)
        return (-1);
    if (index == 0)
    {
        pushFront(list, value);
        return (0);
    }
    if (index == list->size)
    {
        pushBack(list, value);
        return (0);
    }
    Node *current = list->head;
    for (int i = 0; i < index - 1; i++)
        current = current->next;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = current->next;
    current->next = newNode;
    list->size++;
    return (0);
}

int erase(LinkedList *list, int index)
{
    if (index < 0 || index >= list->size)
        return (-1);
    if (index == 0)
    {
        popFront(list);
        return (0);
    }
    if (index == list->size - 1)
    {
        popBack(list);
        return (0);
    }
    Node *current = list->head;
    for (int i = 0; i < index - 1; i++)
        current = current->next;
    Node *node = current->next;
    current->next = node->next;
    free(node);
    list->size--;
    return (0);
}

int valueNFromEnd(LinkedList *list, int n)
{
    if (n < 0 || n >= list->size)
        return (-1);
    Node *current = list->head;
    for (int i = 0; i < list->size - n - 1; i++)
        current = current->next;
    return (current->data);
}

void reverse(LinkedList *list)
{
    if (list->size <= 1)
        return;
    Node *current = list->head;
    Node *prev = NULL;
    Node *next = NULL;
    list->tail = list->head;
    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
}

void removeValue(LinkedList *list, int value)
{
    Node *current = list->head;
    Node *prev = NULL;
    while (current)
    {
        if (current->data == value)
        {
            if (prev)
                prev->next = current->next;
            else
                list->head = current->next;
            if (!current->next)
                list->tail = prev;
            free(current);
            list->size--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void printList(LinkedList *list)
{
    Node *current = list->head;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeList(LinkedList *list)
{
    Node *current = list->head;
    Node *next = NULL;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}