#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
/*Juego RPG para el ramo metodos de programacion,
Hecho por Franco Barría rosas con la guia de los
profesores Francisco Muñoz y Pablo Roman

franco.barria@usach.cl 20.668.934-K

Compilado en GCC de ubuntu
*/
struct objeto{
	char nombre[100];		// Se crea un struct para almacenar objetos.
	int usos;
};

struct objeto objetos[4];		// Se crea un arreglo para guardar objetos, son solamente 5 los que contiene el juego.

struct heroe{
	char nombre[100];
	int salud;				// Se crea un struct para almacenar los datos de las tribus.
	int fuerza;
	int inteligencia;
	int cordura;
	int agilidad;
};

struct heroe heroes[4];		// Se crea un arreglo para guardar las tribus, son solamente 5 las que contiene el juego.


struct alien{
	int ui;
	int uj;					// En este struct se intento hacer que los Aliens siguieran al usuario, en la proxima
};							// entrega estara disponible.

struct alien aliens[50];

void separador(){
	printf("=============================================================\n"); // Funcion separadora de texto.
}

void enter(){
	printf("Presiona enter para continuar\n");
	char enter = 0; 
	while (enter != '\r' && enter != '\n'){					// Funcion para ir pasando de menus solo presionando enter.
	enter = getchar();
	} 	
}



void intro(){
	printf("\nEs el anio 2945, la humanidad ha \n");
	printf("llegado al pinaculo de la       \n");
	printf("tecnologia debido a la falta de \n");
	printf("materias primas desde hace 400  \n");
	printf("anios, lo cual ha colocado en    \n");
	printf("reto a diferentes cientificos   \n");
	printf("del mundo para lograr encontrar \n");
	printf("mas y asi ser el duenio de estas.\n");
	enter();
	printf("\nUna empresa privada ucraniana   \n");
	printf("financio a un grupo de          \n");
	printf("informaticos para crear una IA  \n");
	printf("que aprenda sobre todas las     \n");
	printf("civilizaciones que el humano ha \n");
	printf("extinguido, para asi lograr una \n");
	printf("forma de clonar materias primas,\n");
	printf("desgraciadamente, la IA no      \n");			// Funcion para contar un poco lo de la historia del juego.
	printf("aprendio nada, por lo cual la   \n");
	printf("empresa privada quebro y los    \n");
	printf("informaticos fueron a otros     \n");
	printf("proyectos, pero dejaron         \n");
	printf("funcionando este carisimo       \n");
	printf("proyecto...                     \n");
	enter();
	printf("\nYa son finales de 3045 y la IA  \n");
	printf("descubrio un codigo prohibido   \n");
	printf("por una federacion estelar de la\n");
	printf("cual el humano ignoraba por     \n");
	printf("completo, y estos tomaron cartas\n");
	printf("en el asunto...\n");
	printf("                                \n");
	printf("  ...Extincion al extinguidor   \n");
	enter();

}
void recomendacion(){
	printf("\n para una mejor experiencia, agrande el visor de comandos\n");	// Funcion para recomendar mejor experiencia.
}

int personajes(){
	char opcion[5] = "0";
	char opcionValida = '0';		// Funcion para elegir al Heroe con el que se jugara.

	char g1 = 'U', g2 = 'U'; // g = guerrequin
	char t1 = ' ', t2 = ' '; // t = tanquequin
	char i1 = 'O', i2 = 'O'; // i = informatequin 			// definimos Caracteres para los ojos de los personajes (x1 x2).
	char a1 = '0', a2 = '0'; // a = androides
	char as1 = 'O', as2 = 'O'; // as = aspiradora espia
	if(heroes[1].salud <= 0 || heroes[1].cordura <=0){
		g1 = 'X'; g2 = 'X';
	}
	if(heroes[2].salud <= 0 || heroes[2].cordura <=0){
		t1 = 'x'; t2 = 'x';
	}
	if(heroes[3].salud <= 0 || heroes[3].cordura <=0){			// Cambiamos los ojos de los personajes en caso de que
		i1 = 'X'; i2 = 'X';										// esten muertos.
	}
	if(heroes[4].salud <= 0 || heroes[4].cordura <=0){
		a1 = 'x'; a2 = 'x';
	}
	if(heroes[5].salud <= 0 || heroes[5].cordura <=0){
		as1 = 'X'; as2 = 'X';
	}
	printf("\n=========================== Elije a tu Heroe ==========================\n\n");
	printf("      ____          ______         ______          ____	 \n");
	printf("     |____|        /   __ \\	  /_____/         |    |\n");
	printf("     |_%c_%c|       |  *|%c%c||       |--%c-%c|         |=%c=%c| \n", g1, g2, t1, t2, i1, i2, a1, a2);
	printf("   __|____|__     |  *|__||       G   __|         \\____/  \n");
	printf("  |  |    |__|__ __\\______/____   \\____/_     ___  | |	           \n");
	printf("  |  |___/______|              |  /      \\   /69/ /| |\\       %c_%c____   \n", as1, as2);
	printf("  |________)  |	  |   L.S.D|   | | |HACK|_|_/__/ / | | \\      /  ___()\n");
	printf("     |    |   |___|________|___| |_|____|___|     /___\\     _/  /___  \n");
	printf("     |  | |       |        |	   |  | |         || ||    |_______|    \n");
	printf("     |__|_|       |_____|__|       |__|_|         || ||    0000 0000 	\n");		// Print para previsualiar personajes.
	printf("\n=======================================================================");
	printf("\n1)GUERREQUIN 2)TANQUEQUIN 3)INFORMATEQUIN 4)ANDROIDE 5)ASPIRADORA ESPIA");
	printf("\n=======================================================================\n");
	while(opcionValida == '0'){
		scanf("%s", opcion);
		int result1 = strcmp(opcion, "1");
		int result2 = strcmp(opcion, "2");
		int result3 = strcmp(opcion, "3");
		int result4 = strcmp(opcion, "4");
		int result5 = strcmp(opcion, "5");		// While para la seleccion del personaje, se pueden ingresar tanto como char e int
		if (result1 == 0){						// sin generar un error en el funcionamiento del juego, esta forma de eleccion
			return(1);							// fue compartida por el profesor Francisco Muñoz.
		}
		else if (result2 == 0){
			return(2);
		}
		else if (result3 == 0){
			return(3);
		}
		else if (result4 == 0){
			return(4);
		}
		else if (result5 == 0){
			return(5);
		}		
		else{
			printf("Opcion no valida, por favor vuelva a ingresar\n");
		}
	}
	/*
	scanf("%d", &opcion);
	if(opcion < 1 || opcion > 5){
		printf("\nPorfavor, ingrese un numero correspondiente al heroe que desea.");
		return(personajes());
	}
	if(heroes[opcion].salud <= 0 || heroes[opcion].cordura <= 0){					// Algoritmo de seleccion anterior
		printf("\nEste heroe ha fallecido, Porfavor, elije otro\n");				// al cambio
		return(personajes());
	}
	return(opcion);*/
}


