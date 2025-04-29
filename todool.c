#include <stdio.h>
#include<string.h>

struct Task{
char description[100];
int completed;
};

struct Task tasks[100];
int taskCount=0;

void addTask(){
    if (taskCount>=100){
        printf("Task List full, you have too many pending tasks. Complete your previous tasks first!\n");
        return;
    }

    printf("Enter Task:");
    fgets(tasks[taskCount].description,100,stdin);
    tasks[taskCount].completed=0;
    taskCount++;
    printf("Task: %s added succesfully",tasks[taskCount-1].description);

}

void printMenu(){
    printf("welcome to Todool- your workbro!\n");
    printf("1.Add Task\n");
    printf("2.List Tasks\n");
    printf("3.Exit\n");
    printf("Choose an option:");
}

int main(){
    printf("Todool activated! Let's grind!");
    int choice;
    do{
        printMenu();
        scanf("%d",&choice);
        getchar();

        switch(choice)
        {
            case 1:
            addTask();
            break;

            case 2:
            printf("\n Tasks will appear here! (Coming soon)\n");
            break;

            case 3:
            printf("Bye Bye! Go crush your tasks!");
            break;

            default:
            printf("Invalid choice. Try again :( \n");
        }
        }while(choice!=3);
        return 0;
    }
   


