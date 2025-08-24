// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[20];
    int ID;
    int status;
} Seat;

#define SEATS 5

Seat seats[SEATS]; // You want to global define your seats array
int count; //You want a global count to check the number of seats occupied at any moment. Plus its more simple and easier to read than using seatEmpty seatFull


void initialise() { // you want to initialise each seat in the array first and call this function in name first.
    for (int i = 0; i < SEATS; i++) {
        seats[i].ID = i + 1;
        seats[i].status = 0; // 0 for EMPTY, 1 for TAKEN
        strcpy(seats[i].name, "");
    }
}

void listTakenSeat();
void assignSeat();
void removeSeat();


int main(){
    initialise();
    printf("NTU AIRLINES SEATING RESERVATION PROGRAM:\n 1: listTakenSeat()\n 2: assignSeat()\n 3: removeSeat()\n 4: quit\n");
    int choice = 0;
    while (choice != 4){ //You want to use while loop instead of do while so that you can check if the choice is to exit. If it is you can just simply exit the loop and the program will end.
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            listTakenSeat();
            break;
        case 2:
            assignSeat();
            break;
        case 3:
            removeSeat();
            break;
        case 4:
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
        }
        // return 0; You do not want to return if not its not gonna loop
    }
}


void listTakenSeat(){
    printf("listTakenSeat():\n");

    //Check if your count is 0 which means no seat assigned yet and always check for it first.
    if (count == 0) {
        printf("The seat assignment list is empty\n");
    }

    for (int i=0; i<SEATS; i++) { //i should always start at 0
            if(seats[i].status==1){
                printf("Customer name: %s\n", seats[i].name); //printing according to requirements
                printf("Seat number (ID): %d\n", seats[i].ID);
           }
    }
}

void assignSeat(){
    char name[20]; //define how long a char is going to be
    int ID;
    //char *p; idk how to use this to take in string sorry :(

    //Check if the flight is full. Just take note to check if all base cases are fulfilled first.
    if (count >= SEATS){
                    printf("The plane is full\n"); return; }

    printf("assignSeat():\n");
    printf("Enter the seat number: \n");
    scanf("%d", &ID);
    /*
    You can do this but this is going to get an error because firstly you are using dowhile loop. When you use do while loop it will start the loop before checking for the condition so you want to use a while loop
    while ((ID>=1 && ID<=5)&& (seat[ID-1].status == 1)){
        if (ID>=1 && ID<=5){
        printf("Enter a seat number between 1 and 5:\n");
          if (seat[ID-1].status == 1)
        printf("�Occupied! Please choose another seat\n");
         printf("Enter a  seat  between 1 and 5:\n");
        scanf("%d", &ID);
        }
    }
    do{
    if (seatOccupied== 1) {
         printf("The plane is full\n");
        return;
    }
    seat[ID].status=1;
    printf("Enter customer name:\n");
    while (getchar()!='\n'){
        continue;

    }
    fgets(seat[ID-1].name,20,stdin);
    if (p=strchr(seat[ID-1].name,'\n')) {
                    *p = '\0';
     printf("The seat has been assigned successfully\n");}
    else if (*p!='\0'){
        printf("the seat is taken");
    }

   }while((ID>=1 && ID<=5)&& (seat[ID-1].status == 1) );
    */


    while (1){
        if (ID < 1 || ID > 5) // Check for valid seat number
        {
            printf("Please enter a seat number between 1 and 5\n");
            scanf("%d", &ID);
            continue; // What im doing here is that if the seatNum is invalid I tell them its invalid and immediately take in another seat position and after they input a valid number, it will go through the while loop to check for discrepencies.
        }

        if (seats[ID - 1].status == 1) // Check if seat is already taken
        {
            printf("Occupied! Please choose another seat\n");
            scanf("%d", &ID);
            continue;
        }
        else
        {
            printf("Enter customer name: \n");
            getchar(); // Clear input buffer
            fgets(name, sizeof(name), stdin); // Read input with spaces
            name[strcspn(name, "\n")] = '\0'; // Remove trailing newline
            strcpy(seats[ID - 1].name, name);
            seats[ID - 1].status = 1; // Set seat status to taken
            printf("The seat has been assigned successfully\n");
            count++; //Add count so that we can track number of seats
            break; //Added so we are done.
        }
    }

}

void removeSeat(){
    //char arr[] = {}; unnecessary.
    int ID;
    printf("removeSeat():\n");
    if (count <= 0){ printf("All the seats are vacant\n"); return; } //You want to check if the flight is empty first. Always check base cases first

    /*
    You want to ask them for an input first then check whether the input is valid.
    while (seat[ID-1].status != 1){
        if (seat[ID-1].status == 0) {
            printf("Empty! Enter another seat number for removal\n");
            scanf("%d", &ID);
        }
        else {
            if ((ID>=1 && ID<=5)){
           seat[ID-1].status = 0;
                strcpy(seat[ID-1].name, arr);
                printf("Removal is successful\n");
                return;
            }
            else {
                printf("Please enter a seat number between 1 and 5\n");
                scanf("%d", &ID);
            }
        }


    }
    */
    printf("Enter the seat number: \n");
    scanf("%d", &ID);

    while(1){
        if (ID < 1 || ID > 5) {
            printf("Please enter a seat number between 1 and 5\n");
            scanf("%d", &ID);
            continue;
        }
        if (seats[ID-1].status == 0) {
            printf("Empty! Enter another seat number for removal\n");
            scanf("%d", &ID);
            continue;
        }
        seats[ID-1].status = 0;
        strcpy(seats[ID-1].name, "");
        printf("Removal is successful\n");
        count--; //Minus the count since we removed a seat successfully.
        break;
    }
}




