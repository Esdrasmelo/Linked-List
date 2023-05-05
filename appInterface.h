#define TRUE 1
#define FALSE 0

typedef struct
{
    char nickname[21];
    char name[21];
    char gender;
    struct TItemNode *nextNode;
} TItemNode;

typedef struct
{
    TItemNode *head, *tail;
    int quantityOfUsers;
} TDescriptor;

void InitializeList(TDescriptor *);
int InsertItemsOnList(TDescriptor *, TItemNode *);
int RemoveItemFromList(TDescriptor *, char *);
void PrintList(TDescriptor *);
