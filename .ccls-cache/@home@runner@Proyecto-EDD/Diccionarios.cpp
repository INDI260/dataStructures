#include "Diccionarios.h"
#include"indice.h"
#include<iostream>
#include<fstream>

#include <cctype> 
using namespace std;
void Diccionarios::inicializarDiccionario(std::string rutaArchivo) {
    std::ifstream myfile(rutaArchivo);
    std::string linea;
    int contador=0;

    
    if(!myfile.is_open()){
        cout<<"El archivo no existe"<<endl;
        
    }else if (diccionarioInicializado){
        cout<<"El archivo ya fue ejecutado"<<endl;
        
    } 
    
  
    
    
    if(myfile.is_open() && !diccionarioInicializado){
        contador=0;
        
          while(getline(myfile,linea)){
        
            for (char c: linea) { 
            // 65-90,97-122
                if ((c >=65 && c <= 90 )||( c>=97 && c<= 122 )) {
                }else{
                    contador++;
                }
              
            }
            int encontro =0;
             
            if(contador==0){
                
                list<indice>::iterator it;
                for(it=indices.begin();it!=indices.end();it++){
                   linea[0] = toupper(linea[0]);
                    if(linea[0]==it->getLetra()){//toupper
                        
                        it->agregarPalabra(linea);
                        encontro ++;
                    }
                }
                if(encontro==0){
                    linea[0] = toupper(linea[0]);
                    indice i(linea[0]);//toupper se maneja desde el constructor 
                    i.agregarPalabra(linea);
                    indices.push_back(i);
                }
                
                diccionarioInicializado=true;
            }
        }
        cout<<"El diccionario se ha inicializado correctamente."<<endl;
        
        // impresion:
    
        list<indice>::iterator it;
        for(it=indices.begin();it!=indices.end();it++){
            cout<<"\n indice: "<<it->getLetra()<<endl;
            vector<Palabra>aux = it->getPalabras();
            for(Palabra p: aux){
                cout<<p.getPalabra()<<endl;
            }
        }
        
    }
    
    
}
bool Diccionarios::puntajePalabra(std::string palabra){
    
    for (char c: palabra) { 
        // 65-90,97-122
        if ((c >=65 && c <= 90 )||( c>=97 && c<= 122 )) {
        }else{
            cout<<"La palabra contiene símbolos inválidos."<<endl;
            return true;
        
        }
              
    }
    
    palabra[0]=toupper(palabra[0]);
    list<indice>::iterator it;
    for(it=indices.begin();it!=indices.end();it++){
        vector<Palabra>aux = it->getPalabras();
        for(Palabra p:aux){
            if(p.getPalabra()==palabra){
                cout<<"la palabra contien un valor de ";
                cout<<p.calcularPuntaje()<<endl;
                return true;
            }
        }
    }
    return false;
}



//Muestra al usuario los comandos disponibles y los explica
void Diccionarios::ayuda(string x) {
    
  if(x == ""){
    cout << endl << endl << " Los comandos disponibles son: " << endl << endl;
    cout << "\tinicializar" << endl;
    cout<< "\tiniciar_inverso" << endl;
    cout << "\tpuntaje" << endl;
    cout << "\tiniciar_arbol" << endl;
    cout << "\tiniciar_arbol_inverso" << endl;
    cout << "\tpalabras_por_prefijo" << endl;
    cout << "\tpalabras_por_sufijo" <<endl;
    cout << "\tgrafo_de_palabras" << endl;
    cout << "\tposibles_palabras" << endl;
    cout << "\tayuda" << endl;
    cout << "\tsalir" << endl;
  }
  
  else if(x == "inicializar")
    cout << "Inicializa el sistema a partir del archivo de texto que contiene el diccionario en idioma ingles. Ejemplo: inicializar diccionario.txt " << endl;
    
  else if(x == "iniciar_inverso")
    cout << "Inicializa el sistema a partir del archivo de texto que contiene el diccionario en idioma ingles pero con las palabras invertidas. Ejemplo: iniciar_inverso diccionario.txt " <<endl;
    
  else if(x == "puntaje")
    cout << "Retorna el puntaje de una palabra. Ejemplo: puntaje palabra" <<endl;
    
  else if(x == "iniciar_arbol")
    cout << "Inicializa el sistema a partir del archivo de texto que contiene el diccionario en idioma ingles y lo almacena en forma de arbol. Ejemlo: iniciar_arbol diccionario.txt" << endl;
    
  else if(x == "iniciar_arbol_inverso")
    cout << "Inicializa el sistema a partir del archivo de texto que contiene el diccionario en idioma ingles pero con las palabras invertidas y lo almacena en forma de arbol. Ejemlo: iniciar_arbol_inverso diccionario.txt" << endl;
    
  else if(x == "palabras_por_prefijo")
    cout << "Presenta una lista de todas las palabras que empiezan con un determinado prefijo. Ejemplo: palabras_por_prefijo pre" << endl;
    
  else if (x == "palabras_por_sufijo")
    cout << "Presenta una lista de todas las palabras que terminan con un determinado sufijo. Ejemplo: palabras_por_sufijo ing" << endl;
    
  else if (x == "grafo_de_palabras")
    cout << "Construye un grafo con las palabras en el arbol en dodne cada palabra se conecta a las demas si y solo si difieren en una unica letra" << endl;
  
  else if (x == "posibles_palabras")
    cout << "Presenta una lista de todas las palabras que pueden ser construidas a partir de una cadena de caracteres. Ademas se permite el uso de un comodin (?) que representa una lestra desconocida para generar mayores posibilidades de palabras. Ejemplo: posibles_palabras ho?l" << endl;

  else if (x == "ayuda")
    cout << "Muestra la lista de comandos disponibles. Si se especifica un comando, muestra la descripcion de este. Ejemplo: ayuda puntaje" << endl;
    
  else if(x == "salir")
    cout << "Termina la ejecucion del programa." << endl;
    
  else
    cout << "El comando no existe." << endl;
}



