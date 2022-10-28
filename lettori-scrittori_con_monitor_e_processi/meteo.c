#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

#include "header.h"

int main(){

	/* TBD: Creare in memoria condivisa un'area per contenere un oggetto "MonitorMeteo" */

	key_t chiave_shm = /* TBD */;
	int id_shm = /* TBD */;
	MonitorMeteo * p = /* TBD */;

	/* TBD: inizializzare il MonitorMeteo, incluso il sotto-oggetto Monitor con init_monitor() */


	pid_t pid;

	int k;
	for (k=0; k<NUM_UTENTI; k++) {

		pid=fork();
		if (pid==0) {
			Utente(p);
			exit(0);
     	} else if(pid<0) {
			perror("fork");
		}
	}


	pid=fork();
	if (pid==0) {
		Servizio(p);
		exit(0);
	} else if(pid<0) {
		perror("fork");
	}


	int status;
	for (k=0; k<NUM_UTENTI+1; k++) {
		pid=wait(&status);
		if (pid==-1)
			perror("errore");
	}

	/* TBD: Deallocare il sotto-oggetto Monitor con remove_monitor() */

	/* TBD: Deallocare la memoria condivisa */

	return 0;
}
