/*
 * ChromosomesComparator.cpp
 *
 *  Created on: 28 апр. 2015
 *      Author: vadim
 */

#include "ChromosomesComparator.h"
#include "GeneticAlgorithm.h"

ChromosomesComparator::ChromosomesComparator() : m_Fitness( NULL )
{
}

ChromosomesComparator::~ChromosomesComparator()
{
}

bool ChromosomesComparator::operator () ( const Chromosome * constChr1, const Chromosome * constChr2 ) const
{
	Chromosome * chr1 = const_cast<Chromosome *>( constChr1 );
	Chromosome * chr2 = const_cast<Chromosome *>( constChr2 );
	ChromosomesType fit1 = fit( chr1 );
	ChromosomesType fit2 = fit( chr2 );

	if( fit1 > fit2 )
	{
		return true;
	}
	return false;
}

ChromosomesType ChromosomesComparator::operator () ( ChromosomesType src_value, Chromosome * chr ) const
{
	ChromosomesType fitness = fit( chr );
	return src_value + fitness;
}

void ChromosomesComparator::setFitness( Fitness * fitness )
{
	m_Fitness = fitness;
}

ChromosomesType ChromosomesComparator::fit( const Chromosome * chr ) const
{
	map< const Chromosome *, ChromosomesType >::iterator found_fit_iter = m_Cache.find( chr );
	ChromosomesType fitnessResult;
//	if( found_fit_iter == m_Cache.end() )
	{
		fitnessResult = m_Fitness->calculate( chr );
		m_Cache[ chr ] = fitnessResult;
	}
	return fitnessResult;
};

void ChromosomesComparator::clearCache()
{
	m_Cache.clear();
}



















