void app(){
    string opcion = "";

    while (opcion != "9" && opcion != "salir"){
        cout << "********MENU********" << endl;
        cout << "1. Agregar Receta" << endl;
        cout << "2. Buscar Receta" << endl;
        cout << "3. Borrar Receta" << endl;
        cout << "4. Imprimir Recetas" << endl;
        cout << "5. Modificar Nombre de una Receta" << endl;
        cout << "6. Modificar Cantidad de un Ingrediente en una Receta" << endl;
        cout << "7. Agregar Ingrediente a una Receta" << endl;
        cout << "8. Calcular para Porciones" << endl;
        cout << "9. Salir" << endl;
        cout << endl << endl;

        getline(cin, opcion);
        transform(opcion.begin(), opcion.end(), opcion.begin(), ::tolower); //Vuelve el input a puras minusculas

        if (opcion == "1" || opcion == "agregar receta")
            menuAgregarReceta();

        else if (opcion == "2" || opcion == "buscar receta"){
            menuBuscarReceta();
        }

        else if (opcion == "3" || opcion == "borrar receta"){
            menuBorrarReceta();
        }

        else if (opcion == "4" || opcion == "imprimir recetas"){
            RECETASDB->imprimir();
            pause();
        }

        else if (opcion == "5" || opcion == "modificar nombre de una receta"){
            menuModificarNombreReceta();
        }
        
        else if (opcion == "6" || opcion == "modificar cantidad de un ingrediente en una receta"){
            menuModificarCantidadIngrediente();
        }
        
        else if (opcion == "7" || opcion == "agregar ingrediente a una receta"){
            menuAgregarIngredientePrincipal();
        }

        else if (opcion == "8" || opcion == "calcular para porcinones"){
            menuCalcularPorciones();
        }

        
    }

    cout << endl << "Hasta Pronto!" << endl << endl;
}

void menuAgregarReceta(){
    int campoDisponible = RECETASDB->siguienteCampoLibre();

    if (campoDisponible == -1){
        cout << "No se puede ingresar ya que la base de datos esta llena" << endl;
        pause();
        return;
    }

    string inNombre;
    double inPorciones;
    cout << "********Agregar Receta********" << endl;
    cout << "Ingrese el nombre de la receta:" << endl;
    getline(cin, inNombre);
    cout << "Ingrese el numero de porciones:" << endl;
    inPorciones = inputDouble();

    string nombre = RECETASDB->agregarReceta(inNombre, inPorciones);

    if (nombre == ""){
        cout << "No se pudo ingresar porque hay otra receta con el mismo nombre" << endl;
        pause();
        return;
    }

    menuAgregarVariosIngredientes(nombre);
    
    cout << "Se ingreso la receta " << nombre << " con exito!" << endl;
    pause();
}

void menuAgregarVariosIngredientes(string nombre) {
    string input = "";

    while (input != "n"){
        cout << "Quiere agregar un ingrediente?(s/n):  ";
        getline(cin, input);
        transform(input.begin(), input.end(), input.begin(), ::tolower); //Vuelve el input a puras minusculas

        if (input == "s"){
            menuAgregarIngrediente(RECETASDB->buscarReceta(nombre));
        } else if (input == "n"){
            break;
        }
        else
            cout << endl << "Esa no es una opcion valida!  " << endl;
    }
}

void menuAgregarIngrediente(int indexReceta){
    string inNombre, inCantidad, inMedida;
    double parsedCantidad;
    cout << "********Agregar Ingrediente************" << endl;
    cout << "Ingrese el nombre del ingrediente: " << endl;
    getline(cin, inNombre);
    cout << "Ingrese la cantidad del ingrediente:" << endl;
    parsedCantidad = inputDouble();
    cout << "Ingrese la medida del ingrediente(g,ml,kg,tbsp):" << endl;
    getline(cin, inMedida);
    cout << endl;
    string nombreIngresado = RECETASDB->recetas[indexReceta].anadirIngrediente(inNombre, parsedCantidad, inMedida);
    if (nombreIngresado == ""){
        cout << endl << "ERROR: Ya existe un ingrediente con ese nombre o la lista de ingredientes esta llena" << endl;
    } else{
        cout << endl << "Se ingreso el ingrediente " << nombreIngresado << " con exito!" << endl;
    }

    pause();
}

