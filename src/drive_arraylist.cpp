/*
 * Test aaplication for the Dictionary with Array Lits or DAL.
 *
 * Try to test as many DAL's methods in varying situations
 * as possible.
 *
 * */
#include <iostream>
#include <sstream>
#include <cmath>
#include <functional>
#include <stdexcept>

#include "dal.h"
#include "dsal.h"

int main ( )
{
    DAL< int, std::string  >  myList( 50 ); // Lista de no máximo 50 elementos.
    int y = 0;
	try{
	    myList.insert( 15, "dado 1" );
	    myList.insert( 2, "dado 2" );
	    myList.insert( 8, "dado 3" );
	} catch( std::length_error & e){
		std::cout << "EXCEPTION! " << e.what() << std::endl;
	}

    myList.sucessor(15, y);
    cout << "sucessor MAIN: " << y << endl;
    myList.predecessor(8, y);
    cout << "predecessor MAIN: " << y << endl;
    std::cout << "\n>>> myList: " << myList << std::endl;

    std::cout << "\n>>> Normal ending...\n\n";
    return EXIT_SUCCESS;
}

