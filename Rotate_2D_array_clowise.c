#include <stdio.h>
void swap(int *a, int *b){
    int t=0;
    t = *a;
    *a = *b;
    *b = t;
}
void reverse(int start,int end, int rows, int cols, int array[rows][cols]){
   
    int index = 0;
    while(index<cols){
        int i = start;
        int j = end;
        while(i<=j){
            swap(&array[i][index],&array[j][index]);
            i++;
            j--;
        }
        index++;
    }
}
void rotate(int rows, int cols, int array[rows][cols], int k){
    k = k%rows;
    reverse(0,rows-1,rows,cols,array);
    reverse(0,rows-k-1,rows,cols,array);
    reverse(rows-k,rows-1,rows,cols,array);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d",array[i][j]);
        }
        printf("\n");
    }
   
}
int main() {
    int rows=0;
    int cols = 0;
    printf("Enter rows or cols\n");
    scanf("%d %d",&rows, &cols);
    int array[rows][cols];
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            scanf("%d",&array[i][j]);
        }
    }
   
    int k=0;
    printf("Enter the value of k\n");
    scanf("%d",&k);
    rotate(rows, cols, array,k);
   
 
    return 0;
}
