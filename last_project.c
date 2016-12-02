/*Header Comment
    Zachary Bledsoe
    COP3223C - 0003
    Project 8, charityrun.c
    12/02/2016

    This program will log the number of teams and individual who are signed up for the different
    races, process the racing events to see who has the fastest times, and track the
    total amount of money raised by teams and individuals for charity.
 */

 //included libraries
 #include <stdio.h>
#include <string.h>

//Constants
#define TEAMS 200
#define RUNNERS 10000
#define LENGTH 20
#define TEAMSIZE 50
#define MEMORY 1000

//structures
struct person {
    char name[LENGTH];
    int number;
    float age;
    float even;
    float money;
    float time;
};

struct team {
    char name[LENGTH];
    int nummembers;
    float money;
    struct person members[TEAMSIZE];
};

//Function prototypes
/*
void teamRegister();
void runEvents();
void totalCalc();
*/

//main function
int main() {
    FILE * ifp;
    int i, j;
    char fileName[MEMORY];
    float earlyCost, regCost, teamCost;

    int indivRegisterAmount;
    int normRegister;

    char type[MEMORY];

    struct person indivRoster[MEMORY];

    //prompts user for file name
    printf("Please enter the input file name.\n");
    //scans file name in to fileName variable
    scanf("%s", fileName);
    //reads through user submitted file
    ifp = fopen(fileName, "r");

    //if file name invalid print error message
    if (fileName == NULL)
    {
        printf("\nError, Unable to open the file for reading\n");
        return 1;
    }

    //scans in data for ticket costs from file
    fscanf(ifp, "%f%f%f", &earlyCost, &regCost, &teamCost);
    //printf("%.2f\n%.2f\n%.2f", earlyCost, regCost, teamCost);

    fscanf(ifp, "%d", &indivRegisterAmount);
    //printf("%d", indivRegisterAmount);


    struct person roster[RUNNERS];
    struct team teamRoster[TEAMSIZE];


    for (i=0; i<indivRegisterAmount; i++) {
        fscanf(ifp, "%s", type);
        printf("%s \n", type);

        if(strcmp(type, "INDV") == 0){
            fscanf(ifp, "%s", roster[i].name);
            fscanf(ifp, "%d", &roster[i].number);
            fscanf(ifp, "%f", &roster[i].age);
            fscanf(ifp, "%f", &roster[i].even);
            roster[i].money = earlyCost;
            printf("%s \n %d \n %f \n %f \n %f \n", roster[i].name, roster[i].number, roster[i].age, roster[i].even, roster[i].money);
            printf("%s \n %d \n %f \n %s \n", teamRoster[i].name, teamRoster[i].nummembers, teamRoster[i].money, teamRoster[i].members[i]);
        }
        else if(strcmp(type, "TEAM") == 0){
            fscanf(ifp, "%s", teamRoster[i].name);
            fscanf(ifp, "%d", teamRoster[i].nummembers);
            int memCounter = teamRoster[i].nummembers;
            teamRoster[i].money = earlyCost;
            //printf("%d", teamRoster[i].nummembers);
            for(j=0; j<memCounter; j++){
                fscanf(ifp, "%s", teamRoster[i].members[j].name);
                fscanf(ifp, "%d", &teamRoster[i].members[j].number);
                fscanf(ifp, "%f", &teamRoster[i].members[j].age);
                fscanf(ifp, "%f", &teamRoster[i].members[j].even);
                //printf("%s \n %d \n %f \n %s \n", teamRoster[i].name, teamRoster[i].nummembers, teamRoster[i].money, teamRoster[i].members[j]);
            }
        }
    }

    fscanf(ifp, "%d", &normRegister);

    for(i=0; i<normRegister; i++){
        fscanf(ifp, "%s", roster[i+indivRegisterAmount].name);
        fscanf(ifp, "%d", &roster[i+indivRegisterAmount].number);
        fscanf(ifp, "%f", &roster[i+indivRegisterAmount].age);
        fscanf(ifp, "%f", &roster[i+indivRegisterAmount].even);
        roster[i+indivRegisterAmount].money = regCost;
    }

/*
    int printTest = normRegister + indivRegisterAmount;
    for(i=0; i<printTest; i++)
        printf("%s \n %d \n %f \n %f \n %f \n", roster[i].name, roster[i].number, roster[i].age, roster[i].even, roster[i].money);
*/


    //close file
    fclose(ifp);

    return;
}

/*

void teamRegister() {

    return;
}

void runEvents() {

    return;
}

void totalCalc() {

    return;
}
*/
