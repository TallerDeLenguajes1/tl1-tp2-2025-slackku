#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CANTIDAD 5

struct compu
{
    int velocidad;        // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio;             // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu;       // Tipo de procesador (apuntador a cadena de caracteres)
} typedef PC;

PC crearComputadora(char *tipos);
void *cargarLista(PC *lista, char *tipos);
// void listarPcs(PC *listarPCs);
int main()
{
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    char *pTipos;
    pTipos = &tipos[0][0];
    PC *listaComputadoras = (PC *)malloc(CANTIDAD * sizeof(PC));
    srand(time(NULL));

    cargarLista(listaComputadoras, pTipos);

    return 0;
}

void *cargarLista(PC *lista, char *tipos)
{
    for (int i = 0; i < CANTIDAD; i++)
    {
        PC compu = crearComputadora(tipos);
        *lista = compu;
        lista++;
    }
}

PC crearComputadora(char *tipos)
{
    int tipoRandom = rand() % (6 - 0 + 1) + 0;
    tipos += (10 * tipoRandom);
    PC computadora;
    computadora.velocidad = rand() % (3 - 1 + 1) + 1;
    computadora.anio = rand() % (2024 - 2015 + 1) + 2015;
    printf("%d\n", computadora.anio);

    computadora.cantidad_nucleos = rand() % (8 - 1 + 1) + 1;
    computadora.tipo_cpu = tipos;

    tipos -= (10 * tipoRandom);

    return computadora;
}

// void listarPCs(PC listaCompus[], int cantidad)
// {
//     for (int i = 0; i < cantidad; i++)
//     {
//         printf("Velocidad: %d\n", listaCompus[i].velocidad);
//         printf("Anio: %d\n", listaCompus[i].anio);
//         printf("Cantidad Nucleos: %d\n", listaCompus[i].cantidad_nucleos);
//         // while (listaCompus[i].tipo_cpu != "\0")
//         // {
//         //     printf("%c", listaCompus[i].tipo_cpu);
//         //     listaCompus[i].tipo_cpu++;
//         // }
//     }
// }
