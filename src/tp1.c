/*
 ============================================================================
 Name        : tp1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "librarytp1.h"

int main(void) {

	int opcionIngresada;
	float kilometrosViaje = 0;
	char opcionEmpresa;
	float precioViajeAerolineas = 0;
	float precioViajeLatam = 0;
	float tarjetaDebitoAerolineas = 0;
	float tarjetaDebitoLatam = 0;
	float tarjetaCreditoAerolineas = 0;
	float tarjetaCreditoLatam = 0;
	float bitcoinAerolineas = 0;
	float bitcoinLatam = 0;
	float precioXKilometroAerolineas = 0;
	float precioXKilometroLatam = 0;
	float diferenciaPrecio = 0;
	float kilometrosPrueba = 0;
	float precioAerolineasPrueba = 0;
	float precioLatamPrueba = 0;
	setbuf(stdout, NULL);


	do{
		printf("\n1. Ingresar Kilometros");
		printf("\n2. Ingresar precio de vuelos");
		printf("\n3. Calcular todos los costos");
		printf("\n4. Informar resultado");
		printf("\n5. Carga forzada de datos");
		printf("\n6. Salir");

		fflush(stdin);
		scanf("%d", &opcionIngresada);

		switch(opcionIngresada)
		{
		case 1:
			printf("\nIngrese la cantidad de Kilometros del viaje");
			fflush(stdin);
			scanf("%f",&kilometrosViaje);
			break;
		case 2:
			while(precioViajeAerolineas == 0 || precioViajeLatam == 0)
			{
				printf("\nIngrese Y para ingresar el precio por Aerolinias o Z para Latam");
				fflush(stdin);
				scanf("%c",&opcionEmpresa);
				opcionEmpresa = toupper(opcionEmpresa);
				switch(opcionEmpresa)
				{
				case 'Y':
					printf("\nIngrese el precio del viaje en Aerolineas:");
					fflush(stdin);
					scanf("%f",&precioViajeAerolineas);
					break;
				case 'Z':
						printf("\nIngrese el precio del viaje en Latam:");
						fflush(stdin);
						scanf("%f",&precioViajeLatam);
						break;
				default:
						printf("\nNo se ingreso una opcion correcta, vuelva a intentarlo : \n");
						fflush(stdin);
						break;
				}
			}
			break;
		case 3:
			tarjetaDebitoAerolineas = calcularDescuento(precioViajeAerolineas,0.10);
			tarjetaDebitoLatam = calcularDescuento(precioViajeLatam,0.10);
			tarjetaCreditoAerolineas = calcularInteres( precioViajeAerolineas,0.25);
			tarjetaCreditoLatam = calcularInteres( precioViajeLatam,0.25);
			bitcoinAerolineas = calcularValorEnOtraMoneda(precioViajeAerolineas,4606954.55);
			bitcoinLatam = calcularValorEnOtraMoneda(precioViajeLatam,4606954.55);
			precioXKilometroAerolineas = calcularPrecioPorKm(precioViajeAerolineas,kilometrosViaje);
			precioXKilometroLatam = calcularPrecioPorKm(precioViajeLatam,kilometrosViaje);
			diferenciaPrecio = calcularDiferenciaPrecio(precioViajeAerolineas,precioViajeLatam);
			break;
		case 4:
			if(precioViajeAerolineas == 0 || precioViajeLatam == 0)
			{
				printf("\nNo se pueden mostrar los resultados ya que no se ingresaron los precios en la opcion 2\n");
				fflush(stdin);
			}
			else
			{
				if(kilometrosViaje == 0)
				{
					printf("\nNo se pueden mostrar los resultados al faltar ingresar los Kilometros en la opcion 1\n");

				}
				else
				{
					if(tarjetaDebitoAerolineas == 0)
					{
						printf("\nNo se pueden mostrar los resultados al no haber ingresado la opcion 3 anteriormente\n");
					}
					else
					{
						printf("Latam:\n");
						printf("\na) Precio con tarjeta de débito: %f\n",tarjetaDebitoLatam);
						printf("\nb) Precio con tarjeta de crédito: %f\n",tarjetaCreditoLatam);
						printf("\nc) Precio pagando con bitcoin : %f\n",bitcoinLatam);
						printf("\nd) Precio unitario: %f\n",precioXKilometroLatam);
						printf("Aerolineas:\n");
						printf("\na) Precio con tarjeta de débito: %f\n",tarjetaDebitoAerolineas);
						printf("\nb) Precio con tarjeta de crédito: %f\n",tarjetaCreditoAerolineas);
						printf("\nc) Precio pagando con bitcoin : %f\n",bitcoinAerolineas);
						printf("\nd) Precio unitario: %f\n",precioXKilometroAerolineas);
						printf("\nLa diferencia de precio es %d\n",diferenciaPrecio);
					}
				}
			}
			break;
		case 5:
			 kilometrosPrueba = 7090;
			 precioAerolineasPrueba = 162965 ;
			 precioLatamPrueba = 159339 ;
			 float tarjetaDebitoAerolineasPrueba;
			 tarjetaDebitoAerolineasPrueba = calcularDescuento(precioAerolineasPrueba,0.10);
			 float tarjetaDebitoLatamPrueba;
			 tarjetaDebitoLatamPrueba = calcularDescuento(precioLatamPrueba,0.10);
			 float tarjetaCreditoLatamPrueba;
			 tarjetaCreditoLatamPrueba = calcularInteres( precioLatamPrueba,0.25);
			 float tarjetaCreditoAerolineasPrueba;
			 tarjetaCreditoAerolineasPrueba = calcularInteres( precioAerolineasPrueba,0.25);
			 float bitcoinAerolineasPrueba;
			 bitcoinAerolineasPrueba = calcularValorEnOtraMoneda(precioAerolineasPrueba,4606954.55);
			 float bitcoinLatamPrueba = calcularValorEnOtraMoneda(precioLatamPrueba,4606954.55);
			 float precioXKilometroAerolineasPrueba;
			 precioXKilometroAerolineasPrueba = calcularPrecioPorKm(precioAerolineasPrueba,kilometrosPrueba);
			 float precioXKilometroLatamPrueba;
			 precioXKilometroLatamPrueba = calcularPrecioPorKm(precioLatamPrueba,kilometrosPrueba);
			 int diferenciaPrecioPrueba;
			 diferenciaPrecioPrueba = calcularDiferenciaPrecio(precioAerolineasPrueba,precioLatamPrueba);

			 printf("Latam:\n");
			 printf("\na) Precio con tarjeta de debito: %f\n",tarjetaDebitoLatamPrueba);
			 printf("\nb) Precio con tarjeta de credito: %f\n",tarjetaCreditoLatamPrueba);
			 printf("\nc) Precio pagando con bitcoin : %f\n",bitcoinLatamPrueba);
			 printf("\nd) Precio unitario: %f\n",precioXKilometroLatamPrueba);
			 printf("Aerolineas:\n");
			 printf("\na) Precio con tarjeta de debito: %f\n",tarjetaDebitoAerolineasPrueba);
			 printf("\nb) Precio con tarjeta de credito: %f\n",tarjetaCreditoAerolineasPrueba);
			 printf("\nc) Precio pagando con bitcoin : %f\n",bitcoinAerolineasPrueba);
			 printf("\nd) Precio unitario: %f\n",precioXKilometroAerolineasPrueba);
			 printf("\nLa diferencia de precio es %d\n",diferenciaPrecioPrueba);
			break;
		case 6:
			break;
		default:
			printf("\nSe ingreso una opcion que no existe, vuelva a intentarlo\n");
			break;
		}



	}
	while(opcionIngresada != 6);


	return 0;
}
