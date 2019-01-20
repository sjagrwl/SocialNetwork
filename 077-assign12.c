#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include <unistd.h>

#define clear system("clear");
#define DATABASE_FILE_NAME "database.txt"
#define bar(c) printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");printf(c);printf("\n\n\n-----------------------------------------------------------------------------------------------------------------------------------------------\n\n\n");
#define progress(c,d,e) printf(c);for(int count=0;count < d; ++count){printf(". ") ;fflush(stdout);sleep(1);}printf(e);
#define BuffEmpty int garbage;while ((garbage = getchar()) != '\n' && garbage != EOF);

typedef struct PROFILE PROFILE;

// declaration of LIST structure
typedef struct LIST {
	char data[50];
//For having link to friend's profile in user's friendlist.
	PROFILE *profile;

	struct LIST *next;
}LIST;

// declaration of  PROFILE structure
struct PROFILE {
	char name[30];
	LIST *flist;
	LIST *intlist;
	LIST *movlist;
	LIST *gamlist;

	struct PROFILE *next;
};

// funtion for creating and linking profiles of user
PROFILE *CreateProfile (PROFILE *head, char name[]) {
	PROFILE *newp=(PROFILE *)malloc(sizeof(PROFILE));
	if(!newp) {
		exit(-1);
	}

	strcpy(newp->name,name);

	newp->flist=NULL;
	newp->intlist=NULL;
	newp->movlist=NULL;
	newp->gamlist=NULL;

	newp->next=head;
	return newp;
}

// function to add friends/interest/game/movie into their respective lists
LIST *AddInList(LIST *head,char data[],PROFILE *fpoint) {
	LIST *newl=(LIST *)malloc(sizeof(LIST));
	if(!newl) {
		exit(-1);
	}

	strcpy(newl->data,data);

	newl->profile=fpoint;
	newl->next=head;
	return newl;	
}

//  function for character checking  
int AlphaCheck(char c) {
	if( (c-'a')<26 && (c-'a')>=0 ) {
		return 1;
	}

	if( (c-'A')<26 && (c-'A')>=0 ) {
		return 1;
	}

	return -1;
}

// function for sting comparision  for both lower case and upper case
int STRCMP(char A[], char B[]) {
	int i;
	int l1=strlen(A), l2=strlen(B);
	if(l1!=l2) {
		return -1;
	}
	else {
		for(i=0;i<l1;i++) {
			if(A[i]!=B[i] && A[i]!= B[i]-32 && A[i]!=B[i]+32) {
				return A[i]-B[i];
			}
		}
		return 0;
	}
}
 // to check if the profile is already present or not
PROFILE * ProfileCheck(PROFILE *head,char name[]) {
	while(head!=NULL) {
		if(STRCMP(head->name,name)==0) {
			return head;
		}

		head=head->next;
	}
	return NULL;
}

// to check if the data is already there in the list (common for all four lists)
int DataCheck(LIST *head,char data[]) {
	while(head!=NULL) {
		if(STRCMP(head->data,data)==0) {
			return -1;
		}

		head=head->next;
	}
	
	return 1;
}

// to load data into the structure (linkedlist of linkedlists ie. hashtable)

