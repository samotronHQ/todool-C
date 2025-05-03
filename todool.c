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
    printf("Task: %s added succesfully\n",tasks[taskCount-1].description);

}

void listTasks()
{
    if(taskCount==0){
        printf("You do not have any pending tasks! Enter a task first\n");
        roastUser();
        return;
    }
    printf("----YOUR TASKS-----\n");
    for(int i=0;i< taskCount;
    i++){
        printf("%d.[%c] %s", i+1, tasks[i].completed?'X':' ',tasks[i].description);
    }
}

void roastUser(){
    const char* roasts[]={
        "Bro..Your list is literally empty, are you even trying?", "Task List cleared, time to touch some grass!", "Zero Tasks? Damn you fast af"};
        printf("\n %s\n",roasts[rand()%3]);
    }

void deleteTask(){
    if(taskCount==0){
    printf("Task List is empty,cannot delete tasks!");
    roastUser();
    return;}

    printf("Enter task number to delete(1-%d)",taskCount);
    int taskNum;
    scanf("%d",&taskNum);
    getchar();

    if(taskNum<1|| taskNum>taskCount)
    {
        printf("Invalid task number. Try again, champ!\n");
        return;
    }
    for(int i=taskNum-1;i<taskCount-1;i++){
        tasks[i]=tasls[i+1];
    }
    taskCount--;
    printf("Task %d DELETED. Out of sight, out of mind!\n",taskNum);
    
}




void printMenu(){
    printf("welcome to Todool- your workbro!\n");
    printf("1.Add Task\n");
    printf("2.List Tasks\n");
    printf("3.Delete Tasks\n");
    printf("4.Exit\n");
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
            listTasks();
            break;
             
            case 3:
            deleteTask();
            break;

            case 4:
            printf("Bye Bye! Go crush your tasks!");
            break;

            default:
            printf("Invalid choice. Try again :( \n");
        }
        }while(choice!=3);
        return 0;
    }
   


