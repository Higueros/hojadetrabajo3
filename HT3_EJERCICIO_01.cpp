#include <fstream>
#include <iostream>
#include <string>
using namespace std;
struct jugadores{
	string nombre;
	int edad;
	string nacio;
	float salario;
};
void mp();
void leer_archivo();
void grabar_archivo();
int main(){
	mp();
}

void mp(){
	
	int resp;
	
	do {
		system("CLS");
		cout<<"______________________________________"<<"\n"<<"\n";
		cout<<"	MENU PRINCIPAL DE JUGADORES"<<"\n";
		cout<<"______________________________________"<<"\n"<<"\n";
		cout<<"1 . Ingresa jugador"<<"\n";
		cout<<"2 . Jugadores ingresados"<<"\n";
		cout<<"3 . Salir"<<"\n";
		cout<<"______________________________________"<<"\n"<<"\n";
		cout<<"Selecciona una opcion:";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			grabar_archivo();			
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

void grabar_archivo(){
	
	string nombre_juga;
	string nacio_juga;
	int edad_juga;
	float salario_juga = 2500,incremento=0;
	fflush(stdin);
	cout<<"__________________________________"<<"\n"<<"\n";
	cout<<"	REGISTRO DE JUGADORES "<<"\n"<<"\n";
	cout<<"__________________________________"<<"\n"<<"\n";
	cout<<"Nombre del jugador:"<<endl;
	getline(cin,nombre_juga);
	fflush(stdin);
	cout<<"Edad del jugador: "<<endl;
	cin>>edad_juga;
	cout<<"Nacionalidad del jugador: "<<endl;
	cin>>nacio_juga;
	
	
	if(nacio_juga[0] != 'G'){
		if(edad_juga >= 15 ){
		salario_juga += 1400;
		incremento = salario_juga;
	}
	else if(edad_juga >= 21){
		salario_juga += 1500;
		incremento = salario_juga;
	}
	else if(edad_juga >= 25){
		salario_juga += 1200;
		incremento = salario_juga;
	}
	else  if(edad_juga > 30){
		salario_juga += 800;
		incremento = salario_juga;
	}
	}
	
	ofstream archivo;  
	archivo.open("HT3_EJERCICIO_01.txt",ios::app);
	
	
	archivo<<nombre_juga<<"\t"<<edad_juga<<"\t"<<nacio_juga<<"\t"<<salario_juga<<endl;
	archivo.close();
}
void leer_archivo(){
	ifstream archivo; 
	archivo.open("HT3_EJERCICIO_01.txt",ios::in);
	int lineas,i=0;
	string s,linea;
	float sumatoriasalarial=0.00;	
	if(archivo.fail()){
		cout<<"ERROR AL CARGAR EL ARCHIVO...";
		exit(1); 
	}
	while (getline(archivo, s))
        lineas++;
	archivo.close();
	
	jugadores recordset[lineas];
	
	archivo.open("HT3_EJERCICIO_01.txt",ios::in);
		if(archivo.fail()){
		cout<<"ERROR AL CARGAR EL ARCHIVO...";
		exit(1);
	}
	
	
	
	for (int i = 0; i < lineas; i++)
    {
        if (!archivo)
        {                                               
            cerr << "ERROR AL CARGAR EL ARCHIVO.." << endl;
            system("PAUSE");
        }
      
        archivo>>recordset[i].nombre>>recordset[i].edad>>recordset[i].nacio>>recordset[i].salario;
    }
    
        cout<<"_____________________________________________________________"<<"\n"<<"\n";
    	cout<<"			DATOS DE JUGADORES"<<"\n";
    	cout<<"_____________________________________________________________"<<"\n"<<"\n";
    
    archivo.close(); 
    for(int i = 0; i < lineas; i++){
    	cout<<recordset[i].nombre<<"		"<<recordset[i].edad<<"		"<<recordset[i].salario<<"		"<<recordset[i].nacio<<endl;
    	sumatoriasalarial+=recordset[i].salario;
	}
	cout<<"\n"<<"\n";
	cout<<"Sumatorial total: "<<sumatoriasalarial<<"\n"<<endl;;
	system("PAUSE");
}
