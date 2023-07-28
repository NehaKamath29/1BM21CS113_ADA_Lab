#include <stdio.h>
#include<stdbool.h>
#define size 11
void main()
{
    int arr[]={11,12,4,97,68,41,13,44,51,61,24};
    int hashtable[size];
    bool table[size];
    int i,j=0,index;
    for(i=0;i<size;i++)
    {
        table[i]=false;
    }
    for(i=0;i<size;i++)
    {
        while(j<size)
        {
            index=(arr[i]+j)%size;
            if(table[index]==false)
            {
                hashtable[index]=arr[i];
                table[index]=true;
                j=0;
                break;
            }
            else
            j++;
        }
    }
    for(i=0;i<size;i++)
    {
        printf("%d ",hashtable[i]);
    }
}
/*This is linear probing code*/