int sobjeto(int num){
	char opcion[6] = "0";		// Funcion para elegir objetos antes de ingresar al laberinto, el algoritmo de eleccion
	char opcionValida = '0';	// es el mismo que en la funcion pasada.

	printf("\nINVENTARIO:\n\nPorfavor, elija el objeto a llevar en la casilla nº%d:\n\n", num);
	printf("1)%s     Cantidad restante: %d\n", objetos[0].nombre, objetos[0].usos);
	printf("2)%s    Cantidad restante: %d\n", objetos[1].nombre, objetos[1].usos);
	printf("3)%s       Cantidad restante: %d\n", objetos[2].nombre, objetos[2].usos);
	printf("4)%s        Cantidad restante: %d\n", objetos[3].nombre, objetos[3].usos);		// Imprimimos los objetos que el juego
	printf("5)%s          Cantidad restante: %d\n", objetos[4].nombre, objetos[4].usos);	// tiene para ofrecer
	printf("6)Ninguno\n");
	printf("\n= Recuerda que puedes encontrar mas objetos en el laberinto =\n");

	while(opcionValida == '0'){
		scanf("%s", opcion);
		int result1 = strcmp(opcion, "1");
		int result2 = strcmp(opcion, "2");
		int result3 = strcmp(opcion, "3");
		int result4 = strcmp(opcion, "4");
		int result5 = strcmp(opcion, "5");
		int result6 = strcmp(opcion, "6");
		if (result1 == 0){
			if(objetos[0].usos == 0){
				printf("No hay suficientes usos para este objeto");
				return(sobjeto(num));
			}															// En caso de que los usos esten agotados, se ocupa la recursion
 																		// volviendo a ocupar la misma funcion hasta que retorne un entero
			return(0);													// deseado.
		}
		else if (result2 == 0){
			if(objetos[1].usos == 0){
				printf("No hay suficientes usos para este objeto");
				return(sobjeto(num));
			}
			return(1);
		}
		else if (result3 == 0){
			if(objetos[2].usos == 0){
				printf("No hay suficientes usos para este objeto");
				return(sobjeto(num));
			}
			return(2);
		}
		else if (result4 == 0){
			if(objetos[3].usos == 0){
				printf("No hay suficientes usos para este objeto");
				return(sobjeto(num));
			}
			return(3);
		}
		else if (result5 == 0){
			if(objetos[4].usos == 0){
				printf("No hay suficientes usos para este objeto");
				return(sobjeto(num));
			}
			return(4);
		}
		else if (result6 == 0){
			return(5);
		}		
		else{
			printf("Opcion no valida, por favor vuelva a ingresar\n");
		}
	}

}

int menu(){
	char opcion[6] = "0";												// Funcion del menu del juego, el algoritmo de eleccion
	char opcionValida = '0';											// es el mismo que en la funcion pasada.

	printf("=================================================\n");
	printf("\nSeleccione una opcion:\n 1)Jugar\n 2)Instrucciones\n 3)Creditos\n 4)Salir del Juego\n");
	printf("\n=================================================\n");
	while(opcionValida == '0'){
		scanf("%s", opcion);
		int result1 = strcmp(opcion, "1");
		int result2 = strcmp(opcion, "2");
		int result3 = strcmp(opcion, "3");
		int result4 = strcmp(opcion, "4");
		if (result1 == 0){
			printf("Preparate para la fatal aventura...\n");				// Se inicia el juego
			return(1);
		}
		else if (result2 == 0){
			printf("\nInstrucciones dentro del laberinto: \n");
			printf("-Movimiento: w, a, s, d.  -salir del juego: k.\n");
			printf("\n");
			printf("Usted debe recoger las llaves (L) para salir del laberinto (S),\n");
			printf("pero cuidado, que los aliens (A) asechan, para enfrentarlos, busca\n");
			printf("objetos que puedan ayudarte en proximos laberintos.\n\n");
			printf("La eleccion de objetos se hace por casillas, la casilla 1\n");					// Muestra instrucciones
			printf("es el objeto que se usara primero, al usarse, el de la casilla 2\n");
			printf("pasa a su puesto en la batalla.\n\n");
			printf("El heroe muere cuando su vida o energia llega a 0, el juego acaba si\n");
			printf("mueren todos los heroes, o el jugador supera los laberintos\n\n");
			printf("Especificacion de las clases:\n");
			printf("-Guerrequin: debido a sus estadisticas moderadas, es recomendado para pelear\n");
			printf("-Tanquequin: debido a su gran salud es recomendado para aguantar daño\n");
			printf("-Informatequin: alta energia y evasion, recomendado para recolectar objetos\n");
			printf("-Androide: Demasiado daño, pero baja salud, se recomienda recolectar parchecuritas antes de pelear\n");
			printf("-Aspiradora Espia: Alta energia, esta creada para pasar idnavertida, se recomienda usar en caso de problemas\n");
			printf("(La aspiradora espia se creo ademas para que no fuera necesario pelear con cada Alien y superar etapas\n");
			printf("facilmente, cuenta con sus propias animaciones)\n\n");
			return(menu());
		}
		else if (result3 == 0){
			printf("Creditos:\n\n");											// Muestra los creditos
			printf("Creado por Franco Barría Rosas en 2021-2022 franco.barria@usach.cl\n\n");
			return(menu());
		}
		else if (result4 == 0){
			printf("Nos vemos en una proxima aventura\n");			// Opcion para salir del juego
			return(0);
		}else{
			printf("\nNo se ha encontrado una respuesta valida, porfavor reintentar.\n");
		}
	}

}

