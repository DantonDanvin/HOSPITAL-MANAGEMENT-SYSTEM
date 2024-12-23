#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define totalBed 1000

struct MenuNode {
    char name[50];
    void (*function)();
    struct MenuNode* next;
    struct MenuNode* prev;
};

struct MenuNode* currentMenu = NULL;

struct MenuNode* createMenuNode(const char* name, void (*function)()) {
    struct MenuNode* newNode = (struct MenuNode*)malloc(sizeof(struct MenuNode));
    strcpy(newNode->name, name);
    newNode->function = function;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

char password[10];
int Bed=totalBed;

void getPassword() {
    printf("\nNote: Maximum 10 char for password:-\n");
    printf("\nChoose a password for your system:  ");
    scanf("%s",&password);
}

int verifyPassword() {
    char x[10];
    printf("\nEnter the password:  ");
    scanf("%s",&x);

    if (strcmp(password, x) == 0)
        return 1;
    else
        return 0;
}

void passwordProtect(){
    int veri=verifyPassword();

    if(veri==1){
        printf("\nAccess Granted!\n");
    }
    else
    {
        printf("\nAccess Denied!\n");
        exit(0);
    }
}

struct Patient {
    int id;
    char fname[50];
    char lname[50];
    int age;
    char phnumber[50];
    char disease[100];
    char admissionDate[15];
    int bill;
};

struct Patient* Patients[totalBed];
int maintainbed[totalBed]={0}; 

void addPatient(){	

    int y=-1;
    int flag=0;
    for(int i=0;i<totalBed;i++) {
       if(maintainbed[i]==0) {maintainbed[i]=1; flag=1; y=i; break;}
    }			
    if(flag==0)	{
        printf("\nNo Beds are Available!\n");
        return;
    }				
    //ID,firstname,lastname,age,phnumber,occupation,city,disease,Adate,Rdate,bill
    printf("Fill up the following details\n");
    printf("Note: don't use space:-\n");
    Patients[y] = (struct Patient*)malloc(sizeof(struct Patient));
    if (Patients[y] == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("\nID: %d\n",y);
    Patients[y]->id=y;
    printf("\nFirst Name: ");
    scanf("%s",Patients[y]->fname);
    printf("\nLast Name: ");
    scanf("%s",Patients[y]->lname);
    printf("\nAge: ");
    scanf("%d",&Patients[y]->age);
    printf("\nPhone No.: ");
    scanf("%s",Patients[y]->phnumber);
    printf("\nDisease/Symptoms: ");
    scanf("%s",Patients[y]->disease);
    printf("\nAdmission date  (DD/MM/YYYY): ");
    scanf("%s",Patients[y]->admissionDate);
    printf("\nTotal Bill generated: ");
    scanf("%d",&Patients[y]->bill);

    printf("\n\tNew Patient profile created successfully!\n\n");
    Bed--;
}

void editPatient() {
    if (Bed >= totalBed) {
        printf("\nNo Patient records found!\n");
        return;
    }

    int x;
    printf("\nEnter the ID of the Patient whose profile you want to Edit:\n");
    scanf("%d", &x);

    if (maintainbed[x] == 1) {
        printf("Fill up the following details\n");
        printf("Note: Enter -1 if you don't want to change (for 'age and bill') or 'skip' for else:\n");

        char temp[100];
        int tempInt;

        printf("\nID: %d",x);
        printf("\nCurrent First Name: %s", Patients[x]->fname);
        printf("\nNew First Name: ");
        scanf("%s", temp);
        if (strcmp(temp, "skip") != 0) {
            strcpy(Patients[x]->fname, temp);
        }

        printf("\nCurrent Last Name: %s", Patients[x]->lname);
        printf("\nNew Last Name: ");
        scanf("%s", temp);
        if (strcmp(temp, "skip") != 0) {
            strcpy(Patients[x]->lname, temp);
        }

        printf("\nCurrent Age: %d", Patients[x]->age);
        printf("\nNew Age: ");
        scanf("%d", &tempInt);
        if (tempInt != -1) {
            Patients[x]->age = tempInt;
        }

        printf("\nCurrent Phone No.: %s", Patients[x]->phnumber);
        printf("\nNew Phone No.: ");
        scanf("%s", temp);
        if (strcmp(temp, "skip") != 0) {
            strcpy(Patients[x]->phnumber, temp);
        }

        printf("\nCurrent Disease/Symptoms: %s", Patients[x]->disease);
        printf("\nNew Disease/Symptoms: ");
        scanf("%s", temp);
        if (strcmp(temp, "skip") != 0) {
            strcpy(Patients[x]->disease, temp);
        }

        printf("\nCurrent Admission Date: %s", Patients[x]->admissionDate);
        printf("\nNew Admission Date (DD/MM/YYYY): ");
        scanf("%s", temp);
        if (strcmp(temp, "skip") != 0) {
            strcpy(Patients[x]->admissionDate, temp);
        }

        printf("\nCurrent Bill: %d", Patients[x]->bill);
        printf("\nNew Bill: ");
        scanf("%d", &tempInt);
        if (tempInt != -1) {
            Patients[x]->bill = tempInt;
        }

        printf("\n\nPatient profile edited successfully!\n\n");
    } else {
        printf("\nNo matching records found!\n");
        return;
    }
}

void displayPat(){

    if(Bed>=totalBed) {
        printf("\nNo Patient records found!\n");
        return;
    }
    int x;
    printf("\nEnter the ID of the Patient whose profile you want to Display:\n");
    scanf("%d",&x);

    if(maintainbed[x]==1){
        printf("\n1. ID: %d",Patients[x]->id);
        printf("\n2. First Name: %s",Patients[x]->fname);
        printf("\n3. Last Name: %s",Patients[x]->lname);
        printf("\n4. Age: %d",Patients[x]->age);
        printf("\n5. Phone No.: %s",Patients[x]->phnumber);
        printf("\n6. Disease/Symptoms: %s",Patients[x]->disease);
        printf("\n7. Admission date(DD/MM/YYYY): %s",Patients[x]->admissionDate);
        printf("\n8. Total Bill generated: %d\n",Patients[x]->bill);
    }
    else {
        printf("\nNo matching records found!\n");
        return;
    }

}

void deletePat() {
    if(Bed>=totalBed) {
        printf("\nNo Patient records found!\n");
        return;
    }
    int x;
    printf("\nEnter the ID of the Patient whose profile you want to Delete:\n");
    scanf("%d",&x);
    
        if(maintainbed[x]==1){
            free(Patients[x]);
            Bed++;
            maintainbed[x]=0;
            printf("\n\t Patient profile Deleted successfully!\n\n");
            printf("\n");
        }
        else {
        printf("\nNo matching records found!\n");
        return;
    }
}

void dispPatDatabase() {
    if(Bed>=totalBed) {
        printf("\nNo Patient records found!\n");
        return;
    }

    for(int i=0;i<totalBed;i++) {
            if(maintainbed[i]==1) {
            printf("\n1. ID: %d",Patients[i]->id);
            printf("\n2. First Name: %s",Patients[i]->fname);
            printf("\n3. Last Name: %s",Patients[i]->lname);
            printf("\n4. Age: %d",Patients[i]->age);
            printf("\n5. Phone No.: %s",Patients[i]->phnumber);
            printf("\n6. Disease/Symptoms: %s",Patients[i]->disease);
            printf("\n7. Admission date(DD/MM/YYYY): %s",Patients[i]->admissionDate);
            printf("\n8. Total Bill generated: %d",Patients[i]->bill);
            printf("\n");
            }
    }
}

void numberofPats() {
    printf("\nTotal number of Patients: %d\n",totalBed-Bed);
}


void getPatientDatabase(){
    passwordProtect();
    while(1) {
    printf("\n-----------------------------");
    printf("\nWELCOME TO PATIENT'S DATABASE\n\n");
    printf("1. Add New Patient's Information\n");
    printf("2. Edit a Patient's Information\n");
    printf("3. Display a Patient's Information\n");
    printf("4. Delete a Patient's Information\n");
    printf("5. Display Entire Patient Database\n");
    printf("6. Total Number of Patients\n");
    printf("7. Go Back to Main Menu\n");
    printf("8. Move to Bed Database\n");
    printf("-----------------------------\n\n");

    printf("\nEnter the number corresponding to your choice: ");
    int choice_pat;
    scanf("%d",&choice_pat);
    printf("\n\n");
    
    switch(choice_pat){
        case 1:{
            addPatient();
            break;
        }
        case 2:{
            editPatient();
            break;
        }
        case 3:{
            displayPat();
            break;
        }
        case 4:{
            deletePat();
            break;
        }
        case 5:{
            dispPatDatabase();
            break;
        }
        case 6:{
            numberofPats();
            break;
        }
        case 7:{
            currentMenu = currentMenu->prev; // Go back to Main Menu
            currentMenu->function();
            break;
        }
        case 8:{
            currentMenu = currentMenu->next; // Move to Bed Database
            currentMenu->function();
            break;
        }
        default: {
            printf("\nEnter a valid option.\n");
            getPatientDatabase();
        }
    }

    }
}

void getBedDatabase(){
    passwordProtect();
    printf("\nBED DATABASE\n");
    printf("------------\n");

    printf("\nTotal number of bed: %d\n",totalBed);
    printf("Total number of bed available: %d\n",Bed);
    printf("Total number of bed used: %d\n\n\n",totalBed-Bed);

    printf("1. Go Back to Main Menu\n");
    printf("2. Go Back to Patient Database\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            currentMenu = currentMenu->prev->prev; // Go back to Main Menu
            currentMenu->function();
            break;
        case 2:
            currentMenu = currentMenu->prev; // Go back to Patient Database
            currentMenu->function();
            break;
        default:
            printf("\nEnter a valid option.\n");
            getBedDatabase();
    }
}


void mainMenu() {

    printf("\n\nWELCOME TO HOSPITAL MANAGEMENT SYSTEM\n");
    printf("------------------------------------------------\n");

    printf("\nMAIN MENU\n\n");
    printf("1. Enter Into Patients Database\n");
    printf("2. Check for Hospital Bed Availability\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            currentMenu = currentMenu->next; // Move to Patient Database
            currentMenu->function();
            break;
        case 2:
            currentMenu = currentMenu->next->next; // Move to Bed Database
            currentMenu->function();
            break;
        case 3:
            printf("\nThanks for working with us.\n");
            exit(0);
        default:
            printf("\nEnter a valid option.\n");
            mainMenu();
    }
}

// Main program
int main() {

    getPassword();

    struct MenuNode* mainMenuNode = createMenuNode("Main Menu", mainMenu);
    struct MenuNode* patientDatabaseNode = createMenuNode("Patient Database", getPatientDatabase);
    struct MenuNode* bedDatabaseNode = createMenuNode("Bed Database", getBedDatabase);

    mainMenuNode->next = patientDatabaseNode;
    patientDatabaseNode->prev = mainMenuNode;
    patientDatabaseNode->next = bedDatabaseNode;
    bedDatabaseNode->prev = patientDatabaseNode;

    currentMenu = mainMenuNode;

    currentMenu->function();

    return 0;
}

