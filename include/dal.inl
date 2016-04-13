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
int DAL<Key, Data>::_search (const Key & _x) const{
	auto i(0);
	for( ; mpt_Data[i].id == _x and i < mi_Length ; ++i);

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
	auto i(0);
	if(mi_Length <= 0 || _search(_x) <= 0)
		return false;
	for( ; mpt_Data[i].id == _x; ++i);

	mpt_Data[i] = mpt_Data[i+1];

	mi_Length--;
	_data = mpt_Data;
	return true;
}

template < typename Key, typename Data >
bool DAL<Key, Data>::insert( const Key & _novaId, const Data & _novaInfo ){
	int idx = this->_search(_novaId);
	if(idx != 0){
		return false;
		std::cout << "Error" << endl;
	} else{
		if(mi_Length == mi_Capacity){
			throw std::length_error("DAL::insert;; overflow capacity");
		}
		else{
			mpt_Data[mi_Length].id = _novaId;
			mpt_Data[mi_Length].info = _novaInfo;
			mi_Length++;
			return true;
		}
	}
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
	auto xID = _search(_x);
	if(xID != mi_Length){
		_y = mpt_Data[xID+1].id;
		// cout << "Sucessor: " << _y << endl;
		return true;
	} else{
		return false;
	}

}
