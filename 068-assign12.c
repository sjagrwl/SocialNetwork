#include"142-assign12.c"

//function to delete node from the list
LIST *DeleteEntry(LIST *head,char data[]) {
	LIST *delnode;
	LIST *main=head;
	//If the input matches with data in head it returns the address of next node so that this node gets deleted
	if(STRCMP(head->data,data)==0) {
		return head->next;
	}
	else {
		while(head!=NULL) {

			if(STRCMP(head->next->data,data)==0) {
				delnode=head->next;				
				head->next=head->next->next;
				free(delnode);
				return main;
			}

			head=head->next;
		}
	}
}
//function to delete desired info from user's info
PROFILE *DeleteInfo(PROFILE *head) {

	int flag=1,flagd=1,count=0;
	char data[50],garb,choice;
	PROFILE *user=NULL,*friend;
	LIST *datahead=NULL;

	clear
	bar("\t\t\t\t\t\tPROFILE DETAILS DELETION PAGE");
	printf("\n\nEnter the name of the profile whose INFO you want to delete:\n\n");
	while(user==NULL) {

		flagd=1;
		while(flagd==1) {
			//enter the profile name
			scanf("%[^\n]s",data);
			BuffEmpty;
			if(strlen(data)>=1) {
				flagd=0;
			}
			else {	
				printf("\n\nThe Field cannot be left Empty :\n\n");
			}
	
		}
		//checks for profile
		user=ProfileCheck(head,data);
		if(user==NULL) {
			printf("\n\nThe profile does not exist. Please enter an existing profile name :\n\n");
		}	
	}

	do {
		if(count>0) {

			clear
			bar("\t\t\t\t\t\tPROFILE DETAILS DELETION PAGE");
		} 
		printf("\n\nPress 1 to delete a friend from user's Friend List.\nPress 2 to delete an interest from user's Interest List.\nPress 3 to delete a movie from user's Movie List.\nPress 4 to delete a game from user's Game List.\nPress 0 to finish editing user's INFO.\n\n");
		scanf("%c",&choice);
		BuffEmpty;

		if(choice=='0') {  //to exit loop
			flag=0;
		}
		else if(choice=='1') {
			
			printf("\n\nThe FriendList for this particular user:\n\n");
			datahead=user->flist;
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
			sleep(1);
			fflush(stdout);
			printf("\n\nEnter the name of the friend you want to be deleted from the Friend List :\n\n");
			flagd=1;
			while(flagd==1) {
		
				scanf("%[^\n]s",data);
				scanf("%c",&garb);
				if(strlen(data)>=1) {
					flagd=0;
				}
				else {
					printf("\n\nThe Field cannot be left Empty :\n\n");
				}
			}

			friend=ProfileCheck(head,data);//checks for profile
			if(DataCheck(user->flist,data)==1) {//checks for friend in friendlist
				printf("\nThis friend is not present in the user's Friend List\n\n");
			}
			else {
				user->flist=DeleteEntry(user->flist,data); //deleting from user list
				friend->flist=DeleteEntry(friend->flist,user->name);//deleting from friend list
				printf("\n\nThe User's Friend has been Successfully deleted from User's MULTIVERSE Network.\n\n");
				fflush(stdout);	
			}
			sleep(1);
		}
		else if(choice=='2') {

			printf("\n\nThe InterestList for this particular user:\n\n");
			datahead=user->intlist;
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
			sleep(1);
			fflush(stdout);
			printf("\n\nEnter the Interest you want to be deleted from the Interest List :\n\n");
			flagd=1;
			while(flagd==1) {
		
				scanf("%[^\n]s",data);
				scanf("%c",&garb);
				if(strlen(data)>=1) {
					flagd=0;
				}
				else {
					printf("\n\nThe Field cannot be left Empty :\n\n");
				}
			}
			//check for interest in the list
			if(DataCheck(user->intlist,data)==1) {
				printf("\nThis Interest is not present in the user's Interest List\n\n");					
			}
			else {
				//desired interest is deleted and updated in user intlist
				user->intlist=DeleteEntry(user->intlist,data); 
				printf("\n\nThe User's Friend has been Successfully deleted from User's MULTIVERSE Network.\n\n");
				fflush(stdout);
			}
			sleep(1);
		}
		else if(choice=='3') {

			printf("\n\nThe MovieList for this particular user:\n\n");
			datahead=user->movlist;
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
			sleep(1);
			fflush(stdout);
			printf("\n\nEnter the Movie you want to be deleted from the Movie List :\n\n");
			flagd=1;
			while(flagd==1) {
		
				scanf("%[^\n]s",data);
				scanf("%c",&garb);
				if(strlen(data)>=1) {
					flagd=0;
				}
				else {
					printf("\n\nThe Field cannot be left Empty :\n\n");
				}
			}
			//check for movie in the list
			if(DataCheck(user->movlist,data)==1) {				
				printf("\nThis Movie is not present in the user's Movie List\n\n");
			}
			else {
				//desired movie is deleted and updated in user movlist
				user->movlist=DeleteEntry(user->movlist,data); 
				printf("\n\nThe User's Movie has been Successfully deleted from User's MULTIVERSE Network.\n\n");
				fflush(stdout);
			}
			sleep(1);
		}
		else if(choice=='4') {

			printf("\n\nThe GameList for this particular user:\n\n");
			datahead=user->gamlist;
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
			sleep(1);
			fflush(stdout);
			printf("\n\nEnter the Game you want to be deleted from the Games List :\n\n");
			flagd=1;
			while(flagd==1) {
		
				scanf("%[^\n]s",data);
				scanf("%c",&garb);
				if(strlen(data)>=1) {
					flagd=0;
				}
				else {
					printf("\n\nThe Field cannot be left Empty :\n\n");
				}
			}
			//check for game in the list
			if(DataCheck(user->gamlist,data)==1) {				
				printf("\nThis Game is not present in the user's Games List\n\n");
			}
			else {
				//desired game is deleted and updated in user gamelist
				user->gamlist=DeleteEntry(user->gamlist,data); 
				printf("\n\nThe User's Game has been Successfully deleted from User's MULTIVERSE Network.\n\n");
				fflush(stdout);
			}
			sleep(1);
		}
		else {

			printf("\n\nInvalid Entry Detected..!!");
			fflush(stdout);	
			sleep(1);
			printf("\nTry Again...!\n\n");
			fflush(stdout);
			sleep(1);
		}	
		count++;
	}
	while(flag==1);

	printf("\n\nThe User's INFO has been Successfully deleted from the MULTIVERSE Network.\n\n");
	fflush(stdout);
	sleep(1);
	
	printf("Press 1 to View the modified Profile entry or any other key to go back to Functionality choices.\n\n");
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

//Uncomment MAIN to test individual Task 3 BUT DON'T FORGET TO COMMENT IT BACK FOR FINAL DEMO.

/*
int main() {

	PROFILE *head=NULL;

//	printf("\n******************TASK 1**********************\n\n");
	head=LoadDatabase(head);
//	PrintDatabase(head);

	printf("\n******************TASK 2**********************\n\n");
//	head=AddNewUser(head);
//	PrintDatabase(head);

	printf("\n******************TASK 3**********************\n\n");
	head=DeleteInfo(head);
//	PrintDatabase(head);

	printf("\n******************TASK 4**********************\n\n");
//	head=SearchInfo(head);

//	SaveDataBase(head);	
		
	return 0;
}
*/

