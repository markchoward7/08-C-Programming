#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *head = NULL;
node *tail = NULL;

void printList()
{
    // Traverses the entire list and prints out the data of each node
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf(" End\n");
}

void prepend(int data)
{
    // Adds a node to the beginning of the list
    node *link = (node*) malloc(sizeof(node));
    
    link->data = data;
    link->next = head;
    link->prev = NULL;
    if (tail == NULL)
    {
        tail = link;
    }
    else
    {
        head->prev = link;
    }
    head = link;
}

void append(int data)
{
    // Adds a node to the end of the list
    if (head == NULL)
    {
        prepend(data);
    }
    else
    {
        node *link = (node*) malloc(sizeof(node));
        link->data = data;
        link->next = NULL;
        tail->next = link;
        link->prev = tail;
        tail = link;
    }
}

void insert(int index, int data)
{
    // Adds a node to the list at the specified position
    if (head == NULL || index == 0)
    {
        prepend(data);
    }
    else
    {
        node *curr = head;
        while (curr != tail && index > 1)
        {
            curr = curr->next;
            index--;
        }
        node *link = (node*) malloc(sizeof(node));
        link->data = data;
        link->next = curr->next;
        curr->next = link;
        link->prev = curr;
        if (curr == tail)
        {
            tail = link;
        }
        else
        {
            link->next->prev = link;
        }
    }
}

int find(int key)
{
    // Searches the list for the given key and returns the index or -1 if not found
    node *curr = head;
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

void remove_item(int key)
{
    // Traverses the list and removes the first found instance of the given key
    if (head->data == key)
    {
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
        else
        {
            head->prev = NULL;
        }
    }
    else
    {
        node *curr = head;
        node *prev = NULL;
        while (curr != NULL && curr->data != key)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr != NULL)
        {
            prev->next = curr->next;
            if (curr == tail)
            {
                tail = prev;
            }
            else
            {
                prev->next->prev = prev;
            }
        }
        else
        {
            printf("Did not find an element with data %d\n", key);
        }
    }
}

void remove_at(int index)
{
    // Removes the node found at the given position
    if (index <= 0 || head->next == NULL)
    {
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
        else
        {
            head->prev = NULL;
        }
    }
    else
    {
        node *curr = head;
        while (index > 1 && curr->next->next != NULL)
        {
            curr = curr->next;
            index--;
        }
        if (curr->next == tail)
        {
            tail = curr;
        }
        else
        {
            curr->next->next->prev = curr;
        }
        curr->next = curr->next->next;
    }
}

void replace(int key, int data)
{
    // Traverses the node and replaces the first instance of the key with the given data
    if (head->data == key)
    {
        head->data = data;
    }
    else
    {
        node *curr = head;
        while (curr != NULL && curr->data != key)
        {
            curr = curr->next;
        }
        if (curr != NULL)
        {
            curr->data = data;
        }
        else
        {
            printf("Did not find an element with data %d\n", key);
        }
    }
}

void replace_at(int index, int data)
{
    // Replaces the data of the node at the specified index position
    if (head == NULL)
    {
        printf("Index out of range\n");
    }
    else if (index <= 0)
    {
        head->data = data;
    }
    else
    {
        node *curr = head;
        while (index > 0 && curr != NULL)
        {
            curr = curr->next;
            index--;
        }
        if (curr != NULL)
        {
            curr->data = data;
        }
        else
        {
            printf("Index out of range\n");
        }
    }
}

int pop()
{
    // Removes the last item in the list and returns its value
    int removedItem = tail->data;
    tail = tail->prev;
    if (tail == NULL)
    {
        head = tail;
    }
    else
    {
        tail->next = NULL;
    }
    return removedItem;
}

void reverse()
{
    // Reverses the order of the list
    node *curr = tail;
    node *temp;
    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        curr = curr->next;
    }
    temp = head;
    head = tail;
    tail = temp;
}

int count(int key)
{
    // Traverses the list and returns a count of the nodes with the given data
    node *curr = head;
    int count = 0;
    while (curr != NULL)
    {
        if (curr->data == key)
        {
            count++;
        }
        curr = curr->next;
    }
    return count;
}

int length()
{
    // Returns the number of items in the list
    node *curr = head;
    int count = 0;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

void clear()
{
    // Clears the list
    head = NULL;
    tail = NULL;
}

void swap(int index1, int index2)
{
    // Swaps the data between two nodes of specified indices
    node *curr = head;
    while (index1 > 0 && curr != NULL)
    {
        curr = curr->next;
        index1--;
    }
    if (curr == NULL)
    {
        printf("Index1 is out of range\n");
        return;
    }
    node *first = curr;
    curr = head;
    while (index2 > 0 && curr != NULL)
    {
        curr = curr->next;
        index2--;
    }
    if (curr == NULL)
    {
        printf("Index2 is out of range\n");
        return;
    }
    node *second = curr;
    if (first->data != second->data)
    {
        first->data ^= second->data;
        second->data ^= first->data;
        first->data ^= second->data;
    }
}

int main(void)
{
    prepend(10);
    prepend(15);
    prepend(20);
    printList();
    reverse();
    printList();
    append(25);
    printList();
    remove_item(20);
    printList();
    remove_at(0);
    reverse();
    printList();
    remove_at(100);
    printList();
    remove_item(100);
    printList();
    append(20);
    append(25);
    prepend(10);
    prepend(10);
    reverse();
    printList();
    printf("Number of times 10 in list %d\n", count(10));
    printf("Number of times 100 in list %d\n", count(100));
    printf("Length of list %d\n", length());
    printf("Last item popped %d\n", pop());
    printList();
    swap(0, 3);
    printList();
    replace(20, 100);
    printList();
    replace(10, 15);
    printList();
    replace(10,15);
    printList();
    replace(1000, 20);
    printList();
    replace_at(0, 25);
    replace_at(100, 50);
    printList();
    printf("15 found at position %d\n", find(15));
    printf("100 found at position %d\n", find(100));
    insert(2, 40);
    printList();
    clear();
    printList();
    return 0;
}