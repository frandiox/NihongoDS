/**
 * Vector dinamico
 * @file vector.h
 * @date 31/10/2010
 **/

#ifndef __VECTOR_H
#define __VECTOR_H

// Includes
#include <PA9.h>

#define INITIAL_CAPACITY 8

template<class T>
class vector {
public:
	/**
	 * @brief Constructor por defecto
	 * @post Crea un vector vacio con 16 posiciones
	 **/
	vector() {
		_capacity = INITIAL_CAPACITY;
		data = new T[_capacity];
		_size = 0;
	}
	/**
	 * @brief Constructor con parametro
	 * @param capacity Capacidad inicial del vector
	 * @post El vector se quedara iniciado con una capacidad inicial
	 **/
	vector(u16 capacity) {
		if (capacity <= 0) {
			_capacity = INITIAL_CAPACITY;
			data = new T[_capacity];
			_size = 0;
		} else {
			_capacity = capacity;
			_size = 0;
			data = new T[_capacity];
		}
	}
	/**
	 * @brief Constructor de copias
	 * @post Se crea una copia del objeto
	 **/
	vector(const vector& orig) {
		_size = orig._size;
		_capacity = orig._capacity;
		data = new T[_capacity];
		u16 i;
		for (i = 0; i < _size; i++)
			data[i] = orig.data[i];
	}
	/**
	 * @brief Destructor
	 * @post Destruye la memoria gastada por el objeto
	 **/
	~vector() {
		if (data != NULL)
			delete[] data;
	}

	/**
	 * @brief Añade un objeto al final
	 * @post Modifica el objeto. Añade el objeto pasado al final del vector
	 **/
	void add(T item) {
		//Comprobar si hace falta realojar
		realocar();
		//Añadir al final
		data[_size] = item;
		_size++;
	}
	/**
	 * @brief Elimina el elemento correspondiente segun el indice
	 * @pre El indice dado debe ser valido. Debe estar entre 0...size-1
	 * @post Modifica el objeto. Quita un elemento de una posicion
	 **/
	void erase(u16 indice) {
		if (indice < 0 || indice >= _size)
			exit(-1);
		//Arrastrar hacia adelante los elementos que prosiguen al que se ha eliminado
		u16 i;
		for (i = indice; i < _size - 1; i++)
			data[i] = data[i + 1];
		_size--;
	}
	/**
	 * @brief Limpia el vector
	 * @post El vector se queda con la capacidad inicial
	 **/
	void clear() {
		if (data != NULL)
			delete[] data;
		_capacity = INITIAL_CAPACITY;
		_size = 0;
		data = new T[_capacity];
	}
	/**
	 * @brief Devuelve el numero de elementos ocupados
	 **/
	u16 size() const {
		return _size;
	}
	/**
	 * @brief Devuelve la capacidad original de elementos
	 **/
	u16 capacity() const {
		return _capacity;
	}
	/**
	 * @brief Operador de asignacion
	 * @post Se crea una copia del objeto pasado
	 **/
	vector& operator=(const vector& orig) {
		if (this != &orig) {
			//Liberar memoria
			if (data != NULL)
				delete[] data;
			//Copiar vector
			_size = orig._size;
			_capacity = orig._capacity;
			data = new T[_capacity];
			u16 i;
			for (i = 0; i < _size; i++)
				data[i] = orig.data[i];
		}
		return *this;
	}
	/**
	 * @brief Operador de indexacion
	 * @pre Indice debe ser un indice valido
	 **/
	const T& operator[](u16 indice) const {
		if (indice < 0 || indice >= _size)
			exit(-1);
		return data[indice];
	}
	/**
	 * @brief Operador de indexacion
	 * @pre Indice debe ser un indice valido
	 * @post Se modifica el objeto
	 **/
	T& operator[](u16 indice) {
		if (indice < 0 || indice >= _size)
			exit(-1);
		return data[indice];
	}

	/**
	 * @brief Funcion de acceso a posicion
	 * @pre Indice debe ser un indice valido
	 **/
	const T& get(u16 indice) const {
		if (indice < 0 || indice >= _size)
			exit(-1);
		return data[indice];
	}
	/**
	 * @brief Funcion de modificacion de un elemento del array
	 * @pre Indice debe ser un indice valido
	 * @post Se modifica el objeto
	 **/
	void set(u16 indice, const T& item) {
		if (indice < 0 || indice >= _size)
			exit(-1);
		data[indice]=item;
	}
private:
	T* data;
	u16 _size;
	u16 _capacity;

	/**
	 * @brief Reasigna memoria si se ha llegado al final de capacidad
	 **/
	void realocar() {
		if ((_size + 1) > _capacity) {
			//Nuevo vector con doble de capacidad
			_capacity += (_capacity >> 1);
			T* nuevo = new T[_capacity];
			//Copiar antiguas posiciones al nuevo vector
			u16 i;
			for (i = 0; i < _size; i++) {
				nuevo[i] = data[i];
			}
			//Liberar memoria del antiguo y reasignar el puntero de datos
			delete[] data;
			data = nuevo;
		}
	}
};

#endif
