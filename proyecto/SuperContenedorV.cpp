#include "SuperContenedorV.h"

SuperContenedorV::SuperContenedorV() {
	Cantidad=0;
	Tamanio=200;
}

SuperContenedorV::~SuperContenedorV() {
//Destructor
}

//Ingresa un nuevo producto al surtido del supermercado
//# 1

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

//muestra los siguientes datos de todos los productos del supermercado: 
//código, nombre, porcentaje de ganancia y precio de venta
//#6

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

//Elimina un producto del surtido del supermercado por su código
//#2
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


//Inicializamos los datos

void SuperContenedorV::DatosInicializados(){

	// Se crea los objetos
	Producto arroz = Producto(3,"Arroz",2000,0.10,6,2,2,5,2200);
	Producto Frijoles = Producto(1,"Frijoles",1000,0.10,6,10,1,5,1000);
	Producto Leche = Producto(3,"Leche",900,0.10,7,10,1,5,2000);
	Producto Atun = Producto(4,"Atun",1850,0.10,8,10,0.3,5,600);
	Producto Sardina = Producto(5,"Sardina",1000,0.10,3,10,0.2,5,700);
	Producto Mantequilla = Producto(6,"Mantequilla",500,0.15,0,10,0.3,4,700);
	Producto JabonBanno = Producto(7,"Jabon de banno",500,0.15,0,10,0.3,4,700);


	if(Cantidad < Tamanio){
		ArregloProductos[Cantidad++] = arroz;
		ArregloProductos[Cantidad++] = Frijoles;
		ArregloProductos[Cantidad++] = Leche;
		ArregloProductos[Cantidad++] = Atun;
		ArregloProductos[Cantidad++] = Sardina;
		ArregloProductos[Cantidad++] = Mantequilla;
		ArregloProductos[Cantidad++] = JabonBanno;
	}	
}

//devuelve el producto de mayor precio de venta
//# 3

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


//devuelve el producto que tiene mayor existencia
//#4

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

//ordena los productos ascendentemente de acuerdo con el código
//#5

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
//#7

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
//#8

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
//#9

void SuperContenedorV::KgsVendidosGeneral(){
	int totalKilos = 0;
	int cant = 0;
	int peso = 0;

	for (int i = 0; i < Cantidad; i++){

		peso = ArregloProductos[i].getPesoUnidad();
		cant = ArregloProductos[i].getCantidadVendida();

		totalKilos = totalKilos+(peso*cant);
	}

	cout<< "Se vendio: "<<totalKilos <<" kilos gramos de productos"<<endl;
}

//devuelve la cantidad de kilogramos
//que corresponde con la cantidad vendida de un producto
//#10

void SuperContenedorV::KgsPorProducto(){
	int totalKilos = 0, codigo, peso = 0, cant = 0;
	string nombre;

	cout<<"Digite el codigo del producto a consultar: "<<endl;
	cin>>codigo;

	for (int i = 0; i < Cantidad; i++){

		if(codigo == ArregloProductos[i].getCodigo()){
			peso = ArregloProductos[i].getPesoUnidad();
			cant = ArregloProductos[i].getCantidadVendida();
			nombre = ArregloProductos[i].getNombre();
			totalKilos = totalKilos+(peso*cant);
		}
			
	}

	cout<<"El producto: " << nombre <<" con el codigo: " << codigo << " ha vendido: " << totalKilos <<endl;
}

//muestra un listado de los productos cuyo precio de venta es mayor que 
//el de un producto en particular que se recibe como parámetro. Solamente se 
//debe mostrar para cada producto: el código, el nombre y su precio de venta
//#11

string SuperContenedorV::imprimProductosQueSonMasCostososQue(){
	int codigo, precio;
	stringstream aux;

	cout<<"Digite el codigo del producto a consultar: "<<endl;
	cin>>codigo;

	for(int i=0; i<Cantidad; i++){
		if(codigo == ArregloProductos[i].getCodigo()){
			
			precio = ArregloProductos[i].getPrecioTotal();

			for(int j=0; j<Cantidad; j++){
				if(precio < ArregloProductos[j].getPrecioTotal()){
					
					aux<<"-----------------------------------------------"<<endl;
					aux<<"Producto: " <<j+1 <<endl;
					aux<<"Codigo: " << ArregloProductos[j].getCodigo() <<endl;
					aux<<"Nombre: " << ArregloProductos[j].getNombre() <<endl;
					aux<<"Precio de venta: " << ArregloProductos[j].getPrecioTotal() <<endl;	
					aux<<"-----------------------------------------------"<<endl;
				}
			}

		} else {
			cout<<"No existe ese codigo "<<endl;
		}
	}


	return aux.str();
}

//devuelve la cantidad de unidades vendidas de un producto particular
//#12

int SuperContenedorV::cuantasUnidadesSeHanVendidoDelProducto(){
	int codigo, ventas;

	cout<<"Digite el codigo del producto a consultar: "<<endl;
	cin>>codigo;

	for (int i = 0; i < Cantidad; i++){

		if(codigo == ArregloProductos[i].getCodigo()){
			ventas = ArregloProductos[i].getCantidadVendida();
		}	
	}

	return ventas;
}

//devuelve el costo total de los productos en existencia en
//el supermercado, es decir, la suma de los precios de costo ponderados por 
//la cantidad en existencia de cada producto
//#13