void escribir_log(FILE* fp, char *linea) {
  time_t t = time(NULL);							// Funcion para escribir un log de movimientos que ocurren en el laberinto,
  fprintf(fp, "%ld %s\n", t, linea);				// esta forma fue compartida por el profesor Pablo Roman.
}


int valimov(char origen, char final, int llaves, int heroe, int objeto1, int objeto2){
	int random = 0;										// recibe el caracter de origen, al que se va, las llaves que se tienen, un contador
	srand(time(NULL));
	random = rand() % 5;							// Funcion para validar movimientos, ademas de mostrar estados de personajes y objetos

	if(final == '#'){
		printf("\n\n\n\nTelecomunicadora:\n\nNotas que hay una pared, no puedes cruzarla\n\n");		// En caso de que haya una pared
		return(0);
	}
	if(final == ' '){
		printf("\nEstado:\n +Salud: %d\n +Energia: %d\n\nObjetos disponibles:\n +Casilla 1: %s  usos restantes: %d\n +Casilla 2: %s  usos restantes: %d\n ", heroes[heroe].salud, heroes[heroe].cordura -1, objetos[objeto1].nombre, objetos[objeto1].usos, objetos[objeto2].nombre, objetos[objeto2].usos);
		heroes[heroe].cordura -= 1;				// En caso de movimiento normal
		return(1);
	}
	if(final == 'A'){
		printf("\n\n\n\nTelecomunicadora:\n\n¡En Guarde!\n\n");
		return(2);									// En caso de encontrarse con un Alien
	}
	if(final == 'L'){
		printf("\n\n\n\nTelecomunicadora:\n\n¡Has encontrado una llave!\n\n");
		return(3);									// En caso de encontrarse con una llave
	}
	if(final == '*'){
		printf("\n\n\n\nTelecomunicadora:\n\nHas encontrado %s\n\n", objetos[random].nombre);
		objetos[random].usos += 1;						// En caso de encontrarse con un objeto, se otorgara un objeto aleatorio.
		return(4);
	}
	if(final == 'S'){
		if(llaves == 3){
			printf("\n\n\n\nTelecomunicadora:\n\n¡Has llegado a la salida!\n\n");		// En caso de tener todas las llaves, se sale del laberinto
			return(6);
		}else{
		printf("\n\n\n\nTelecomunicadora:\n\nNotas que aun te hacen falta llaves para esta puerta\n\n"); // En caso de que no, se queda en el laberinto
			return(5);			
		}

	}
}

/*
int avalimov(char origen, char final){
	if(final == '#'){
		return(0);
	}
	if(final == ' '){

		return(1);
	}
	if(final == 'A'){						// Se intenta crear una funcion para que los aliens se muevan pero no se logro
		return(2);
	}								
	if(final == 'L'){

		return(3);									
	}
	if(final == '*'){
		return(4);
	}
	if(final == 'E'){
		return(5);
	}
	if(final == 'S'){
		return(6);
	}
}
*/

