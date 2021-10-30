//Vital Muñoz Erik
#include <stdio.h>

#define DIA 1
#define MES 2
#define ANNIO 3

struct struct_fecha
{
	int dia;
	int mes;
	int annio;
};


typedef struct struct_fecha Fecha;


void imprime(Fecha fecha);
void capturaFecha(Fecha *fecha);
void imprimeN(Fecha fechaNueva);
void dameTipoCant(int *num, int *cantidad);
void dameTipoCantRes(int *num, int *cantidad);
Fecha sumaFecha(Fecha fecha, int tipo, int cantidadASumar);
Fecha restaFecha(Fecha fecha, int tipo, int cantidadARestar);
void imprimeN(Fecha fechaNueva);
int comparaFecha(Fecha fecha, Fecha fechaNueva);


int main()
{
	int numero, cantidad, sumaResta, resultado;
	Fecha fecha, fechaNueva;
	
	fecha.dia = 1;
	fecha.mes=4;
	fecha.annio=2019;
	
	imprime(fecha);
	printf("\n\nFecha Principal:\n");
	capturaFecha(&fecha);
	
	printf("\n\nDesea:\n1.-Sumar\n2.-Restar\n");
	scanf("%d", &sumaResta);
	
	if(sumaResta==1)
	{
		dameTipoCant(&numero, &cantidad);
		fechaNueva=sumaFecha(fecha, numero, cantidad);
	}
	else
	{
		dameTipoCantRes(&numero, &cantidad);
		fechaNueva=restaFecha(fecha, numero, cantidad);
	}
	imprimeN(fechaNueva);
	
	resultado=comparaFecha(fecha, fechaNueva);
	
	printf("\n\n\nComparacion hecha: %d", resultado);
	
	return 0;
}

void imprime(Fecha fecha)
{
	printf("%d/%d/%d", fecha.dia, fecha.mes, fecha.annio);
}


void capturaFecha(Fecha *fecha)
{
	printf("\nDia: ");
	scanf("%d", &fecha->dia);
	printf("\nMes: ");
	scanf("%d", &fecha->mes);
	printf("\nAño: ");
	scanf("%d", &fecha->annio);
}


void imprimeN(Fecha fechaNueva)
{
	printf("\nNueva Fecha: \n");
	printf("\n%d/%d/%d", fechaNueva.dia, fechaNueva.mes, fechaNueva.annio);
}

void dameTipoCant(int *num, int *cantidad)
{
	
	printf("1.-Dia\n2.-Mes\n3.-Año\n");
	printf("Dato de la fecha que desea aumentar: ");
	scanf("%d", num);
	
	printf("\nCantidad que desea aumentar: ");
	scanf("%d", cantidad);
}

void dameTipoCantRes(int *num, int *cantidad)
{
	
	printf("1.-Dia\n2.-Mes\n3.-Año\n");
	printf("Dato de la fecha que desea disminuir: ");
	scanf("%d", num);
	
	printf("\nCantidad que desea disminuir: ");
	scanf("%d", cantidad);
}


Fecha sumaFecha(Fecha fecha, int tipo, int cantidadASumar)
{
	Fecha nuevaFecha;
	int elDia, elMes, elMes2, elAnnio, op;
	
	if(tipo==ANNIO)
	{
		nuevaFecha.dia=fecha.dia;
		nuevaFecha.mes=fecha.mes;
		nuevaFecha.annio=fecha.annio+cantidadASumar;
	}
	else if(tipo == MES)
	{
		nuevaFecha.dia=fecha.dia;
		nuevaFecha.mes=fecha.mes+cantidadASumar;
		
		if(nuevaFecha.mes>12)
		{
			op=cantidadASumar + fecha.mes;
			elAnnio=(op)/12;
			elMes= op-(elAnnio*12);
			nuevaFecha.mes=elMes;
			nuevaFecha.annio=fecha.annio+elAnnio;
		}
		else
		{
			nuevaFecha.annio=fecha.annio;
		}
	}
	else
	{
		nuevaFecha.dia=fecha.dia+cantidadASumar;
		
		if(nuevaFecha.dia>30)
		{
			op=cantidadASumar + fecha.dia;
			elMes=(op)/30;
			elDia= op-(elMes*30);
			nuevaFecha.dia=elDia;
			nuevaFecha.mes=fecha.mes+elMes;
			if(nuevaFecha.mes>12)
			{
				elAnnio=(nuevaFecha.mes)/12;
				elMes2= nuevaFecha.mes-(elAnnio*12);
				nuevaFecha.mes=elMes2;
				nuevaFecha.annio=fecha.annio+elAnnio;
			}
		}
		else
		{
			nuevaFecha.mes=fecha.mes;
			nuevaFecha.annio=fecha.annio;
		}
	}
	
	
	return nuevaFecha;
}


Fecha restaFecha(Fecha fecha, int tipo, int cantidadARestar)
{
	Fecha nuevaFecha;
	int elDia, elMes, elMes2, elAnnio, op;
	
	if(tipo==ANNIO)
	{
		nuevaFecha.dia=fecha.dia;
		nuevaFecha.mes=fecha.mes;
		nuevaFecha.annio=fecha.annio-cantidadARestar;
	}
	else if(tipo == MES)
	{
		nuevaFecha.dia=fecha.dia;
		nuevaFecha.mes=fecha.mes-cantidadARestar;
		
		if(nuevaFecha.mes<0)
		{
			op=fecha.mes+cantidadARestar;
			elAnnio=(op)/12;
			elMes= op-(elAnnio*12);
			nuevaFecha.mes=elMes;
			nuevaFecha.annio=fecha.annio-elAnnio;
		}
		else if(nuevaFecha.mes==0)
		{
			nuevaFecha.mes=12;
			nuevaFecha.annio=fecha.annio-1;
		}
		else
		{
			nuevaFecha.annio=fecha.annio;
		}
	}
	else
	{
		nuevaFecha.dia=fecha.dia-cantidadARestar;
		
		if(nuevaFecha.dia>0)
		{
			op=cantidadARestar + fecha.dia;
			elMes=(op)/30;
			elDia= op-(elMes*30);
			nuevaFecha.dia=elDia;
			nuevaFecha.mes=fecha.mes-elMes;
			if(nuevaFecha.mes>0)
			{
				elAnnio=(nuevaFecha.mes)/12;
				elMes2= nuevaFecha.mes-(elAnnio*12);
				nuevaFecha.mes=elMes2;
				nuevaFecha.annio=fecha.annio-elAnnio;
			}
			else if(nuevaFecha.mes==0)
			{
				nuevaFecha.mes=12;
				nuevaFecha.annio=fecha.annio-1;
			}
		}
		else
		{
			nuevaFecha.mes=fecha.mes;
			nuevaFecha.annio=fecha.annio;
		}
	}
	
	
	return nuevaFecha;
}

int comparaFecha(Fecha fecha, Fecha fechaNueva)
{
	int res;
	
	if(fecha.dia>fechaNueva.dia && fecha.mes>=fechaNueva.mes && fecha.annio>=fechaNueva.annio)
	{
		res=-1;
	}
	else if(fecha.dia==fechaNueva.dia && fecha.mes==fechaNueva.mes && fecha.annio==fechaNueva.annio)
	{
		res=0;
	}
	else
	{
		res=1;
	}
	
	return res;
}
