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
    char buffer2[100];
    char place[15];
    int found = 0;
	int opt,usrFound = 0;
	struct user user;
	char password2[50],buffer[64];
	 char pword1[64];
	 char username1[64];
   char buffer1[64];
   int i = 0;

void takeinput(char ch[50]){
	fgets(ch,50,stdin);
	ch[strlen(ch) - 1] = 0; 
}

char generateUsername(char email[50],char username[50]){
	//abc123@gmail.com
	for(int i=0;i<strlen(email);i++){
		if(email[i] == '@') break;
		else username[i] = email[i];
	}
}

void takepassword(char pwd[50]){
		int i;
	char ch;
	while(1){
		ch = getch();
		if(ch == ENTER || ch == TAB){
			pwd[i] = '\0';
			break;
		}else if(ch == BCKSPC){
			if(i>0){
				i--;
				printf("\b \b");
			}
		}else{
			pwd[i++] = ch;
			printf("* \b");
		}
	}
				
fpointer =fopen("record.txt", "r");
   if (!fpointer) {
      printf ("Results.dat could not be opened.\n");
      exit(-1);
   }

   while( fgets (buffer, 64, fpointer)) {
        if(strcmp(buffer,user.password) == 0) {
          printf("\nplz create a strong password\n");
          printf("Enter your password:\t");
		 takepassword(user.password);
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
	scanf("%d",&opt);
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

generateUsername(user.email,user.username);
				
fpointer = fopen("record.txt","a+");
fprintf(fpointer,"%s",user.username);
fprintf(fpointer,"\n");
fprintf(fpointer,"%s",user.password);
fprintf(fpointer,"\n");
fclose(fpointer);
      //embbed in file 
       fp  = fopen("user.txt","a+");
          fprintf(fp,"\n");
          fprintf(fp,"%s				",user.fullName);
          fprintf(fp,"%s				",user.email);
         fprintf(fp,"%s				",user.phone);
          fprintf(fp,"%s			",user.username);
           fprintf(fp,"%s",user.password);
               fclose(fp);

				if(fprintf != 0) printf("\n\nUser resgistration success, Your username is %s",user.username);
				else printf("\n\nSorry! Something went wrong :(");
				fclose(fp);
				system("cls");
				printf("u can login now");
				goto restart;

		break;
		
		case 2: //login	
		login:
  
  
  printf("Enter your username\t:");
 fgets(username1, 64, stdin);

   printf("enter the password:\t");
fgets(pword1, 64, stdin);


fpointer =fopen("record.txt", "a+");
   if (!fpointer) {
      printf ("Results.dat could not be opened.\n");
      exit(-1);
   }


   while( fgets(buffer, 64, fpointer)){
        if(strcmp(buffer,username1) == 0){
		  usrFound =1;
       }
   }
   if (usrFound == 1){
	   usrFound = 0;
   }
   else{
	   printf("Incorrect username\n");
	   goto login;
   }

   fclose(fpointer);

   fpointer =fopen("record.txt", "a+");

   while( fgets(buffer, 64, fpointer)){
        if(strcmp(buffer,pword1) == 0){
          printf("you are registered");
		  usrFound =1;
       }
   }

   fclose(fpointer);

   if (usrFound == 1){

   }
   else{
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
    printf("Enter the place u want to search:");
    fgets(place, 15, stdin);


 for ( i = 0; i <= strlen (place); i++)  
 {  
 if (place[i] >= 65 && place[i] <= 90)  
 place[i] = place[i] + 32; /* add 32 to string character to convert into lower case. */  
 } 



f =fopen("places.txt", "a+");
   if (!f) {
      printf ("Results.dat could not be opened.\n");
      exit(-1);
   }



    while( fgets(buffer, 64, f)) {
       
        if(strcmp(buffer, place) == 0){
          found = 1;
		 
          break;   
   }
   
    }

	if (found == 1) {}
	else{ 
	printf("Please mention the place name correctly");
	Sleep(800);
	fflush(stdin);
	goto guide;
}

//getting the current position of the pointer
fseek(f, 0, SEEK_CUR);
    int pos=ftell(f);

while (fscanf(f,"%s",buffer))
{
  if(strcmp(buffer,"}")==0){
          break;
   }
}
//getting the (reuired)end position of the pointer
fseek(f, 0, SEEK_CUR);
  int pos1=ftell(f);

//getting the reversed position of the posinter
int exactpos = pos1 - pos;
fseek(f, -exactpos, SEEK_CUR);

 while( fgets(buffer, 64, f) ) {
        if(ftell(f)== pos1+2){
			printf("\nsearch another place(1-- yes, 0--no)\n");
          break;
   }
   else{
      printf("\n%s",buffer);
   }
   
  
 }


if (found ==1){
scanf("%d",&opt);
resp:
switch(opt){
	case 1 : system("cls");
	fflush(stdin);
	 goto guide;
	break;

	case 0 : return 0;
	break;

	default : 
	printf("\nsearch another place(1-- yes, 0--no)\n");
scanf("%d",&opt);
	goto resp;
	break;
}
}



  fclose(f);
	return 0;
}