#include "SuperContenedorV.h"

SuperContenedorV::SuperContenedorV() {
	Cantidad=0;
	Tamanio=200;
}

SuperContenedorV::~SuperContenedorV() {
//Destructor
}

void SuperContenedorV::IngresarProducto(){
	
	int Codigo, PrecioBase, CantidadVendida, Existencia, ExistenciaMinima, PrecioTotalTotal;
	string Nombre;
	float Ganancia, PesoUnidad;
	
	cout<<"Por favor, digite los datos del nuevo producto: "<<endl;
	cout<<"Codigo del producto: "<<endl;
	cin>>Codigo;
	cout<<"Nombre del producto: "<<endl;
	cin>>Nombre;
	cout<<"Precio Base del producto: "<<endl;
	cin>>PrecioBase;
	cout<<"Ganancia que generara: "<<endl;
	cin>>Ganancia;
	cout<<"Cantidad vendida: "<<endl;
	cin>>CantidadVendida;
	cout<<"Existencias del producto: "<<endl;
	cin>>Existencia;
	cout<<"Peso por unidad de producto: "<<endl;
	cin>>PesoUnidad;
	cout<<"Existencia minima que puede haber del producto: "<<endl;
	cin>>ExistenciaMinima;

	PrecioTotalTotal = PrecioBase+(PrecioBase*Ganancia);

	Producto productoNuevo = Producto(Codigo,Nombre,PrecioBase,Ganancia,
	CantidadVendida,Existencia,PesoUnidad,ExistenciaMinima,PrecioTotalTotal);
	
	if (Cantidad < Tamanio){
		ArregloProductos[Cantidad++] = productoNuevo;
		cout<<"Producto agregado con exito"<<endl;
	}else{
		cout <<"No hay espacio disponible"<<endl;
	}
}


string SuperContenedorV::toString(){

	stringstream aux;
	if(Cantidad>0){
		for(int i=0; i<Cantidad; i++){
			aux<<"Producto: " <<i+1 <<endl;
			aux<<ArregloProductos[i].toString()<<endl;
			aux<<""<<endl;
		}
		}else{
			cout<<"No existen productos registrados"<<endl;
		}
	
	return aux.str();
}

void SuperContenedorV::EliminarProducto(){

	int codigo;
	Producto eliminado = Producto(0,"",0,0.0,0,0,0,0,0);

	cout<<"Ingrese el codigo del producto a eliminar "<<endl;
	cin>>codigo;

	for(int i=0; i<Cantidad;i++){
		if(ArregloProductos[i].getCodigo() == codigo){
			ArregloProductos[i] = eliminado;
		}
	}

	cout<<"El producto se elimino con exito"<<endl;

}

void SuperContenedorV::DatosInicializados(){

	// Se crea los objetos
	Producto arroz = Producto (3,"Arroz",2000,0.10,1,2,2,5,2200);
	Producto Frijoles = Producto(1,"Frijoles",1000,0.10,1,10,1,5,1000);


	if(Cantidad < Tamanio){
		ArregloProductos[Cantidad++] = arroz;
		ArregloProductos[Cantidad++] = Frijoles;
	}	
}

void SuperContenedorV::ProductoMayorValor(){
	int mayor=0;
	string nombre;

	for(int i=0; i<Cantidad; i++){
		if(ArregloProductos[i].getPrecioTotal() >= mayor){
			mayor = ArregloProductos[i].getPrecioTotal();
			nombre = ArregloProductos[i].getNombre();

		}
	}
		
	cout<<"El producto: "<< nombre <<endl;
	cout<<"Con el valor total de: "<< mayor <<endl;
}

void SuperContenedorV::ProductoMayorExistencia(){
	int mayor=0;
	string nombre;

	for(int i=0; i<Cantidad; i++){
		if(ArregloProductos[i].getExistencia() >= mayor){
			mayor = ArregloProductos[i].getExistencia();
			nombre = ArregloProductos[i].getNombre();

		}
	}
		
	cout<<"El producto: "<< nombre <<endl;
	cout<<"Con el valor total de: "<< mayor <<endl;
}

void SuperContenedorV::OrdenarProductoPorCodigo(){
	Producto aux = Producto(0,"",0,0.0,0,0,0,0,0);

	
	for(int i=0;i<Cantidad;i++){
		for(int j=i+1;j<Cantidad;j++){
			if(ArregloProductos[i].getCodigo()>ArregloProductos[j].getCodigo()){
				aux.setCodigo(ArregloProductos[i].getCodigo());
				aux.setNombre(ArregloProductos[i].getNombre());
				aux.setPrecioBase(ArregloProductos[i].getPrecioBase());
				aux.setGanancia(ArregloProductos[i].getGanancia());
				aux.setCantidadVendida(ArregloProductos[i].getCantidadVendida());
				aux.setExistencia(ArregloProductos[i].getExistencia());
				aux.setPesoUnidad(ArregloProductos[i].getPesoUnidad());
				aux.setPrecioTotal(ArregloProductos[i].getPrecioTotal());
				ArregloProductos[i]=ArregloProductos[j];
				ArregloProductos[j]=aux;
			}
		}		
	}
	
	for(int i=0;i<Cantidad;i++){
		cout<< "Nombre: "<< ArregloProductos[i].getNombre() <<endl;
		cout<< "Codigo: "<<ArregloProductos[i].getCodigo() <<endl;
		cout<< "Precio base: "<<ArregloProductos[i].getPrecioBase() <<endl;
		cout<< "Ganancia: "<<ArregloProductos[i].getGanancia() <<endl;
		cout<< "Cantidad vendida: "<<ArregloProductos[i].getCantidadVendida() <<endl;
		cout<< "Existencia: "<<ArregloProductos[i].getExistencia() <<endl;
		cout<< "Peso: "<<ArregloProductos[i].getPesoUnidad() <<endl;
		cout<< "Precio Toral: "<<ArregloProductos[i].getPrecioTotal() <<endl;
		cout<<" "<<endl;
	}
}

//Devuelve la cantidad de productos
//que tienen una existencia por debajo de su existencia mínima.


void SuperContenedorV::ProductoBajaExistencia(){
	int prodCant = 0;

	for (int i = 0; i < Cantidad; i++){
		if(ArregloProductos[i].getExistencia() < ArregloProductos[i].getExistenciaMinima()){
			prodCant++;
		}
	}
	
	cout<< "Hay un total de: "<<prodCant <<" productos con exixtencia por debajo de la minima"<<endl;
}


//muestra la lista de los productos
//que tienen una existencia por debajo de su existencia mínima. Se debe mostrar solamente: el
//código, el nombre, la existencia y la existencia mínima.

string SuperContenedorV::imprimirProductosBajosDeExistencia(){
	stringstream aux;

	for (int i = 0; i < Cantidad; i++){
		if(ArregloProductos[i].getExistencia() < ArregloProductos[i].getExistenciaMinima()){
			aux<<"Producto: " <<i+1 <<endl;
			aux<<"Codigo: " << ArregloProductos[i].getCodigo() <<endl;
			aux<<"Nombre: " << ArregloProductos[i].getNombre() <<endl;
			aux<<"Existencia: " << ArregloProductos[i].getExistencia() <<endl;
			aux<<"Existencia minima: " << ArregloProductos[i].getExistenciaMinima() <<endl;
			aux<<""<<endl;
		}
	}

	return aux.str();
}

// devuelve la suma de kilogramos
//que corresponde a las cantidades vendidas de todos los productos

void 