int batalla(int heroe, int objeto1, int objeto2, int vida){		// Funcion para las batallas del juego, ocupa el mismo metodo de eleccion de
	char opcion[5] = "0";										// Funciones pasadas
	char opcionValida = '0';
	char opcionobjeto = '0';
	if(vida <= 0){
		return(heroe);	// Si la vida del alien queda en 0, se devuelve al laberinto
	}
	if(heroes[heroe].salud <= 0){
		printf("\n\nHas muerto...\n\n");	// Si la vida del heroe llega a 0, se devuelve al laberinto
		return(heroe);
	}
	if(heroe != 5){
		printf("\nNotas que el Alien tiene una mirada amenazante...\n");
		if(heroe == 1){
		printf("      ____           	    _______		\n");
		printf("     |____|                /       \\	\n"); 
		printf("     |_U_U|               (* * *   | 	\n");
		printf("   __|____|__             (* * *   | 	\n");
		printf("  |  |    |__|__           \\____   |	\n");
		printf("  |  |___/______|     <==0_____/   \\ 	\n");
		printf("  |________)             \\_\\____   ||	\n");
		printf("     |    |  	              |  |_||	\n");			// prints para personalizar cada personaje, excepto la aspiradora espia
		printf("     |  | |                   |     |	\n");
		printf("     |__|_|                   |_|___|	 \n");
		}
		if(heroe == 2){
		printf("      ______                _______		\n");
		printf("     /   __ \\	           /       \\	\n");
		printf("    |  *|  ||             (* * *   | 	\n");
		printf("    |  *|__||             (* * *   | 	\n");
		printf(" ____\\______/____          \\____   |	\n");
		printf("|                |    <==0_____/   \\ 	\n");
		printf("|   |   L.S.D|   |       \\_\\____   ||	\n");
		printf("|___|________|___|            |  |_||	\n");
		printf("    |        |	              |     |	\n");
		printf("    |_____|__|                |_|___|	 \n");
		}
		if(heroe == 3){
		printf("   ______                   _______		\n");
		printf("  /_____/                  /       \\	\n");
		printf("  |--O-O|                 (* * *   | 	\n");
		printf("  G   __|                 (* * *   | 	\n");
		printf("   \\____/_    ___          \\____   |	\n");
		printf("  /       \\  /69/    <==0_____/   \\ 	\n");
		printf(" | |HACK|_|_/__/         \\_\\____   ||	\n");
		printf(" |_|____|___|	              |  |_||	\n");
		printf("   |  | |                     |     |	\n");
		printf("   |__|_|                     |_|___|	 \n");	
		}
		if(heroe == 4){
		printf("    ____                    _______		\n");
		printf("   |    |                  /       \\	\n");
		printf("   |=0=0|                 (* * *   | 	\n");
		printf("   \\____/                 (* * *   | 	\n");
		printf("     | |                   \\____   |	\n");
		printf("    /| |\\             <==0_____/   \\ 	\n");
		printf("   / | | \\               \\_\\____   ||\n");
		printf("    /___\\    	              |  |_||	\n");
		printf("    || ||                     |     |	\n");
		printf("    || ||                     |_|___|	 \n");
		}
		printf("\nVida restante del Alien = %d%%", vida);					// Se muestra la vida restante del Alien y del
		printf("\nSalud restante del Heroe = %d", heroes[heroe].salud);		// heroe
		printf("\n\n¿Que deseas hacer?\n");
		separador();
		printf("(1) <ATACAR> (2) ==OBJETO== (3) //¡CORRER!\\\\\n");			// Se muestra un menu de opciones
		separador();
		while(opcionValida == '0'){
			scanf("%s", opcion);
			int result1 = strcmp(opcion, "1");
			int result2 = strcmp(opcion, "2");
			int result3 = strcmp(opcion, "3");
			int result4 = strcmp(opcion, "4");
			int result5 = strcmp(opcion, "5");
			if (result1 == 0){
				printf("=Has atacado al Alien=\n");
				vida = vida - heroes[heroe].fuerza;					// Si se ataca el heroe, el alien pierde vida segun la fuerza del
				printf("\n¡Te Ha atacado de vuelta!\n");			// Heroe, el heroe pierde 3 puntos de vida, se retorna recursivamente
				heroes[heroe].salud -= 3;							// hasta que la vide del Heroe o el Alien llegue a 0
				return(batalla(heroe, objeto1, objeto2, vida));
			}
			else if (result2 == 0){
				if(objeto1 == 5 && objeto2 == 5){	
					printf("\n=Revisas la mochila y ves que no tienes objetos=\n");		// En caso de no existir objetos, se retorna la funcion
					return(batalla(heroe, objeto1, objeto2, vida));						// recursivamente para otra opcion
				}
				int select = 0;
				printf("\nElija la casilla a usar\n");
				while(opcionobjeto == '0'){
					scanf("%s", opcion);
					int resultob1 = strcmp(opcion, "1");
					int resultob2 = strcmp(opcion, "2");
					if(resultob1 == 0){
						if(objetos[objeto1].usos <= 0){
							printf("=Revisas la mochila y te das cuenta que no queda del objeto solicitado=");
							return(batalla(heroe, objeto1, objeto2, vida));
						}
						if(objeto1 == 0){
							printf("\n=Te has colocado un parchecurita, ¡tu salud aumenta!=\n");
							heroes[heroe].salud += 10;
							objetos[objeto1].usos -= 1;											// En caso de ocupar un parchecurita, la salud del heroe sube
																							// permanentemente, se descuenta el uso del objeto
																							// la casilla numero 2 pasa a ser la numero 1 para el siguiente objeto o pelea
							return(batalla(heroe, objeto1, objeto2, vida));
						}
						if(objeto1 == 1){
							printf("\n=¡Has pulverizado al Alien con la Bazooka!=\n");
							vida = 0;
							objetos[objeto1].usos -= 1;											// En caso de ocupar bazookatomica, el Alien muere
																				// instantaneamente
							return(batalla(heroe, objeto1, objeto2, vida));
						}
						if(objeto1 == 2){
							printf("\n¡Tu fuerza aumenta!, ¡wow que maciz@!");					// En caso de ocupar esteroides, la fuerza del personaje
							heroes[heroe].fuerza += 10;											// aumenta permanentemente, se recomienda ocupar en el
							objetos[objeto1].usos -= 1;											// androide, ademas de parchecuritas, para crear una
																		// maquina de matar.
						
							return(batalla(heroe, objeto1, objeto2, vida));
						}
						if(objeto1 == 3){
							printf("\n=Te tomas un shot de proteinas, ¡Energia aumenta!=\n");
							heroes[heroe].cordura += 40;										// En caso de ocupar proteinas, la agilidad del personaje
							objetos[objeto1].usos -= 1;											// aumenta permanentemente, para asi evadir mas facil

							return(batalla(heroe, objeto1, objeto2, vida));
						}
						if(objeto1 == 4){
							printf("\n=Has decidido tomar cianuro=\n");							// En caso de ocupar cianuro, el heroe muere instantaneamente,
							heroes[heroe].salud = 0;											// ojala que primero se haya ocupado este objeto dentro del
							objetos[objeto1].usos -= 1;											// juego antes de leer esto
							return(batalla(heroe, objeto1, objeto2, vida));
						}
					}
					else if(resultob2 == 0){
						if(objetos[objeto2].usos <= 0){
							printf("=Revisas la mochila y te das cuenta que no queda del objeto solicitado=");
							return(batalla(heroe, objeto1, objeto2, vida));
						}
						if(objeto2 == 0){
							printf("\n=Te has colocado un parchecurita, ¡tu salud aumenta!=\n");
							heroes[heroe].salud += 10;
							objetos[objeto2].usos -= 1;											// En caso de ocupar un parchecurita, la salud del heroe sube
																								// permanentemente, se descuenta el uso del objeto
																								// la casilla numero 2 pasa a ser la numero 1 para el siguiente objeto o pelea
							return(batalla(heroe, objeto1, objeto2, vida));
						}
						if(objeto2 == 1){
							printf("\n=¡Has pulverizado al Alien con la Bazooka!=\n");
							vida = 0;
							objetos[objeto2].usos -= 1;											// En caso de ocupar bazookatomica, el Alien muere
																								// instantaneamente
							return(batalla(heroe, objeto1, objeto2, vida));
						}
						if(objeto2 == 2){
							printf("\n¡Tu fuerza aumenta!, ¡wow que maciz@!");					// En caso de ocupar esteroides, la fuerza del personaje
							heroes[heroe].fuerza += 10;											// aumenta permanentemente, se recomienda ocupar en el
							objetos[objeto2].usos -= 1;											// androide, ademas de parchecuritas, para crear una
																		// maquina de matar.
						
							return(batalla(heroe, objeto1, objeto2, vida));
						}
						if(objeto2 == 3){
							printf("\n=Te tomas un shot de proteinas, ¡Energia aumenta!=\n");
							heroes[heroe].cordura += 40;										// En caso de ocupar proteinas, la agilidad del personaje
							objetos[objeto2].usos -= 1;											// aumenta permanentemente, para asi evadir mas facil

							return(batalla(heroe, objeto1, objeto2, vida));
						}
						if(objeto2 == 4){
							printf("\n=Has decidido tomar cianuro=\n");							// En caso de ocupar cianuro, el heroe muere instantaneamente,
							heroes[heroe].salud = 0;											// ojala que primero se haya ocupado este objeto dentro del
							objetos[objeto2].usos -= 1;											// juego antes de leer esto
							return(batalla(heroe, objeto1, objeto2, vida));
						}
					}
					else{
						printf("Opcion no valida, por favor reintentar.");
					}

				}

			}
			else if (result3 == 0){
				if(heroes[heroe].agilidad * 2 < vida){
					printf("=Intentas correr pero no lo has logrado, ¡intenta ablandarlo un poco!=");	// Si el usuario decide escapar, tiene que considerar
					return(batalla(heroe, objeto1, objeto2, vida));										// que la vida del alien debe ser menor a la
				}else{																					// agilidad del heroe multiplicada por 2
					printf("=Has escapado=");
					return(heroe);
				}
			}
			else{
				printf("Opcion no valida, por favor vuelva a ingresar\n");
			}
		}
		return(heroe, objeto1, objeto2);
	}
	if(heroe == 5){
		printf("\nNotas que el Alien te mira fijamente...\n");
		printf("                     	    _______		\n");
		printf("                           /       \\	\n");
		printf("                          (* * *   | 	\n");
		printf("                          (* * *   | 	\n");				// Funciones especiales para Aspiradora espia
		printf("                           \\____   |	\n");
		printf("       0_0____                 /   \\ 	\n");
		printf("      /  ___()                /    ||	\n");
		printf("    _/  /___ 	              |  |_||	\n");
		printf("   |_______|                  |     |	\n");
		printf("   0000 0000                  |_|___|	 \n");		
		printf("\n\n¿Que deseas hacer?\n");
		separador();
		printf("(1) <Aspirar el piso> (2) //Seguir tu camino\\\\\n");
		separador();
		while(opcionValida == '0'){
			scanf("%s", opcion);
			int result1 = strcmp(opcion, "1");
			int result2 = strcmp(opcion, "2");

			if (result1 == 0){
				printf("=Estas aspirando el piso tttiiuuuuuuuuuu=\n");
				printf("                     	    _______		\n");
				printf("                           /       \\	\n");
				printf("                          (* * *   | 	\n");		// Se muestra una pequeña interaccion de la aspiradora intentando
				printf("                          (* * *   | 	\n");		// pasar desapercibida. Quizas esta tribu se considere incoherente
				printf("      _  _                 \\____   |	\n");		// para la entrega, pero la quise programar para que fuera una forma
				printf("      >__<____                 /   \\ 	\n");		// más facil de poder pasar los laberintos en caso de que existan 
				printf("      /  ___ \\                /    ||	\n");		// jugadores que no puedan pasar el juego facilmente como mi primo
				printf("    _/  /___\\ \\               |  |_||	\n");		// pequeño, ademas, la aspiradora al no pelear, puede ocuparse como
				printf("   |_______| \\ \\              |     |	\n");		// herramienta para revisar el trabajo de forma más fluida.
				printf("   0000 0000  \\_\\             |_|___|	 \n");
				return(batalla(heroe, objeto1, objeto2, vida));
			}
			else if (result2 == 0){
				printf("\nSigues tu camino y notas como el Alien se va\n\n");
				return(heroe);
			}
			else{																// Recordemos que la aspiradora espia no pelea, solo pasa
				printf("Opcion no valida, por favor vuelva a ingresar\n");		// desapercibida por los aliens al ser una aspiradora.
			}

		}
	}
}

 /*
void alienchase(int ji, int jj, int cantidad){
	int i = 0;
	for(i = 0; i < cantidad; i ++){
		aliens[cantidad].ui += 1;									// intento de crear un busqueda de espacio de estados para que los aliens
		aliens[cantidad].uj += 1;									// puedan perseguir al usuario, en la proxima entrega estara operativo

	}
	for(i = 0; i < cantidad; i++);
		map[aliens[cantidad].ui][aliens[cantidad].uj] = "A";

}
*/

