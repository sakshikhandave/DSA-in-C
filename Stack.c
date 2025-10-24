/*
    Stack
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

int Count(PNODE First)
{
    PNODE temp = First;
    int iCount = 0;

    while(temp != NULL)
    {
        iCount++;
        temp = temp->next;
    }

    return iCount;
}

void Push(PPNODE First, int no)
{
    PNODE newn = (PNODE)malloc (sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    newn->next = *First;
    *First = newn;
}

int Pop(PPNODE First)
{
    PNODE temp = *First;
    int value = 0;

    if(*First == NULL)
    {
        return -1;
    }

    else
    {
        value = temp->data;
        *First = (*First)->next;
        free(temp);

        return value;
    }
}

void Display(PNODE First)
{
    while(First != NULL)
    {
        printf("| %d |\n", First->data);
        First = First->next;
    }
    printf("\n");
}

int main()
{
    PNODE head = NULL;

    int iChoice = 0;      
    int iValue = 0;
    int iRet = 0;

    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("----------------------------------------------- Stack --------------------------------------------------\n");
    printf("--------------------------------------------------------------------------------------------------------\n\n");

    while(1)
    {
        printf("--------------------------------------------------------------------------------------------------------\n");
        printf("----------------------------------- Please Select the option -------------------------------------------\n");
        printf("--------------------------------------------------------------------------------------------------------\n\n");
        printf("1: Push element in stack\n");
        printf("2: Poped element from stack\n");
        printf("3: Display all elements of Stack\n");
        printf("4: Count number of nodes Stack\n");
        printf("0: Terminate the Application\n");
        printf("--------------------------------------------------------------------------------------------------------\n");

        scanf("%d",&iChoice);

        if(iChoice == 1)
        {
            printf("Enter the element that you want to insert in stack : \n");
            scanf("%d",&iValue);
            Push(&head, iValue);
        }

        else if(iChoice == 2)
        {
            iRet = Pop(&head);
            printf("Poped element from Stack is : %d\n", iRet);
            Display(head);            
        }

        else if(iChoice == 3)
        {
            printf("Display al the elements from LinkedList\n");
            Display(head);
        }

        else if(iChoice == 4)
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