#include "Producto.h"

Producto::Producto() {
	Codigo=0;
	Nombre="";
	PrecioBase=0;
	Ganancia=0.0;
	CantidadVendida=0;
	Existencia=0;
	PesoUnidad=0.0;
	ExistenciaMinima=0;
	PrecioTotal=0;
}

Producto::Producto(int Codigo,string Nombre,int PrecioBase,float Ganancia,
int CantidadVendida,int Existencia,float PesoUnidad,
int ExistenciaMinima, int PrecioTotal){

	this->Codigo=Codigo;
	this->Nombre=Nombre;
	this->PrecioBase=PrecioBase;
	this->Ganancia=Ganancia;
	this->CantidadVendida=CantidadVendida;
	this->Existencia=Existencia;
	this->PesoUnidad=PesoUnidad;
	this->ExistenciaMinima=ExistenciaMinima;
	this->PrecioTotal=PrecioTotal;
}

Producto::~Producto() {
	//Destructor
}

void Producto::setCodigo(int Codigo){
	this->Codigo=Codigo;
}
void Producto::setNombre(string Nombre){
	this->Nombre=Nombre;
}
void Producto::setPrecioBase(int PrecioBase){
	this->PrecioBase=PrecioBase;
}
void Producto::setGanancia(float Ganancia){
	this->Ganancia=Ganancia;
}
void Producto::setCantidadVendida(int CantidadVendida){
	this->CantidadVendida=CantidadVendida;
}
void Producto::setExistencia(int Existencia){
	this->Existencia=Existencia;
}
void Producto::setPesoUnidad(float PesoUnidad){
	this->PesoUnidad=PesoUnidad;
}
void Producto::setExistenciaMinima(int ExistenciaMinima){
	this->ExistenciaMinima=ExistenciaMinima;
}

void Producto::setPrecioTotal(int getPrecioTotal){
	this->PrecioTotal=PrecioTotal;
}


int Producto::getCodigo(){
	return Codigo;
}
string Producto::getNombre(){
	return Nombre;
}
int Producto::getPrecioBase(){
	return PrecioBase;
}
float Producto::getGanancia(){
	return Ganancia;
}
int Producto::getCantidadVendida(){
	return CantidadVendida;
}
int Producto::getExistencia(){
	return Existencia;
}
float Producto::getPesoUnidad(){
	return PesoUnidad;
}
int Producto::getExistenciaMinima(){
	return ExistenciaMinima;
}

int Producto::getPrecioTotal(){
	return PrecioTotal;
}

string Producto::toString(){
	stringstream aux;
	
	aux<<"Codigo: "<<Codigo<<endl;
	aux<<"Nombre: "<<Nombre<<endl;
	aux<<"Precio Base: "<<PrecioBase<<endl;
	aux<<"Ganancias: "<<Ganancia<<endl;
	aux<<"Cantidad vendida: "<<CantidadVendida<<endl;
	aux<<"Existencia: "<<Existencia<<endl;
	aux<<"Peso por unidad: "<<PesoUnidad<<endl;
	aux<<"Existencia minima: "<<ExistenciaMinima<<endl;
	aux<<"Precio Total: "<<PrecioTotal<<endl;
	
	return aux.str();
}



