#include "apc.h"

// Function definitions
int cla_validation(int argc, char *argv[])
{
    if(argc != 4)
    {
        printf("Invalid number of CLA\n");
        return FAILURE;
    }
    return SUCCESS;
}
void create_list(char *opr, node **head, node **tail)
{
    int i=0;
    while(opr[i])
    {
        insert_last(head,tail,opr[i]-48);
        i++;
    }

}
int insert_first(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));
    if (!new)
        return FAILURE;

    new->data = data;
    new->prev = NULL;
    new->next = *head;

    if (*head)
    {
        (*head)->prev = new;
    }
    else
    {
        *tail = new;
    }
    *head = new;
    return SUCCESS;
}
int insert_last(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node));
    if (!new)
    {
        return FAILURE;
    }

    new->data = data;
    new->next = NULL;
    new->prev = *tail;

    if (*tail)
    {
        (*tail)->next = new;
    }
    else
    {
        *head = new;
    }
    *tail = new;
    return SUCCESS;
}
void print_list(node *head)
{
/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    printf("Head -> ");
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d <-", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
		    if (head)
		        printf("> ");
	    }
    	printf(" Tail\n");
    }
}
int list_len(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
int compare_list(node *head1, node *head2)
{
    int len1=list_len(head1);
    int len2=list_len(head2);
    if(len1 > len2)
    {
        return OPERAND1;
    }
    if(len1 < len2)
    {
        return OPERAND2;
    }
    else
    {
        node *temp1=head1;
        node *temp2=head2;
        
        while(temp1 != NULL && temp2 != NULL)
        {
            if(temp1->data > temp2->data)
            {
                return OPERAND1;
            }
            else if(temp1->data < temp2->data)
            {
                return OPERAND2;
            }
            else
            {
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        return SAME;
    }
}
void remove_pre_zeros(node **head)
{
	while((*head)->data==0)
	{
		if((*head)->next==NULL)
			return; 

		*head=(*head)->next;
		free((*head)->prev);
		(*head)->prev=NULL;
	}
}
int delete_list(node **head, node **tail)
{
    if (*head == NULL)
    {
        return FAILURE;
    }
    node *temp = *head;
    while (temp)
    {
        node *next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
    *tail = NULL;
    return SUCCESS;

}