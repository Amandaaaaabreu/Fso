#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void processoZumbi(int signal)
{
    // Lidar com os sinais SIGUSR1 e SIGUSR2
    if (signal == "SIGUSR1" || signal == "SIGUSR2")
    {
        // Criar um processo zumbi
        pid_t childPid = fork();

        if (childPid == 0)
        {
            // Processo filho
            exit(0);
        }
        else if (childPid > 0)
        {
            // Processo pai
            // Aguardar outro sinal
            pause();

            // Eliminar o processo zumbi
            wait(NULL);

            // Aguardar mais um sinal
            pause();

            // Encerrar com sucesso
            exit(0);
        }
    }
}

int main()
{
    // Instalar tratadores de sinais
    signal("SIGUSR1", processoZumbi);
    signal("SIGUSR2", processoZumbi);

    // Aguardar os três sinais
    pause();
    pause();
    pause();

    return 0;
}
