#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

typedef struct list
{
    node *head;
    node *tail;
} list;

void printList(list *list1)
{
    // Traverses the entire list and prints out the data of each node
    node *ptr = list1->head;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf(" End\n");
}

void prepend(int data, list *list1)
{
    // Adds a node to the beginning of the list
    node *link = (node*) malloc(sizeof(node));
    
    link->data = data;
    link->next = list1->head;
    link->prev = NULL;
    if (list1->tail == NULL)
    {
        (*list1).tail = link;
    }
    else
    {
        (*list1).head->prev = link;
    }
    (*list1).head = link;
}

void append(int data, list *list1)
{
    // Adds a node to the end of the list
    if (list1->head == NULL)
    {
        prepend(data, list1);
    }
    else
    {
        node *link = (node*) malloc(sizeof(node));
        link->data = data;
        link->next = NULL;
        (*list1).tail->next = link;
        link->prev = list1->tail;
        (*list1).tail = link;
    }
}

int find(int key, list *list1)
{
    // Searches the list for the given key and returns the index or -1 if not found
    node *curr = list1->head;
    int index = 0;
    while (curr != NULL && curr->data != key)
    {
        curr = curr->next;
        index++;
    }
    if (curr != NULL)
    {
        return index;
    }
    return -1;
}

void remove_at(int index, list *list1)
{
    // Removes the node found at the given position
    if (index <= 0 || list1->head->next == NULL)
    {
        (*list1).head = list1->head->next;
        if (list1->head == NULL)
        {
            (*list1).tail = NULL;
        }
        else
        {
            (*list1).head->prev = NULL;
        }
    }
    else
    {
        node *curr = list1->head;
        while (index > 1 && curr->next->next != NULL)
        {
            curr = curr->next;
            index--;
        }
        if (curr->next == list1->tail)
        {
            (*list1).tail = curr;
        }
        else
        {
            curr->next->next->prev = curr;
        }
        curr->next = curr->next->next;
    }
}

int pop(list *list1)
{
    // Removes the last item in the list and returns its value
    int removedItem = list1->tail->data;
    (*list1).tail = list1->tail->prev;
    if (list1->tail == NULL)
    {
        (*list1).head = list1->tail;
    }
    else
    {
        (*list1).tail->next = NULL;
    }
    return removedItem;
}

int length(list *list1)
{
    // Returns the number of items in the list
    node *curr = list1->head;
    int count = 0;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

void anagram(list *list1, list *list2)
{
    // takes a linked list item and checks if they are anagrams of each other
    // prints the result to the terminal
    if (length(list1) != length(list2))
    {
        printf("Not an anagram");
        return;
    }
    else
    {
        while (length(list1) != 0)
        {
            int index = find(pop(list1), list2);
            if (index == -1)
            {
                printf("Not an anagram");
                return;
            }
            else
            {
                remove_at(index, list2);
            }
        }
        printf("That is an anagram");
    }
}

int main(void)
{
    // set up the lists
    list list1 = {NULL, NULL};
    list list2 = {NULL, NULL};
    // get user input
    printf("Enter the first word\n");
    char c = getchar();
    while (c != '\n')
    {
        append(c, &list1);
        c = getchar();
    }
    printf("Enter the second word\n");
    c = getchar();
    while (c != '\n')
    {
        append(c, &list2);
        c = getchar();
    }
    // check if they are anagrams
    anagram(&list1, &list2);
    return 0;
}