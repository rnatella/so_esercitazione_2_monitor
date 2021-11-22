#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "header.h"

void InizioLettura(MonitorMeteo* p){

	/* TBD: Effettuare inizio lettura */

}

void FineLettura(MonitorMeteo* p) {

	/* TBD: Effettuare fine lettura */

}



//Procedure di inizio e fine scrittura

void InizioScrittura(MonitorMeteo* p){

	/* TBD: Effettuare inizio scrittura */
}

void FineScrittura(MonitorMeteo* p){

	/* TBD: Effettuare fine scrittura */
}



void Servizio(MonitorMeteo* p){

	srand(time(0));

	int i;
	for(i=0; i<20; i++) {

		/* TBD: Richiamare InizioScrittura e FineScrittura */

		p->meteo.temperatura = (rand()%101)-50;
		p->meteo.umidita = rand()%101;
		p->meteo.pioggia = rand()%2;

		printf("<%d> scrittura: Temperatura=%d, Umidità=%d, Pioggia=%s\n", getpid(), p->meteo.temperatura, p->meteo.umidita, (p->meteo.pioggia ? "si" : "no") );

		sleep(2);
	}

}

void Utente(MonitorMeteo* p) {

	int i;
	for(i=0; i<10; i++) {

		/* TBD: Richiamare InizioLettura e FineLettura */

		printf("<%d> lettura: Temperatura=%d, Umidità=%d, Pioggia=%s\n", getpid(), p->meteo.temperatura, p->meteo.umidita, (p->meteo.pioggia ? "si" : "no") );

		sleep(1);
	}

}


