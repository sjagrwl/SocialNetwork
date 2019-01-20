TASK 1 - SAHAJ AGARWAL                        ROLL NO : 201601077	email-id: sahaj.a16@iiits.in
TASK 2 - NALLURI VENKTA VAISHNAVI             ROLL NO : 201611142	email-id: venkatavaishnavi.n16@iiits.in
TASK 3 - SAI MADHU CHANDHANA PYAPALI          ROLL NO : 201601068	email-id: madhuchandhana.p16@iiits.in
TASK 4 - SALLA DASHARATHA SAI VAMSHI          ROLL NO : 201601080	email-id: saivamshi.s16@iiits.in



STRUCTURES USED:
	1) PROFILE structure: 
				consists of 6 fields.
				->a charcter array for user name
				-> four LIST pointers :- *flist, *intlist, *movlist, *gamlist
				-> a PROFILE pointer *next
	2) LIST structure :
				consist 3 fields
				-> a character array to store data ( like friend name, movie ,game ,interest)
				-> a PROFILE pointer *profile (for easy approach to self profile instead of traversal)
				-> a LIST pointer *next

USE OF LINKED : As seen and understood from the project pdf, a lot of traversal ,addition and deletion aspects and searching aspects are present .
		So to maintain a network ,we have chosen to use linkedlist of linkedlist . All additions to the list are done using front end addition 
		inorder to reduce time complexity.

FILE FORMAT  :
	The database  file format has to be maintained with some flexibility for the program to function properly.
	
	Example Entry:

USERNAME: HARSHITA KARUTURI
FRIENDLIST: MAHESHWARI KOTTA,PRAGNA VENNAKOTI,MOUNIKA CHADALAVADA,SAHAJ AGARWAL,ANJALI POORNIMA,PARKHI MOHAN.
INTERESTS: SPORTS,CHEMISTRY,BIOLOGY,MATHS.
MOVIES: ROMANCE,THRILLER,HORROR.
GAMES: THROWBALL,ATHELETICS,VOLLEYBALL.


TASK 1 

Function prototype  :     PROFILE *LoadDatabase(PROFILE *head);


INPUT : No input is given to this function .
	This is the main function where entire database is stored into a hashtable(linkedlist of linkedlist)
	This data structure is used so that the network traversal is convinient and understandable to any outsider reading the code.
	
	The main process goes like this:

-> database file is opened in read mode
-> as long as the database file pointer doesn't reaches the end of the file,file is read line by line and stored in a character array.
-> if the first letter of the array is 'U' ,then the name of the user is coppied to 'name' field of the new profile is created by CreateProfile function. New profile is creaed for a user only if a profile doen't exist for him.
    This is verified by ProfileCheck function.	 
-> if the first letter of the array is 'F', then a traversal is done through the friends list and all names of the friends are added to the '*flist' pointer field  using ' AddInList ' function. Also a profile gets created to the friend iff it does not exist in the above explained way.
    Addition of friends in the list ensures that the 'flist' of the friend also is updated with the username ensuring mutual friend list.
-> if the first letter of the array is 'I', then a traversal is made through the intrests in th file and are added to the 'intlist' field of the Profile of the user using ' AddInList ' function.
-> if the first letter of the array is 'M', then a traversal is made through the list of movies in th file and are added to the 'movlist' field of the Profile of the user  using ' AddInList ' function.
-> if the first letter of the array is 'G', then a traversal is made through the games list in th file and are added to the 'gamlist' field of the Profile of the user  using ' AddInList ' function.
-> all these list get their upgradation only if the interest / movie / game / friend is not previously present in the list which is checked using 'DataCheck' finction.
-> in this way the entire prifile of a person gets loaded into the userprofile.
-> this process is done for all profiles. The linking of the profiles is taken care by CreateProfile.
-> the entire database is loaded into linkedlist of linkedlist (hashtable)

OUTPUT : The stored database is printed .
	 The PrintDatabase function is used for printing.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
TASK 2

Function prototype  : PROFILE *AddNewUser(PROFILE *head);

