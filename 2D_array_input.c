#include<stdio.h>
#include<stdlib.h>
 
void printMatrix(int** mat,int rows,int columns){
    
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<columns;j++){
            printf("%d ",*(*(mat + i)+j));
        }
        printf("\n");
    }
}
 
 
int main(){
 
    int rows = 0,columns = 0;
    printf("Enter the no. of Rows\n");
    scanf("%d",&rows);
    printf("Enter the no. of Columns\n");
    scanf("%d",&columns);
 
    
    int ** matrix = (int **)malloc(rows*sizeof(int *));

    for(int i = 0; i<rows; i++){
        matrix[i] = (int *)malloc(columns * sizeof(int));
    }
   
    printf("Enter the values of Matrix\n");
 
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            scanf("%d",(*(matrix+i)+j));
        }
    }
 
    printf("Matrix:\n");

    printMatrix(matrix,rows,columns);
 
    return 0;
}