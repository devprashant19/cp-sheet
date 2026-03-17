#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    pid_t child_pid, grandchild_pid;
    child_pid=fork();
    if(child_pid<0){
        perror("Fork failed");
        exit(1);
    }
    else if(child_pid>0){
        wait(NULL);
        printf("Parent process (PID:%d) - Execution finished.\n",getpid());
    }else{
        grandchild_pid=fork();
        if(grandchild_pid<0){
            perror("Fork failed");
            exit(1);
        }else if(grandchild_pid>0){
            wait(NULL);
            printf("Child process (PID:%d) - Execution finished. \n",getpid());
        }else{
            printf("Grandchild process (PID:%d) - Execution finished.\n",getpid());
            exit(0);
        }
        exit(0);
    }
    return 0;
}