void menuBuscarReceta(){
    string input;
    cout << "Ingrese el nombre de la receta que desea buscar: ";
    getline(cin, input);
    int indexReceta = RECETASDB->buscarReceta(input);

    if (indexReceta == -1){
        cout << "No se encontro una receta con ese nombre!";
        pause();
        return;
    }

    RECETASDB->recetas[indexReceta].imprimir(RECETASDB->recetas[indexReceta].porciones);

    pause();
}

void menuBorrarReceta(){
    string input;
    cout << "Ingrese el nombre de la receta que desea borrar: ";
    getline(cin, input);
    int indexReceta = RECETASDB->buscarReceta(input);

    if (indexReceta == -1){
        cout << "No se encontro una receta con ese nombre!";
        pause();
        return;
    }

    string nombre = RECETASDB->borrarReceta(indexReceta);

    cout << "Se elimino " << nombre << " con exito!" << endl;

    pause();
}

void menuModificarNombreReceta(){
    string input, nuevoNombre;
    cout << "Ingrese el nombre de la receta que desea cambiarle el nombre: ";
    getline(cin, input);
    int indexReceta = RECETASDB->buscarReceta(input);

    if (indexReceta == -1){
        cout << "No se encontro una receta con ese nombre!";
        pause();
        return;
    }
    cout << "Ingrese el nuevo nombre que le quiere poner: " << endl;
    getline(cin,nuevoNombre);

    string nombreViejo = RECETASDB->cambiarNombre(indexReceta, nuevoNombre);
    if (nombreViejo == ""){
        cout << "El nombre nuevo de la receta ya existia" << endl;
        pause();
        return;
    }

    cout << "Se cambio el nombre de la receta " << nombreViejo << " por " << nuevoNombre << "!" << endl;
    pause();
}

void menuModificarCantidadIngrediente(){
    string inputReceta, inputIngrediente;
    cout << "Ingrese el nombre de la receta que desea editar: ";
    getline(cin, inputReceta);
    int indexReceta = RECETASDB->buscarReceta(inputReceta);

    if (indexReceta == -1){
        cout << "No se encontro una receta con ese nombre!";
        pause();
        return;
    }
    cout << "Ingrese el nombre del ingrediente que desea cambiar la cantidad: ";
    getline(cin, inputIngrediente);
    int indexIngrediente = RECETASDB->recetas[indexReceta].indexIngrediente(inputIngrediente);

    if (indexIngrediente == -1){
        cout << "No se encontro un ingrediente con ese nombre!";
        pause();
        return;
    }

    double viejaCantidad = RECETASDB->recetas[indexReceta].ingredientes[indexIngrediente].cantidad;
    string unidad = RECETASDB->recetas[indexReceta].ingredientes[indexIngrediente].medida;
    cout << "Ingrese la nueva cantidad de " << inputIngrediente << " (Actual: " << viejaCantidad << " " << unidad << "):" << endl;
    double nuevaCantidad = inputDouble();

    RECETASDB->recetas[indexReceta].modificarCantidad(indexIngrediente, nuevaCantidad);
    cout << "Se cambio la cantidad de " << inputIngrediente << " de " << viejaCantidad << " " << unidad << " a " << nuevaCantidad << " " << unidad << endl;
    pause();
}

void menuAgregarIngredientePrincipal(){
    string input;
    cout << "Ingrese el nombre de la receta a la cual quiere anadirle un ingrediente: ";
    getline(cin, input);
    int indexReceta = RECETASDB->buscarReceta(input);

    if (indexReceta == -1){
        cout << "No se encontro una receta con ese nombre!";
        pause();
        return;
    }

    menuAgregarIngrediente(indexReceta);
}

void menuCalcularPorciones(){
    string inputReceta;
    double porciones;
    cout << "Ingrese el nombre de la receta que quiere calcular: ";
    getline(cin, inputReceta);
    int indexReceta = RECETASDB->buscarReceta(inputReceta);

    if (indexReceta == -1){
        cout << "No se encontro una receta con ese nombre!";
        pause();
        return;
    }

    cout << "Ingrese el numero de porciones que desea: ";
    porciones = inputDouble();

    RECETASDB->recetas[indexReceta].imprimir(porciones);

    pause();
}