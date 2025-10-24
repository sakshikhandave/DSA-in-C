/*
    Doubly Circular LinkedList
*/

#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

int Count(PNODE First, PNODE Last)
{
    int iCount = 0;

    if((First == NULL) || (Last == NULL))
    {
        return;
    }

    do
    {
        iCount++;
        First = First->next;
    }while(First != Last->next);

    return iCount;
}

void InsertFirst(PPNODE First, PPNODE Last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((*First == NULL) && (*Last == NULL))
    {
        *First = newn;
        *Last = newn;
        (*Last)->next = *First;
        (*First)->prev = *Last;
    }

    else
    {
        newn->next = *First;
        (*First)->prev = newn;
        *First = newn;
        newn->prev = *Last;
        (*Last)->next = newn;
    }
}

void InsertLast(PPNODE First, PPNODE Last, int no)
{
    PNODE temp = NULL;
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((*First == NULL) && (*Last == NULL))
    {
        *First = newn;
        *Last = newn;
        (*Last)->next = *First;
        (*First)->prev = *Last;
    }

    else
    {
        (*Last)->next = newn;
        newn->prev = *Last;
        *Last = newn;
        (*Last)->next = *First;
        (*First)->prev = *Last;
    }
}

void InsertAtPos(PPNODE First, PPNODE Last, int no, int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    int iCount = 0;
    int iCnt = 0;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    iCount = Count(*First, *Last);

    if((pos < 1) || (pos > iCount+1))
    {
        printf("Invalid position");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(First, Last, no);
    }

    else if(pos == iCount+1)
    {
        InsertLast(First, Last, no);
    }

    else
    {
        temp = *First;
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->prev = temp;
        temp->next = newn;
        newn->next->prev = newn;        
    }
}

void DeleteFirst(PPNODE First, PPNODE Last)
{
    if((*First == NULL) && (*Last == NULL))
    {
        return;
    }

    else if(*First == *Last)
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }

    else
    {
        *First = (*First)->next;
        (*First)->prev = *Last;        
    }
}

void DeleteLast(PPNODE First, PPNODE Last)
{
    PNODE temp = NULL;
    if((*First == NULL) && (*Last == NULL))
    {
        return;
    }

    else if(*First == *Last)
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }

    else
    {
        temp = *First;

        while(temp->next != *Last)
        {
            temp = temp->next;
        }
        temp->next = *First;
        *Last = temp;
        (*First)->prev = *Last;
    }
}

void DeleteAtPos(PPNODE First, PPNODE Last, int pos)
{
    PNODE target = NULL;
    PNODE temp = NULL;

    int iCount = 0;
    int iCnt = 0;

    iCount = Count(*First, *Last);

    if((pos < 1) || (pos > iCount))
    {
        printf("Invalid position");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(First, Last);
    }

    else if(pos == iCount)
    {
        DeleteLast(First, Last);
    }

    else
    {
        temp = *First;
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        target = temp->next; 
        temp->next = target->next;
        target->next->prev = temp;
        free(target);      
    }
}

void Display(PNODE First, PNODE Last)
{
    if((First == NULL) || (Last == NULL))
    {
        return;
    }

    do
    {
        printf("| %d | <=> ",First->data);
        First = First->next;
    }while(First != Last->next);
    printf("\n");
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    int iChoice = 0;      //choise of user
    int iValue = 0;
    int iPos = 0;         //position for insert or delete
    int iRet = 0;

    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("------------------------------------ Singly Circular LinkedList ------------------------------------------\n");
    printf("--------------------------------------------------------------------------------------------------------\n\n");

    while(1)
    {
        printf("--------------------------------------------------------------------------------------------------------\n");
        printf("----------------------------------- Please Select the option -------------------------------------------\n");
        printf("--------------------------------------------------------------------------------------------------------\n\n");
        printf("1: Insert new node at first position\n");
        printf("2: Insert new node at last position\n");
        printf("3: Insert new node at given position\n");
        printf("4: Delete node from first position\n");
        printf("5: Delete node from last position\n");
        printf("6: Delete node from given position\n");
        printf("7: Display all elements of LinkedList\n");
        printf("8: Count number of nodes LinkedList\n");
        printf("0: Terminate the Application\n");
        printf("--------------------------------------------------------------------------------------------------------\n");

        scanf("%d",&iChoice);

        if(iChoice == 1)
        {
            printf("Enter the element that you want to insert : \n");
            scanf("%d",&iValue);
            InsertFirst(&head, &tail, iValue);
        }

        else if(iChoice == 2)
        {
            printf("Enter the element that you want to insert at Last: \n");
            scanf("%d",&iValue);
            InsertLast(&head, &tail, iValue);
        }

        else if(iChoice == 3)
        {
            printf("Enter the element that you want to insert at given Position: \n");
            scanf("%d",&iValue);

            printf("Enter the position where you want to insert element : \n");
            scanf("%d",&iPos);

            InsertAtPos(&head, &tail, iValue, iPos);
        }

        else if(iChoice == 4)
        {
            printf("Deleting the first element from your LinkedList...\n");
            DeleteFirst(&head, &tail);
        }

        else if(iChoice == 5)
        {
            printf("Deleting the last element from your LinkedList...\n");
            DeleteLast(&head, &tail);
        }

        else if(iChoice == 6)
        {
            printf("Enter the postion which you want to delete : \n");
            scanf("%d",&iPos);
            printf("Deleting the element from given position from your LinkedList...\n");

            DeleteAtPos(&head, &tail, iPos);
        }

        else if(iChoice == 7)
        {
            printf("Display al the elements from LinkedList\n");
            Display(head, tail);
        }

        else if(iChoice == 8)
        {
            iRet = Count(head, tail); 
            printf("Number of elements in LinkedList are :%d \n",iRet);           
        }

        else if(iChoice == 0)
        {
            printf("Thank you for using our application \n");
            break;
        }

        else
        {
            printf("Invalid Input\n");
        }
        printf("--------------------------------------------------------------------------------------------------------\n\n"); 
    } 


    return 0;
}