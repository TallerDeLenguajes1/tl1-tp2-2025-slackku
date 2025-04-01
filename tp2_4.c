#include <stdio.h>
#include <stdlib.h>
struct compu
{
    int velocidad;        // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio;             // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu;       // Tipo de procesador (apuntador a cadena de caracteres)
} typedef PC;

PC crearComputadora(char *tipos);

int main()
{
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

    PC compu1 = crearComputadora(tipos);
    PC compu2 = crearComputadora(tipos);
    PC compu3 = crearComputadora(tipos);
    PC compu4 = crearComputadora(tipos);
    PC compu5 = crearComputadora(tipos);


    return 0;
}

PC crearComputadora(char *tipos)
{
    PC computadora = {
        rand() % (4 - 1 + 1) + 1,
        rand() % (2025 - 2015 + 1) + 2015,
        rand() % (9 - 1 + 1) + 1,
        tipos[rand() % 6]};
    return computadora;
}