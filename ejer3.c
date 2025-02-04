#include <stdio.h>
#include <unistd.h>  // Para fork(), sleep()
#include <sys/wait.h>  // Para wait()
#include <stdlib.h>  // Para atoi()

int main(int argc, char *argv[]) {
    // Verificar que se proporcionó un argumento
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <número de procesos>\n", argv[0]);
        return 1;
    }

    // Convertir el argumento a entero
    int n = atoi(argv[1]);

    // Verificar que el número de procesos sea válido
    if (n <= 0) {
        fprintf(stderr, "El número de procesos debe ser un entero positivo.\n");
        return 1;
    }

    // Crear n procesos hijos
    for (int i = 1; i <= n; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            // Error al crear el proceso hijo
            fprintf(stderr, "Error al crear el proceso hijo.\n");
            return 1;
        } else if (pid == 0) {
            // Código del proceso hijo
            printf("Proceso hijo %d\n", i);
            return 0;  // Terminar el proceso hijo
        }
    }

    // Esperar a que todos los hijos terminen
    for (int i = 1; i <= n; i++) {
        wait(NULL);
    }

    // Mensaje final del proceso padre
    printf("Fin\n");

    return 0;
}
