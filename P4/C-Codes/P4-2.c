// Arturo Vázquez Muñoz - A00570187
// Laboratorio de Microcontroladores 
// Práctica 4 - Problema 2 - Multiplicaciones y divisiones

#include<stdio.h>

unsigned int a, b, M;
int main() {
   
    printf("Primer dígito = ");        // Se pide al usuario el primer digito
    scanf("%d", &a);                   // Se le asigna a variable a con AND
    
    printf("Segundo dígito = ");       // Se pide al usuario el segundo digito
    scanf("%d", &b);                   // Se le asigna a variable b con AND

    printf("Multiplicación = %d \n" , multiply(a,b));   //Se imprimen los resultados de la función multiply
    printf("División = %d \n" , divide(a,b));           //Se imprimen los resultados de la función divide

    return 0;
}

int multiply(int a, int b){                                  // Función para hacer la multiplicación
    
    for (unsigned int i = 0; i < 32; i++)           // Ciclo for de 32 bits para sumar resultado cada que cumpla la condición
    {
        if (a & ( 1 << i))                          // Se checa con un AND cuando debe de entrar segun el valor de i 
        {
            M += (b << i);                          // Se suma el corrimiento a la izquierda del segundo dígito a i unidades
        }
    }
    return M;                                       // Se obtiene como salida el resultado final de la múltiplicación
}

int divide(long long a, long long b){                         // Función para hacer la división
     
long long int D = 0, temp = 0;                          // Se inicializan variables para obtener resultado

for (int i = 31; i >= 0; --i) {                     // Ciclo for para 32 bits en retroceso para división
  
    if (temp + (b << i) <= a) {                     // Se checa si la variable temp más el corrieminto a la izquierda en 'i' unidades del segundo dígito
                                                    //  es menor al primer dígito
      temp += b << i;                               // Se aumenta su tamaño haciendo corrimiento del  pr dígito a la izquierda en 'i' unidades
      D |= 1LL << i;                                // 1LL es igual a 1 en formato long lon. Se hace corrieminto de este hacia la izquierda en 'i' unidades
    } 
  } 
  return  D;                                        // Se obtiene como salida el resultado final de la división 
}