INPUT  :  This function takes a username as the input whoes friendlist , intrest list ,movie list and games list have to updated.
		A list of options are displayed as to what all opperations can be performed in this function (these are the subtasks)
	
	1) if choice == 1 : (add friend name)
			INPUT :  friend name to be added is taken as input
				-> a traversal is made in the given users "flist" and given friend name is added only if he is not present by the 'AddInList ' function and if he is already in the user's friend list a message is displayed.
				   the checking part is done using 'DataCheck' .The traversal is done in the 'DataCheck' function. At the time of addition a new profile is created if his profile doesn't exist with the username added to his friend list.
				   if the friend already has a profile , the given user name is added into his friend list in the same way.
				   'ProfileCheck' funtion is used for profile verification.
 				
			OUTPUT : the entire linkedlist of linkedlist(hashtable) is printed again with the added information.
				 the list of options are displayed again for further additions.

	2) if choice == 2 :(add an interest )
			INPUT : interest to be added is taken as the input
			       -> 'DataCheck ' function is called to check if the interest is already present in the 'intlist' of the user PROFILE.
				   if it is not found, it is added into the 'intlist' using 'AddInList'.
				   if present an alert message is displayed. 
			OUTPUT : the entire linkedlist of linkedlist(hashtable) is printed again with the added information.
				 the list of options are displayed again for further additions.

	3) if choice == 3 :(add an movie )
			INPUT : movie name to be added is taken as the input
			       -> 'DataCheck ' function is called to check if the movie is already present in the 'movlist' of the user PROFILE.
				   if it is not found, it is added into the 'movlist' using 'AddInList'.
				   if present an alert message is displayed. 
			OUTPUT : the entire linkedlist of linkedlist(hashtable) is printed again with the added information.
				 the list of options are displayed again for further additions.
	4) if choice == 4 :(add an game )
			INPUT : game to be added is taken as the input
			       -> 'DataCheck ' function is called to check if the game is already present in the 'gamlist' of the user PROFILE.
				   if it is not found, it is added into the 'gamlist' using 'AddInList'.
				   if present an alert message is displayed. 

			OUTPUT : the entire linkedlist of linkedlist(hashtable) is printed again with the added information.
				 the list of options are displayed again for further additions.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
TASK 3:		DELETION OF USER'S INFO:


Function Prototype:	PROFILE *DeleteInfo(PROFILE *head)

Functions Used:		1)LIST *DeleteEntry(LIST *head,char data[])
			
				- function to delete node from the list			
			
			2)PROFILE * ProfileCheck(PROFILE *head,char name[])

				- function to check if the profile is already present or not

			3)int DataCheck(LIST *head,char data[])

				- fucntion to check if the data is already there in the list