float SuperContenedorV::costoDelInventario(){
	float promedio = 0.0;
	int suma = 0;

	for (int i = 0; i < Cantidad; i++)
	{
		promedio =+ (ArregloProductos[i].getExistencia() * ArregloProductos[i].getPrecioBase());
		suma += ArregloProductos[i].getExistencia();

	}

	promedio /= suma;
	
	return promedio;
}

//devuelve el costo total de los productos que se ha vendido, es decir, la suma 
//de los precios de costo ponderados por la cantidad vendida de cada producto.
//#14

float SuperContenedorV::costoDeLasVentas(){
	float promedio = 0.0;
	int suma = 0;

	for (int i = 0; i < Cantidad; i++)
	{
		promedio =+ (ArregloProductos[i].getCantidadVendida() * ArregloProductos[i].getPrecioBase());
		suma += ArregloProductos[i].getCantidadVendida();

	}

	promedio /= suma;

	return promedio;
}

//devuelve el valor total de las ventas del supermercado, es decir, la suma 
//de los precios de venta ponderados por la cantidad vendida de cada producto
//#15

float SuperContenedorV::valorDeLasVentas(){
	float promedio = 0.0;
	int suma = 0;

	for (int i = 0; i < Cantidad; i++)
	{
		promedio =+ (ArregloProductos[i].getPrecioTotal() * ArregloProductos[i].getCantidadVendida());
		suma += ArregloProductos[i].getCantidadVendida();

	}

	promedio /= suma;

	return promedio;
}

//devuelve la ganancia total del supermercado por las ventas realizadas.
//#16

void SuperContenedorV::ganaciaDelSuperMercadoPorVentas(){
	int ganancias = 0;

	for (int i = 0; i < Cantidad; i++)
	{
		ganancias = ganancias + (ArregloProductos[i].getCantidadVendida() * ArregloProductos[i].getPrecioTotal());

	}
	
	cout<<"La ganancias son de:  "<< ganancias <<endl;
}

/*
Muestra un gráfico de barras horizontales, dibujadas con asteriscos (*), que representan 
la cantidad vendida de los 5 productos más vendidos en el supermercado. En las ordenadas (eje Y) 
se mostrarán los nombres de los productos y en las abscisas (eje X) la representación 
de la cantidad vendida del producto
*/
//#17

void SuperContenedorV::graficoDeVentasDeLos15ProductsMasVendidos(){
	string grafico[5][5];
	int pro1 = 0, pro2 = 0, pro3 = 0, pro4 = 0, pro5 = 0, mayor = 1;

	for (int i = 0; i < Cantidad; i++)
	{
		if(ArregloProductos[i].getCantidadVendida() >= (mayor-1)){
			pro1 = ArregloProductos[i].getCantidadVendida();

		} else if(ArregloProductos[i].getCantidadVendida() <= mayor){
			pro2 = ArregloProductos[i].getCantidadVendida();

		} else if(ArregloProductos[i].getCantidadVendida() <= pro2){
			pro3 = ArregloProductos[i].getCantidadVendida();

		} else if(ArregloProductos[i].getCantidadVendida() <= pro3){
			pro4 = ArregloProductos[i].getCantidadVendida();

		} else if(ArregloProductos[i].getCantidadVendida() <= pro4){
			pro5 = ArregloProductos[i].getCantidadVendida();
		}		

		cout<<"productos:  "<< pro1<<pro2<<pro3<<pro4<<pro5 <<endl;
	}

	

	/*do{
		if(ArregloProductos[i].getCantidadVendida() >= mayor){
			mayor = ArregloProductos[i].getCantidadVendida();			

		} else if(ArregloProductos[i].getCantidadVendida() <= mayor){
			pro2 = ArregloProductos[i].getCantidadVendida();

		} else if(ArregloProductos[i].getCantidadVendida() <= pro2){
			pro3 = ArregloProductos[i].getCantidadVendida();

		} else if(ArregloProductos[i].getCantidadVendida() <= pro3){
			pro4 = ArregloProductos[i].getCantidadVendida();

		} else if(ArregloProductos[i].getCantidadVendida() <= pro4){
			pro5 = ArregloProductos[i].getCantidadVendida();
		}


		i ++;
		cout<<"productos:  "<< mayor<<pro2<<pro3<<pro4<<pro5 <<endl;

	} while (i <= Cantidad);
	*/

	/*
	else if(ArregloProductos[i].getCantidadVendida() <= mayor){
			pro2 = ArregloProductos[i].getCantidadVendida();

		} else if(ArregloProductos[i].getCantidadVendida() <= pro2){
			pro3 = ArregloProductos[i].getCantidadVendida();

		} else if(ArregloProductos[i].getCantidadVendida() <= pro3){
			pro4 = ArregloProductos[i].getCantidadVendida();

		} else if(ArregloProductos[i].getCantidadVendida() <= pro4){
			pro5 = ArregloProductos[i].getCantidadVendida();
		}



---------------------------------------

if(ArregloProductos[i].getCantidadVendida() <= mayor){
				pro2 = ArregloProductos[i].getCantidadVendida();

				if(ArregloProductos[i].getCantidadVendida() <= pro2){
					pro3 = ArregloProductos[i].getCantidadVendida();

					if(ArregloProductos[i].getCantidadVendida() <= pro3){
						pro4 = ArregloProductos[i].getCantidadVendida();

						if(ArregloProductos[i].getCantidadVendida() <= pro4){
							pro5 = ArregloProductos[i].getCantidadVendida();
							
						}
					}
				}
			}
	*/
	
}

//#18


//#19

