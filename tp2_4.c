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
void listarPCs(PC *listarPCs);
void mostrarMasVieja(PC *listarPCs);
int main()
{
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    char *pTipos;
    pTipos = &tipos[0][0];
    PC *listaComputadoras = (PC *)malloc(CANTIDAD * sizeof(PC));
    srand(time(NULL));

    cargarLista(listaComputadoras, pTipos);
    listarPCs(listaComputadoras);

    mostrarMasVieja(listaComputadoras);

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
    int tipoRandom = rand() % (5 - 0 + 1) + 0;
    tipos += (10 * tipoRandom);
    PC computadora;
    computadora.velocidad = rand() % (3 - 1 + 1) + 1;
    computadora.anio = rand() % (2024 - 2015 + 1) + 2015;
    computadora.cantidad_nucleos = rand() % (8 - 1 + 1) + 1;
    computadora.tipo_cpu = tipos;
    return computadora;
}

void listarPCs(PC *listaCompus)
{
    for (int i = 0; i < CANTIDAD; i++)
    {
        printf("======= MAQUINA %d =======\n", i + 1);
        printf("Velocidad: %d\n", listaCompus->velocidad);
        printf("Anio: %d\n", listaCompus->anio);
        printf("Cantidad Nucleos: %d\n", listaCompus->cantidad_nucleos);
        printf("Tipo CPU: ");
        for (int j = 0; listaCompus->tipo_cpu[j] != '\0'; j++)
        {
            printf("%c", listaCompus->tipo_cpu[j]);
        }
        printf("\n");
        printf("==========================\n");

        listaCompus++;
    }
}

void mostrarMasVieja(PC *listaPC)
{
    PC *vieja = listaPC;
    for (int i = 0; i < CANTIDAD; i++)
    {
        if (listaPC->anio < vieja->anio)
        {
            vieja = listaPC;
        }
        listaPC++;
    }

    printf("======= MAQUINA MAS VIEJA =======\n");
    printf("Velocidad: %d\n", vieja->velocidad);
    printf("Anio: %d\n", vieja->anio);
    printf("Cantidad Nucleos: %d\n", vieja->cantidad_nucleos);
    printf("Tipo CPU: ");
    for (int j = 0; vieja->tipo_cpu[j] != '\0'; j++)
    {
        printf("%c", vieja->tipo_cpu[j]);
    }
    printf("\n");
    printf("==========================\n");
}