/*
Write a C program to left rotate an array.

*/
#include <stdio.h>

int getMax(int arr[], int n);
void rotateLeft(int arr[], int n, int k, int max);
int main()
{
    int n, k;
    printf("Enter size of array: "); scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++)
    scanf("%d",&arr[i]);

    printf("Enter number of times to rotate:"); scanf("%d",&k);
    k = k%n;

    int max = getMax(arr,n);
    if(++max%2 == 0) max++;

    rotateLeft(arr,n,k,max);

    for(int i = 0; i < n; i++)
    printf("%d ",arr[i]/max);

    return 0;
}
void rotateLeft(int arr[], int n, int k, int max)
{
    int c = 0;

    for(int i = k; i < n; i++)
    arr[c++] += arr[i]%max*max;

    for(int i = 0; i < k; i++)
    arr[c++] += arr[i]%max*max;

}
int getMax(int arr[], int n)
{
    int max = arr[0];

    for(int i = 0; i < n; i++)
    if(max < arr[i]) max = arr[i];

    return max;
}