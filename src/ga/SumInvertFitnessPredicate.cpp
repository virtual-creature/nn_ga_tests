/*
 * SumInvertFitnessPredicate.cpp
 *
 *  Created on: 12 мая 2015
 *      Author: vadim
 */

#include "SumInvertFitnessPredicate.h"

SumInvertFitnessPredicate::SumInvertFitnessPredicate( Fitness * fitnessFunc ) :
	m_FitnessFunc( fitnessFunc )
{
}

SumInvertFitnessPredicate::~SumInvertFitnessPredicate()
{
}

ChromosomesType SumInvertFitnessPredicate::operator () ( ChromosomesType src_value, const Chromosome * chr ) const
{
	double fitness = chr->getFitness();
	double invFitness = 1.0 / fitness;
	if( invFitness > 100 )
	{
		int a = 0;
		double fitness = chr->getFitness();
		a++;
	}
	return src_value + invFitness;
}














