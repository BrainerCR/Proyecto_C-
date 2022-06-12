#ifndef SUPERCONTENEDORV_H
#define SUPERCONTENEDORV_H
#include "Producto.h"


using namespace std;

class SuperContenedorV {
public:
	SuperContenedorV();
	~SuperContenedorV();

	void setCantida(int Cantidad);
	int getCantida();

	void IngresarProducto();
	void EliminarProducto();
	void ProductoMayorValor();
	void ProductoMayorExistencia();
	void OrdenarProductoPorCodigo();

	string toString();
	
	void ProductoBajaExistencia();
	string imprimirProductosBajosDeExistencia();
	void KgsVendidosGeneral();
	void KgsPorProducto();
	string imprimProductosQueSonMasCostososQue();
	int cuantasUnidadesSeHanVendidoDelProducto(); 
	float costoDelInventario();
	float costoDeLasVentas();
	float valorDeLasVentas();
	void ganaciaDelSuperMercadoPorVentas(); 

	void DatosInicializados();
	void IngresarDatos(Producto dato);
	
private:
	Producto ArregloProductos[200];
	int Cantidad;
	int Tamanio;
};

#endif

