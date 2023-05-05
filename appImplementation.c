#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "appInterface.h"

void InitializeList(TDescriptor *descriptor)
{
    descriptor->head = NULL;
    descriptor->tail = NULL;
    descriptor->quantityOfUsers = 0;
}

int InsertItemsOnList(TDescriptor *descriptor, TItemNode *item)
{
    TItemNode *auxiliar;

    auxiliar = (TItemNode *)malloc(sizeof(TItemNode));

    strcpy(auxiliar->name, item->name);
    strcpy(auxiliar->nickname, item->nickname);
    auxiliar->gender = item->gender;
    auxiliar->nextNode = NULL;

    if (auxiliar == NULL)
        return FALSE;

    if (descriptor->head == NULL)
        descriptor->head = auxiliar;
    else
        descriptor->tail->nextNode = auxiliar;

    descriptor->tail = auxiliar;
    descriptor->quantityOfUsers += 1;

    return TRUE;
};

void PrintList(TDescriptor *descriptor)
{
    TItemNode *item = descriptor->head;

    if (descriptor->head == NULL)
        printf("\nEmpty List");
    else
    {
        printf("\nList content: \n");

        while (item)
        {
            printf("\nUser name: %s", item->name);
            printf("\nUser nickname: %s", item->nickname);
            printf("\nUser gender: %c\n", item->gender);

            item = item->nextNode;
        }
    }
}

int RemoveItemFromList(TDescriptor *listDescriptor, char *userName)
{
    TItemNode *auxiliar = listDescriptor->head, *previousNode = NULL;

    while (auxiliar != NULL && strcmp(auxiliar->name, userName))
    {
        previousNode = auxiliar;
        auxiliar = auxiliar->nextNode;
    }

    if (auxiliar == NULL)
        return FALSE;
    else
    {
        if (previousNode == NULL)
            listDescriptor->head = auxiliar->nextNode;
        else
            previousNode->nextNode = auxiliar->nextNode;

        if (listDescriptor->tail == auxiliar)
            listDescriptor->tail = previousNode;

        free(auxiliar);
    }

    return TRUE;
}