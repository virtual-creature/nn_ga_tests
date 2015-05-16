/*
 * FindChromosomePredicate.cpp
 *
 *  Created on: 12 мая 2015
 *      Author: vadim
 */

#include "FindChromosomePredicate.h"
#include <cassert>
#include <cstring>

FindChromosomePredicate::FindChromosomePredicate( const Chromosome * chr ) :
	m_Chromosome( chr )
{
}

FindChromosomePredicate::~FindChromosomePredicate()
{
}

bool FindChromosomePredicate::operator () ( const Chromosome * chr1 ) const
{
	vector<ChromosomesType> genes1;
	vector<ChromosomesType> genes2;
	chr1->getGenes( genes1 );
	m_Chromosome->getGenes( genes2 );

	if( genes1.size() != genes2.size() )
	{
		assert( false );
	}

	ChromosomesType * genes_1_ptr = &genes1[0];
	ChromosomesType * genes_2_ptr = &genes2[0];

	if( memcmp( &genes1[0], &genes2[0], genes1.size() * sizeof( ChromosomesType ) ) != 0 )
	{
		return false;
	}
	return true;
}


















