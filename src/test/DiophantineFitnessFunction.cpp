/*
 * DiophantineFitnessFunction.cpp
 *
 *  Created on: 6 мая 2015
 *      Author: vadim
 */

#include "DiophantineFitnessFunction.h"
#include <cmath>

DiophantineFitnessFunction::DiophantineFitnessFunction( int a, int b, int c, int d, int res ) :
	m_A( a ), m_B( b ), m_C( c ), m_D( d ), m_ExpectedResult( res )
{
}

DiophantineFitnessFunction::~DiophantineFitnessFunction()
{
}

double DiophantineFitnessFunction::calculate( const Chromosome * chromosome )
{
	Alleli * object = dynamic_cast<Alleli *>( const_cast<Chromosome *>( chromosome ) );
	vector<ChromosomesType> genes;
	object->getGenes( genes );

	double total = m_A * genes[ 0 ];
	total += m_B * genes[ 1 ];
	total += m_C * genes[ 2 ];
	total += m_D * genes[ 3 ];

	object->setGenes( genes );

	double fitness = ( abs( (double)m_ExpectedResult - total ) );

	if( fitness == 0.0 )
	{
		fitness = 0.000001;
	}

	object->setFitness( fitness );

	return fitness;
}
