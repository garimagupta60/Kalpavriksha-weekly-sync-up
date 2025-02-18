#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    char character;
    struct node* next;
}node;

typedef struct stack{
    node* top;
    int size;
}stack;

typedef struct map{
    char character;
    int count;
}map;

node* createnode(char character){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->character = character;
    newnode->next = NULL;
    return newnode;
}

stack* createstack(){
    stack* newstack = (stack*)malloc(sizeof(stack));
    newstack->top = NULL;
    newstack->size = 0;
    return newstack;
}

map* hashmap;
void createhashmap(){
    hashmap = (map*)malloc(sizeof(map)*6);
    char symbols[6] = {'(', '{', '[', ')', '}', ']'};
    for (int i = 0; i < 6; i++) {
        hashmap[i].character = symbols[i];
        hashmap[i].count = 0;
    }

}

int isEmpty(stack* newstack){
    return (newstack->top == NULL);
}

void push(stack* newstack, char character){
    node* newnode = createnode(character);
    if(isEmpty(newstack)){
        newstack->top = newnode;
        newstack->size++;
        return;
    }
    newnode->next = newstack->top;
    newstack->top = newnode;
    newstack->size++;
}

void pop(stack* newstack){
    if(isEmpty(newstack)){
        return;
    }
    node* temp = newstack->top;
    newstack->top = newstack->top->next;
    newstack->size--;
    free(temp);
}

void freestack(stack* newstack){
    while(!isEmpty(newstack)){
        pop(newstack);
    }
    free(newstack);
}
int ischaracter(char character){
    if(character ==')' || character == '}' || character == ']' || character =='(' || character == '{' || character == '[')return 1;
    return 0;
}

int main(){
    char string[100000];
    scanf("%[^\n]%*c",string);
    stack* newstack = createstack();
    int validity = 1;
    createhashmap();
    for(int i=0; i<strlen(string); i++){
        char character = string[i];
        if(!ischaracter(character))continue;
        if(character=='('){
            push(newstack,character);
            hashmap[0].count++;
        }
        else if(character=='{'){
            push(newstack,character);
            hashmap[1].count++;
        }
        else if(character=='['){
            push(newstack,character);
            hashmap[2].count++;
        }
        else if(character ==')' || character == '}' || character == ']'){
            if(!isEmpty(newstack)){
                if(character == ')')hashmap[3].count++;
                else if(character == '}')hashmap[4].count++;
                else if(character == ']')hashmap[5].count++;
                char topchar = newstack->top->character;
                if((character == ')' && topchar == '(' ) || (character == ']' && topchar == '[' )|| (character == '}' && topchar == '{' ) ){
                    pop(newstack);
                }else{
                    validity = 0;
                }
            }else{
                validity = 0;
            }
        }
    }
    if(!isEmpty(newstack)){
        validity = 0;
    }
    validity == 1 ? printf("valid\n"): printf("Not Valid\n");
    for(int i=0; i<6; i++){
        printf("%c -> %d ",hashmap[i].character,hashmap[i].count);
    }

    freestack(newstack);
    free(hashmap);
}