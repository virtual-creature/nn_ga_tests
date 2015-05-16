/*
 * SortByLikelihoodPredicate.cpp
 *
 *  Created on: 12 мая 2015
 *      Author: vadim
 */

#include "SortByLikelihoodPredicate.h"

SortByLikelihoodPredicate::SortByLikelihoodPredicate( double totalLikelihood, Fitness * fitnessFunc ) :
	m_TotalLikelihood( totalLikelihood ), m_FitnessFunc( fitnessFunc )
{
}

SortByLikelihoodPredicate::~SortByLikelihoodPredicate()
{
}

bool SortByLikelihoodPredicate::operator () ( Chromosome * chr1, Chromosome * chr2 )
{
	double prob1 = chr1->getDistributionProb();
	double prob2 = chr2->getDistributionProb();

	if( prob1 > prob2 )
	{
		return true;
	}
	return false;
}













