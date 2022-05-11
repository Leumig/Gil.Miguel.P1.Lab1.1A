/*
 * Tipo.c
 *
 *  Created on: 11 may. 2022
 *      Author: JUNMI
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Tipo.h"

int listarTipos(eTipo tipos[], int tam)
{
	int todoOk = 0;

		if(tipos != NULL && tam > 0)
		{
			printf("***  Lista de Tipos  ***\n\n");
			printf("    ID      Descripcion\n");
			printf("------------------------\n");
			for(int i = 0; i < tam; i++){
				printf("   %4d    %10s\n", tipos[i].id, tipos[i].descripcion);
			}
			printf("\n\n");
			todoOk = 1;
		}
	 return todoOk;
}

int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[])
{
	int todoOk = 0;
	int indice;

	buscarTipo(tipos, tam, id, &indice);

    if(descripcion != NULL && indice != -1)
    {
		strcpy(descripcion, tipos[indice].descripcion);

		todoOk = 1;
    }

  return todoOk;
}

int buscarTipo(eTipo tipos[], int tam, int id, int* pIndice) //El puntero indice es lo que voy a buscar para devolver
{
	int todoOk = 0;

	if(tipos != NULL && tam > 0 && pIndice != NULL)
	{
		*pIndice = -1;   //Seteamos que no se encontr� coincidencia
		for(int i=0; i < tam; i++)  //Recorremos
		{
			if(tipos[i].id == id)  //Si la id del sector (puede ser 5000, 5001.. etc) es igual a la id recibida...
			{
				*pIndice = i;  //Cargo en indice la posici�n en donde se hay� la coincidencia (0, 1, 2, etc)
				break;  //Corto para que no siga buscando
			}
		}

		todoOk = 1;
	}

	return todoOk;
}

int validarTipo(eTipo tipos[], int tam, int id)
{
	int esValido = 0;
	int indice;

	buscarTipo(tipos, tam, id, &indice);

	if(!(indice == -1))
	{
		esValido = 1;
	}


	return esValido;
}

