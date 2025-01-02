// Online C compiler to run C program online
#include <stdio.h>

void swap(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
void sort(int *t, int size){
    int *low = t;
    int * mid = t;
    int *high = t+size-1;
    while(mid<=high){
        if(*mid == 0){
            swap(low,mid);
            low++;
            mid++;
        }else if(*mid == 1){
            mid++;
        }else{
            swap(mid,high);
            high--;
        }
    }
}
int main() {
    // Write C code here
    int size;
    printf("Enter the size\n");
    scanf("%d",&size);
    int arr[size];
    for(int i=0; i<size; i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,size);
    for(int i=0; i<size; i++){
        printf("%d\n",arr[i]);
    }

    return 0;
}