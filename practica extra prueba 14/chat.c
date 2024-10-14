#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 100 // Máximo número de clientes
#define MAX_NOMBRE 50    // Longitud máxima de nombres

// Estructura para almacenar la información del cliente
typedef struct {
    char dni[20];
    char nombre[MAX_NOMBRE];
    char apellido[MAX_NOMBRE];
    char sexo; // 'M' para masculino, 'F' para femenino
    int edad;
    char celular[20];
} Cliente;

// Estructura para almacenar la información de la compra
typedef struct {
    float precio;
    int idProducto;
    Cliente cliente;
} Compra;

// Prototipos de funciones
void ingresarClientes(Compra compras[], int *n);
int buscarCliente(Compra compras[], int n, char* nombre, char sexo, float precioMin);
void almacenarMayoresDeEdad(Compra compras[], int n, Cliente mayores[], int* count);
void ordenarClientes(Cliente clientes[], int n);
int buscarClientePorNombre(Cliente clientes[], int n, char* nombre);
float promedioPreciosFemeninos(Compra compras[], int n);
float porcentajeMujeres(Compra compras[], int n);

int main() {
    Compra compras[MAX_CLIENTES];
    int n = 0; // Contador de compras

    // Ingresar datos de clientes
    ingresarClientes(compras, &n);

    // Buscar cliente específico
    char nombreBuscado[MAX_NOMBRE] = "Pedro";
    char sexoBuscado = 'M';
    float precioMinimo = 50.0;
    if (buscarCliente(compras, n, nombreBuscado, sexoBuscado, precioMinimo)) {
        printf("Cliente %s encontrado.\n", nombreBuscado);
    } else {
        printf("Cliente no existe.\n");
    }

    // Almacenar mayores de edad
    Cliente mayores[MAX_CLIENTES];
    int countMayores = 0;
    almacenarMayoresDeEdad(compras, n, mayores, &countMayores);

    // Ordenar mayores de edad
    ordenarClientes(mayores, countMayores);
    printf("\nClientes mayores de edad ordenados:\n");
    for (int i = 0; i < countMayores; i++) {
        printf("%s %s, Edad: %d\n", mayores[i].nombre, mayores[i].apellido, mayores[i].edad);
    }

    // Buscar cliente por nombre en el arreglo ordenado
    buscarClientePorNombre(mayores, countMayores, "Pedro");
    buscarClientePorNombre(mayores, countMayores, "Julia");

    // Calcular promedio de precios de clientes femeninos mayores de edad
    float promedioFemeninos = promedioPreciosFemeninos(compras, n);
    printf("\nPromedio de precios de productos comprados por mujeres mayores de edad: %.2f\n", promedioFemeninos);

    // Calcular porcentaje de clientes mujeres
    float porcentajeMujeresCompradoras = porcentajeMujeres(compras, n);
    printf("Porcentaje de mujeres que compraron: %.2f%%\n", porcentajeMujeresCompradoras);

    return 0;
}

// Función 1: Ingresar datos de clientes
void ingresarClientes(Compra compras[], int *n) {
    printf("Ingrese la cantidad de clientes (máximo %d): ", MAX_CLIENTES);
    int cantidad;
    scanf("%d", &cantidad);
    if (cantidad > MAX_CLIENTES) {
        cantidad = MAX_CLIENTES; // Limitar la cantidad a MAX_CLIENTES
    }

    for (int i = 0; i < cantidad; i++) {
        printf("\nIngrese los datos del cliente %d:\n", i + 1);
        printf("DNI: ");
        scanf("%s", compras[i].cliente.dni);
        printf("Nombre: ");
        scanf("%s", compras[i].cliente.nombre);
        printf("Apellido: ");
        scanf("%s", compras[i].cliente.apellido);
        printf("Sexo (M/F): ");
        scanf(" %c", &compras[i].cliente.sexo);
        printf("Edad: ");
        scanf("%d", &compras[i].cliente.edad);
        printf("Celular: ");
        scanf("%s", compras[i].cliente.celular);
        printf("Precio del producto: ");
        scanf("%f", &compras[i].precio);
        printf("ID del producto: ");
        scanf("%d", &compras[i].idProducto);
    }

    *n = cantidad; // Actualizar el contador de compras
}

// Función 2: Buscar cliente
int buscarCliente(Compra compras[], int n, char* nombre, char sexo, float precioMin) {
    for (int i = 0; i < n; i++) {
        if (strcmp(compras[i].cliente.nombre, nombre) == 0 && 
            compras[i].cliente.sexo == sexo && 
            compras[i].precio > precioMin) {
            printf("DNI: %s, Nombre: %s, Apellido: %s, Sexo: %c, Edad: %d, Celular: %s\n",
                   compras[i].cliente.dni,
                   compras[i].cliente.nombre,
                   compras[i].cliente.apellido,
                   compras[i].cliente.sexo,
                   compras[i].cliente.edad,
                   compras[i].cliente.celular);
            return 1; // Cliente encontrado
        }
    }
    return 0; // Cliente no encontrado
}

// Función 3: Almacenar mayores de edad
void almacenarMayoresDeEdad(Compra compras[], int n, Cliente mayores[], int* count) {
    for (int i = 0; i < n; i++) {
        if (compras[i].cliente.edad >= 18) {
            mayores[*count] = compras[i].cliente; // Almacenar solo la información relevante
            (*count)++;
        }
    }
}

// Función 4: Ordenar clientes
void ordenarClientes(Cliente clientes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Comparar por nombre y edad
            if (strcmp(clientes[j].nombre, clientes[j + 1].nombre) > 0 || 
               (strcmp(clientes[j].nombre, clientes[j + 1].nombre) == 0 && 
                clientes[j].edad > clientes[j + 1].edad)) {
                Cliente temp = clientes[j];
                clientes[j] = clientes[j + 1];
                clientes[j + 1] = temp;
            }
        }
    }
}

// Función 5: Buscar cliente por nombre
int buscarClientePorNombre(Cliente clientes[], int n, char* nombre) {
    for (int i = 0; i < n; i++) {
        if (strcmp(clientes[i].nombre, nombre) == 0) {
            printf("Cliente %s encontrado en la posición: %d\n", nombre, i);
            return i; // Retorna la posición
        }
    }
    printf("Cliente %s no existe.\n", nombre);
    return -1; // Cliente no encontrado
}

// Función 6: Calcular promedio de precios de clientes femeninos mayores de edad
float promedioPreciosFemeninos(Compra compras[], int n) {
    float suma = 0.0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (compras[i].cliente.sexo == 'F' && compras[i].cliente.edad >= 18) {
            suma += compras[i].precio;
            count++;
        }
    }
    return (count > 0) ? (suma / count) : 0.0; // Evitar división por cero
}

// Función 7: Calcular porcentaje de clientes mujeres
float porcentajeMujeres(Compra compras[], int n) {
    int countMujeres = 0;
    for (int i = 0; i < n; i++) {
        if (compras[i].cliente.sexo == 'F') {
            countMujeres++;
        }
    }
    return (n > 0) ? ((float)countMujeres / n * 100) : 0.0; // Evitar división por cero
}
