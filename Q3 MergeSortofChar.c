#include <stdio.h>
#include<stdlib.h>

void swap(char *x,char *y)
{
    char temp=*x;
    *x=*y;
    *y=temp;
}


void Merge(char A[],int l,int mid,int h)
{
    int i=l,j=mid+1,k=l;
    char B[100];
    while(i<=mid && j<=h)
    {
        
        if(A[i]<A[j])
        {
            B[k++]=A[i++];
        }
        else
        {
            B[k++]=A[j++];
        }
    }

    //remaining element from array1 or array2 are move to B array 
    for(;i<=mid;i++)
        B[k++]=A[i];
    for(;j<=h;j++)
        B[k++]=A[j];

    //copy all the elements from array B to array A         
    for(i=l;i<=h;i++)
        A[i]=B[i];
}


void MergeSort(char A[],int l,int h)
{
    int mid;
    if(l<h)
    {
        mid=(l+h)/2;
        MergeSort(A,l,mid);
        MergeSort(A,mid+1,h);
        Merge(A,l,mid,h);
    }
}


int main()
{
    char A[]={"Polynomial"},n=10,i=0,j=0;

    //Coverting all capital letter to small
    while(i<10)
    {
        if(A[i]>=65&&A[i]<97)
            {
                A[i]=A[i]+32;
            }
            i++;
    }

    MergeSort(A,0,n-1);

    printf("\n");
    for(i=0;i<10;i++)
    {
        printf("%c ",A[i]);   
    }
    return 0;
}