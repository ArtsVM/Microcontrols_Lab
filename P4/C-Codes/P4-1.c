// Arturo Vázquez Muñoz - A00570187
// Laboratorio de Microcontroladores 
// Práctica 4 - Problema 1 - Encuentra el elemnto único

#include <stdio.h> 
  
int main() 
{ 
    int arr[] =  {10, 1, 10, 3, 10, 1, 1, 2, 3, 3};                  // Aqui se coloca el array de números dejando un dígito sin repetir
    int n = sizeof(arr) / sizeof(arr[0]);                            // Se calcula el tamaño del array 
    printf("Único elememto del arreglo es = %d ", unico(arr, n));    // Se despliega el resultado, mandando llamar la función 'unico' 
    return 0; 
}

int unico(int arr[], int n) 
{ 
    int ones = 0, twos = 0, common_bit_mask;          // Inicialización de de variables tipo entero
 
    for (int i = 0; i < n; i++) {                     // Ciclo for para hacer un recorrido en todo el array                
        
        twos = twos | (ones & arr[i]);                // twos se encarga los que se repiden más de una vez. Se checa colocando el valor actual con un OR comparado
                                                      // con un AND del digito en la posición i en el array, con el valor actual de ones (si se cumple es un 'two')
        ones = ones ^ arr[i];                         // Se coge digito nuevo y se cambia de estado co un XOR

        common_bit_mask = ~(ones & twos);             // Se hace una mascara, de los ones AND twos para poder empalmarla con lo optenido arriba y filtrar
                                                      // cual realmente es un digito ya repetido y cual solo ha salido una vez en el barrido del for
        ones &= common_bit_mask;                      // Se filtra cual a salido solo una vez en el recorrido
  
        twos &= common_bit_mask;                      // Se filtra cual ya es un dígito repetido
    } 
  return ones;                                        // Se entrega el valor unico 
} 