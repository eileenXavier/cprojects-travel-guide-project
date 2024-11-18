#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include<conio.h>
#include<windows.h>
#include <time.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8

struct user{
    char fullName[50];
    char email[50];
    char password[50];
    char username[50];
    char phone[50];
};
FILE *fp;
FILE *fpointer;
FILE *f;
char buffer2[200];
char place[15];
int found = 0;
int opt, usrFound = 0;
struct user user;
char password2[50], buffer[200];
char pword1[64];
char username1[64];
char buffer1[200];
int i = 0;

void takeinput(char ch[50]){
    fgets(ch, 50, stdin);
    ch[strlen(ch) - 1] = 0;
}

char generateUsername(char email[50], char username[50]){
    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '@') break;
        else username[i] = email[i];
    }
}

void takepassword(char pwd[50]){
    int i = 0;
    char ch;
    while (1) {
        ch = getch();
        if (ch == ENTER || ch == TAB) {
            pwd[i] = '\0';
            break;
        } else if (ch == BCKSPC) {
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            pwd[i++] = ch;
            printf("# \b"); // Changed mask character to '#'
        }
    }
}

int main(){
restart:
    system("cls");
    system("color 0b");
    printf("\n\t\t\t\t----------Welcome to travel guide ----------");
    printf("\nPlease choose your operation");
    printf("\n1.Signup");
    printf("\n2.Login");
    printf("\n3.Exit");
    printf("\n\nYour choice:\t");
    scanf("%d", &opt);
    fgetc(stdin);

    switch(opt){
        case 1:
            system("cls");
            printf("\nEnter your full name:\t");
            takeinput(user.fullName);
            printf("Enter your email:\t");
            takeinput(user.email);
            printf("Enter your contact no:\t");
            takeinput(user.phone);
            printf("Enter your password:\t");
            takepassword(user.password);

            generateUsername(user.email, user.username);

            fpointer = fopen("record.txt", "a+");
            fprintf(fpointer, "%s", user.username);
            fprintf(fpointer, "\n");
            fprintf(fpointer, "%s", user.password);
            fprintf(fpointer, "\n");
            fclose(fpointer);

            fp = fopen("user.txt", "a+");
            fprintf(fp, "\n");
            fprintf(fp, "%s\t", user.fullName);
            fprintf(fp, "%s\t", user.email);
            fprintf(fp, "%s\t", user.phone);
            fprintf(fp, "%s\t", user.username);
            fprintf(fp, "%s", user.password);
            fclose(fp);

            if (fprintf != 0) printf("\n\nUser registration success, Your username is %s", user.username);
            else printf("\n\nSorry! Something went wrong :(");
            system("cls");
            printf("You can login now");
            goto restart;

        break;

        case 2:
        login:
            printf("Enter your username\t:");
            fgets(username1, 64, stdin);

            printf("Enter the password:\t");
            fgets(pword1, 64, stdin);

            fpointer = fopen("record.txt", "a+");
            if (!fpointer) {
                printf ("Results.dat could not be opened.\n");
                exit(-1);
            }

            while (fgets(buffer, 200, fpointer)) {
                if (strcmp(buffer, username1) == 0) {
                    usrFound = 1;
                }
            }
            if (usrFound == 1) usrFound = 0;
            else {
                printf("Incorrect username\n");
                goto login;
            }

            fclose(fpointer);

            fpointer = fopen("record.txt", "a+");

            while (fgets(buffer, 200, fpointer)) {
                if (strcmp(buffer, pword1) == 0) {
                    printf("You are registered");
                    usrFound = 1;
                }
            }

            fclose(fpointer);

            if (usrFound == 1) {}
            else {
                printf("Incorrect password\n");
                goto login;
            }

        goto guide;

        break;

        case 3:
            printf("\t\t\tBye Bye :)");
            return 0;        
    }

guide:
    system("cls");
    printf("Enter the place you want to search:");
    fgets(place, 15, stdin);

    for (i = 0; i <= strlen(place); i++) {
        if (place[i] >= 65 && place[i] <= 90)
            place[i] = place[i] + 32; 
    }

    f = fopen("places.txt", "a+");
    if (!f) {
        printf ("Results.dat could not be opened.\n");
        exit(-1);
    }

    while (fgets(buffer, 200, f)) {
        if (strcmp(buffer, place) == 0) {
            found = 1;
            break;   
        }
    }

    if (found == 1) {}
    else {
        printf("Please mention the place name correctly");
        Sleep(800);
        fflush(stdin);
        goto guide;
    }

    while (fgets(buffer, 200, f)) {
        printf("%s", buffer);
    }

    fclose(f);
    return 0;
}
