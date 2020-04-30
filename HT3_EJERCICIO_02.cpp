/*	Ejercicio #2	*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

void venta();
void reporte();

using namespace std;

struct ventas{
	int tipoprod;
	float descuento;
	float precio;
	int unidades;
	float totalvta;
};

int main(){
	venta();
	reporte();
}
	
void venta(){
	int tipoprod;
	float precio;
	int unidades;
	float descuento;
	float totalvta;
	string s;
	
	cout<<"_____________________________________________________"<<"\n"<<"\n";
	cout<<"		PIZZERIA"<<" *EL GRAN SABOR*"<<"\n"<<endl;
	cout<<"_____________________________________________________"<<"\n"<<"\n";
	cout<<"		ELIGE TU TIPO DE PIZZA: "<<"\n"<<"\n";
	cout<<" 1 . Q80.00	Pizza Grande	- Descuento 10%"<<endl;
	cout<<" 2 . Q115.00	Pizza Familiar	- Descuento 15%"<<endl;
	cout<<" 3 . Q100.00	Pizza Fiesta	- Descuento 20%"<<endl;
	cout<<"\n";
	cout<<"	Ingresa el tipo de pizza que desees: ";
	cin>>tipoprod;
	cout<<"\n";
	cout<<"	Indica las unidades que desees comprar: ";
	cin>>unidades;
	cout<<"\n";
	if (tipoprod ==1){
		descuento = 0.10;
		precio = 80.00;
		totalvta = (precio - (descuento * precio) )* unidades; 	
	}
	else if (tipoprod ==2){
		descuento = 0.20;
		precio = 100.00;
		totalvta = (precio - (descuento * precio) )* unidades; 	
	} else if (tipoprod ==3){
		descuento = 0.10;
		precio = 100.00;
		totalvta = (precio - (descuento * precio) )* unidades; 
	}
	cout<<"__________________________________________________________________________________________________________"<<"\n"<<"\n";
	cout<<"Tipo de pizza: "<<tipoprod<<"\t"<<"Descuento: "<<descuento<<"\t"<<"Precio: "<<precio<<"\t"<<"Unidades: "<<unidades<<"\t"<<"Total de la venta: "<<totalvta<<"\n";
	cout<<"__________________________________________________________________________________________________________"<<"\n"<<"\n";
	ofstream grabararchivo;
	
	try {
		grabararchivo.open("HT3_EJERCICIO_02.txt",ios::app);
		grabararchivo<<tipoprod<<"\t"<<descuento<<"\t"<<precio<<"\t"<<unidades<<"\t"<<totalvta<<endl;
		grabararchivo.close();
	}
	
	catch(exception X){
		cout<<"ERROR AL CARGAR EL ARCHIVO..."<<endl;
	}
	
	cout<<"\n";
	cout<<"__________________________________________"<<"\n"<<"\n";
	cout<<"	REGISTRRO DE VENTAS	"<<endl;
	cout<<"__________________________________________"<<"\n";
	cout<<"Pizza	Desc	Prc	Uni	Total"<<endl;
	ifstream leerarchivo;
	try {
		leerarchivo.open("HT3_EJERCICIO_02.txt",ios::in);				
		while (getline(leerarchivo, s))
			cout<<s<<endl;		
		leerarchivo.close();
	}
	
	catch(exception X){
		cout<<"ERROR AL CARGAR EL ARCHIVO..."<<endl;
	}
	
}

void reporte(){


	float tp,d,p,u,tv=0;
	float sumatotal=0;
	float tp1=0;
	float tp2=0;
	float tp3=0;	
	ifstream db;
	try{	
		db.open("HT3_EJERCICIO_02.txt",ios::in);
		
		while (db >>tp >> d >>p>> u>>tv){
			sumatotal = tv + sumatotal;	
			if (tp==1)
				tp1+=tv;
			else if (tp==2)
				tp2+=tv;
			else if (tp==3)
				tp3+=tv;
		}	
		db.close();
		cout<<"\n"<<"______________________________________________________"<<"\n"<<"\n";
		cout<<setprecision(5)<<"	TOTAL DE LAS VENTAS:"<<"\t"<<sumatotal<<"\n"<<endl;
		cout<<"		Detalle por producto:"<<"\n"<<endl;
		cout<<setprecision(5)<<" Pizza Grande   "<<tp1<<" - % sobre el total: "<<setprecision(3)<<tp1*100/sumatotal<<endl;
		cout<<setprecision(5)<<" Pizza Familiar "<<tp2<<" - % sobre el total: "<<setprecision(3)<<tp2*100/sumatotal<<endl;
		cout<<setprecision(5)<<" Pizza Fiesta   "<<tp3<<" - % sobre el total: "<<setprecision(3)<<tp3*100/sumatotal<<endl;
		cout<<"\n"<<"______________________________________________________";	
	}
	catch (exception X){		
			cout<<"ERROR AL CARGAR EL ARCHIVO..."<<endl;			
			exit(1);
	}	
}

