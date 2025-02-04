#include <stdio.h>
#include <unistd.h>  // Para fork(), sleep()
#include <sys/wait.h>  // Para wait()

int main() {
    // Crear un proceso hijo
    pid_t pid = fork();

    if (pid < 0) {
        // Error al crear el proceso hijo
        fprintf(stderr, "Error al crear el proceso hijo.\n");
        return 1;
    } else if (pid == 0) {
        // Código del proceso hijo
        for (int i = 0; i < 10; i++) {
            printf("Soy el hijo\n");
            sleep(1);  // Pausa de 1 segundo
        }
    } else {
        // Código del proceso padre
        for (int i = 0; i < 10; i++) {
            printf("Soy el padre\n");
            sleep(1);  // Pausa de 1 segundo
        }

        // Esperar a que el hijo termine
        wait(NULL);
        printf("Mi proceso hijo ya ha terminado.\n");
    }

    return 0;
}