int omapa(int heroe, int nivel, int objeto1, int objeto2){			    	// Funcion para el mapeado del laberinto, aqui ocurre toda la magia, recibe
	int vida = 100;		// Vida de los aliens								// el id del heroe, el nivel, y los id de objetos
	char opcion, movaux;		// Definimos char de opcion y de movimiento auxiliar para más adelante.
	int * inifinal = (int *)malloc(sizeof(int*)*4);			// Se asigna memoria para lograr guardar la entrada (E) y salida (S)
	int i = 0, j = 0, k = 0, llaves = 0, aux;						// Se crean iteradores, ademas de la variable llaves que nos servira 
	int runmap = 1; // Variable para que funcione un ciclo			// para pasar al siguiente laberinto, y tambienuna variable auxiliar
	int alien = 0;  // Variable para saber cuantos aliens hay en el laberinto
	int gameover = 0; // Variable para saber si se acabo el juego
	char  ** map = (char **)malloc(sizeof(char*)*36);
	for(int k = 0; k < 37; k++){						// Se asigna memoria para la matriz del mapa
		map[k] = (char*)malloc(sizeof(char*)*20);
	}

	FILE* fp = fopen("log.txt","a+");	// Se abre el archivo log.txt para editar, este algoritmo fue compartido por el profesor Pablo Roman
  	char buffer[500];   				// Se crea un arreglo de caracteres para buffer


	FILE * f;					
	if(nivel == 1){										
	f = fopen("Laberinto_00.in","r");	
	}
	if(nivel == 2){
	f = fopen("Laberinto_01.in","r");			// Se abren los archivos Laberinto_xx.in dependiendo el nivel 
	}
	if(nivel == 3){
	f = fopen("Laberinto_02.in","r");
	}
	if(nivel == 4){
	f = fopen("Laberinto_03.in","r");
	}
	if(f == NULL){
		printf("No se ha podido abrir el Archivo");
		return(0);
	}

	for(j = 0; j < 20; j++){
		for(i = 0; i < 37; i++){
			map[i][j] = fgetc(f);				// Se guarda los caracteres obtenidos en la matriz declarada map
			if(map[i][j] == 'E'){
				inifinal[0] = i;				// En caso de que se encuentre una E, se guarda en el arreglo declarado inifinal
				inifinal[1] = j;
			}	
			if(map[i][j] == 'S'){
				inifinal[2] = i;				// En caso de que se encuentre una S, se guarda en el arreglo declarado inifinal
				inifinal[3] = j;
			}
			if(map[i][j] == 'A'){
				aliens[alien].ui = i;
				aliens[alien].uj = j;			// En caso de que se encuentre una A, se guarda en el struct de aliens
				alien += 1;		// se suma la cantidad de aliens que hay en el mapa
			}
		}
	}

	while(runmap == 1){			// Mientras que el mapa funcione
		printf("\n");

			for(j = 0; j < 20; j++){
					for(i = 0; i < 37; i++){			// Se imprime el mapa actualizado en cada ciclo
				printf("%c", map[i][j]);	
			}	
		}
		printf("Posicion actual = %d %d|", inifinal[0], inifinal[1]);		// Se muestra la poscicion actual del usuario
		printf("Siguiente movimiento: ");
		scanf("%s", &opcion);				// Se pide al usuario que ingrese wasd para mover la direccion del personaje
		if(opcion == 'w'){					// solo explicare a fondo la opcion con w, debido a que a, s y d es la misma estructura
			aux = valimov(map[inifinal[0]][inifinal[1]], map[inifinal[0]][inifinal[1] - 1], llaves, heroe, objeto1, objeto2); // Validar movimiento
			if(aux == 1 || aux == 2 || aux == 3 || aux == 4 || aux == 6){
				movaux = map[inifinal[0]][inifinal[1]];								// Si valimov retorna alguno de esos enteros, se genera el 
				map[inifinal[0]][inifinal[1]] = map[inifinal[0]][inifinal[1] - 1];	// movimiento, en este caso en el eje Y, con un [i][j--]
				map[inifinal[0]][inifinal[1] - 1] = movaux;
				map[inifinal[0]][inifinal[1]] = ' ';
				if(aux == 2){
					batalla(heroe, objeto1, objeto2, vida);		// Si valimov retorna un 2, significa que hay batalla, y nos dirigimos a la
					if(heroes[heroe].salud <= 0){				// funcion de la batalla, si el heroe pierde la salud, el ciclo se acaba
						runmap = 0;
					}
				}
				if(aux == 3){
					llaves +=1;		// Si encuentra una llave, la variable aumentara 
				}
				if(aux == 4){
				}
				if(aux == 5){		// Los if que estan vacios, son opciones a añadir al programa

				}
				if(aux == 6){
					runmap = 0;
				}
				inifinal[1] -= 1; 		// Se graba el movimiento [i][j--]
				/*
				for(int i = 0; i < alien; i++){
					aux = avalimov(map[aliens[i].ui][aliens[i].uj], map[aliens[i].ui][aliens[i].uj - 1]);
					if(aux == 1 || aux == 2 || aux == 3 || aux == 4){
						movaux = map[aliens[i].ui][aliens[i].uj];
						map[aliens[i].ui][aliens[i].uj] = map[aliens[i].ui][aliens[i].uj - 1];		// Se intento hacer que los aliens se movieran,
						map[aliens[i].ui][aliens[i].uj - 1] = movaux;								// se logro pero se bugeaba con el personaje
						aliens[i].uj -= 1;
					}
					if(aux == 5){
						map[aliens[i].ui][aliens[i].uj] = map[inifinal[0]][inifinal[1]];
					}
				}
				*/
			}else{}


		}
		if(opcion == 'd'){
			aux = valimov(map[inifinal[0]][inifinal[1]], map[inifinal[0] + 1][inifinal[1]], llaves, heroe, objeto1, objeto2);
			if(aux == 1 || aux == 2 || aux == 3 || aux == 4 || aux == 6){
				movaux = map[inifinal[0]][inifinal[1]];			
				map[inifinal[0]][inifinal[1]] = map[inifinal[0] + 1][inifinal[1]];			
				map[inifinal[0] + 1][inifinal[1]] = movaux;						
				map[inifinal[0]][inifinal[1]] = ' ';
				if(aux == 2){
					batalla(heroe, objeto1, objeto2, vida);
					if(heroes[heroe].salud <= 0){
						runmap = 0;
					}
				}
				if(aux == 3){
					llaves +=1;
				}
				if(aux == 4){
				}
				if(aux == 5){

				}
				if(aux == 6){
					runmap = 0;
				}
				inifinal[0] +=1;		// Se graba el movimiento [i++][j]
				/*
				for(int i = 0; i < alien; i++){
					aux = avalimov(map[aliens[i].ui][aliens[i].uj], map[aliens[i].ui + 1][aliens[i].uj]);
					if(aux == 1 || aux == 2 || aux == 3 || aux == 4){
						movaux = map[aliens[i].ui][aliens[i].uj];
						map[aliens[i].ui][aliens[i].uj] = map[aliens[i].ui + 1][aliens[i].uj];
						map[aliens[i].ui + 1][aliens[i].uj] = movaux;
						aliens[i].ui += 1;
					}
					if(aux ==5){
					}
				}
				*/
			}else{}
		}
		if(opcion == 'a'){
			aux = valimov(map[inifinal[0]][inifinal[1]], map[inifinal[0] - 1][inifinal[1]], llaves, heroe, objeto1, objeto2);
			if(aux == 1 || aux == 2 || aux == 3 || aux == 4 || aux == 6){
				movaux = map[inifinal[0]][inifinal[1]];			
				map[inifinal[0]][inifinal[1]] = map[inifinal[0] - 1][inifinal[1]];			
				map[inifinal[0] - 1][inifinal[1]] = movaux;
				map[inifinal[0]][inifinal[1]] = ' ';
				if(aux == 2){
					batalla(heroe, objeto1, objeto2, vida);
				}
				if(aux == 3){
					llaves +=1;
				}
				if(aux == 4){
				}
				if(aux == 5){

				}
				if(aux == 6){
					runmap = 0;
				}
				inifinal[0] -=1;		// Se graba el movimiento [i--][j]
				/*
				for(int i = 0; i < alien; i++){
					aux = avalimov(map[aliens[i].ui][aliens[i].uj], map[aliens[i].ui - 1][aliens[i].uj]);
					if(aux == 1 || aux == 2 || aux == 3 || aux == 4){
						movaux = map[aliens[i].ui][aliens[i].uj];
						map[aliens[i].ui][aliens[i].uj] = map[aliens[i].ui - 1][aliens[i].uj];
						map[aliens[i].ui - 1][aliens[i].uj] = movaux;
						aliens[i].ui -= 1;
					}
					if(aux == 5){
						map[aliens[i].ui][aliens[i].uj] = map[inifinal[0]][inifinal[1]];
					}
				}
				*/
			}else{}
		}
		if(opcion == 's'){
			aux = valimov(map[inifinal[0]][inifinal[1]], map[inifinal[0]][inifinal[1] + 1], llaves, heroe, objeto1, objeto2);
			if(aux == 1 || aux == 2 || aux == 3 || aux == 4 || aux == 6){
				movaux = map[inifinal[0]][inifinal[1]];
				map[inifinal[0]][inifinal[1]] = map[inifinal[0]][inifinal[1] + 1];			
				map[inifinal[0]][inifinal[1] + 1] = movaux;
				map[inifinal[0]][inifinal[1]] = ' ';
				if(aux == 2){
					batalla(heroe, objeto1, objeto2, vida);
					if(heroes[heroe].salud <= 0){
						runmap = 0;
					}
				}
				if(aux == 3){
					llaves +=1;
				}
				if(aux == 4){

				}
				if(aux == 5){

				}
				if(aux == 6){
					runmap = 0;
				}
				inifinal[1] += 1;		// Se graba el movimiento [i][j++]
				/*
				for(int i = 0; i < alien; i++){
					aux = avalimov(map[aliens[i].ui][aliens[i].uj], map[aliens[i].ui][aliens[i].uj - 1]);
					if(aux == 1 || aux == 2 || aux == 3 || aux == 4){
						movaux = map[aliens[i].ui][aliens[i].uj];
						map[aliens[i].ui][aliens[i].uj] = map[aliens[i].ui][aliens[i].uj - 1];
						map[aliens[i].ui][aliens[i].uj - 1] = movaux;
						aliens[i].uj -= 1;
					}
					if(aux == 5){
						map[aliens[i].ui][aliens[i].uj] = map[inifinal[0]][inifinal[1]];
					}
				}
				*/
			}else{}

		}


		sprintf(buffer, "Movimiento de %s en [%d][%d]", heroes[heroe].nombre, inifinal[0], inifinal[1]);
  		escribir_log(fp, buffer);									// Se guarda en el log.txt el movimiento del personaje

		if(opcion == 'k'){
			printf("¡Nos vemos en otra aventura!");					// Si el usuario ingresa k en vez de w a s d, el juego
			return(0);												// se acabara retornando un 0, recordemos que esta funcion
		}															// es run = omapa(...) por lo cual, retornar 0 afecta al ciclo principal del juego
		if(heroes[heroe].salud <= 0){
			runmap = 0;								// Si el personaje tiene salud menor o igual a 0, se acaba el ciclo actual					
		}
		if(heroes[heroe].cordura <= 0){				// Si el personaje tiene energia menor o igual a 0, se acaba el ciclo actual
			printf("\nTe has quedado sin energia, ves que todo se desvanece...\n\n");
			runmap = 0;
		}

		vida = 100;			// Se actualiza la variable de vida de los aliens, en caso de que se haya eliminado a uno
	}
	fclose(f);		// Al acabarse el ciclo, se cierra (f) que es el FILE del mapeado, y tambien se cierra (fp) que es el FILE del log.
	fclose(fp);
	return(1);		// Se retorna 1 al ciclo principal.
}

