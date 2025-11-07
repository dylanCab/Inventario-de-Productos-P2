#ifndef FUNCIONES_H
#define FUNCIONES_H

void ingresarDatos(char nombres[][50], float precios[], int n);
float calcularTotal(float precios[], int n);
float calcularPromedio(float precios[], int n);
void productoCaroBarato(char nombres[][50], float precios[], int n);
void buscarProducto(char nombres[][50], float precios[], int n, char nombreBuscar[]);
void mostrarProductos(char nombres[][50], float precios[], int n);
int valida_int();
float valida_float();

#endif