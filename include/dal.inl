/**
 * DAL class implementation.
 *
 */

#include "dal.h"

/**
 * ---------------------------------------------------------------------------
 * Common methods from DAL.
 * ---------------------------------------------------------------------------
 */

// Construtor inicializa TAD.
template < typename Key, typename Data >
DAL<Key,Data>::DAL ( int _iMaxSz ) :
    mi_Length( 0 ),         // Tamanho logico.
    mi_Capacity( _iMaxSz ), // Guardar capacidade atual.
    mpt_Data( nullptr )
{
    if ( _iMaxSz < 0 )          // Nao aceitamos lista com tamanho negativo.
        throw std::invalid_argument( "[DAL()]: Tamanho de lista invalido!" );
    mpt_Data = new NodeAL[ _iMaxSz ]; // Tamanho maximo.
}

template < typename Key, typename Data >
int DAL<Key, Data>::_search(const Key & _x) const{
	// auto i(0);
	// for( ; mpt_Data[i].id == _x and i < mi_Length ; ++i);

	// return i;

	auto i(0);
	for(/*Empty*/; mpt_Data[i].id != _x and i < mi_Length; i++)
		/*Empty*/;
	return i;
}

template < typename Key, typename Data >
bool DAL<Key, Data>::search( const Key &_x, Data & _result) const{
	auto idx = _search(_x);
	if(idx == mi_Length)
		return false;

	_result = mpt_Data[idx].info;

	return true;
}

template < typename Key, typename Data >
bool DAL<Key, Data>::remove( const Key & _x, Data & _data){  // Remove da lista.
	auto idx = _search(_x);
	if(idx != mi_Length){
		mpt_Data[idx] = mpt_Data[--mi_Length];
		_data = mpt_Data;
		return true;
	}
	return false;

}

template < typename Key, typename Data >
bool DAL<Key, Data>::insert( const Key & _novaId, const Data & _novaInfo ){
	int idx = _search( _novaId );

	if ( idx == mi_Length  ) {
		if(mi_Length == mi_Capacity){
			throw std::length_error("DAL::insert;; overflow capacity");
		}
		else{
			mpt_Data[mi_Length].id = _novaId;
			mpt_Data[mi_Length].info = _novaInfo;
			mi_Length++;
		}
		return true;
	}else return false;
}

template < typename Key, typename Data >
Key DAL<Key, Data>::min() const {
	int minId = sizeof(int);
	for (int i = 0; i < mi_Length; ++i)
	{
		if(mpt_Data[i].id < minId){
			minId = mpt_Data[i].id;
		}
	}
	return minId;
}

template < typename Key, typename Data >
Key DAL<Key, Data>::max() const {
	int maxId = 0;
	for (int i = 0; i < mi_Length; ++i)
	{
		if(mpt_Data[i].id > maxId){
			maxId = mpt_Data[i].id;
		}
	}
	return maxId;
}

template < typename Key, typename Data >
bool DAL<Key, Data>::sucessor(const Key & _x, Key & _y) const{
	auto i(0);
	if(mi_Length <= 0) // Check if mi_Length is valid
		return false;

	for( ; mpt_Data[i].id != _x; ++i);

	if(i == mi_Length-1){ // If reaches the final of the vector, returns the actual index "i"
		_y = mpt_Data[i].id;
		return true;
	}else{ // else, returns the sucessor;
		_y = mpt_Data[i+1].id;
		return true;
	}
	// cout << "Sucessor: " << _y << endl;

}


template < typename Key, typename Data >
bool DAL<Key, Data>::predecessor(const Key & _x, Key & _y) const{
	auto i(0);
	if(mi_Length <= 0) // Check if mi_Length is valid
		return false;

	for( ; mpt_Data[i].id != _x; ++i);

	if(i == 0){ // If reaches the final of the vector, returns the actual index "i"
		_y = mpt_Data[i].id;
		return true;
	}else{ // else, returns the sucessor;
		_y = mpt_Data[i-1].id;
		return true;
	}
	// cout << "Sucessor: " << _y << endl;

}