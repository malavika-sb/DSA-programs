/*Binary Search*/
#include<stdio.h>
#include<stdlib.h>
//search function
int binary_search(int arr[], int n,int key){
  int mid, low=0, high=n-1;
while(low<=high){
  mid=(low+high)/2;
  if(arr[mid]==key)
     return mid;
  else if(arr[mid]<key)
    low=mid+1;
  else 
    high=mid-1;
 }
 return -1;
}

int main(){
int n,i,key;

printf("Enter the size of array:");
scanf("%d",&n);
if (n <= 0) {
        printf("Invalid size!\n");
        return 0;
    }
  //dynamic allocation
int *arr=malloc(n*sizeof(int));
if(!arr){
  printf("Allocation failed !!");
  return 1;
}
printf("Enter the elements into the array(in sorted order):");
for(i=0;i<n;i++)
   scanf("%d",&arr[i]);

printf("ARRAY:\n");
for(i=0;i<n;i++)
   printf("%d\t",arr[i]);
printf("\n");

printf("Enter the element to search:");
scanf("%d",&key);
//calling function
int index=binary_search(arr,n,key);

if(index==-1)
  printf("Element not found!!");
else 
  printf("Element found at position %d",index+1);

free(arr);
return 0;

}
