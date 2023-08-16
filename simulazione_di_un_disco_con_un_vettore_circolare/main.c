#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "header.h"


void Utente(MonitorSchedulatore * s) {

	int i;

	for(i=0; i<TOTALE_RICHIESTE; i++) {

		/*
		  Creazione e inserimento di una richiesta
		*/

		richiesta r;

		r.posizione = rand() % TOTALE_POSIZIONI;
		r.processo = getpid();

		printf("[%d] Richiesta Utente: posizione=%d, processo=%d\n", getpid(), r.posizione, r.processo);

		/* TBD: Chiamare qui il metodo del monitor "InserisciRichiesta()",
		 *		passando come parametri di ingresso "s" (l'oggetto-monitor)
		 *		ed "&r" (puntatore alla variabile di uscita "r").
		 */
	}
}


void Schedulatore(MonitorSchedulatore * s) {

	int i;

	/*
	  Variabile locale contenente la posizione dell'ultima richiesta
	  che è stata servita (inizialmente si assume la posizione 0)
	*/

	int posizione_corrente = 0;



	/*
	  Array locale che rappresenta il disco. Ogni locazione del
	  disco ospiterà il PID del processo che ha richiesto l'ultima
	  operazione in quella posizione
	*/

	pid_t disco[TOTALE_POSIZIONI];



	for(i=0; i<TOTALE_RICHIESTE*TOTALE_UTENTI; i++) {

		richiesta r;



		/*
		  Lo Schedulatore preleva una richiesta, che verrà copiata
		  nella variabile locale "r"
		*/

		printf("Schedulatore in attesa di richieste...\n");

		/* TBD: Chiamare qui il metodo del monitor "PrelevaRichiesta()",
		 *		passando come parametri di ingresso "s" (l'oggetto-monitor)
		 *		ed "&r" (puntatore alla variabile di uscita "r").
		 */

		printf("[%d] Prelevo richiesta: posizione=%d, processo=%d\n", getpid(), r.posizione, r.processo);


		/*
		  Lo Schedulatore attende alcuni secondi (in base alla posizione
		  della richiesta), ed aggiorna la posizione del disco con il
		  PID del processo richiedente
		*/

		int attesa = abs(posizione_corrente - (int)r.posizione);

        printf("[%d] Attesa Schedulatore... (%d secondi)\n", getpid(), attesa);

		sleep(attesa);



		posizione_corrente = r.posizione;

		disco[posizione_corrente] = r.processo;



		printf("Disco aggiornato alla posizione %d, nuovo valore %d\n", r.posizione, r.processo);

	}
}


int main() {

	int id_shm;


	/*
	  Allocazione di una memoria condivisa per la coda di richieste
	*/

	id_shm = /* TBD: Allocare una memoria condivisa per l'oggetto-monitor, di tipo "MonitorSchedulatore" */

	if( id_shm < 0 ) {

		perror("Errore shmget()");
		exit(1);
	}



	/*
	  Inizializzazione di un puntatore alla memoria condivisa
	*/

	MonitorSchedulatore * s = /* TBD: Effettuare l'attach della memoria condivisa */

	if( s == (void *)-1 ) {

		perror("Errore shmat()");
		exit(1);
	}



	/* TBD: Inizializzare l'oggetto-monitor "s", chiamando la funzione "InizializzaMonitor()" */


	int i;
	pid_t p;

	/*
	  Creazione dei processi figli Utente, ricevono in ingresso
	  un puntatore al monitor
	*/

	for(i=0; i<TOTALE_UTENTI; i++) {

		p = fork();


		if(p == 0) {

			printf("Processo figlio utente in esecuzione (PID %d)\n", getpid());

			Utente(s);
			exit(0);
		}

		if(p < 0) {

			perror("Errore fork() utente");
			exit(1);
		}
	}



	/*
	  Creazione del processo figlio Schedulatore, riceve in ingresso
	  un puntatore al monitor
	*/

	p = fork();

	if(p == 0) {

		printf("Processo figlio schedulatore in esecuzione (PID %d)\n", getpid());

		Schedulatore(s);
		exit(0);
	}

	if(p < 0) {

		perror("Errore fork() schedulatore");
		exit(1);
	}



	/*
	  Il processo padre si pone in attesa della terminazione
	  dei processi Utente e del processo Schedulatore
	*/

	for(i=0; i<TOTALE_UTENTI+1; i++) {

		wait(NULL);

		printf("Processo figlio terminato\n");
	}



	/* TBD: De-inizializzare l'oggetto-monitor "s", chiamando la funzione "RimuoviMonitor()" */


	int ret = /* TBD: De-allocare la memoria condivisa contenente l'oggetto-monitor */;

	if(ret < 0) {

		perror("Errore shmctl()");
		exit(1);
	}


	return 0;
}

