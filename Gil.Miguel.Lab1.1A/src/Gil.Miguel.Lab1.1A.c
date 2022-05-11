/*
 ============================================================================
 Name        : 1A.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Menu.h"
#include "Notebook.h"
#include "Marca.h"
#include "Tipo.h"
#include "Servicio.h"
#include "Trabajo.h"


#define ASC 1
#define DESC 0

#define TAM 10
#define TAMM 4
#define TAMT 4
#define TAMS 4
#define TAMTR 5


int main() {
	setbuf(stdout, NULL);


	char salir = 'n';
	int proximaId = 10000;
	int idTrabajo = 7000;

	eNotebook lista[TAM];
	eTrabajo listaT[TAMTR];
	eMarca marcas[TAMM] ={
		{1000, "Compaq"},
		{1001, "Asus"},
		{1002, "Acer"},
		{1003, "HP"}
	};
	eTipo tipos[TAMT] ={
		{5000, "Gamer"},
		{5001, "Disenio"},
		{5002, "Ultrabook"},
		{5003, "Normalita"}
	};
	eServicio servicios[TAMS] ={
		{20000, "Bateria", 2250},
		{20001, "Display", 10300},
		{20002, "Mantenimiento", 4400},
		{20003, "Fuente", 5600}
	};

	inicializarNotebooks(lista, TAM);
	inicializarTrabajos(listaT, TAMTR);

	hardcodearNotebooks(lista, TAM, 5, &proximaId);

	do
	{
		switch(menu())
		{

		case 1:
			if(altaNotebook(lista, TAM, &proximaId, marcas, TAMM, tipos, TAMT))
			{
				printf("Notebok agregada correctamente\n");
			}
			else
			{
				printf("Error al hacer el alta de Notebok\n");
			}
			break;

		case 2:
			if(modificarNotebook(lista, TAM, marcas, TAMM, tipos, TAMT) == 0)
			{
				printf("Error al hacer la modificaci�n de Notebok\n");
			}
			break;

		case 3:
			bajaNotebook(lista, TAM, marcas, TAMM, tipos, TAMT);

			break;

		case 4:
			listarNotebooks(lista, marcas, TAMM, tipos, TAMT);
			break;

		case 5:
			listarMarcas(marcas, TAMM);
			break;

		case 6:
			listarTipos(tipos, TAMT);
			break;

		 case 7:
			listarServicios(servicios, TAMS);
			break;

		 case 8:
			altaTrabajo(listaT, TAMTR, &idTrabajo, lista, TAM, marcas, TAMM,
			tipos, TAMT, servicios, TAMS);
			break;

		 case 9:
			listarTrabajos(listaT, lista, TAM, servicios, TAMS);
			break;

	     case 10:
	            confirmarSalidaMenu(&salir);
	        break;

		default:
			printf("Opci�n inv�lida. Debe ingresar una opci�n del 1 al 10\n");
			break;
		}
		system("pause");

	}
	while(salir != 's');

	printf("Fin del programa");


	return 0;
}