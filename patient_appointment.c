#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct patient{
    int id;
    char severity[100];
    struct patient* next;
}patient;

patient* head = NULL;
patient* criticallisthead = NULL;
patient* seriouslisthead = NULL;
patient* Stablelisthead = NULL;
patient* criticallisttail = NULL;
patient* seriouslisttail = NULL;
patient* Stablelisttail = NULL;

patient* createPatient(){
    int id;
    char severity[100];
    //printf("Enter ID: ");
    scanf("%d", &id);
    //printf("Enter Severity: ");
    getchar();
    scanf("%[^\n]%*c",severity);

    patient* newpatient = (patient*)malloc(sizeof(patient));
    newpatient->id = id;
    strcpy(newpatient->severity, severity);
    newpatient->next = NULL;
    return newpatient;
}

patient* addpatient(){
    patient* newpatient = createPatient();
    if(head == NULL){
        head = newpatient;
    }else{
        patient* currentpatient = head;
        while(currentpatient->next!=NULL){
            currentpatient = currentpatient->next;
        }
        currentpatient->next = newpatient;
    }
    return head;
}

void displaypatients(patient* head){
    patient* currentpatient = head;
    while(currentpatient!=NULL){
        printf("%d %s\n",currentpatient->id,currentpatient->severity);
        currentpatient = currentpatient->next;
    }
}

patient* findmiddle(patient* head){
    patient* slow = head;
    patient* fast = head->next;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

patient* merge(patient* left, patient* right){

    patient* ans = (patient*)malloc(sizeof(patient));
    patient* temp = ans;
    while(left!=NULL && right!=NULL){
        if(left->id < right->id){
            temp->next = left;
            temp= temp->next;
            left = left->next;
        }else{
            temp->next = right;
            temp= temp->next;
            right = right->next;
        }
    }
    if(left){
        temp->next = left;
    }
    if(right){
        temp->next = right;
    }

    patient* result = ans->next;
    free(ans);
    return result;


}

patient* mergesort(patient* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    patient* middle = findmiddle(head);
    patient* left = head;
    patient* right = middle->next;
    middle->next = NULL;

    left = mergesort(left);
    right = mergesort(right);
    return merge(left,right);
}

patient* customsort(){
    patient* current = head;
    while(current!=NULL){
        if(strcmp(current->severity,"Critical")==0){
            if(criticallisthead == NULL){
                criticallisthead = current;
                criticallisttail = criticallisthead;
            }else{
                criticallisttail->next = current;
                criticallisttail = criticallisttail->next;
            }
            current = current->next;
        }else if(strcmp(current->severity,"Serious")==0){
            if(seriouslisthead == NULL){
                seriouslisthead = current;
                seriouslisttail = seriouslisthead;
            }else{
                seriouslisttail->next = current;
                seriouslisttail = seriouslisttail->next;
            }
            current = current->next;
        }else if(strcmp(current->severity,"Stable")==0){
            if(Stablelisthead == NULL){
                Stablelisthead = current;
                Stablelisttail = Stablelisthead;
            }else{
                Stablelisttail->next = current;
                Stablelisttail = Stablelisttail->next;
            }
            current = current->next;
        }
    }
    if(criticallisttail!=NULL){
        criticallisttail->next = NULL;
    }
    if(seriouslisttail!=NULL){
        seriouslisttail->next = NULL;
    }
    if(Stablelisttail!=NULL){
        Stablelisttail->next = NULL;
    }


    printf("\nCritical List\n");
    displaypatients(criticallisthead);
    printf("\nserious List\n");
    displaypatients(seriouslisthead);
    printf("\nstable List\n");
    displaypatients(Stablelisthead);


    criticallisthead = mergesort(criticallisthead);
    seriouslisthead = mergesort(seriouslisthead);
    Stablelisthead = mergesort(Stablelisthead);

    if(criticallisthead!=NULL){
        head = criticallisthead;
        if(seriouslisthead!=NULL){
            criticallisttail->next = seriouslisthead;
        }
        else{
            criticallisttail->next = Stablelisthead;
        }
        return head;
    }else if(seriouslisthead!=NULL){
        head = seriouslisthead;
        if(Stablelisthead!=NULL){
            seriouslisttail->next = Stablelisthead;
        }
        return head;
    }else{
        head = Stablelisthead;
        return head;
    }
    return head;
}
patient* sortPatientList(){
    if(head == NULL || head->next == NULL){
        return head;
    }
    head = customsort();
    return head;
}

int main(){
    int number_of_patients=0;
    scanf("%d",&number_of_patients);
    while(number_of_patients>0){
        head = addpatient();
        number_of_patients--;
    }

    printf("Inital list\n");
    displaypatients(head);
    head = customsort();
    printf("\n");
    displaypatients(head);
}