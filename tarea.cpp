//autor: Vitor Rene Cortez Sis						carne: 2490-19-14590

//programa: que permita administrar informacion de "n" emplesdos


#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

	void registro_del_empleado();
	void consulta();
	void generar_boleta_de_pago();
	int op;


int main()
{	
	do{
		cout<<"\n\n";
		
		cout<<"         MENU   "<<endl;
		cout<<"----------------------------"<<endl;
		cout<<"1.registro del empleado"<<endl;
	 	cout<<"2.consulta"<<endl;
		cout<<"3.generar boleta de pago"<<endl;
		cout<<"----------------------------";
		cout<<"\nSeleccione opcion: ";
	 	cin>>op;
if (op==1)
{
	 
	cout<<"\nIngreso a opcion 1"<<endl;
	registro_del_empleado();
}	
else if (op==2)
{
	cout<<"\nIngreso a opcion 2"<<endl;
	consulta();
}
else if (op==3)
{
	cout<<"\nIngreso a la  opcion 3"<<endl;	
	generar_boleta_de_pago();
}

}
 while (op!=0);
getchar();
return 0;

}
	
void registro_del_empleado()
 	
 {
 	cout<<"\n";
 	int codigo;
 	char nombre[32];
 	int puesto, sb,op,comisiones,hrse,costo,t ;
cout<<"Ingrese codigo: ";
cin>>codigo;
cout<<"Ingrese nombre: ";
cin.getline(nombre,30);
cout<<"Ingrese puesto: ";
cin>>puesto;
cout<<"Ingrese sueldo base: ";
cin>>sb;
cout<<"Tiene Comisiones"<<endl;
cout<<"1.Si"<<endl;
cout<<"2.No"<<endl;
cin>>op;
	if(op==1)
	{
 		cout<<"Ingrese el monto de comisiones: ";
 		cin>>comisiones;
	 }
 	else if(op==2)
 	{
 		cout<<" Continue!! "<<endl;
	 }
	 cout<<"Tiene horas extras"<<endl;
	 cout<<"1.Si"<<endl;
	 cout<<"2.No"<<endl;
	 cin>>op;
	 
	 if(op==1)
	 {
	 	cout<<"Ingrese cuantas horas extras:";
	 	cin>>hrse;
	 	cout<<"Ingrese costo por horas: ";
	 	cin>>costo;
	 	t=hrse*costo;
	 	cout<<t;
	}
	else if(op==2)
	{
		cout<<"Continue!!"<<endl;
	}
}

void consulta() 
{
	cout<<"\n";
	int codigo, puesto,sb,com,t,e,s;
	char nombre[32];
	
	cout<<"Ingrese codigo:";
	cin>>codigo;
	cout<<"Ingrese nombre:";
	cin.getline(nombre,30);
	cout<<"Ingrese puesto:";
	cin>>puesto;
	cout<<"Ingrese sueldo:";
	cin>>sb;
	cout<<"Ingrese comisiones:";
	cin>>com;
	cout<<"Ingrese el monto extras:";
	cin>>e;
	t=sb*com;
	s=t+e;
	cout<<"EL SUELDO CALCULADO ES: "<<s;
	
}

void generar_boleta_de_pago()
{
	cout<<"\n";
{
	char empresa[33];
	char nombre[32];
	int fecha,codigo;
	int sb,com,hrs,total;
	
	cout<<"Igrese el nombre de la empresa: "<<endl;
	cin.getline(empresa, 32);
	cout<<"Ingrese fecha: ";
	cin>>fecha;																								
	cout<<"Ingrese codigo: ";
	cin>>codigo;
	cout<<"Ingrese nombre:"<<endl;
	cin.getline(nombre,32);
	cout<<"Ingrese sueldo base:";
	cin>>sb;
	cout<<"Ingrese el monto de comisiones: ";
	cin>>com;
 	cout<<"Ingrese el monto de  horas extras:";
 	cin>>hrs;
 	total=sb+com+hrs;
 	cout<<"TOTAL: "<<total;
	



 
	ofstream archivo("boleta de pago .txt");
	if(archivo.is_open());
	{
			archivo<<"                    	Empresa:   "<<empresa<<endl;
			archivo<<"									Fecha: "<<fecha<<endl;
			archivo<<"Codigo:"<<codigo<<endl;
			archivo<<"\nNombre:"<<nombre<<endl;                     ;
			archivo<<"\nSueldo base:"<<sb<<endl;
			archivo<<"\nMonto de comisiones:"<<com<<endl;
			archivo<<"\nHoras extras:"<<hrs<<endl;
			archivo<<"\nTOTAL:"<<total<<endl;
			
		archivo.close();
	}
 

	}	

}
	
	

