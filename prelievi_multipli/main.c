#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>

#include "prodcons.h"

int main()
{

    int shm_id = /* TBD: Allocazione di una shared memory per l'oggetto-monitor */

    if (shm_id < 0)
    {
        perror("Errore creazione shared memory");
        exit(1);
    }

    ProdCons *p = /* TBD: Attach della shared memory */

    if (p == (void *)-1)
    {
        perror("Errore attach shared memory");
        exit(1);
    }


    /* TBD: Inizializzare l'oggetto-monitor, chiamando la funzione di inizializzazione */


    for (int i = 0; i < 5; i++)
    {

        pid_t pid = fork();

        if (pid == 0)
        {

            /* Produttore */

            printf("[%d] Avvio produttore\n", getpid());

            srand(getpid());

            for (int j = 0; j < 6; j++)
            {

                int val = rand() % 10;

                /* TBD: Chiamare il metodo "produci()" dell'oggetto-monitor,
                 *      passando in ingresso "val".
                 */

                sleep(2);
            }

            exit(0);
        }
    }

    for (int i = 0; i < 5; i++)
    {

        pid_t pid = fork();

        if (pid == 0)
        {

            /* Consumatore */

            printf("[%d] Avvio consumatore\n", getpid());

            for (int j = 0; j < 3; j++)
            {

                int val_1, val_2;

                /* TBD: Chiamare il metodo "consuma()" dell'oggetto-monitor,
                 *      passando in ingresso "&val_1" e "&val_2" (parametri di uscita).
                 */

                sleep(1);
            }

            exit(0);
        }
    }

    printf("[%d] Processo padre in attesa...\n", getpid());

    for (int i = 0; i < 10; i++)
    {
        wait(NULL);
    }

    printf("[%d] Terminazione\n", getpid());


    /* TBD: De-inizializzare l'oggetto-monitor, chiamando la funzione di rimozione */


    /* TBD: De-allocazione della shared memory */


    return 0;
}
