/**
 * Definition of a class that implements a dictionary based on array.
 * This is a template class, where we need to specify the type
 * of key (unique) and the type of information we need to store
 * in the dictionary.
 *
 * Author: Selan Santos
 * Date: March 25th, 2015
 * Uptaded on: April 2016.
 * */

#ifndef _DAL_H_
#define _DAL_H_

#include <iostream>
#include <stdexcept>
#include <functional>

using std::cout;
using std::cerr;
using std::endl;
using std::string;


template < typename Key, typename Data >
class DAL
{
    protected:
        struct NodeAL {    // Estrutura do noh de um lista seq.
            Key id;       // A chave eh um inteiro nesta TAD.
            Data info;// A informacao tambem eh inteiro.
        };

        static const int SIZE=50;   // Tamanho maximo da lista.
        int mi_Length;              // Comprimento atual da lista.
        int mi_Capacity;            // Capacidade maxima de armazenamento.
        NodeAL *mpt_Data;          // Area de armazenamento: vetor regular.

        int _search(const Key & _x ) const; // Metodo de busca auxiliar.

    public:
        DAL ( int _MaxSz = SIZE );
        virtual ~DAL () { delete [] mpt_Data; };
        bool remove( const Key & _x, Data & );     // Remove da lista.
        bool search( const Key & _x, Data & ) const;         // busca publica.
        bool insert( const Key & _novaId, const Data & _novaInfo ); // Insere na lista.
        Key min() const; // Recupera a menor chave do dicionário .
        Key max() const; // Recupera a maior chave do dicionário.
        // Recupera em _y a chave antecessora a _x , se existir ( true ).
        bool sucessor(const Key & _x, Key & _y) const;
        //! Sobrecarga do operador <<, que faz com que seja impresso o conteudo da lista.
        /*! @param _os Output stream, normalmente o <CODE>cout</code>.
         *  @param _oList A lista a ser impressa.
         *  @return A pr&oacute;pria <CODE>os</code> recebida como par&acirc;metros (para permitir encadeamento).
         */
        inline friend std::ostream &operator<< (std::ostream& _os, const DAL& _oList )
        {
            _os << "[ ";
            for( int i(0) ; i < _oList.mi_Length ; ++i )
                _os << "{id: " << _oList.mpt_Data[i].id << ", info: " << _oList.mpt_Data[i].info << "}  ";
            _os << "]";
            return _os;
        }
};


#include "dal.inl" // This is to get "implementation" from another file.

#endif
