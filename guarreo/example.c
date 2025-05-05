

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main() {
    int pipefd[2];
    pid_t pid1, pid2;

    // 1. Crear el pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // 2. Primer hijo: grep a1 < infile
    pid1 = fork();
    if (pid1 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) {
        // Abrir infile para lectura
        int fd_in = open("infile", O_RDONLY);
        if (fd_in < 0) {
            perror("open infile");
            exit(EXIT_FAILURE);
        }

        // Redirigir stdin desde infile
        dup2(fd_in, STDIN_FILENO);
        close(fd_in);

        // Redirigir stdout al pipe
        close(pipefd[0]); // Cerramos lectura
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        char *args[] = {"/bin/grep", "a1", NULL};
        execve("/bin/grep", args, NULL);

        perror("execve grep");
        exit(EXIT_FAILURE);
    }

    // 3. Segundo hijo: wc -w > outfile
    pid2 = fork();
    if (pid2 == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0) {
        // Abrir outfile para escritura (crea si no existe, trunca si existe)
        int fd_out = open("outfile", O_CREAT | O_WRONLY | O_TRUNC, 0644);
        if (fd_out < 0) {
            perror("open outfile");
            exit(EXIT_FAILURE);
        }

        // Redirigir stdin desde el pipe
        close(pipefd[1]); // Cerramos escritura
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);

        // Redirigir stdout al archivo
        dup2(fd_out, STDOUT_FILENO);
        close(fd_out);

        char *args[] = {"/usr/bin/wc", "-w", NULL};
        execve("/usr/bin/wc", args, NULL);

        perror("execve wc");
        exit(EXIT_FAILURE);
    }

    // 4. Proceso padre: cerrar todo y esperar
    close(pipefd[0]);
    close(pipefd[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}


Main checklist

Check the existence of infile and outfile

    be sure to understand what > does when the file does not exist

Create the necessary pipe (or pipes)

Create a child process for each command

    Wait for all the processes to end before writing to the outfile

When using here_doc, the second argument is not a command ;)
Execute checklist

Remember that the execve() function needs the path to a binary file as parameter, 
so youll have to find where the commands binaries are stored on your computer. 
Before going further, you have to know how to find any command binary.

Check in all possible locations if the binary (command) requested by the user exists.

"Build" the arguments array for the command.

Execute the command using execve()



Código: imprimir variables de entorno

#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
    int i = 0;

    printf("=== Variables de entorno ===\n");
    while (envp[i] != NULL) {
        printf("%s\n", envp[i]);
        i++;
    }

    return 0;
}

Si luego haces un execve() desde este programa, puedes pasarle el mismo envp 
para que el proceso hijo tenga acceso al mismo entorno:

execve("/bin/ls", args, envp);