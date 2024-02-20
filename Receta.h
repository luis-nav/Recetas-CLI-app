void Receta::imprimir(double porcionesImpresas){
    cout << nombre << endl;
    cout << "Porciones: " << porcionesImpresas << endl;
    cout << "Ingredientes: " << endl;
    for (int i = 0; i < numeroIngredientes; i++)
    {
        if (ingredientes[i].nombre != ""){
            ingredientes[i].imprimir(porciones, porcionesImpresas);
        }
    }
    
}

bool Receta::existeIngrediente(string nombreIngrediente){
    for (int i = 0; i < numeroIngredientes; i++)
    {
        if (ingredientes[i].nombre == nombreIngrediente){
            return true;
        }
    }
    return false;
}

int Receta::indexIngrediente(string nombreIngrediente){
    for (int i = 0; i < numeroIngredientes; i++)
    {
        if (ingredientes[i].nombre == nombreIngrediente){
            return i;
        }
    }
    return -1;
}

int Receta::indexSiguienteIngrediente(){
    for (int i = 0; i < numeroIngredientes; i++){
        if (ingredientes[i].nombre == ""){
            return i;
        }
    }
    return -1;
}

string Receta::anadirIngrediente(string _nombre, double _cantidad, string _medida){
    if (existeIngrediente(_nombre)){
        return ""; 
    }
    int siguienteIngrediente = indexSiguienteIngrediente();

    if (siguienteIngrediente == -1){
        return "";
    }
    ingredientes[siguienteIngrediente].nombre = _nombre;
    ingredientes[siguienteIngrediente].cantidad = _cantidad;
    ingredientes[siguienteIngrediente].medida = _medida;

    return _nombre;
}

double Receta::modificarCantidad(int indexIngrediente, double nuevaCantidad){
    double cantidadAntigua = ingredientes[indexIngrediente].cantidad;
    ingredientes[indexIngrediente].cantidad = nuevaCantidad;

    return cantidadAntigua;
}

void Receta::limpiarIngredientes(){
    for (int i = 0; i < numeroIngredientes; i++)
    {
        ingredientes[i].nombre = "";
        ingredientes[i].cantidad = 0;
        ingredientes[i].medida = "";
    }
    
}