#include <stdio.h>
#include <windows.h>
#include <MMsystem.h>

struct node {
	char songName[30];
	char songPath[40];
	struct node *next;
}*head = NULL;
int nos=0;//no of songs

void playSongs();
void insert();
void display();

int main() {
	int choice;
	printf("Welcome to top music player\n");
	printf("  =============           =========\n");
	printf("  |           |          |         |\n");
	printf("  =====|  |====          |         |\n");
	printf("       |  |      ======  |=========\n");
	printf("       |  |     |      | |\n");
	printf("       |  |     |      | |\n");
	printf("        ==       ======  |\n");
	printf("\nVersion: 1.0\n");
	printf("Copyright 2023 Top | All Rights reserved\n");
	PlaySound(TEXT(".\\welcome-note.WAV"),NULL,SND_SYNC);
	printf("\nOperations that this music player can perform\n");
	printf("  1. Play Songs\n  2. Select from which song to play\n  3. Insert new song in playlist\n  4. Shuffle playlist\n  5. Delete a song from playlist\n");
	printf("  6. Display playlist\n  7. Exit\n");
	PlaySound(TEXT(".\\Info.WAV"),NULL,SND_SYNC);
	
	while (1) {
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch (choice){
			case 1: playSongs();
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				exit(0);
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
	printf("Enter the name of the song you want to insert:");
        scanf("%[^\n]",newnode->songName);
	printf("Enter the path of the song:");
        scanf("%s",newnode->songPath);  
        if(head==NULL){
		head=newnode;
	}
        else{
              struct node *ptr=head;
              while(ptr->next!=NULL){
                     ptr=ptr->next;
	      }
              ptr->next=newnode;
	}
	nos++;
}
void display(){
	struct node *ptr=head;
        int i=1;
        while(ptr!=NULL){
                 printf("%d.",i);
                 i=i+1;
                 printf("%s\n",ptr->songName);
                 printf(" %s",ptr->songPath):
	         ptr=ptr->next;
	}
}
          

