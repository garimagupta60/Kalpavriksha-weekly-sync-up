#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
    struct node*prev;
}node;

node* head = NULL;

node* createnode(int value){
    node* newnode = (node*)malloc(sizeof(node));
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

void insertAtBeginning(int value){
    node* newnode = createnode(value);
    if(head == NULL){
        head = newnode;
    }else{
        newnode->next= head;
        head->prev = newnode;
        head = newnode;
    }
}

void insertAtEnd(int value){
    node* newnode = createnode(value);
    if(head == NULL){
        head = newnode;
    }else{
        node* current = head;
        while(current->next!=NULL){
            current= current->next;
        }
        current->next= newnode;
        newnode->prev = current;
    }
}

int countNodes(){
    node* current = head;
    int count =0;
    while(current!=NULL){
        count++;
        current= current->next;
    }
    return count;
}
void insertAtPosition(int value, int position){
    int count = countNodes();
    if(position<1 || position>count+1){
        printf("Invalid position\n");
        exit(0);
    }else if(position==1){
        insertAtBeginning(value);
    }else{
        int number_steps = 1;
        node* current = head;
        node* newnode = createnode(value);
        while(number_steps<position-1 && current!=NULL){
            current= current->next;
            number_steps++;
        }
        node* temp = current->next;
        if(current->next!=NULL){
            newnode ->next = current->next;
        }
        current->prev = newnode;
        newnode->prev = current;
        current->next = newnode;
    }
}

void insertAtMiddle(int value){
    node* newnode = createnode(value);
    int count = countNodes();
    int middle = (count)/2;
    node* current = head;
    while(middle>0){
        current = current->next;
        middle--;
    }
    newnode->next = current;
    node* temp = current->prev;
    current->prev = newnode;
    newnode->prev = current->prev;
    temp->next = newnode;
}
void displayList(){
    if(head==NULL){
        printf("Empty List\n");
        exit(0);
    }
    node* current = head;
    while(current!=NULL){
        if(current->next!=NULL)
            printf("%d ",current->data);
        else
            printf("%d",current->data);
        current= current->next;
    }
}
int main(){
    int choice,data,position;
        printf("\nMenu\n");
        printf("1. Insert at Begin\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Display\n");
        printf("5. Insert at Middle\n");
    while(1){
        if(scanf("%d", &choice)!=1){
            break;
        }
        switch (choice) {
            case 1:
            printf("Enter data to insert at beginning: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;
            
            case 2:
            printf("Enter data to insert at end: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
            
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;

            case 4:
                displayList();
                break;

            case 5:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtMiddle(data);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                exit(0);
        }
    }
    return 0;
}
