#include <stdio.h>
#include <stdlib.h>

struct DLListNode
{
    char* str;
    struct DLListNode* prev;
    struct DLListNode* next;
};

int insertAtHead(struct DLListNode* node, char* str);
int insertAtTail(struct DLListNode* node, char* str);
struct DLListNode* getHeadNode(struct DLListNode* node);
struct DLListNode* getTailNode(struct DLListNode* node);
int printNode(struct DLListNode* node);
int destroy(struct DLListNode* node);

int main(int argc, char* argv)
{
    struct DLListNode* node = malloc(sizeof(struct DLListNode));
    if (node == NULL) { return -1; }

    node->str = ",";
    node->prev = NULL;
    node->next = NULL;

    insertAtHead(node, " ");
    insertAtHead(node, "World");
    insertAtHead(node, "!");
    insertAtTail(node, "Hello");

    printNode(node);
    destroy(node);

    return 0;
}

int insertAtHead(struct DLListNode* node, char* str)
{
    if (node == NULL) { return -1; }
    struct DLListNode* headNode = getHeadNode(node);
    struct DLListNode* newNode = malloc(sizeof(struct DLListNode));

    newNode->str = str;
    newNode->prev = headNode;
    newNode->next = NULL;
    headNode->next = newNode;
    return 0;
}

int insertAtTail(struct DLListNode* node, char* str)
{
    if (node == NULL) { return -1; }
    struct DLListNode* tailNode = getTailNode(node);
    struct DLListNode* newNode = malloc(sizeof(struct DLListNode));

    newNode->str = str;
    newNode->prev = NULL;
    newNode->next = tailNode;
    tailNode->prev = newNode;
    return 0;
}

struct DLListNode* getHeadNode(struct DLListNode* node)
{
    if (node == NULL) { return NULL; }
    while (node->next != NULL)
    {
        node = node->next;
    }
    return node;
}

struct DLListNode* getTailNode(struct DLListNode* node)
{
    if (node == NULL) { return NULL; }
    while (node->prev != NULL)
    {
        node = node->prev;
    }
    return node;
}

int printNode(struct DLListNode* node)
{
    struct DLListNode* cursorNode = getTailNode(node);
    if (cursorNode == NULL) { return -1; }

    while (cursorNode->next != NULL)
    {
        printf("%s --> ", cursorNode->str);
        cursorNode = cursorNode->next;
    }
    printf("%s\n", cursorNode->str);
    return 0;
}

int destroy(struct DLListNode* node)
{
    struct DLListNode* tailNode = getTailNode(node);
    while(tailNode != NULL)
    {
        free(tailNode);
        tailNode = tailNode->next;
    }

    return 0;
}
