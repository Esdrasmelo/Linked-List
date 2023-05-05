#include <stdio.h>
#include "appInterface.h"

int main(void)
{
    TDescriptor listDescriptor;
    TItemNode item;
    int wantToStop = 0, wantToRemoveAnyUser = 0;

    InitializeList(&listDescriptor);

    while (TRUE)
    {
        printf("\nEnter the user name: ");
        scanf("%s", item.name);

        printf("Enter the user nickname: ");
        scanf("%s", item.nickname);

        printf("Enter the user gender (M or F): ");
        scanf(" %c", &item.gender);

        int wasUserCreated = InsertItemsOnList(&listDescriptor, &item);

        if (wasUserCreated == FALSE)
        {
            puts("\nInsufficient memory for this operation");
            break;
        }

        printf("\nDo you want to stop (0 = No, 1 = Yes): \n");
        scanf("%d", &wantToStop);

        if (wantToStop)
            break;
    }

    PrintList(&listDescriptor);

    printf("\n\nDo you want remove any user? Type 0 (zero) for No or 1 (one) for Yes: ");
    scanf("%d", &wantToRemoveAnyUser);

    if (wantToRemoveAnyUser)
    {

        while (TRUE)
        {
            char userName[21];

            printf("\nType the user name: ");
            scanf("%s", userName);

            int wasUserRemoved = RemoveItemFromList(&listDescriptor, userName);

            if (wasUserRemoved == FALSE)
                printf("\nUser %s does not exists.", userName);
            else
                PrintList(&listDescriptor);

            if (listDescriptor.head == NULL)
                break;

            printf("\n\nDo you want remove more one user? Type 0 (zero) for No or 1 (one) for Yes: ");
            scanf("%d", &wantToRemoveAnyUser);
        }
    }

    puts("\n\nFinishing process...");

    return 0;
}