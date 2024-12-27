#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int findLength(char s1[]){
    int count=0;
    for(int i=0; s1[i]!='\0';i++){
        count++;
    }
    return count;
}
int isRotation(char s1[], char s2[]){

    int n1 = findLength(s1);
    int n2 = findLength(s2);
    if(n1!=n2)return 0;

    for(int i=0; i< n1; i++){
        if(strcmp(s1,s2)==0)return 1;
        char last = s1[n1-1];
        for(int j=n1-1; j>0; j--){
            s1[j] = s1[j-1];
        }
        s1[0] = last;

    }
    return 0;
}
int main(){
    char s1[10],s2[10];
    scanf("%s",s1);
    scanf("%s",s2);
    if(isRotation(s1,s2)){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
}