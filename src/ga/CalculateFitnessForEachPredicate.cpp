/*
 * CalculateFitnessForEachPredicate.cpp
 *
 *  Created on: 12 мая 2015
 *      Author: vadim
 */

#include "CalculateFitnessForEachPredicate.h"

CalculateFitnessForEachPredicate::CalculateFitnessForEachPredicate( Fitness * fitnessFunc ) :
	m_FitnessFunc( fitnessFunc )
{
}

CalculateFitnessForEachPredicate::~CalculateFitnessForEachPredicate()
{
}

void CalculateFitnessForEachPredicate::operator() ( const Chromosome * chr ) const
{
	m_FitnessFunc->calculate( chr );
}
















