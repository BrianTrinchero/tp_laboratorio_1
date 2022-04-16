/*
 * librarytp1.c
 *
 *  Created on: 11 abr. 2022
 *      Author: mytic
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/**
 * Retorna un numero menos su descuento.
 * @param precioBruto Recibe el precio al cual le queremos hacer el decuento
 * @param descuento Es el valor del descuento que queremos aplicar
 * @return El valor neto el cual se calcula restandole el precio bruto a el mismo por el descuento.
 */
float calcularDescuento(int precioBruto, float descuento)
{
	float precioNeto;
	float restaDescuento = precioBruto * descuento;

	precioNeto = precioBruto - restaDescuento;

	return (precioNeto);

}

/**
 * Retorna un numero mas su interes.
 * @param Recibe el precio al cual le queremos sumar el interes
 * @param interes El prcentaje de interes.
 * @return el valor neto dado de la suma del precio bruto mas si mismo por el interes.
 */

float calcularInteres(int precioBruto, float interes)
{
	float precioNeto;
	float sumaInteres = precioBruto * interes;

	precioNeto = precioBruto + sumaInteres;

	return (precioNeto);

}

/**
 * Paso un valor en pesos y el valor en pesos de otra moneda para retornar el valor originaol en la moneda solicitada.
 * @param precioPesos El precio que vamos a cambiar de pesos a otra moneda.
 * @param valorMoneda El valor de una moneda a pesos.
 * @return El numero de pesos de la primer variable a otra moneda.
 */

float calcularValorEnOtraMoneda(int precioPesos,float valorMoneda)
{
	float precioOtraMoneda;

	precioOtraMoneda = precioPesos / valorMoneda;

	return precioOtraMoneda;
}

/**
 * Calcula el precio por kilometro dado
 * @param precioTotal El precio total dado a calcular.
 * @param kilometrosTotales Los kilometros totales a calcular
 * @return el precio por kilometro de los valores dados.
 */
float calcularPrecioPorKm(int precioTotal,float kilometrosTotales)
{
	float precioPorKilometro;

	precioPorKilometro = precioTotal / kilometrosTotales;
	return precioPorKilometro;

}
/**
 * Me informa la diferencia que hay entre 2 numeros.
 * @param precioViaje1 El primer valor a calcular
 * @param precioViaje2 El segundo valor a calcular
 * @return La diferencia entre los dos valores, si son iguales retorna 0.
 */

int calcularDiferenciaPrecio(int precioViaje1, int precioViaje2)
{
	int diferenciaDePrecios;

	if(precioViaje1 > precioViaje2)
	{
		diferenciaDePrecios = precioViaje1 - precioViaje2;
	}
	else
	{
		if(precioViaje2 >= precioViaje1)
		{
			diferenciaDePrecios = precioViaje2 - precioViaje1;
		}
	}
	return diferenciaDePrecios;
}