========================================================================================================================================================================================================
			


	->In this task "do while" loop is used.
	->This function takes the input of the profile name whose info you want to delete.
 	->If choice == 1:  ( Delete friend from friend list )
		
		->INPUT:Name of the friend you want to delete.
			->First it checks if profile exists or not and then if he is a friend in the input's friend list.
			  If exists,the friendship is deleted in both the friends.
		->OUTPUT:updated friendlist in both user and friend.
	->If choice == 2:  ( Delete interest from user's interest list )

		->INPUT:Interest you want to delete.
			->Checks for interest in the intlist of user using "DataCheck" function.If exixts it deletes using "DeleteEntry" function.
		->OUTPUT:updated interest list of the user.
	->If choice == 3:  ( Delete movie from user's movie list )

		->INPUT:Movie you want to delete.
			->Checks for movie in the movlist of user using "DataCheck" function.If exists it deletes using "DeleteEntry" function.
		->OUTPUT:updated movie list of the user.
	->If choice == 4:  ( Delete game from user's game list )
		
		->INPUT:Game you want to delete.
			->Checks for game in the gamelist of user using "DataCheck" function.If exists it deletes using "DeleteEntry" function.
		->OUTPUT:updated game list of the user.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

TASK 4:		SEARCHING USER'S INFO:

Function prototype:	PROFILE *SearchInfo(PROFILE *head)

Functions used-		1)void PrintSingleProfile(PROFILE *head)
				
				- function for printing details of of the user

			2)int STRCMP(char A[], char B[])

				- function for sting comparision  for both lower case and upper case

			3)PROFILE * ProfileCheck(PROFILE *head,char name[])

				- function to check if the profile is already present or not

	In this task I am using "do while" loop.

	->Initially flag=1,when choice is '0',flag becomes 0.
	->The do loop is executed if flag==1.

	In do loop:
		If choice==1:
			
			We have to enter the profile name which we to search.
			->INPUT:Profile name.
			->PROCEDURE:head pointer should not be lost so assign it to another dummy pointer named "dummy".Initially an integer is initialised to zero.
				  Comparing the input with dummy->name,if it matches the integer is incremented by 1 and the pointer is stored in another dummy pointer named "dummy1".
				  In this way we traverse through entire linked list.Finally,if integer value>0 we will print the profile details of the given input using the function 
				  "PrintSingleProfile(dummy1)".Else profile not found is printed.
			->OUTPUT:Details of the profile name entered.

		If choice==2:

			We have to search for common friends.
			->INPUT:2 profile names to find the common friends between them.
			->PROCEDURE:head pointer should not be lost so assign it to another dummy pointer named "dummy".Compare the 1st profile name with all the names in the linked
				    list,if it matches,place the flist of the particular person in "node1".Do same process for another person and store his flist in "node2".
				    If any one of node1 and node2 is "NULL",print improper choices.Else,run 2 while loops and compare each name in flist of node1 with all names in
				    flist of node2.If any name matches,print it.		
			OUTPUT:Traverses through the linked list named "flist" and finds out the common friends using strcmp function and prints the matched ones.

		If choice==3:

			We have to search for common interests of 2 persons.
			->INPUT:2 profile names to find common interests between them.
			->PROCEDURE:head pointer should not be lost so assign it to another dummy pointer named "dummy".Compare the 1st profile name with all the names in the linked
			      	    list,if it matches,place the intlist of the particular person in "node1".Do same process for another person and store his intlist in "node2".
				    If any one of node1 and node2 is "NULL",print improper choices.Else,run 2 while loops and compare each interest in intlist of node1 with all interests in
				    intlist of node2.If any interest matches,print it.		
			->OUTPUT:Traverses through the linked list named "intlist" and finds out the common interests using strcmp function and prints the matched ones.

		If choice==4:

			We have to display all the second connections of the person.
			->INPUT:Name of the person whose second connections are to be displayed.
			->PROCEDURE:First of all we have to check if the profile exists or not.So,"ProfileCheck(head,input)" function is used.This function returns the head pointer if name matches.
				    Else,returns NULL.So,this returned value is stored in a pointer "dummy1".If dummy1==NULL,Profile not found is printed.Else,a traversal is done in user's friendlist
				    and for every friend in this list another traversal is done in his or her friend list and all the friends are displayed.This displays user's friends of friends 
				    that is second connections.  
			->OUTPUT:Displaying the friends of friends of the profile name entered.

		If choice==5:

			We have to search persons with common interests.
			->INPUT:Interest is given as input.
			->PROCEDURE:head pointer should not be lost so assign it to another dummy pointer named "dummy".dummy->intlist is stored in temp and now this temp->data is compared with input.
				  If they match the profile name that is dummy->name is printed.
			->OUTPUT:Persons with this interest in their "intlist" will be displayed.

		If choice==6:

			We have to search persons who play common game.
			->INPUT:Game name is given as input.
			->PROCEDURE:head pointer should not be lost so assign it to another dummy pointer named 'dummy'.dummy->gamlist is stored in temp and now this temp->data is compared with input.
				  If they match the profile name that is dummy->name is printed.
			->OUTPUT:Persons with this game in their "gamlist" will be displayed.

		If choice==7:

			We have to search persons who watch common movie.
			->INPUT:Movie type is given as input.
			->PROCEDURE:head pointer should not be lost so assign it to another dummy pointer named 'dummy'.dummy-movlist is stored in temp and now this temp->data is compared with input.
				  If they match the profile name that is dummy->name is printed.
			->OUTPUT:Persons with this movie type in their "movlist" will be displayed.

		If choice==0:

			To finish Searching user's Info.
			->Flag becomes 0. 

------------------------------------------------------------------------------------------------------------------------------------------------------------------
ADDITION TO THE PROJECT 

	An extra function is added by the team to the project
	This function is used to update each an every change that is made in the linkedlist of linkedlist (hashtable) into the database file so that a track of all 
	the changes done is maintained .
	As the project is a mini social network, any upgradations are to be maintained to know the status of any user.
	
	
