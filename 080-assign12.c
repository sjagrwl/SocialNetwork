#include"068-assign12.c"

//for searching user's info
PROFILE *SearchInfo(PROFILE *head) {
	int flag=1,choice,c1=0,fff=0;
	char garb,pname[40],name1[40],name2[40];
	PROFILE *dummy,*dummy1,*dummy2;
	LIST *node1=NULL,*node2=NULL,*temp,*temp1;
	
	do {

		clear
		bar("\t\t\t\t\t\tPROFILE INFO SEARCH PAGE");
		printf("\n\n\nPress 1 to search for a profile.\nPress 2 to search common friends.\nPress 3 to search common intrests.\nPress 4 to display all second connections.\nPress 5 to search friends with common intrests.\nPress 6 to search people who play a common game.\nPress 7 to serach people who like same movies.\nPress 0 to finish searching user's INFO\n\n");
		//entering the value of choice		
		scanf("%d",&choice);
		BuffEmpty;

		if(choice==0) {
			flag=0;
		}
		else if(choice==1) {	
			printf("\nEnter the profile name you want to search\n");
			//enter the profile name
			scanf("%[^\n]s",pname);
			//storing head in dummy
			dummy = head;
			while (dummy!=NULL) {
				//calling function to string compare both upper and lower and lower cases
				if(STRCMP(pname,dummy->name)==0) {
					c1++;
					dummy1=dummy;	
				}
				dummy=dummy->next;
			}
			if(c1>0){
				printf("\n Profile found.\n\n");
				//calling the function for printing all the details
				PrintSingleProfile(dummy1);
				sleep(1);
				fflush(stdout);
				printf("\n\n\nPress any key to continue.\n\n");
				scanf("%c",&garb);
				BuffEmpty;
			}
			else {
				printf("\n Profile not found.\n\n");
				fflush(stdout);
				sleep(1);
			}
			//again we are setting the values to NULL
			dummy1=NULL;
			dummy=NULL;
			c1=0;
		}
		else if(choice==2){
			printf("\nEnter the first  profile name \n");
			//enter the 1st profile name
			scanf("%[^\n]s",name1);
			scanf("%c",&garb);
			printf("\nEnter the second profile name \n");
			//enter the 2nd profile name
			scanf("%[^\n]s",name2);
			scanf("%c",&garb);
			//storing head in dummy
			dummy = head;
			while (dummy!=NULL) {

				// function for string comparision  for both lower case and upper case
				if(STRCMP(name1,dummy->name)==0) {				
					node1=dummy->flist;
				}	
				// function for string comparision  for both lower case and upper case
				 if(STRCMP(name2,dummy->name)==0) {
					node2=dummy->flist;
				}
				dummy=dummy->next;
			}
			if(node1==NULL || node2==NULL) {	
				printf("\n Improper choice of names. Select again. \n");
				fflush(stdout);
				sleep(1);
			}
			else {
				printf("\n Common friends are:- \n\n");
				while(node1!=NULL) {

					//storing node2 in temp					
					temp=node2;
					while(temp!=NULL) {
						// function for string comparision  for both lower case and upper case
						if(STRCMP(node1->data,temp->data)==0) {			
							printf("                           %s   \n",node1->data);
						}
						temp=temp->next;
					}
					node1=node1->next;
				}
				sleep(1);
				fflush(stdout);
				printf("\n\n\nPress any key to continue.\n\n");
				scanf("%c",&garb);
				BuffEmpty;			
			}
			//setting values to NULL
			node1=NULL;
			node2=NULL;
			temp=NULL;
		}
		else if(choice==3) {
			printf("\nEnter the first profile name \n");
			//enter the 1st profile name
			scanf("%[^\n]s",name1);
			scanf("%c",&garb);
			printf("\nEnter the second profile name \n");
			//enter the 2nd profile name
			scanf("%[^\n]s",name2);
			scanf("%c",&garb);
			int f=0;
			//storing head in dummy
			dummy = head;
			while (dummy!=NULL) {
				
				// function for string comparision  for both lower case and upper case
				if(STRCMP(name1,dummy->name)==0) {
					node1=dummy->intlist;
					f++;
				}
				// function for string comparision  for both lower case and upper case				
				if(STRCMP(name2,dummy->name)==0) {
					node2=dummy->intlist;
					f++;
				}
				dummy=dummy->next;
			}
			if((node1==NULL || node2==NULL) && f<2) {	
				printf("\n Improper choice of names. Select again. \n");
				fflush(stdout);
				sleep(1);
			}
			else {
				printf("\n Common intrests are:- \n\n");
				while(node1!=NULL) {
					
					//storing node2 in temp					
					temp=node2;
					while(temp!=NULL) {
	
						// function for string comparision  for both lower case and upper case
						if(STRCMP(node1->data,temp->data)==0) {
							printf("                           %s   \n",node1->data);
						}
						temp=temp->next;
					}
					node1=node1->next;
				}	
				sleep(1);
				fflush(stdout);
				printf("\n\n\nPress any key to continue.\n\n");
				scanf("%c",&garb);
				BuffEmpty;		
			}
			//setting values to NULL
			node1=NULL;
			node2=NULL;
			temp=NULL;	
		}
		else if(choice==4) {
			printf("\nEnter the profile name \n\n");
			//enter the name
			scanf("%[^\n]s",name1);
			scanf("%c",&garb);
			printf("\n");
			// to check if the profile is already present or not
			dummy1=ProfileCheck(head,name1);
			if( dummy1==NULL) {
				printf("Profile notfound.\n\n");
				fflush(stdout);
				sleep(1);
			}
			else {
							//printing the name
				printf("Second connections of %s  :-\n\n",name1);
				//storing friendslist in temp
				temp=dummy1->flist;
				while(temp!=NULL){
					//storing friends of friends
					temp1=temp->profile->flist;
					printf("                               through %s :- \n\n",temp->profile->name);
					while(temp1!=NULL) {
				
						if(STRCMP(dummy1->name,temp1->data)!=0){
							printf("                                                     %s \n",temp1->data);
						}						
						temp1=temp1->next;	
					}
					printf("\n");
					temp=temp->next;
				}
				sleep(1);
				fflush(stdout);
				printf("\n\n\nPress any key to continue.\n\n");
				scanf("%c",&garb);
				BuffEmpty;
			}
			//again setting these values to NULL
			dummy1=NULL;
			temp1=NULL;
			temp=NULL;
		}
		else if(choice==5) {
			printf("\nEnter the interest \n\n");
			//enter the interest
			scanf("%[^\n]s",name1);
			scanf("%c",&garb);
			printf("\n");
			//storing head in dummy
			dummy=head;
			while(dummy!=NULL) {

				//storing the interest list in temp  
				temp=dummy->intlist;
				while(temp!=NULL) {

					// function for string comparision  for both lower case and upper case
					if(STRCMP(name1,temp->data)==0) {	
						fff=1;			
						printf("            %s\n",dummy->name);
					}
				temp=temp->next;
				}
			dummy=dummy->next;
			}
			if(fff==0){
				printf(" Interest not available in any user interest list\n\n");
				fflush(stdout);
				sleep(1);			
			}
			else {

				sleep(1);
				fflush(stdout);
				printf("\n\n\nPress any key to continue.\n\n");
				scanf("%c",&garb);
				BuffEmpty;
			}
			dummy=NULL;
			temp=NULL;
			fff=0;
		}
		else if(choice==6) {
			printf("\nEnter the game \n\n");
			//enter the game
			scanf("%[^\n]s",name1);
			scanf("%c",&garb);
			printf("\n");
			//storing head in dummy
			dummy=head;
			while(dummy!=NULL) {

				//storing gamelist in temp
				temp=dummy->gamlist;
				while(temp!=NULL) {

					// function for string comparision  for both lower case and upper case
					if(STRCMP(name1,temp->data)==0) {	
						fff=1;
						printf("            %s\n",dummy->name);
					}
				temp=temp->next;
				}
			dummy=dummy->next;
			}
			if(fff==0){
				printf(" Game not available in any user game list\n\n");
				fflush(stdout);
				sleep(1);
			}
			else {
		
				sleep(1);
				fflush(stdout);
				printf("\n\n\nPress any key to continue.\n\n");
				scanf("%c",&garb);
				BuffEmpty;
			}
			dummy=NULL;
			temp=NULL;
			fff=0;
		}
		else if(choice==7) {
			printf("\nEnter the movie \n");
			//enter the movie name
			scanf("%[^\n]s",name1);
			scanf("%c",&garb);
			printf("\n");
			//storing head in dummy
			dummy=head;
			while(dummy!=NULL) {

				//storing movielist in temp
				temp=dummy->movlist;
				while(temp!=NULL) {

					// function for string comparision  for both lower case and upper case			
					if(STRCMP(name1,temp->data)==0) {
						fff=1;
						printf("	    %s\n",dummy->name);
					}
				temp=temp->next;
				}
			dummy=dummy->next;
			}
			if(fff==0) {
				printf(" Movie not available in any user movie list\n\n");
				fflush(stdout);
				sleep(1);
			}
			else {
			
				sleep(1);
				fflush(stdout);
				printf("\n\n\nPress any key to continue.\n\n");
				scanf("%c",&garb);
				BuffEmpty;
			}
			dummy=NULL;
			temp=NULL;
			fff=0;
		}
		else {

			printf("\n\nInvalid Entry Detected..!!");
			fflush(stdout);	
			sleep(1);
			printf("\nTry Again...!\n\n");
			fflush(stdout);
			sleep(1);
		}			
	}
	while(flag==1);

	return head;
}

