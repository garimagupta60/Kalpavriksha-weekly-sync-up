#include<stdio.h>
#include<string.h>

void reverseCase(char expression[]){
    for(int i=0; i<strlen(expression); i++){
        if(expression[i]>='a' && expression[i]<='z'){
            expression[i] = expression[i] - 32;
        }else if(expression[i]>='A' && expression[i]<='Z'){
            expression[i] = expression[i] + 32;
        }else if(expression[i]>='1' && expression[i]<='9'){
            continue;
        }
    }
}
int main(){
    printf("Enter string\n");
    char expression[20];
    fgets(expression,20,stdin);
    reverseCase(expression);
    printf("%s", expression);
}
