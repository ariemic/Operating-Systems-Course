#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


//run make numberOfProcesses for example make 4
int main(int argc, char* argv[]){

    const int cntProcesses = atoi(argv[1]);
    pid_t child_pid;

    for(int i=cntProcesses; i > 0; i--){
        child_pid = fork();
        if(child_pid == 0){
            //fork zwrócił teraz wartość 0 dla procesu potomnego, wiec jestesmy w nowym procesie
            //czytamy jego pid, i ppid
            printf("Wartosc pid dla procesu macierzystego: %d\n", (int)getppid());
            printf("Wartosc pid dla procesu potomnego: %d\n --------------- \n", (int)getpid());
            exit(0);
        }
    }

    int status;
    for(int i=cntProcesses; i > 0 ; i--){
        child_pid = wait(&status);//czeka na zakonczenie procesu potomnego i zwarca jego id oraz status
        if ( WIFEXITED(status) ) { //sprawdza czy status jest poprawny
            printf("Proces %d zakonczl sie poprawnie. Status: %d \n", child_pid, WEXITSTATUS(status) );

        } else {
            printf("Proces %d zakonczyl sie niepowodzeniem. Status: %d \n", child_pid, WEXITSTATUS(status));
        }
        fflush(stdout);
    }

    printf("liczba procesow: %d\n", cntProcesses);

    return 0;
}
