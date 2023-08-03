#include<stdio.h>
#include<time.h>
void conquor(int arr[], int s,int mid,int e)
{
    int merged[e-s+1];
    int i1=s;
    int i2=mid+1;
    int x=0;
    while(i1<=mid && i2<=e)
    {
        if(arr[i1]<=arr[i2])
        {
            merged[x]=arr[i1];
            x++;
            i1++;
        }
        else
        {
            merged[x]=arr[i2];
            x++;
            i2++;
        }
    }
    while(i1<=mid)
    {
        merged[x]=arr[i1];
        x++;
        i1++;
    }
    while(i2<=e)
    {
        merged[x]=arr[i2];
        x++;
        i2++;
    }
    for(int i=0;i<x;i++)
    {
        arr[i+s]=merged[i];
    }

}
void divide(int arr[], int s, int e)
{
    if(s>=e)
    return;
    int mid=s+(e-s)/2;
    divide(arr,s,mid);
    divide(arr,mid+1,e);
    conquor(arr,s,mid,e);
}
void main()
{
    clock_t st,et;
    double ts;
    int arr[]={9,8,7,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    st=clock();
    divide(arr,0,n-1);
    et=clock();
    ts=(double)((et-st)/CLOCKS_PER_SEC);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nThe time taken for merge sort is: %f\n",ts);
}