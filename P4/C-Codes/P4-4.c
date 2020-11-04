#include <stdio.h>

int main()
{
    unsigned int N, Grayinput;         // declaración de variables enteras sin signo 
    printf("Ingresar número para generar patrones de 0 a 2^(n-1) = ");     // Se pide al usuario ingresar número de N
    scanf("%i", &N);                                                       // Se le asigna a variable N con AND
    printf("Gray Code (n = %i): \n",N);
    for (int i = 0; i < (1<<N); ++i){   // Ciclo for hasta que llegue a los 2^(n-1)
        Grayinput = i ^ (i >> 1);       // Se calcula el número que controla a posición del código Gray
        printbin(Grayinput);            // Se manda llamar la función que imprime el código gray
        printf("\n");                   // Se imprime un enter para dar seguimiento al siguiente dígito
    }
    return 0;
}

void printbin(int n){
    if (!n) printf("0");      // Se imprime un 0. Caso error
    while (n) {
        if (n & 1)            // Con operador AND
            printf("1");      // Se imprime un 1
        else
            printf("0");      // Se imprime un 0
        n >>= 1;
    }
}
