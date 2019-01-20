#include"080-assign12.c"

int main() {

	PROFILE *head=NULL;
	int c,flag=1,key;

	while(flag>0) {
		
		clear	
		bar("\t\t\t\t\t\tWELCOME TO MULTIVERSE - Your Personlised Social Universe");	
		
		if(flag==1) {
			printf("Please Wait while the Database gets Fetched and Feeded to the Network.\n\n");

	    		progress("Loading In Progress ",4,"\n\nDataBase Successfully Loaded.......!!\n\n");
			head=LoadDatabase(head);
		}

		printf("\n\n\n\n\n\nPress 1 to view the entire database\nPress 2 to continue to Network Functionalities\n\n");
		scanf("%d",&c);
		BuffEmpty
	
		if(c==1) {	
			PrintDatabase(head);	
			sleep(1);
			fflush(stdout);
			printf("\n\n\n\n\n\nPress any key to go back to the Selection Menu.\n\n");
			scanf("%d",&c);
			BuffEmpty;
		}
		else if(c==2) {	
			while (MainMenu(head)!=-1);
			flag=-1;
		}
		else {
		
			printf("\n\nInvalid Entry Detected..!!");
			fflush(stdout);	
			sleep(1);
			printf("\nTry Again...!\n\n");
			fflush(stdout);
			sleep(1);
		}
		flag++;	
	}

	SaveDataBase(head);

	return 0;
}
