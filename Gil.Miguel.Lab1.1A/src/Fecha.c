/*
 * Fecha.c
 *
 *  Created on: 11 may. 2022
 *      Author: JUNMI
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Notebook.h"
#include "Fecha.h"


int validarFecha(eFecha* unaFecha)
{
	int todoOk = 0;
	int primerValidacion = 0;
	int segundaValidacion = 0;
	int dia;


	if(unaFecha != NULL && (unaFecha->anio >= 1900 && unaFecha->anio <= 2030) &&
	  (unaFecha->mes > 0 && unaFecha->mes <= 12) && (unaFecha->dia > 0 && unaFecha->dia <= 31))
	{
		primerValidacion = 1;
	}else
	{
		while(primerValidacion == 0)
		{
			printf("Fecha inv�lida. Recuerde que debe separar d�a, mes y a�o (m�x 2030) usando / / / \n");
			printf("Reingrese fecha dd/mm/aaaa: ");
			fflush(stdin);
			scanf("%d/%d/%d", &unaFecha->dia, &unaFecha->mes, &unaFecha->anio);
		}
		primerValidacion = 1;
	}

	if(primerValidacion == 1)
	{
		switch(unaFecha->mes)
		{
		case 2:
			while(!(dia > 0 && dia <= 28))
			{
				printf("D�a inv�lido. Febrero tiene 28 d�as \n");
				printf("Reingrese d�a: ");
				fflush(stdin);
				scanf("%d", &dia);
			}
			segundaValidacion = 1;
			unaFecha->dia = dia;

		break;

		case 4:
			while(!(dia > 0 && dia <= 30))
			{
				printf("D�a inv�lido. Abril tiene 30 d�as \n");
				printf("Reingrese d�a: ");
				fflush(stdin);
				scanf("%d", &dia);
			}
			segundaValidacion = 1;
			unaFecha->dia = dia;

		break;

		case 6:
			while(!(dia > 0 && dia <= 30))
			{
				printf("D�a inv�lido. Junio tiene 30 d�as \n");
				printf("Reingrese d�a: ");
				fflush(stdin);
				scanf("%d", &dia);
			}
			segundaValidacion = 1;
			unaFecha->dia = dia;

		break;

		case 9:
			while(!(dia > 0 && dia <= 30))
			{
				printf("D�a inv�lido. Septiembre tiene 30 d�as \n");
				printf("Reingrese d�a: ");
				fflush(stdin);
				scanf("%d", &dia);
			}
			segundaValidacion = 1;
			unaFecha->dia = dia;

		break;

		case 11:
			while(!(dia > 0 && dia <= 30))
			{
				printf("D�a inv�lido. Noviembre tiene 30 d�as \n");
				printf("Reingrese d�a: ");
				fflush(stdin);
				scanf("%d", &dia);
			}
			segundaValidacion = 1;
			unaFecha->dia = dia;

		break;

		default:
				segundaValidacion = 1;
		}
	}

	if(primerValidacion == 1 && segundaValidacion == 1)
	{
		todoOk = 1;
	}

	return todoOk;
}