int MainMenu(PROFILE *head) {

	sleep(1);

	char c;
	clear
	bar("\t\t\t\t\t\tWELCOME TO MULTIVERSE - Your Personlised Social Universe");	
	
	printf("\n\n\n\nYou can Choose Any of the various Functionalities provided below to Manipulate the MULTIVERSE: \n\n");

	printf("\nPress 1 to ADD a New User To the MULTIVERSE Network.\nPress 2 to Purge Out an Existing User's Profile Data.\nPress 3 to Search the MULTIVERSE Network.\nPress 4 to Leave the MULTIVERSE.\n\n");	
	scanf("%c",&c);	
	BuffEmpty

	if(c=='1') {
		head=AddNewUser(head);

		return 1;		
	}
	else if(c=='2') {
		head=DeleteInfo(head);

		return 1;	
	}
	else if(c=='3') {
		
		head=SearchInfo(head);
		return 1;
	}
	else if(c=='4'){
	
		printf("\nThank You for using MULTIVERSE..Hope To See You Again...:)\n\n");	
		fflush(stdout);
		sleep(1);
		return -1;
	}
	else {
		
		printf("\n\nInvalid Entry Detected..!!");
		fflush(stdout);	
		sleep(1);
		printf("\nTry Again...!\n\n");
		fflush(stdout);
		sleep(1);	
	}

	return 1;
}

//Uncomment MAIN to test individual Task 4 BUT DON'T FORGET TO COMMENT IT BACK FOR FINAL DEMO.

/*
int main() {

	PROFILE *head=NULL;

//	printf("\n******************TASK 1**********************\n\n");
	head=LoadDatabase(head);
//	PrintDatabase(head);

//	printf("\n******************TASK 2**********************\n\n");
//	head=AddNewUser(head);
//	PrintDatabase(head);

//	printf("\n******************TASK 3**********************\n\n");
//	head=DeleteInfo(head);
//	PrintDatabase(head);

	printf("\n******************TASK 4**********************\n\n");
	head=SearchInfo(head);

//	SaveDataBase(head);	
		
	return 0;
}
*/

