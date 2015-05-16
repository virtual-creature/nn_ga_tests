/*
 * DistributeLikelihoodPredicate.cpp
 *
 *  Created on: 12 мая 2015
 *      Author: vadim
 */

#include "DistributeLikelihoodPredicate.h"

DistributeLikelihoodPredicate::DistributeLikelihoodPredicate( double totalLikelihood ) :
	m_SumPercent( 0.0 ), m_TotalLikelihood( totalLikelihood )
{
}

DistributeLikelihoodPredicate::DistributeLikelihoodPredicate( const DistributeLikelihoodPredicate & src )
{
	m_SumPercent = src.m_SumPercent;
	m_TotalLikelihood = src.m_TotalLikelihood;
}

DistributeLikelihoodPredicate::~DistributeLikelihoodPredicate()
{
}

void DistributeLikelihoodPredicate::operator () ( Chromosome * chr )
{
	double fitness = chr->getFitness();
	double invFitness = ( 1.0 / fitness );
	m_SumPercent = ( invFitness / m_TotalLikelihood ) * 100.0;

	if( m_SumPercent == 0.0 )
	{
		int a = 0;
		a++;
	}

	chr->setDistributionProb( m_SumPercent );
}















