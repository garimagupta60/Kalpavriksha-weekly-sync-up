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

int searchid(int id){
    patient* currentpatient = head;
    while(currentpatient!=NULL){
        if(currentpatient->id == id)return 1;
        currentpatient = currentpatient->next;
    }
    return -1;
}
patient* createPatient() {
    int id;
    char severity[100];
    //printf("Enter ID: ");
    scanf("%d", &id);
    getchar();

    while (searchid(id) != -1) {
        printf("This ID already exists. Enter a new ID: ");
        scanf("%d", &id);
        getchar();
    }

    //printf("Enter Severity (Critical, Serious, Stable): ");
    scanf("%[^\n]%*c", severity);

    while (strcmp(severity, "Critical") != 0 && strcmp(severity, "Serious") != 0 && strcmp(severity, "Stable") != 0) {
        printf("This is an invalid severity. Enter a valid severity (Critical, Serious, Stable): ");
        scanf("%[^\n]%*c", severity);
    }

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
        }else if(strcmp(current->severity,"Serious")==0){
            if(seriouslisthead == NULL){
                seriouslisthead = current;
                seriouslisttail = seriouslisthead;
            }else{
                seriouslisttail->next = current;
                seriouslisttail = seriouslisttail->next;
            }
        }else if(strcmp(current->severity,"Stable")==0){
            if(Stablelisthead == NULL){
                Stablelisthead = current;
                Stablelisttail = Stablelisthead;
            }else{
                Stablelisttail->next = current;
                Stablelisttail = Stablelisttail->next;
            }
        }
        current = current->next;
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

    if (criticallisttail) criticallisttail->next = seriouslisthead;
    if (seriouslisttail) seriouslisttail->next = Stablelisthead;

    if (criticallisthead) {
        head = criticallisthead;
    } else if (seriouslisthead) {
        head = seriouslisthead;
    } else {
        head = Stablelisthead;
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

    // printf("Inital list\n");
    // displaypatients(head);
    head = customsort();
    printf("\n");
    displaypatients(head);
}