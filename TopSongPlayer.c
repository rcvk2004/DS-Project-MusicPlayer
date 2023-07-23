#include <stdio.h>
#include <windows.h>
#include <MMsystem.h>
#include <stdlib.h>
#include<string.h>

struct node {
	char songName[30];
	char songPath[40];
	struct node *next;
}*head = NULL;
int nos=0;		// variable to count no of songs
void search();
void playSongs();	// Function to play songs in a queue
void insert();		// Function to insert songs in a queue
void display();         // Function to display the songs present in the list
void shuffle();          //Function to shuffle the songs
void delete();           //Function to delete the song 
int main() {
	int choice;
	printf("\3\3\3 Welcome to top music player \3\3\3\n");
	printf("   ===========            =========\n");
	printf("  |           |          |         |\n");
	printf("   ====|  |===           |         |\n");
	printf("       |  |      ======  |=========\n");
	printf("       |  |     |      | |\n");
	printf("       |  |     |      | |\n");
	printf("        ==       ======  |\n");
	printf("\nVersion: 1.0\n");
	printf("Copyright 2023 Top | All Rights reserved\n");
	PlaySound(TEXT(".\\Songs\\welcome-note.WAV"),NULL,SND_SYNC);
	printf("\nOperations that this music player can perform\n");
	printf("  1. Play Songs\n  2. Select from which song to play\n  3. Insert new song in playlist\n  4. Shuffle playlist\n  5. Delete a song from playlist\n");
	printf("  6. Display playlist\n  7. Exit\n");
	PlaySound(TEXT(".\\Songs\\Info.WAV"),NULL,SND_SYNC);
	
	while (1) {
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch (choice){
			case 1: playSongs();
				break;
			case 2:
				break;
			case 3: insert();
				break;
			case 4:shuffle();
				break;
			case 5: delete();
				break;
			case 6: display();
				break;
			case 7: exit(0);
			default: printf("     Enter a valid choice !\n\n");
		}
	}
	
	return 0;
}

void playSongs() {
	if (head==NULL) {
		printf("Playlist is empty!\n\n");
		return;
	}
	struct node *ptr = head;
	while (ptr!=NULL) {
		printf("Playing song: %s\n",ptr->songName);
		PlaySound(TEXT(ptr->songPath),NULL,SND_SYNC);
		ptr = ptr->next;
	}
	
	printf("Reached end of playlist\n");
}

void insert(){
	struct node *newnode;
    	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->next=NULL;
	printf("Enter the name of the song you want to insert: ");
	scanf("%s",newnode->songName);
	printf("Enter the path of the song: ");
	scanf("%s",newnode->songPath);
    	if(head==NULL){
		head=newnode;
	}
    	else {
        	struct node *ptr=head;
        	while(ptr->next!=NULL){
            		ptr=ptr->next;
	    	}
            	ptr->next=newnode;
	}
	nos++;
}

void display() {
	struct node *ptr=head;
        int i=1;
	printf("Here is your playlist: \n");
        while(ptr!=NULL){
                 printf("  %d. ",i);
                 i=i+1;
                 printf("%s\n",ptr->songName);
	         ptr=ptr->next;
	}
	printf("\n");
}
void search()
{
        int position=0,status=0;
        printf("Enter song name to be searched:\n");
	char song[40];
        scanf("%s",song);
        struct node*pointer=head;
        while(pointer!=NULL)
        {
                 if(strcmp(pointer->songName,song)==0)
                 {	  
                    status=1;
                    break;
		 }
                 pointer=pointer->next;
                 position++;
	}
        if(status==1)
       {	printf("The song is at position %d in the queue\nPlaying %s song...\n",position,song);
                PlaySound(TEXT((pointer->songpath),NULL,SND_SYNC)
			}
	else
		printf("OOPS!Song not found in our playlist.Try a different one... :)\n")

}
void shuffle()
{ 
  struct node *first=head;
  struct node *second=head->next;
  struct node *firsteven=head->next;
   if(head==NULL)
    {
       printf("Playlist is empty");
       return;
    }
  while(1)
   {
        if(second==NULL || second->next==NULL)
          {
              first->next=firsteven;
	      return;
          }
          first->next=second->next;
          first=second->next;
          second->next=first->next;
          second=first->next;
   }
}
  void delete()
{
    char songDelete[40];
    printf("Enter the name of the song to delete:");
    scanf("%s",songDelete);
    struct node*ptr=head;
    struct node*ptr1=NULL;
    int found=0,position=0;
    
    for(ptr=head;ptr!=NULL;ptr=ptr->next)
    {
        if(strcmp(ptr->songName,songDelete)==0)
	{
            found=1;
            break;
        }
        ptr1=ptr;
        position++;
    }
    if(found==1)
    {
        if(ptr1==NULL)
	{
            head=ptr->next;
        }
        else
	{
            ptr1->next=ptr->next;
        }
        free(ptr);
        printf("YAY..! %s song is successfully deleted from your playlist.\n",songDelete);
        nos--;
    }
    else
    {
        printf("SORRY..we couldn't find the song %s in your playlist .\n",songDelete);
    }
    
}
     

	  
