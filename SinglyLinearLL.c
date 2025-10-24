/* 
    Singly Linear LinkedList
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE First, int no)
{
    PNODE newn = NULL;
    newn = (PNODE) malloc (sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if (*First == NULL)
    {
        *First  = newn;
    }

    else
    {
        newn->next = *First;
        *First = newn;
    }
}

void InsertLast(PPNODE First, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*First == NULL)
    {
        *First = NULL;
    }
    else
    {
        temp = *First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE First)
{
    PNODE temp = NULL;

    if(*First == NULL)
    {
        return;
    }
    
    else if((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
    }

    else
    {
        temp = *First;
        *First = (*First)->next;
        free(temp);

    }
}

void DeleteLast(PPNODE First)
{
    PNODE temp = NULL;

    if(*First == NULL)
    {
        return;
    }

    else if((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
    }

    else
    {
        temp = *First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void Display(PNODE First)
{
    while(First != NULL)
    {
        printf("| %d |->", First->data);
        First = First->next;
    }
    printf(" NULL\n");
}

int Count(PNODE First)
{
    int iCount = 0;
    while(First != NULL)
    {
        iCount++;
        First = First->next;
    }
    return iCount;
}

void InsertAtPos(PPNODE First, int no, int pos)
{
    int iCount = 0;
    int iCnt = 0;

    PNODE temp = NULL;
    PNODE newn = NULL;

    iCount = Count(*First);

    if((pos < 1) || (pos > iCount+1))
    {
        printf("Invalid position\n");
        return;
    }
    if(pos == 1)
    {
        InsertFirst(First, no);
    }

    else if(pos == iCount+1)
    {
        InsertLast(First, no);
    }

    else
    {
        temp = *First;
        for(iCnt = 1; iCnt <= pos-2; iCnt++)
        {
            temp = temp->next;
        }
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteAtPos(PPNODE First, int pos)
{
    int iCount = 0;
    int iCnt = 0;

    PNODE temp = NULL;
    PNODE target = NULL;

    iCount = Count(*First);

    if((pos < 1) || (pos > iCount+1))
    {
        printf("Invalid position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(First);
    }
    else if(pos == iCount)
    {
        DeleteLast(First);
    }
    else
    {
        temp = *First;
        for(iCnt = 1; iCnt <= pos-2; iCnt++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        free(target);
    }

}

int main()
{
    PNODE head = NULL;

    int iChoice = 0;      //choise of user
    int iValue = 0;
    int iPos = 0;         //position for insert or delete
    int iRet = 0;

    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("------------------------------------ Singly Linear LinkedList ------------------------------------------\n");
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
            InsertFirst(&head, iValue);
        }

        else if(iChoice == 2)
        {
            printf("Enter the element that you want to insert at Last: \n");
            scanf("%d",&iValue);
            InsertLast(&head, iValue);
        }

        else if(iChoice == 3)
        {
            printf("Enter the element that you want to insert at given Position: \n");
            scanf("%d",&iValue);

            printf("Enter the position where you want to insert element : \n");
            scanf("%d",&iPos);

            InsertAtPos(&head, iValue, iPos);
        }

        else if(iChoice == 4)
        {
            printf("Deleting the first element from your LinkedList...\n");
            DeleteFirst(&head);
        }

        else if(iChoice == 5)
        {
            printf("Deleting the last element from your LinkedList...\n");
            DeleteLast(&head);
        }

        else if(iChoice == 6)
        {
            printf("Enter the postion which you want to delete : \n");
            scanf("%d",&iPos);
            printf("Deleting the element from given position from your LinkedList...\n");

            DeleteAtPos(&head, iPos);
        }

        else if(iChoice == 7)
        {
            printf("Display al the elements from LinkedList\n");
            Display(head);
        }

        else if(iChoice == 8)
        {
            iRet = Count(head); 
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