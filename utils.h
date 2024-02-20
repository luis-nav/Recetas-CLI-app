double inputDouble(){
    while (true){
        string input;
        getline(cin,input);
        double output;
        try
        {
            output = stod(input);
            return output;
        }
        catch(const invalid_argument e)
        {
            cout << "Dato invalido!" << endl;
        }
        
    }
}

void pause(){
    string basura;
    cout << endl << endl << "Presione ENTER para continuar";
    getline(cin,basura);
    cout << endl << endl;
}