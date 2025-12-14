#include <stdio.h>
#include <string.h>

#define MAX 100

void registerUser() {
    char username[MAX], password[MAX];
    FILE *fp = fopen("login.txt", "w");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Register\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    fprintf(fp, "%s %s\n", username, password);
    fclose(fp);

    printf("Registration successful!\n");
}

void loginUser() {
    char username[MAX], password[MAX];
    char storedUser[MAX], storedPass[MAX];
    FILE *fp = fopen("login.txt", "r");

    if (fp == NULL) {
        printf("No registered user found. Please register first.\n");
        return;
    }

    fscanf(fp, "%s %s", storedUser, storedPass);
    fclose(fp);

    printf("Login\n");
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(username, storedUser) == 0 && strcmp(password, storedPass) == 0) {
        printf("Login successful!\n");
    } else {
        printf("Invalid credentials.\n");
    }
}

int main() {
    int choice;

    printf("1. Register\n2. Login\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        registerUser();
    } else if (choice == 2) {
        loginUser();
    } else {
        printf("Invalid choice.\n");
    }
   
    

    return 0;
}


    
