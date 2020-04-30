/*EJERCICIO #3*/


#include <fstream>
#include <iostream>
#include <string>
using namespace std;
struct vehiculos{
	string placa;
	string marca;
	int anho;
	float precio;
};
void mp();	/*definicion de la funcion*/ 
void inventario();
void leer_archivo();
int main(){	
	mp();	
	//return 0;
}
void mp(){	/*menu principal*/
	
	int resp;
	
	do{
		system("CLS");
		cout<<"__________________________________"<<"\n"<<"\n";
		cout<<"	MENU DE VEHICULOS"<<"\n";
		cout<<"__________________________________"<<"\n"<<"\n";
		cout<<"1 . Ingresa un vehiculo "<<"\n";
		cout<<"2 . Inventario de vehiculos "<<"\n";
		cout<<"3 . Salir"<<"\n";
		cout<<"__________________________________"<<"\n"<<"\n";
		cout<<" Selecciona una opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			inventario();			
		}
		else if (resp==2){		
			system("CLS");
			leer_archivo();
		}			
		else if (resp==3)
			break;
		else 
			break;
		
	} while(resp!=3);	
}
void inventario(){
	string placa_v;
	string marca_v;
	int anho_v;
	float precio_v;
	ofstream archivo; /*grabar archivo*/
	fflush(stdin);
	
	cout<<"__________________________________"<<"\n"<<"\n";
	cout<<"	REGISTRO DE VEHICULO"<<"\n";
	cout<<"__________________________________"<<"\n"<<"\n";
	cout<<"Ingresa la placa: "<<endl;
	getline(cin,placa_v);
	fflush(stdin);
	cout<<"Ingresa la marca: "<<endl;
	getline(cin,marca_v);
	cout<<"Ingresa el año: "<<endl;
	cin>>anho_v;	
	cout<<"Ingresa el precio: "<<endl;
	cin>>precio_v;
	
	archivo.open("HT3_EJERCICIO_03.txt",ios::app);	/*abrir archivo append*/
	archivo<<placa_v<<"\t"<<marca_v<<"\t"<<anho_v<<"\t"<<precio_v<<endl;
	archivo.close();	
}
void leer_archivo(){
	ifstream archivo;	/*leer archivo*/
	archivo.open("HT3_EJERCICIO_03.txt",ios::in);	/*leer archivo*/
	int lineas,i=0;
	string s,linea;	
	while (getline(archivo, s))
        lineas++;
	archivo.close();
	
	vehiculos recordset[lineas];
	
	archivo.open("HT3_EJERCICIO_03.txt",ios::in);
	if(archivo.fail()){
		cout<<"ERROR AL CARGAR EL ARCHIVO...";
		exit(1);
	}	
	/*Leer datos del archivo*/
	for (int i = 0; i < lineas; i++)
    {
        if (!archivo)
        {                                               
            cerr << "ERROR AL CARGAR EL ARCHIVO..." << endl;
            system("PAUSE");
        }
        archivo>>recordset[i].placa>>recordset[i].marca>>recordset[i].anho>>recordset[i].precio;
    }
    archivo.close(); 
    
    cout<<"________________________________________________________"<<"\n"<<"\n";
    cout<<"		INVENTARIO DE VEHICULOS	"<<"\n";
   	cout<<"________________________________________________________"<<"\n"<<"\n";
    cout<<"PLACA		MARCA		AÑO		PRECIO"<<"\n"<<"\n";
    
    for(int i = 0; i <lineas; i++){
    	
    	cout<<recordset[i].placa<<"\t\t"<<recordset[i].marca<<"\t\t"<<recordset[i].anho<<"\t\t"<<recordset[i].precio<<"\n";
	}
		cout<<"\n";
	system("Pause");
	

}
