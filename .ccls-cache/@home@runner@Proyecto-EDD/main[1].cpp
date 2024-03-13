//#include "ScrabbleSupportSystem.h" // Esto seria igual que lo de sistema 

// para leer los arhivos 
#include <iostream>
#include <sstream>

using namespace std; 
int main() {
    ScrabbleSupportSystem sistema;// aqui se crea la instancia sistema
    
    
	cout << ":'######:::'######::'########:::::'###::::'########::'########::'##:::::::'########:" << endl;
	cout << "'##... ##:'##... ##: ##.... ##:::'## ##::: ##.... ##: ##.... ##: ##::::::: ##.....::" << endl;
	cout << " ##:::..:: ##:::..:: ##:::: ##::'##:. ##:: ##:::: ##: ##:::: ##: ##::::::: ##:::::::" << endl;
	cout << ". ######:: ##::::::: ########::'##:::. ##: ########:: ########:: ##::::::: ######:::" << endl;
	cout << ":..... ##: ##::::::: ##.. ##::: #########: ##.... ##: ##.... ##: ##::::::: ##...::::" << endl;
	cout << "'##::: ##: ##::: ##: ##::. ##:: ##.... ##: ##:::: ##: ##:::: ##: ##::::::: ##:::::::" << endl;
	cout << ". ######::. ######:: ##:::. ##: ##:::: ##: ########:: ########:: ########: ########:" << endl;
	cout << ":......::::......:::..:::::..::..:::::..::........:::........:::........::........::" << endl;

    while (true) {
        cout << "$";
        getline(cin, linea);
        istringstream stream(linea);
        stream >> comando;

      // no se puede usar un swicht switch case con string entonces toca con if or else if 


        if (comando == "salir") {
            break;
        } else if (comando == "inicializar" || comando == "iniciar_inverso" || comando == "puntaje"|| comando == "ayuda") {
            stream >> argumento;
            if (comando == "ayuda") {
                sistema.ayuda();
            }else if (comando == "inicializar"){
            	sistema.inicializarDiccionario(argumento);
            } else if (comando == "iniciar_inverso") {
                sistema.iniciarInverso(argumento);
            } else if (comando == "puntaje") {
            	sistema.puntajePalabra(argumento);
            }
        } else {
            cout << "Comando no reconocido." <<endl;
        }
    }

    return 0;
}
