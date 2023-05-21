#include <stdio.h>
void merge(int a[],int l,int mid,int h)
{
    int i=l,j=mid+1,k=l;
    int b[h+1];
    while(i<=mid && j<=h)
    {
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    for(;i<=mid;i++)
        b[k++]=a[i];
    for(;j<=h;j++)
        b[k++]=a[j];
    for(i=l;i<=h;i++)
        a[i]=b[i];
}
void mergeSort(int arr[],int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}
int main()
{
    int arr[100];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
