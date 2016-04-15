/**
 * Class and Methods from the sorted DAL
 * Author: Johnnylee Bryan
 * Created on: April 2016.
 * */

#ifndef _DSAL_H_
#define _DSAL_H_

#include <iostream>
#include <stdexcept>
#include <functional>
#include "dal.h"

using std::cout;
using std::cerr;
using std::endl;
using std::string;

template < typename Key, typename Data >
class DSAL : public DAL<Key,Data>::DAL
{
public:
    DSAL(int _MaxSz) : DAL<Key,Data>::DAL(_MaxSz){/*Empty*/};
    virtual ~DSAL(){/*Empty*/};
    bool remove( const Key & _x, Data & );     // Remove da lista.
    bool insert( const Key & _novaId, const Data & _novaInfo ); // Insere na lista.
    Key min() const; // Recupera a menor chave do dicionário .
    Key max() const; // Recupera a maior chave do dicionário.
    // Recupera em _y a chave predecessora a _x , se existir ( true ).
    bool sucessor(const Key & _x, Key & _y) const;
    // Recupera em _y a chave antecessora a _x , se existir ( true ).
    bool predecessor(const Key & _x, Key & _y) const;

private:
    int _search(const Key & _x) const; // Método de busca auxiliar.
};

#include "dsal.inl" // This is to get "implementation" from another file.

#endif