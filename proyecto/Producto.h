#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
#include <sstream>

using namespace std;

class Producto {
public:
	Producto();
	Producto(int Codigo,string Nombre,int PrecioBase,float Ganancia,
	int CantidadVendida,int Existencia,float PesoUnidad,int ExistenciaMinima, 
	int PrecioTotal);
	~Producto();
	
	void setCodigo(int Codigo);
	void setNombre(string Nombre);
	void setPrecioBase(int PrecioBase);
	void setGanancia(float Ganancia);
	void setCantidadVendida(int CantidadVendida);
	void setExistencia(int Existencia);
	void setPesoUnidad(float PesoUnidad);
	void setExistenciaMinima(int ExistenciaMinima);
	void setPrecioTotal(int PrecioTotal);

	int getCodigo();
	string getNombre();
	int getPrecioBase();
	float getGanancia();
	int getCantidadVendida();
	int getExistencia();
	float getPesoUnidad();
	int getExistenciaMinima();
	int getPrecioTotal();

	string toString();
	
private:
	int Codigo;
	string Nombre;
	int PrecioBase;
	float Ganancia;
	int CantidadVendida;
	int Existencia;
	float PesoUnidad;
	int ExistenciaMinima;
	int PrecioTotal;
};

#endif

