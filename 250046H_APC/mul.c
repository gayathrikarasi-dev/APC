#include "apc.h"

void multiplication(node *tail1, node *tail2, node **headR1, node **tailR1)
{
    node *temp1=tail1,*temp2=tail2,*headR2=NULL,*tailR2=NULL,*headAR=NULL,*tailAR=NULL;
    int count=0,carry=0,num1,num2,mul,res;
    while(temp2)
    {
        carry=0;
        for (int i = 0; i < count; i++)
            insert_first(&headR2, &tailR2, 0);
        count++;
        while(temp1)
        {
            num1=temp1->data;
            num2=temp2->data;
            mul=num1*num2+carry;
            res=mul%10;
            carry=mul/10;
            if(count == 0)
                insert_first(headR1,tailR1,res);
            else
                insert_first(&headR2,&tailR2,res);
            temp1=temp1->prev;
        }
        if(carry)
        {
            if(count == 0)
                insert_first(headR1,tailR1,carry);
            else
                insert_first(&headR2,&tailR2,carry);
        }
        
        addition(*tailR1,tailR2,&headAR,&tailAR);
        delete_list(headR1,tailR1);
        delete_list(&headR2,&tailR2);
        *headR1=headAR;
        *tailR1=tailAR;
        headAR=tailAR=NULL;
        
        temp2=temp2->prev;
        temp1=tail1;
        
    }
    remove_pre_zeros(headR1);
}