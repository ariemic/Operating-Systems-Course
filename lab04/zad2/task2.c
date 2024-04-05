#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
// ./task2 /home/ariel/Downloads - run

int globalVar = 0;
int main(int argc, char *dir_name[]){
    printf("Program's name: %s\n", dir_name[0]);
    int localVar = 0;
    int status;
    pid_t child_pid;
    child_pid = fork();
    if (child_pid == 0){
        printf("child process\n");
        globalVar++;
        localVar++;
        printf("child pid = %d, parent pid = %d\n", getpid(), getppid() );
        printf("child's local = %d, child's global = %d\n", localVar, globalVar);
        int processStatus = execl("/bin/ls", "ls", dir_name[1], NULL);
        if (processStatus == -1){
            perror("error, execl didn't work, child process failed\n");
            exit(1);
        }

    }
    else{
        wait(&status); //oczekuje na zakonczenie procesu dziecka
        printf("parent process\n");
        printf("parent pid = %d, child pid = %d\n",  getpid(), child_pid);
        if(WIFEXITED(status)){
            int child_exit_code = WEXITSTATUS(status);
            printf("Child exit code: %d\n", child_exit_code);
        }
        else{
            printf("Child process has failed, an error occurred\n");
        }
        printf("child's local = %d, child's global = %d\n", localVar, globalVar);
    }


    return 0;
}