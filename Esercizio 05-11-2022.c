#include <stdio.h>
#include <stdlib.h>


void menu ();
void moltiplica ();
void dividi ();
void ins_string();


int main () 

/* Ho inserito altre due variabile char per permetterci una scelta iniziale e una finale per ripetere il programma,
attraverso le funzioni while e do con all'interno lo svolgimento del set dell switch, dove ho aggiunto 
un altro caso che è quello che da la possibilità all'utente di uscire
*/
{
	char scelta_iniziale = {'\0'};
	char scelta_finale = {'\0'};
	do{
		menu ();
			scanf ("%c", &scelta_iniziale);
/*ho inserito la funzione rewind, anche nelle operazioni a seguire così che finita l'opereazioni si riposiziona all'inizio 
dell'operazione così da non avere un errore nel ciclo del while per la scelta finale anche dopo l'operazione di divisione,
moltiplicazione e di inserimento testo. Poi ho inserito delle funzioni if così che se si inserisce un valore in lettera minuscola
per la scelta iniziale
*/ 	
			rewind(stdin);
			if(scelta_iniziale=='a')
				scelta_iniziale='A';
			if(scelta_iniziale=='b')
				scelta_iniziale='B';
			if(scelta_iniziale=='c')
			scelta_iniziale='C';
			if(scelta_iniziale=='d')
				scelta_iniziale='D';
				
// ho impostato nel default dello switch il controllo se si inserisci un valore non indicato e ci fa ritornare alla scelta iniziale

			switch (scelta_iniziale)
			{
				case 'A':{
					moltiplica();
					break;
				}
				case 'B':{
					dividi();
					break;
				}
				case 'C':{
					ins_string();
					break;
				}
    	    	case 'D':
        			{
        				printf("\nGrazie, arrivederci \n");
	        			system("pause");
    	    			return 0;
					}
				default:{
					printf("\nValore inserito non corretto, riprova: ");
					break;
				}
			}
			
/* Ho inserito anche nel ciclo while la scelta finale  come dicevo sopra chiedendo all'utente se vuole ripetere 
le operazioni oppure uscire dal programma		
*/		
		printf("\nCiao, vuoi continuare ad usare i miei servizi?\n\nRispondi Y oppure clicca qualsiasi altro tasto per uscire: ");
		scanf("%c",&scelta_finale);
		rewind(stdin);
	}while(scelta_finale=='Y' || scelta_finale=='y');
	printf("\nGrazie, arrivederci\n\n");
	system("pause");
	return 0;

}


void menu ()
{
	printf ("\nBenvenuto, sono un assistente digitale, posso aiutarti a sbrigare alcuni compiti\n");
	printf ("\nCome posso aiutarti?\n");
	printf ("\nA >> Moltiplicare due numeri\nB >> Dividere due numeri\nC >> Inserire una stringa\nD >> Esci\n\nRisposta: ");

}

// nelle operazioni ho corretto gli errori che ho segnalato sul report PDF

void moltiplica ()
{
	int  a,b;
	printf ("\nInserisci i due numeri da moltiplicare\n");
	printf("\nPrimo fattore: ");
	scanf ("%d", &a);
	rewind(stdin);
	printf("\nSecondo fattore: ");
	scanf ("%d", &b);
	rewind(stdin);

	int prodotto = a * b;

	printf ("\nIl prodotto tra %d e %d e': %d\n\n", a, b, prodotto);
}


void dividi ()
{
        int  a,b;
        printf ("\ninserisci i numeri da dividere\n");
        printf ("\nInserisci il numeratore: ");
        scanf ("%d", &a);
        rewind(stdin);
        printf ("\nInserisci il denominatore: ");
        scanf ("%d", &b);
        rewind(stdin);
        	
		
        float divisione = a / b;

        printf ("\nLa divisione tra %d e %d e': %f\n\n", a,b,divisione);
}





void ins_string () 
{
	char stringa[10];
        printf ("\nInserisci la stringa: ");
        scanf ("%s", &stringa);
        rewind(stdin);
        printf("\n\nQuesta è la tua stringa: %s\n", stringa);
}