int leertribus(){											// Funcion para leer el .in de las tribus
  	int i;				// Se crea un iterador
  	char buffer[1000];	// Se crea un arreglo para buffer
	FILE * t;
	t = fopen("tribus.in","r");		
	if(t == NULL){										// Se abre el archivo
		printf("No se ha podido abrir el Archivo");	
		return(0);
	}																			// Este algoritmo fue compartido por el profesor
  	fgets(buffer,49,t);															// Pablo Roman.
    int tt; //tribus totales
    sscanf(buffer, "%d", &tt); // sscanf busca lo que indica dentro un string   
    for (i=1; i<tt+1; i++) {
  	  fgets(buffer,49,t); //nombre
      sscanf(buffer, "%s\n", heroes[i].nombre);		
  	  fgets(buffer,49,t); //Salud
      sscanf(buffer, "Salud = %d\n", &(heroes[i].salud));
  	  fgets(buffer,49,t); //Fuerza											// Se guardan los int de las lineas del archivo .in a sus respectivo struct
      sscanf(buffer, "Fuerza = %d\n", &(heroes[i].fuerza));
  	  fgets(buffer,49,t); //Inteligencia
      sscanf(buffer, "Inteligencia = %d\n", &(heroes[i].inteligencia)); 
  	  fgets(buffer,49,t); //Cordura
      sscanf(buffer, "Cordura = %d\n", &(heroes[i].cordura)); 
  	  fgets(buffer,49,t); //Agilidad
      sscanf(buffer, "Agilidad = %d\n", &(heroes[i].agilidad));    
      // solo para chequear
    }
}   
int leerobjetos(){
	int ot = 0; //objetos totales						// Funcion para leer objetos
	char buffer[1000];
	int i = 0;
	FILE * o; // objetos
	o = fopen("objetos.in","r");
	if(o == NULL){
		printf("No se ha podido abrir el Archivo");
		return(0);
	}
  	fgets(buffer, 49, o);
    sscanf(buffer, "%d", &ot); 
    for(i = 0; i < ot; i++) {	
  	  	fgets(buffer, 49, o); //nombre						// Se guarda el respectivo objeto a su respectivo Stuct
      	sscanf(buffer, "%s\n", objetos[i].nombre);
      	if(i <= 2){
      		objetos[i].usos = 1;
      	}
    }
}



