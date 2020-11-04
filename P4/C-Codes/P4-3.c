// Arturo Vázquez Muñoz - A00570187
// Laboratorio de Microcontroladores 
// Práctica 4 - Problema 3 - Número al Cuadrado

#include <stdio.h>
#include <stdlib.h>         // Librerias agregadas

int n;                      // Inicialización de variables globales
int resultado;
int save;
int save2; 
int CR;
int *halfs; 
int *odds;
int ciclo = 0;
int ciclo2; 

int main()
{
    printf("Ingresar número a elevar al cuadrado = "); // Se pide al usuario ingresar número
    scanf("%i", &n);                                   // Se le asigna a variable n con AND
    save = n;
       
    halfs = (int *) calloc(asize(n),sizeof(int));      // Se crean arrays dinamicos
    odds = (int *) calloc(asize(n),sizeof(int)); 

    ciclo2 = asize(n)+1;

        for (int j = 1; j < (asize(n)+1); j++)
        {
            save = save >> 1;                   // Division entre 2 de num (tipo entero redondiado hacia abajo). 
            halfs[j] = save;                    // se calculan todos los halfs y complementos para los número impares (odds)
            odds[j] = halfs[j] << 2;            
        }
    
    resultado = P4_Square(n);                          // Se corre P4_Square con dicho número
    printf("El resultado es = %i", resultado);         // Se imprime resultado
    return 0;
}


int P4_Square(int num)
{
    ciclo++; 

	if (num < 2){      // Si el número es menor a 2, su cuadrado es igual a si mismo
		return num;    // se obtiene el mismo numero como salida
	}
	num = abs(num);    // sacamos el valor absoluto del númeor para siempre tenerlo en positivo
    if (num & 1){       // es IMPAR si --> num AND 1 = TRUE o 1 (AND binario)
	    CR = P4_Square(halfs[ciclo]) << 2;   // Se hace función de nuevo pero para la mitad de num (Chain Reaction)
                    	                     // dando corrimiento a la izquierda en dos unidades
        ciclo2--;
        return (CR + odds[ciclo2] + 1); // el resultado es igual al Chain Effect + 1 + corrimiento en 2 de la mitad
	}
	else{                           // en caso contrario el numero es PAR == FALSE o 0
	    CR = P4_Square(halfs[ciclo]) << 2;     // Se hace función de nuevo pero para la mitad de num
	                                // dando corrimiento a la izquierda en dos unidades (Chain Reaction
	   ciclo2--;
		return CR;                // En este caso PAR el resultado es igual a dicho corrimiento
   }
}

int asize(int value)     // Esta función sirve para determinar el tamaño de mi array y que el código funcione correctamente al volver al punto anterior
{                       // guardando los datos en orden y con halfs y odds (arrays) del tamaño ideal
    int size = 0; 
    while (1)
            {
                value = value >> 1;
                size++; 
                if (value == 1){
                    break; 
                }
            }
        return size; 
}

