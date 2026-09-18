#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
    int id;
    char name[50];
    char description[100];
    char location[50];
    char type[10];
    int returned;
};

struct Item items[MAX_ITEMS];
int count = 0;
int nextID = 1;

// Function to clear input buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to report a lost or found item
void reportItem(char type[]) {
    if (count >= MAX_ITEMS) {
        printf("\nItem storage is full!\n");
        return;
    }

    items[count].id = nextID++;

    strcpy(items[count].type, type);

    printf("\nEnter item name: ");
    fgets(items[count].name, 50, stdin);
    items[count].name[strcspn(items[count].name, "\n")] = '\0';

    printf("Enter description: ");
    fgets(items[count].description, 100, stdin);
    items[count].description[strcspn(items[count].description, "\n")] = '\0';

    printf("Enter location: ");
    fgets(items[count].location, 50, stdin);
    items[count].location[strcspn(items[count].location, "\n")] = '\0';

    items[count].returned = 0;
    count++;

    printf("\n%s item reported successfully!\n", type);
    printf("Your Item ID is: %d\n", items[count - 1].id);
}

// Function to view all items
void viewItems() {
    int i;

    if (count == 0) {
        printf("\nNo items have been reported yet.\n");
        return;
    }

    printf("\n========== ALL REPORTED ITEMS ==========\n");

    for (i = 0; i < count; i++) {
        printf("\nItem ID: %d", items[i].id);
        printf("\nType: %s", items[i].type);
        printf("\nName: %s", items[i].name);
        printf("\nDescription: %s", items[i].description);
        printf("\nLocation: %s", items[i].location);

        if (items[i].returned == 1) {
            printf("\nStatus: Returned\n");
        } else {
            printf("\nStatus: Not Returned\n");
        }

        printf("----------------------------------------\n");
    }
}

// Function to search for an item
void searchItem() {
    char searchName[50];
    int i;
    int found = 0;

    printf("\nEnter item name to search: ");
    fgets(searchName, 50, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for (i = 0; i < count; i++) {
        if (strstr(items[i].name, searchName) != NULL) {
            printf("\nItem ID: %d", items[i].id);
            printf("\nType: %s", items[i].type);
            printf("\nName: %s", items[i].name);
            printf("\nDescription: %s", items[i].description);
            printf("\nLocation: %s", items[i].location);

            if (items[i].returned == 1) {
                printf("\nStatus: Returned\n");
            } else {
                printf("\nStatus: Not Returned\n");
            }

            printf("----------------------------------------\n");
            found = 1;
        }
    }

    if (found == 0) {
        printf("\nNo matching item found.\n");
    }
}

// Function to mark an item as returned
void markReturned() {
    int id;
    int i;

    printf("\nEnter Item ID to mark as returned: ");
    scanf("%d", &id);
    clearBuffer();

    for (i = 0; i < count; i++) {
        if (items[i].id == id) {
            items[i].returned = 1;
            printf("\nItem marked as returned successfully!\n");
            return;
        }
    }

    printf("\nItem ID not found.\n");
}

// Main function
int main() {
    int choice;

    do {
        printf("\n\n========================================\n");
        printf("       CAMPUS LOST & FOUND SYSTEM\n");
        printf("========================================\n");
        printf("1. Report Lost Item\n");
        printf("2. Report Found Item\n");
        printf("3. Search Item\n");
        printf("4. View All Items\n");
        printf("5. Mark Item as Returned\n");
        printf("6. Exit\n");
        printf("========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                reportItem("Lost");
                break;

            case 2:
                reportItem("Found");
                break;

            case 3:
                searchItem();
                break;

            case 4:
                viewItems();
                break;

            case 5:
                markReturned();
                break;

            case 6:
                printf("\nThank you for using Campus Lost & Found!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
