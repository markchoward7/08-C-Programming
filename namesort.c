#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data[256];
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
        printf("%s -> ", ptr->data);
        ptr = ptr->next;
    }
    printf(" End\n");
}

void prepend(char* data)
{
    // Adds a node to the beginning of the list
    node *link = (node*) malloc(sizeof(node));
    
    strcpy(link->data, data);
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

void append(char* data)
{
    // Adds a node to the end of the list
    if (head == NULL)
    {
        prepend(data);
    }
    else
    {
        node *link = (node*) malloc(sizeof(node));
        strcpy(link->data, data);
        link->next = NULL;
        tail->next = link;
        link->prev = tail;
        tail = link;
    }
}

void insert(int index, char* data)
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
        strcpy(link->data, data);
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

int find(char* key)
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

void remove_item(char* key)
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

void replace(char* key, char* data)
{
    // Traverses the node and replaces the first instance of the key with the given data
    if (head->data == key)
    {
        strcpy(head->data, data);
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
            strcpy(curr->data, data);
        }
        else
        {
            printf("Did not find an element with data %d\n", key);
        }
    }
}

void replace_at(int index, char* data)
{
    // Replaces the data of the node at the specified index position
    if (head == NULL)
    {
        printf("Index out of range\n");
    }
    else if (index <= 0)
    {
        strcpy(head->data, data);
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
            strcpy(curr->data, data);
        }
        else
        {
            printf("Index out of range\n");
        }
    }
}

char* pop()
{
    // Removes the last item in the list and returns its value
    char *removedItem = tail->data;
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

int count(char* key)
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

void swapByIndex(int index1, int index2)
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
    char temp[256];
    strcpy(temp, first->data);
    strcpy(first->data, second->data);
    strcpy(second->data, temp);
}

void swapByNodes(node* first, node* second)
{
    char temp[256];
    strcpy(temp, first->data);
    strcpy(first->data, second->data);
    strcpy(second->data, temp);
}

int isBigger(char* first, char* second)
{
    if (*first > *second)
    {
        return 1;
    }
    else if (*first < *second)
    {
        return 0;
    }
    else
    {
        if (*(first+1) == 0)
        {
            return 1;
        }
        else if (*(second+1) == 0)
        {
            return 0;
        }
        else
        {
            return isBigger(first+1, second+1);
        }
    }
}

void sort()
{
    node* i = head;
    while (i->next != NULL)
    {
        node* j = head;
        while (j->next != NULL)
        {
            if (isBigger(j->data, j->next->data))
            {
                swapByNodes(j, j->next);
            }
            j = j->next;
        }
        i = i->next;
    }
}

int main(void)
{
    printf("How many names?\n");
    int num;
    scanf("%d", &num);
    while (num > 0)
    {
        fseek(stdin, 0, SEEK_END);
        printf("Enter a name\n");
        char name[256] = {0};
        scanf("%255[^\n]s", &name);
        append(name);
        num--;
    }
    printList();
    sort();
    printList();
    return 0;
}