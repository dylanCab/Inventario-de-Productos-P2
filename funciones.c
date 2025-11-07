#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

void ingresarDatos(char nombres[][50], float precios[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        fgets(nombres[i], 50, stdin);
        nombres[i][strcspn(nombres[i], "\n")]='\0';
        printf("Ingrese el precio del producto %d: ", i + 1);
        precios[i]=valida_float();
    }
}

float calcularTotal(float precios[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++)
        total += precios[i];
    return total;
}

float calcularPromedio(float precios[], int n) {
    return calcularTotal(precios, n) / n;
}

void productoCaroBarato(char nombres[][50], float precios[], int n) {
    int idxMax = 0, idxMin = 0;
    for (int i = 1; i < n; i++) {
        if (precios[i] > precios[idxMax]) idxMax = i;
        if (precios[i] < precios[idxMin]) idxMin = i;
    }
    printf("Producto mas caro: %s ($%.2f)\n", nombres[idxMax], precios[idxMax]);
    printf("Producto mas barato: %s ($%.2f)\n", nombres[idxMin], precios[idxMin]);
}

void buscarProducto(char nombres[][50], float precios[], int n, char nombreBuscar[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(nombres[i], nombreBuscar) == 0) {
            printf("El producto '%s' cuesta $%.2f\n", nombres[i], precios[i]);
            break;
        }
        printf("Producto no encontrado.\n");
        break;
    }
    
}

void mostrarProductos(char nombres[][50], float precios[], int n) {
    printf("\n--- LISTA DE PRODUCTOS ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - $%.2f\n", i + 1, nombres[i], precios[i]);
    }
}
int valida_int(){
    char vec[30];
    int valid;
    do{
        fgets(vec, 30, stdin);
        vec[strcspn(vec, "\n")]='\0';
        valid=0;
        int len=strlen(vec);
        for(int i=0;i<len;i++){
            if(isdigit(vec[i])){
                valid+=0;
            }else{
                valid+=1;
            }
        }
        if(valid>0){
            printf("ERROR\nIngrese un numero valido:");
        }
    }while(valid>0);
    return atoi(vec);
}

float valida_float(){
    char vec[30];
    int valid;
    do{
        fgets(vec, 30, stdin);
        vec[strcspn(vec, "\n")]='\0';
        valid=0;
        int len=strlen(vec);
        for(int i=0;i<len;i++){
            if(isdigit(vec[i])||vec[i]=='.'){
                valid+=0;
            }else{
                valid+=1;
            }
        }
        if(valid>0){
            printf("ERROR\nIngrese un numero valido:");
        }
    }while(valid>0);
    return atof(vec);
}