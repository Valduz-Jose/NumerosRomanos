#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<iomanip>
using namespace std;
int main(){
	
	//leer archivo
	ifstream Archivo;
	string texto;
	int numero=0,unidades,decenas,centenas,millares;
	Archivo.open("romanos.txt",ios::in);//abrir en modo lectura
	if(Archivo.fail()){
		cout<<"No se puede abrir el archivo";
		exit(1);
	}
	//
	
	//crear archivo de escritura
	ofstream archivo;
	archivo.open("salidaromanos.txt",ios::out);//abrir
	//verifico errores de apertura
	if(archivo.fail()){
		exit(1);//salida inmediata del programa
	}
	//
	while(!Archivo.eof()){
		getline(Archivo,texto);
		numero= stoi(texto);
	//	cout<<right<<setw(20)<<fixed<<numero<<"    "<<endl;
		if(numero==0){
			exit(1);
		}else{
			if(numero>3500){
				cout<<"Existe un criterio de calculo hasta el 3500 y "<<numero<<" excede ese limite"<<endl;
			}else{
				//
				archivo<<left<<setw(5)<<numero<<"    ";//escribo en el archivo el left y setw me ayudan a la alineacion del mismo
				/*Esto se hace para separar el numero,
				 tomen como ejemplo el numero 2103, a ese numero
				 lo debemos transformar de la manera siguiente: 
				 2 - 1 - 0 - 3 donde 3 va a ocupar la unidades, 
				 0 las decenas, 1 las centenas y 2 los millares*/
				
				 unidades = numero % 10; numero /= 10;
				 decenas = numero % 10; numero /= 10;
				 centenas = numero % 10; numero /= 10;
				 millares = numero % 10; numero /= 10;
				//archivo<<right<<setw(10)<<fixed;
				 switch (millares)
				 {
				  case 1: archivo<<"M"; break;
				  case 2: archivo<<"MM"; break;
				  case 3: archivo<<"MMM"; break;
				 }
				 
				 switch (centenas)
				 {
				  case 1: archivo<<"C"; break;
				  case 2: archivo<<"CC"; break;
				  case 3: archivo<<"CCC"; break;
				  case 4: archivo<<"CD"; break;
				  case 5: archivo<<"D"; break;
				  case 6: archivo<<"DC"; break;
				  case 7: archivo<<"DCC"; break;
				  case 8: archivo<<"DCCC"; break;
				  case 9: archivo<<"CM"; break; 
				 }
				 
				 switch (decenas)
				 {
				  case 1: archivo<<"X"; break;
				  case 2: archivo<<"XX"; break;
				  case 3: archivo<<"XXX"; break;
				  case 4: archivo<<"XL"; break;
				  case 5: archivo<<"L"; break;
				  case 6: archivo<<"LX"; break;
				  case 7: archivo<<"LXX"; break;
				  case 8: archivo<<"LXXX"; break;
				  case 9: archivo<<"XC"; break; 
				 }
				 
				 switch (unidades)
				 {
				  case 1: archivo<<"I"; break;
				  case 2: archivo<<"II"; break;
				  case 3: archivo<<"III"; break;
				  case 4: archivo<<"IV"; break;
				  case 5: archivo<<"V"; break;
				  case 6: archivo<<"VI"; break;
				  case 7: archivo<<"VII"; break;
				  case 8: archivo<<"VIII"; break;
				  case 9: archivo<<"IX"; break;
				 }
				 archivo<<endl;
				//	
			}	
		}
		
	}
	Archivo.close();
	//archivo<<;//escribo en el archivo
	archivo.close();
	return 0;
}
/*
Universidad Nacional Experimental del Táchira
Ingenieria Informatica
Programacion 2 Profesor Marcel Molina
Autor: José Alejandro Valduz Contreras
