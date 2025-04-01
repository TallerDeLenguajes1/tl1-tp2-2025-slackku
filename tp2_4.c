#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 5

struct compu
{
    int velocidad;        // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio;             // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu;       // Tipo de procesador (apuntador a cadena de caracteres)
} typedef PC;

PC crearComputadora(char *tipos);
void listarPCs(PC listaCompus[], int cantidad);
int main()
{
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    char *pTipos = tipos;

    PC compu1 = crearComputadora(pTipos);
    PC compu2 = crearComputadora(pTipos);
    PC compu3 = crearComputadora(pTipos);
    PC compu4 = crearComputadora(pTipos);
    PC compu5 = crearComputadora(pTipos);

    PC listaCompus[CANTIDAD] = {compu1, compu2, compu3, compu4, compu5};

    listarPCs(listaCompus, CANTIDAD);

    return 0;
}

PC crearComputadora(char *tipos)
{
    PC computadora = {
        rand() % (4 - 1 + 1) + 1,
        rand() % (2025 - 2015 + 1) + 2015,
        rand() % (9 - 1 + 1) + 1,
        tipos += rand() % (6 - 1 + 1) + 1};
    return computadora;
}

void listarPCs(PC listaCompus[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        printf("Velocidad: %d\n", listaCompus[i].velocidad);
        printf("Anio: %d\n", listaCompus[i].anio);
        printf("Cantidad Nucleos: %d\n");
        while (listaCompus[i].tipo_cpu != "\0")
        {
            printf("%c", listaCompus[i].tipo_cpu);
            listaCompus[i].tipo_cpu++;
        }
    }
}
