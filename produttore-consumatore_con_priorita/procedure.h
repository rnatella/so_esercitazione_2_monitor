#ifndef __PROCEDURE_H
#define __PROCEDURE_H

#include "monitor_signal_continue.h"

#define DIM 3

typedef struct{
	int buffer[DIM];
	
	/* TBD: Completare la definizione di questa struttura,
	 *      aggiungendo le seguenti variabili:
	 *       - un sotto-oggetto Monitor (per la sincronizzazione)
	 *       - le variabili "testa" e "coda"
	 *       - una variabile "contatore", per contare
	 *         il numero di elementi occupati nel vettore di buffer
	 *       - (opzionale) una variabile "num_produttori_alta_priorita",
	 *         per contare il numero di processi ad alta priorità che sono sospesi
	 */
}PriorityProdCons;


void inizializza_prod_cons(PriorityProdCons* p);
void produci_alta_prio(PriorityProdCons* p, int value);
void produci_bassa_prio(PriorityProdCons* p, int value);
int consuma(PriorityProdCons* p);
void rimuovi_prod_cons(PriorityProdCons* p);

#endif