int main(){

	// Esta es la funcion principal del juego, en el cual podemos observar las siguientes variables:

	int heroe = 0;						// Un entero para guardar la id del heroe
	int run = 1;						// Un entero para ocuparlo como booleano y que funcione el ciclo principal del juego
	int nivel = 1;						// Un entero para designar el nivel que se jugara
	int muertes = 0;					// Un contador de muertes para saber cuando los 5 heroes esten incapacitados
	int objeto1 = 0, objeto2 = 0;		// enteros para saber las id de los objetos

	printf("=================================================\n");
	printf("          				       				     \n");
	printf("          				       					 \n");
	printf("          				     				     \n");
	printf(" 							    				 \n");
	printf("          		                                 \n");
	printf(" 		  100 años luz   	             \n");					// Pantalla de titulo
	printf("   		    				                     \n");
	printf("     				        	                 \n");
	printf("                                             +\n");
	printf("     			                		         \n");
	printf("=================================================\n");
	enter();				// Enter para continuar
	recomendacion();		// Recomendacion
	separador();			// Separador
	intro();				// Intro
	run = menu();			// Se asigna Run respecto a las opciones ingresadas en el menu
	leertribus();			// Se leen las tribus
	leerobjetos();			// Se leen los objetos

	// Debido a experiencias anteriores creando juegos (en otros lenguajes), me gusta crear las funciones antes para despues solo
	// agregarlas o quitarlas del loop principal, asi generando un entorno más ordenado y mutable

	while(run == 1){									// Ciclo principal del juego
		separador();
		heroe = personajes();							// Se elije personaje
		objeto1 = sobjeto(1);							// Objeto para la casilla 1
		objeto2 = sobjeto(2);							// Objeto para la casilla 2
		run = omapa(heroe, nivel, objeto1, objeto2);	// Se carga el mapa y el juego dentro del laberinto
		if(heroes[heroe].salud <= 0){					// Al salir del laberinto, se verifica la salud del Heroe.
			nivel -= 1;					// Se resta el nivel actual (despues se volvera a sumar para quedar en el mismo)				
			muertes += 1;				// Se suma una muerte para saber que murio un personaje Q.E.P.D.
		}
		if(heroes[heroe].cordura <= 0){					// Verificacion de la cordura del heroe
			nivel -= 1;					// funciona parecido a la verificacion anterior
			muertes += 1;
		}
		if(muertes == 5){
			printf("\nHemos fracasado, han muerto todos los heroes...\n");		// En caso de que mueran todos los heroes
			run = 0;															// Se imprime un mensaje de fracaso y se cierra el juego
		}

		nivel += 1;					// Se suma un 1 a la variable nivel

		if(nivel == 5){
			printf("\nFelicidades, has expulsado a los Aliens de nuestro planeta\n");	// En caso de que el jugador complete los 5 niveles (0,1,2,3,4)
			run = 0;																	// se comprueba que el nivel es igual a 5 y se cierra el juego
		}
	}				
}							
