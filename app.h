#include <iostream>
#include <algorithm> 

using namespace std;

struct Ingrediente{
    string nombre;
    double cantidad;
    string medida;

    Ingrediente(){
        nombre = "";
        cantidad = 0;
        medida = "";
    }
    void cambiarCantidad(double nuevaCantidad){
        cantidad = nuevaCantidad;
    }
    double calcularCantidad(double proporcion, double porciones){
        return ((cantidad*porciones)/proporcion);
    }
    void imprimir(double proporcion, double porciones){
        cout << nombre << ":  " << calcularCantidad(proporcion, porciones) << " " << medida << endl;
    }
};

struct Receta{
    string nombre;
    double porciones;
    int numeroIngredientes;
    Ingrediente ingredientes[30];

    Receta(){
        nombre = "";
        porciones = 0;
        numeroIngredientes = 30;
    }

    void imprimir(double porcionesImpresas);
    bool existeIngrediente(string nombreIngrediente);
    int indexIngrediente(string nombreIngrediente);
    int indexSiguienteIngrediente();
    string anadirIngrediente(string _nombre, double _cantidad, string _medidas);
    double modificarCantidad(int indexIngrediente, double nuevaCantidad);
    void limpiarIngredientes();
};

struct BaseDeDatos
{
    Receta recetas[100];
    int numeroRecetas;

    BaseDeDatos(){
        numeroRecetas = 100;
    }

    string agregarReceta(string _nombre, double _porciones);
    int siguienteCampoLibre();
    int buscarReceta(string nombreReceta);
    string borrarReceta(int indexReceta);
    string cambiarNombre(int indexReceta, string nuevoNombre);
    void imprimir();
};

void app();

void menuAgregarReceta();
void menuBuscarReceta();
void menuBorrarReceta();
// void menuImprimirTodo();
void menuModificarNombreReceta();
void menuModificarCantidadIngrediente();
void menuAgregarIngredientePrincipal();
void menuCalcularPorciones();

void menuAgregarIngrediente(int indexReceta);
int menuBuscarRecetaIndex();
void menuAgregarVariosIngredientes(string nombre);

// Utils:
double inputDouble();
void pause();

// Global:
BaseDeDatos* RECETASDB = new BaseDeDatos();

#include "Receta.h"
#include "BaseDeDatos.h"
#include "utils.h"
#include "Menus.h"