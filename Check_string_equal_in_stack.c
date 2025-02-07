#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char data;
    struct node* next;
}node;

typedef struct stack{
    int size;
    node* top;
}stack;

node* createNode(char value){
    node* newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

stack* createStack(){
    stack* newStack = (stack*)malloc(sizeof(stack));
    if(newStack == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newStack->size = 0;
    newStack->top = NULL;
    return newStack;
}


int isEmpty(stack* newStack){
    return(newStack->top == NULL);
}

void push(stack* newStack, char value){
    node* newnode = createNode(value);
    if(isEmpty(newStack)){
        newStack->top = newnode;
    }else{
        newnode->next = newStack->top;
        newStack->top = newnode;
    }
    newStack->size++;
}

char pop(stack* newStack){
    if(isEmpty(newStack)){
        return '@';
    }else{
        node* temp = newStack->top;
        char item = temp->data;
        newStack->top = newStack->top->next;
        free(temp);
        newStack->size--;
        return item;
    }
}

int ischaracter(char ch){
    if(ch>='a' && ch<='z')return 1;
    return 0;
}

void modifyString(stack* stack1, char string1[100]){
    int index = 0;
    while(string1[index]!='\0'){
        if(ischaracter(string1[index])){
            push(stack1,string1[index]);
        }else if(string1[index] == '#'){
            char ch = pop(stack1);
        }
        index++;
    }
    int string_index = 0;
    if(isEmpty(stack1)){

        string1[string_index] = '\0';
        return;
    }

    while(!isEmpty(stack1)){
        string1[string_index] = pop(stack1);
        string_index++;
    }
    string1[string_index] = '\0';
}

int string_compare(char string1[200], char string2[200]){
    int index1= 0;
    int index2 = 0;
    while(string1[index1]!='\0' && string2[index2]!='\0'){
        if(string1[index1]!=string2[index2]){
            return 0;
        }
        index1++;
        index2++;
    }
    return 1;
}
int main(){
    char string1[200];
    char string2[200];
    stack* stack1 = createStack();
    stack* stack2 = createStack();

    printf("Enter string1: ");
    scanf("%[^\n]%*c",string1);

    printf("Enter string2: ");
    scanf("%[^\n]%*c",string2);

    modifyString(stack1,string1);
    modifyString(stack2,string2);

    if(string_compare(string1,string2)){
        printf("True");
    }else{
        printf("False");
    }

    return 0;
}
