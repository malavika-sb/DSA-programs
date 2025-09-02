/*Insertion Sort*/
#include<stdio.h>
#include<stdlib.h>
void insertion_sort(int arr[],int n){
    int i,j,key;
    for(i=1;i<n;i++){
       key=arr[i];
       j=i-1;
       while(j>=0 && arr[j]>key){
         arr[j+1]=arr[j];
         j--;
       }
       arr[j+1]=key;
    }
}
int main(){
    int i,n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    if(n<=0){
      printf("Invalid size!!\n");
      return 0;}
    int *arr=malloc(n*sizeof(int));
    if(!arr){
        printf("Allocation failed\n");
        return 0;
    }
    printf("Enter the elements:");
    for(i=0;i<n;i++)
       scanf("%d",&arr[i]);
    printf("--ARRAY BEFORE SORTING--\n");
    for(i=0;i<n;i++)
       printf("%d\t",arr[i]);
 printf("\n");
    insertion_sort(arr,n);

    printf("--ARRAY ATER SORTING--\n");
    for(i=0;i<n;i++)
       printf("%d\t",arr[i]);
free(arr);
return 0;
}