/*Bubble Sort*/
#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int arr[],int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
               temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
            }
        }
    }
}
int main(){
 int n,i;
 printf("Enter number of elements:");
 scanf("%d",&n);
 int *arr=malloc(n*sizeof(int));
 if (!arr) {
    printf("Memory allocation failed!\n");
    return 1;
}
 printf("Enter the elements:");
 for(i=0;i<n;i++)
   scanf("%d",&arr[i]);
printf("--ARRAY BEFORE SORTING--\n");
for(i=0;i<n;i++)
  printf("%d\t",arr[i]);

printf("\n");
bubble_sort(arr,n);
printf("--ARRAY AFTER SORTING--\n");
for(i=0;i<n;i++)
  printf("%d\t",arr[i]);

free(arr);
return 0;
}
