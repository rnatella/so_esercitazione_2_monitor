#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "header.h"


void InizializzaMonitor(MonitorSchedulatore * s) {

	/* TBD: Inizializzare la struttura dati */
}


void RimuoviMonitor(MonitorSchedulatore * s) {

	/* TBD: Deallocare il sotto-oggetto monitor */
}


void InserisciRichiesta(MonitorSchedulatore * s, richiesta * r) {

	/* TBD: Effettuare l'ingresso nel monitor */


	/*
	  TBD: Verifica se la coda di richieste sia piena.
	  In caso affermativo, il processo è posto in attesa.
	*/



	printf("[%d] Produzione in testa: %d\n", getpid(), s->testa);

	s->coda_richieste[s->testa].posizione = r->posizione;
	s->coda_richieste[s->testa].processo = r->processo;

	s->testa = (s->testa + 1) % DIMENSIONE_CODA;



	/* TBD: Effettuare signal_condition() */


	/* TBD: Uscire dal monitor */
}


void PrelevaRichiesta(MonitorSchedulatore * s, richiesta * r) {

	/* TBD: Effettuare l'ingresso nel monitor */


	/*
	  TBD: Verifica se la coda di richieste sia vuota.
	  In caso affermativo, il processo è posto in attesa.
	*/


	printf("[%d] Consumazione in coda: %d\n", getpid(), s->coda);

	r->posizione = s->coda_richieste[s->coda].posizione;
	r->processo = s->coda_richieste[s->coda].processo;

	s->coda = (s->coda + 1) % DIMENSIONE_CODA;


	/* TBD: Effettuare signal_condition() */


	/* TBD: Uscire dal monitor */
}


