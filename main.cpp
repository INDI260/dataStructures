#include <iostream>
#include <sstream>
#include "Diccionarios.h"
#include "Palabra.h"
#include "indice.h"
#include "DiccionarioInverso.h"

using namespace std; 
int main() {
  
    Diccionarios sistema1;// aqui se crea la instancia sistema
    DiccionarioInverso sistema2;
    string linea; // donde se guarda las lineas 
    string comando;
    string argumento;
    string otro = "";

  cout << ":'######:::'######::'########:::::'###::::'########::'########::'##:::::::'########:" << endl;
  cout << "'##... ##:'##... ##: ##.... ##:::'## ##::: ##.... ##: ##.... ##: ##::::::: ##.....::" << endl;
  cout << " ##:::..:: ##:::..:: ##:::: ##::'##:. ##:: ##:::: ##: ##:::: ##: ##::::::: ##:::::::" << endl;
  cout << ". ######:: ##::::::: ########::'##:::. ##: ########:: ########:: ##::::::: ######:::" << endl;
  cout << ":..... ##: ##::::::: ##.. ##::: #########: ##.... ##: ##.... ##: ##::::::: ##...::::" << endl;
  cout << "'##::: ##: ##::: ##: ##::. ##:: ##.... ##: ##:::: ##: ##:::: ##: ##::::::: ##:::::::" << endl;
  cout << ". ######::. ######:: ##:::. ##: ##:::: ##: ########:: ########:: ########: ########:" << endl;
  cout << ":......::::......:::..:::::..::..:::::..::........:::........:::........::........::" << endl;

  cout << "\n\nBienvenido al sistema de apoyo para Scrabble" << endl << endl;
  cout << "Escriba ayuda para ver la lista de comandos disponibles o ingrese ayuda seguido del nombre del comando para obtener informacion sobre el" << endl;

    while (true) {
        cout << "$";
        getline(cin, linea);
        istringstream stream(linea);
        stream >> comando;

      // no se puede usar un switch case con string entonces toca con if or else if 


        if (comando == "salir") {
            break;
        } else if (comando == "inicializar" || comando == "iniciar_inverso" || comando == "puntaje"|| comando == "ayuda") {
            stream >> argumento;
            stream >> otro;
            if(otro != ""){
                cout << "El comando " << comando << " solo puede llevar maximo un argumento " << endl;
              otro = "";
            }
            else if (comando == "ayuda") {
                sistema1.ayuda(argumento);
            }else if (comando == "inicializar"){
              sistema1.inicializarDiccionario(argumento);
            } else if (comando == "iniciar_inverso") {
                sistema2.inicializarInverso(argumento);
            } else if (comando == "puntaje") {
                if(sistema1.getDiccionarioInicializado() && sistema2.getDiccionarioInversoInicializado()){
                  if(!sistema1.puntajePalabra(argumento)){
                    if(!sistema2.puntajePalabra(argumento)){
                        cout<<"la palabra no existe en el diccionario"<<endl;
                    }
                  }
                }else{
                  if(!sistema1.getDiccionarioInicializado())
                    cout << "El diccionario no ha sido inicializado" << endl;
                  if(!sistema2.getDiccionarioInversoInicializado())
                    cout << "El diccionario inverso no ha sido inicializado" << endl;
                }
            }
        } else {
            cout << "Comando no reconocido." <<endl;
        }
      argumento = "";
      otro = "";
    }

    return 0;
}
