#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void create_process_tree(int level, int max_level) {
    printf("%d,", level);
    fflush(stdout);
    
    if (level < max_level) {
        for (int i = 0; i < 2; i++) {
            pid_t pid = fork();
            if (pid == 0) {
                create_process_tree(level + 1, max_level);
                exit(0); 
            }
        }
        for (int i = 0; i < 2; i++) {
            wait(NULL);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <n>\n", argv[0]);
        return 1;
    }
    
    int n = atoi(argv[1]);
    if (n < 0) {
        printf("El nivel debe ser un número entero no negativo.\n");
        return 1;
    }
    
    create_process_tree(0, n);
    printf("\n");
    return 0;
}

