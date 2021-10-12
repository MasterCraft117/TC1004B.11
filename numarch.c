#include <unistd.h>

int main(int argc, char const *argv[]){
    int fd[2];
    int pid;

    pipe(fd);
    pid = fork();
    if( pid == 0){
        //close(0);
        close(STDIN_FILENO);
        dup(fd[0]);
        close(fd[1]);
        execlp("wc", "wc", "-l", NULL);
        /* 
        1. Proceso 
        2. Nombre
        3. Args
         */
    }
    else{
        //close(1);
        close(STDOUT_FILENO);
        dup(fd[1]);
        close(fd[0]);
        execlp("ls","ls",NULL);
    }
    return 0;
}