#include <stdio.h>
#include <windows.h>
#include <MMsystem.h>

void playier();

int main()
{
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
			case 1:
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


