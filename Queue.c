/*
    Queue
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

void Enqueue(PPNODE First, int no)
{
    PNODE newn = (PNODE)malloc (sizeof(NODE));
    PNODE temp = NULL;
    
    newn->data = no;
    newn->next = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }

    else
    {
        temp  =* First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
}

int Dequeue(PPNODE First)
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
        printf("| %d |-", First->data);
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
    printf("----------------------------------------------- Queue --------------------------------------------------\n");
    printf("--------------------------------------------------------------------------------------------------------\n\n");

    while(1)
    {
        printf("--------------------------------------------------------------------------------------------------------\n");
        printf("----------------------------------- Please Select the option -------------------------------------------\n");
        printf("--------------------------------------------------------------------------------------------------------\n\n");
        printf("1: Add element in queue\n");
        printf("2: Remove element from queue\n");
        printf("3: Display all elements of queue\n");
        printf("4: Count number of nodes Staqueueck\n");
        printf("0: Terminate the Application\n");
        printf("--------------------------------------------------------------------------------------------------------\n");

        scanf("%d",&iChoice);

        if(iChoice == 1)
        {
            printf("Enter the element that you want to insert in queue : \n");
            scanf("%d",&iValue);
            Enqueue(&head, iValue);
        }

        else if(iChoice == 2)
        {
            iRet = Dequeue(&head);
            printf("Removed element from queue is : %d\n", iRet);
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