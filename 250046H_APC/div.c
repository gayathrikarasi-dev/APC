#include "apc.h"

void division(node *head_L1, node *head_OPR2,node *tail_OPR2, node **headR, node **tailR)
{
    node *head_OPR1=NULL;
    node *tail_OPR1=NULL;
    node *L1_temp=head_L1;
    node *head_SR=NULL;
    node *tail_SR=NULL;
    int sub_count;
    insert_last(&head_OPR1,&tail_OPR1,L1_temp->data);
    while(compare_list(head_OPR1,head_OPR2)==OPERAND2)
    {
        L1_temp=L1_temp->next;
        if(!L1_temp)
        {
            insert_last(headR,tailR,0);
            return;
        }
        insert_last(&head_OPR1,&tail_OPR1,L1_temp->data);

    }
    while(L1_temp != NULL)
    {
        sub_count=0;
        remove_pre_zeros(&head_OPR1);
        while(compare_list(head_OPR1,head_OPR2) != OPERAND2)
        {
            subtraction(tail_OPR1,tail_OPR2,&head_SR,&tail_SR);
            sub_count++;
            delete_list(&head_OPR1,&tail_OPR1);
            head_OPR1=head_SR;
            tail_OPR1=tail_SR;
            head_SR=tail_SR=NULL;
            
        }
        insert_last(headR,tailR,sub_count);
        L1_temp=L1_temp->next;
        if(L1_temp == NULL)
        {
            break;
        }
        insert_last(&head_OPR1,&tail_OPR1,L1_temp->data);
    }
}