PROFILE *LoadDatabase(PROFILE *head) {
	FILE *fp=fopen(DATABASE_FILE_NAME,"r");

	char Line[1000],Data[50],c;
	int i,flag=0,index;
	PROFILE *user,*friend;
	while(fscanf(fp,"%[^\n]s",Line)>=1 || fscanf(fp,"%c",&c)>=1) {

		if(strlen(Line)>1) {
			// to store the username
			if(Line[0]=='U' || Line[1]=='U') {
				index=0;
				for(i=0;i<strlen(Line);i++) {
			
					if(Line[i]==':') {
						flag=1;		
					}

					if(flag==2) {
						Data[index]=Line[i];
						index++;		
					}

					if(flag==1 && AlphaCheck(Line[i])==1 ) {			
						Data[index]=Line[i];
						index++;		
						flag++;
					}
				}

				Data[index]='\0';
				// checking or profile
				user=ProfileCheck(head,Data);
				if(user==NULL) {
					// creating a user profile
					head=CreateProfile(head,Data);
				}

				flag=0;	
			}
			// to store the friend list
			else if(Line[0]=='F' || Line[1]=='F') {
				index=0;
				for(i=0;i<strlen(Line);i++) {
			
					if(Line[i]==':') {
						flag=1;		
					}
					//avoiding ',' and '.'
					if(flag==2 && !(Line[i]==',' || Line[i]=='.')) {
						Data[index]=Line[i];
						index++;		
					}

					if(flag==1 && AlphaCheck(Line[i])==1) {				
						Data[index]=Line[i];
						index++;
						flag++;					
					}
					//avoiding ',' and '.'
					if(flag==2 && (Line[i]==',' || Line[i]=='.')) {
						Data[index]='\0';
						// checking for the friend
						friend=ProfileCheck(head,Data);
						if(friend==NULL) {

							head=CreateProfile(head,Data);
							friend=head;	
						}

						if(DataCheck(user->flist,Data)==1) {
							// addition into flist of user
							user->flist=AddInList(user->flist,Data,friend);
						}

						if(DataCheck(friend->flist,user->name)==1) {
							// addition into flist of friend
							friend->flist=AddInList(friend->flist,user->name,user);
						}

						flag--;
						index=0;
					} 
				}
	
				flag=0;			
			}
			// to store interest
			else if(Line[0]=='I' || Line[1]=='I') {
				index=0;
				for(i=0;i<strlen(Line);i++) {
		
					if(Line[i]==':') {
						flag=1;		
					}
					//avoiding ',' and '.'
					if(flag==2 && !(Line[i]==',' || Line[i]=='.')) {
					
						Data[index]=Line[i];
						index++;		
					}

					if(flag==1 && AlphaCheck(Line[i])==1) {
					
						Data[index]=Line[i];
						index++;	
						flag++;				
					}
					//avoiding ',' and '.'
					if(flag==2 && (Line[i]==',' || Line[i]=='.')) {
						Data[index]='\0';
						if(DataCheck(user->intlist,Data)==1) {
							// addition of interest  into intlist		
							user->intlist=AddInList(user->intlist,Data,NULL);
						}
				
						flag--;
						index=0;
					} 
				}
				flag=0;
			}
			//to store movies
			else if(Line[0]=='M' || Line[1]=='M') {
				index=0;
				for(i=0;i<strlen(Line);i++) {
	
					if(Line[i]==':') {
	
						flag=1;		
					}
					//avoiding ',' and '.'
					if(flag==2 && !(Line[i]==',' || Line[i]=='.')) {
					
						Data[index]=Line[i];
						index++;		
					}

					if(flag==1 && AlphaCheck(Line[i])==1) {
					
						Data[index]=Line[i];
						index++;
						flag++;					
					}
					//avoiding ',' and '.'
					if(flag==2 && (Line[i]==',' || Line[i]=='.')) {
						Data[index]='\0';
						if(DataCheck(user->movlist,Data)==1) {
							// addiion of movie to movlist		
							user->movlist=AddInList(user->movlist,Data,NULL);
						}
						flag--;
						index=0;
					} 
				}
	
				flag=0;
			}
			// to store game list
			else if(Line[0]=='G' || Line[1]=='G') {		
				index=0;
				for(i=0;i<strlen(Line);i++) {
	
					if(Line[i]==':') {
	
						flag=1;		
					}
					//avoiding ',' and '.'
					if(flag==2 && !(Line[i]==',' || Line[i]=='.')) {
					
						Data[index]=Line[i];
						index++;		
					}

					if(flag==1 && AlphaCheck(Line[i])==1) {
					
						Data[index]=Line[i];
						index++;
						flag++;					
					}
					//avoiding ',' and '.'
					if(flag==2 && (Line[i]==',' || Line[i]=='.')) {	
						Data[index]='\0';
						if(DataCheck(user->gamlist,Data)==1) {
							// addition into the game list	
							user->gamlist=AddInList(user->gamlist,Data,NULL);
						}
						flag--;
						index=0;
					} 
				}
				flag=0;
			}
		}
	}
	fclose(fp);
	return head;
}

