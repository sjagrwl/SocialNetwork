#include"077-assign12.c"

//Printing the entry for a particular user.
void PrintSingleProfile(PROFILE *head) {
	LIST *datahead;

	clear
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
} 

// function to add user information
PROFILE *AddNewUser(PROFILE *head) {
	int flag=1,flagd=1,c;
	char data[50],garb,choice;
	PROFILE *user,*friend;

	clear
	bar("\t\t\t\t\t\tNEW PROFILE ENRTY PAGE");
	printf("\n\nEnter the name of the new user :\n\n");
	while(flagd==1) {
		// taking username as input
		scanf("%[^\n]s",data);
		BuffEmpty;
		if(strlen(data)>=1) {
			flagd=0;
		}
		else {
			// displaying alert message
			printf("\n\nThe Field cannot be left Empty :\n\n");
		}

	}
	//checking for profile 
	user=ProfileCheck(head,data);
	if(user==NULL) {
		// create profile
		head=CreateProfile(head,data);
		user=head;
	}	
	else {
		printf("\nProfile already exists!!\n\n");
	}

	do {

		printf("\n\nPress 1 to add a friend to user's Friend List.\nPress 2 to add an interest to user's Interest List.\nPress 3 to add a movie to user's Movie List.\nPress 4 to add a game to user's Game List.\nPress 0 to finish adding user's INFO.\n\n");		
		scanf("%c",&choice);
		BuffEmpty;
		// to exit loop
		if(choice=='0') {
			flag=0;
		}
		// adding friend
		else if(choice=='1') {
			printf("\n\nEnter the name of the friend you want to be added to the Friend List :\n\n");
			flagd=1;
			while(flagd==1) {
				
				// enter the name
				scanf("%[^\n]s",data);
				scanf("%c",&garb);
				if(strlen(data)>=1) {
					flagd=0;
				}
				else {
					printf("\n\nThe Field cannot be left Empty :\n\n");
				}
			}		
			//checking for profile
			friend=ProfileCheck(head,data);
			if(friend==NULL) {
				// creating profile
				head=CreateProfile(head,data);
				friend=head;	
			}

			if(DataCheck(user->flist,data)==1) {				
				// addition into flist of user
				user->flist=AddInList(user->flist,data,friend);
			}
			else {
				printf("\nThis friend is already present in the Friend List\n\n"); 
			}
			if(DataCheck(friend->flist,user->name)==1) {
				//addition into flist of friend
				friend->flist=AddInList(friend->flist,user->name,user);
			}
		}
		else if(choice=='2') {

			printf("\n\nEnter the Interest you want to be added to the Interest List :\n\n");
			flagd=1;
			while(flagd==1) {
				// enter interest
				scanf("%[^\n]s",data);
				scanf("%c",&garb);
				if(strlen(data)>=1) {
					flagd=0;
				}
				else {
					printf("\n\nThe Field cannot be left Empty :\n\n");
				}
			}
			
			// check for interest in the list
			if(DataCheck(user->intlist,data)==1) {
				//addition into list					
				user->intlist=AddInList(user->intlist,data,NULL);
			}
			else {
				printf("\nThis interest is already present in the Interest List\n\n"); 
			}
		}
		else if(choice=='3') {

			printf("\n\nEnter the Movie you want to be added to the Movie List :\n\n");
			flagd=1;
			while(flagd==1) {
		
				// enter the movie
				scanf("%[^\n]s",data);
				scanf("%c",&garb);
				if(strlen(data)>=1) {
					flagd=0;
				}
				else {
					printf("\n\nThe Field cannot be left Empty :\n\n");
				}
			}
		
			// check for it in the list
			if(DataCheck(user->movlist,data)==1) {
				// addition into the movlist					
				user->movlist=AddInList(user->movlist,data,NULL);
			}
			else {
				printf("\nThis movie is already present in the Movie List\n\n"); 
			}
		}
		else if(choice=='4') {

			printf("\n\nEnter the Game you want to be added to the Games List :\n\n");
			flagd=1;
			while(flagd==1) {
		
				// enter the game
				scanf("%[^\n]s",data);
				scanf("%c",&garb);
				if(strlen(data)>=1) {
					flagd=0;
				}
				else {
					printf("\n\nThe Field cannot be left Empty :\n\n");
				}
			}

			// check for the game in the list
			if(DataCheck(user->gamlist,data)==1) {
				// addition into the game list					
				user->gamlist=AddInList(user->gamlist,data,NULL);
			}
			else {
				printf("\nThis game is already present in the Games List\n\n"); 
			}
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

	printf("\n\nNew User's INFO has been Successfully placed into MULTIVERSE Network.\n\n");
	fflush(stdout);
	sleep(1);
	
	printf("Press 1 to View the Profile that has just been added or any other key to go back to Functionality choices.\n\n");
	scanf("%c",&choice);
	BuffEmpty;

	if(choice=='1') {
		PrintSingleProfile(user);
		printf("\n\n\n\nPress any key to go back to Functionality choices.\n\n");
		scanf("%c",&choice);
		BuffEmpty;
	}

	return head;
}

//Uncomment MAIN to test individual Task 2 BUT DON'T FORGET TO COMMENT IT BACK FOR FINAL DEMO.

/*
int main() {

	PROFILE *head=NULL;

//	printf("\n******************TASK 1**********************\n\n");
	head=LoadDatabase(head);
//	PrintDatabase(head);

	printf("\n******************TASK 2**********************\n\n");
	head=AddNewUser(head);
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

