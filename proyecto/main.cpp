#include <iostream>
#include <windows.h>
#include "SuperContenedorV.h"
#include "Producto.h"
using namespace std;

int main () {
	
	int opc;
	SuperContenedorV G;
	G.DatosInicializados();
	
	Producto ArregloProductos[200] = Producto();
	
	/*
	Producto Arroz(1,"Arroz",2000,0.10,1,10,2,5,1000);
	Producto Frijoles(2,"Frijoles",1000,0.10,1,10,1,5);
	Producto Leche(3,"Leche",900,0.10,1,10,1,5);
	Producto Atun(4,"Atun",1850,0.10,1,10,0.3,5);
	Producto Sardina(5,"Sardina",1000,0.10,1,10,0.2,5);
	Producto Mantequilla(6,"Mantequilla",500,0.15,0,10,0.3,4);
	Producto JabonBanno(7,"Jabon de banno",500,0.15,0,10,0.3,4);
	Producto Shampoo(8,"Shampoo",3000,0.15,0,10,0.3,4);
	Producto JabonLavaplatos(9,"Jabon lavaplatos",2500,0.15,0,10,0.3,4);
	Producto JabonRopa(10,"Jabon ropa",5000,0.15,0,10,1.5,4);
	Producto Desinfectantes(11,"Desinfectantes",2000,0.05,2,10,2,3);
	Producto EsponjaLavaplatos(12,"Esponja lavaplatos",600,0.05,2,10,0.1,3);
	Producto Escoba(13,"Escoba",1500,0.05,2,10,0.5,3);
	Producto BolsasBasuraGrande(14,"Bolsas basura grandes",600,0.5,2,10,0.3,3);
	Producto CepilloDientes(15,"Cepillo de dientes",2000,0.20,2,10,0.01,3);
	Producto PastaDienteas(16,"Pasta de dientes",3500,0.20,0,10,0.2,5);
	Producto DesodoranteHombre(17,"Desodorante hombre",4000,0.20,0,10,0.1,5);
	Producto DesodoranteMujer(18,"Desodorante mujer",4500,0.20,0,10,0.1,5);
	Producto Oregano(19,"Oregano",700,0.10,0,10,0.01,5);
	Producto Sal(20,"Sal",400,0.10,0,10,0.5,5);
	*/
	

	for(;;){
	system("cls");
	cout<<"<------------------------->Menu<------------------------->"<<endl;
	cout<<"1- Ingresar un producto nuevo"<<endl;
	cout<<"2- Eliminar un producto"<<endl;
	cout<<"3- Desplegar el producto mas caro"<<endl;
	cout<<"4- Desplegar el producto con mayor unidades"<<endl;
	cout<<"5- Ordenar los productos por codigo"<<endl;
	cout<<"6- Desplegar todos los productos"<<endl;
	cout<<"7- Desplegar la canbtidad de productos bajos de existencia"<<endl;
	cout<<"8- Desplegar los productios bajos de existencia"<<endl;
	cout<<"9- Desplegar el total de kilogramos de todos los productos vendidos"<<endl;
	cout<<"10- Desplegar el total de kilogramos vendidos de un producto"<<endl;
	cout<<"11- Lista de productos mas caros que un producto a digitar"<<endl;
	cout<<"12- Desplegar la cantidad de unidades vendidas de un producto"<<endl;
	cout<<"13- Desplegar costo del inventario"<<endl;
	cout<<"14- Desplegar costo de ventas"<<endl;
	cout<<"15- Desplegar valor de las ventas"<<endl;
	cout<<"16- Ganancias del supermercado por ventas"<<endl;
	cout<<"17- Grafico de los 5 productos mas vendidos"<<endl;
	cout<<"18- Grafico de los 5 productos menos vendidos"<<endl;
	cout<<"19- Promedio de precios de venta de los productoa vendidos con ganancia"<<endl;
	cout<<"20- Salir del programa"<<endl;
	cin>>opc;
	switch(opc){
	case 1:{
		system("cls");
		G.IngresarProducto();
		system("pause");
		break;
	}
	case 2:{
		system("cls");
		G.EliminarProducto();
		system("pause");
		break;
	}
	case 3:{
		system("cls");
		G.ProductoMayorValor();
		system("pause");
		break;
	}
	case 4:{
		system("cls");
		G.ProductoMayorExistencia();
		system("pause");
		break;
	}
	case 5:{
		system("cls");
		G.OrdenarProductoPorCodigo();
		system("pause");
		break;
	}
	case 6:{
		system("cls");
		cout<<G.toString();
		system("pause");
		break;
	}
	case 7:{
		system("cls");
		G.ProductoBajaExistencia();
		system("pause");
		break;
	}
	case 8:{
		system("cls");
		cout<<G.imprimirProductosBajosDeExistencia();
		system("pause");
		break;
	}
	case 9:{
		
		
		system("pause");
		break;
	}
	case 10:{
		
		
		system("pause");
		break;
	}
	case 11:{
		
		
		system("pause");
		break;
	}
	case 12:{
		
		
		system("pause");
		break;
	}
	case 13:{
		
		
		system("pause");
		break;
	}
	case 14:{
		
		
		system("pause");
		break;
	}
	case 15:{
		
		
		system("pause");
		break;
	}
	case 16:{
		
		
		system("pause");
		break;
	}
	case 17:{
		
		
		system("pause");
		break;
	}
	case 18:{
		
		
		system("pause");
		break;
	}
	case 19:{
		
		
		system("pause");
		break;
	}
	case 20:{
		cout<<"Hasta luego"<<endl;
		return 0;
	}
	default: {
		cout<<"Opcion no valida"<<endl;
		system("pause");
		break;
	}}}}