// function to print the database stored int the hashtable
void PrintDatabase(PROFILE *head) {
	LIST *datahead;
	clear
	bar("\t\t\t\t\t\t\t  COMPLETE DATABASE ENTRIES");
	while(head!=NULL) {

		printf(" %s\n\n",head->name);
		printf("FRIENDLIST:");	
		datahead=head->flist;	
		while(datahead!=NULL) {

			printf(" %s",datahead->data);
			datahead=datahead->next;
			if(datahead!=NULL) {

				printf(",");
			}
			else {

				printf(".");
			}
		}
		printf("\n");

		printf("INTERESTS:");
		datahead=head->intlist;		
		while(datahead!=NULL) {

			printf(" %s",datahead->data);
			datahead=datahead->next;
			if(datahead!=NULL) {

				printf(",");
			}
			else {

				printf(".");
			}
		}
		printf("\n");
		
		printf("MOVIES:");
		datahead=head->movlist;		
		while(datahead!=NULL) {

			printf(" %s",datahead->data);
			datahead=datahead->next;
			if(datahead!=NULL) {

				printf(",");
			}
			else {

				printf(".");
			}
		}
		printf("\n");

		printf("GAMES:");
		datahead=head->gamlist;		
		while(datahead!=NULL) {

			printf(" %s",datahead->data);
			datahead=datahead->next;
			if(datahead!=NULL) {

				printf(",");
			}
			else {

				printf(".");
			}
		}
		printf("\n\n");

		head=head->next;
	}
} 

//Saving the complete database back to the database file.
void SaveDataBase(PROFILE *head) {
	FILE *fp=fopen(DATABASE_FILE_NAME,"w");
	LIST *datahead;
	while(head!=NULL) {

		fprintf(fp,"USERNAME: %s\n",head->name);
		fprintf(fp,"FRIENDLIST: ");	
		datahead=head->flist;	
		while(datahead!=NULL) {

			fprintf(fp,"%s",datahead->data);
			datahead=datahead->next;
			if(datahead!=NULL) {
				fprintf(fp,",");
			}
			else {
				fprintf(fp,".");
			}
		}
		fprintf(fp,"\n");

		fprintf(fp,"INTERESTS: ");
		datahead=head->intlist;		
		while(datahead!=NULL) {

			fprintf(fp,"%s",datahead->data);
			datahead=datahead->next;
			if(datahead!=NULL) {
				fprintf(fp,",");
			}
			else {
				fprintf(fp,".");
			}
		}
		fprintf(fp,"\n");
		
		fprintf(fp,"MOVIES: ");
		datahead=head->movlist;		
		while(datahead!=NULL) {

			fprintf(fp,"%s",datahead->data);
			datahead=datahead->next;
			if(datahead!=NULL) {
				fprintf(fp,",");
			}
			else {
				fprintf(fp,".");
			}
		}
		fprintf(fp,"\n");

		fprintf(fp,"GAMES: ");
		datahead=head->gamlist;		
		while(datahead!=NULL) {

			fprintf(fp,"%s",datahead->data);
			datahead=datahead->next;
			if(datahead!=NULL) {
				fprintf(fp,",");
			}
			else {
				fprintf(fp,".");
			}
		}
		fprintf(fp,"\n\n");
		head=head->next;
	}
	fclose(fp);	
} 

//Uncomment MAIN to test individual Task 1 BUT DON'T FORGET TO COMMENT IT BACK FOR FINAL DEMO.

/*
int main() {

	PROFILE *head=NULL;

	printf("\n******************TASK 1**********************\n\n");
	head=LoadDatabase(head);
//	PrintDatabase(head);

//	printf("\n******************TASK 2**********************\n\n");
//	head=AddNewUser(head);
//	PrintDatabase(head);

//	printf("\n******************TASK 3**********************\n\n");
//	head=DeleteInfo(head);
//	PrintDatabase(head);

//	printf("\n******************TASK 4**********************\n\n");
//	head=SearchInfo(head);

//	SaveDataBase(head);	
		
	return 0;
}
*/

