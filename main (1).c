#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.c"

int main()
{
    char nombres[10][50];
    float precios[10];
    int n = 0, opcion;
    char nombreBuscar[50];

    printf("Ingrese la cantidad de productos (maximo 10): ");
    while (n < 1 || n > 10)
    {
        n = valida_int();
        if (n < 1 || n > 10)
        {
            printf("ERROR\nIngrese un numero de 1 a 10:\n");
        }
    }

    ingresarDatos(nombres, precios, n);

    do
    {
        printf("==== MENU ====\n");
        printf("1. Mostrar precio total del inventario\n");
        printf("2. Mostrar producto mas caro y mas barato\n");
        printf("3. Calcular precio promedio\n");
        printf("4. Buscar producto por nombre\n");
        printf("5. Mostrar todos los productos\n");
        printf("0. Salir\n");
        printf("Elija una opcion: ");

        opcion = valida_int();

        switch (opcion)
        {
        case 1:
            printf("Precio total del inventario: $%.2f\n", calcularTotal(precios, n));
            break;
        case 2:
            productoCaroBarato(nombres, precios, n);
            break;
        case 3:
            printf("Precio promedio: $%.2f\n", calcularPromedio(precios, n));
            break;
        case 4:
            printf("Ingrese el nombre del producto a buscar: ");
            fgets(nombreBuscar, 50, stdin);
            nombreBuscar[strcspn(nombreBuscar, "\n")] = '\0';
            buscarProducto(nombres, precios, n, nombreBuscar);
            break;
        case 5:
            mostrarProductos(nombres, precios, n);
            break;
        case 0:
            printf("Saliendo del programa...\n");
            break;
        default:
            printf("Opcion invalida. Intente nuevamente.\n");
        }
        if (opcion != 0)
        {
            printf("\nPresione ENTER para continuar...\n");
            getchar();
        }

    } while (opcion != 0);

    return 0;
}
