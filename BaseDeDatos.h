int BaseDeDatos::siguienteCampoLibre(){
    for (int i = 0; i < numeroRecetas; i++)
    {
        if(recetas[i].nombre == ""){
            return i;
        }
    }
    return -1;
}

string BaseDeDatos::agregarReceta(string _nombre, double _porciones){
    bool existe = (buscarReceta(_nombre) != -1);
    if (existe)
        return "";

    int campo = siguienteCampoLibre();

    if (campo == -1){
        return "";
    }

    recetas[campo].nombre = _nombre;
    recetas[campo].porciones = _porciones;

    return _nombre;
}

int BaseDeDatos::buscarReceta(string nombreReceta){
    for (int i = 0; i < numeroRecetas; i++)
    {
        if (recetas[i].nombre == nombreReceta){
            return i;
        }
    }
    return -1;
}

string BaseDeDatos::borrarReceta(int indexReceta){
    string nombreBorrado = recetas[indexReceta].nombre;
    recetas[indexReceta].nombre = "";
    recetas[indexReceta].porciones = 0;
    recetas[indexReceta].limpiarIngredientes();
    return nombreBorrado;

}

string BaseDeDatos::cambiarNombre(int indexReceta, string nuevoNombre){
    string nombreBorrado = recetas[indexReceta].nombre;
    bool existe = (buscarReceta(nuevoNombre) != -1);
    if (existe)
        return "";

    recetas[indexReceta].nombre = nuevoNombre;

    return nombreBorrado;
}

void BaseDeDatos::imprimir(){
    cout << endl << "=======================" << endl;
    for (int i = 0; i < numeroRecetas; i++)
    {
        if (recetas[i].nombre != ""){
            recetas[i].imprimir(recetas[i].porciones);
            cout << endl << "=======================" << endl;
        }
    }
}