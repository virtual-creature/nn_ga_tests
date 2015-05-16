/*
 * Chromosome.cpp
 *
 *  Created on: 12 мая 2015
 *      Author: vadim
 */

#include "Chromosome.h"

void Chromosome::setDistributionProb( double value )
{
	m_ProbabilityDistribution = value;
}

double Chromosome::getDistributionProb() const
{
	return m_ProbabilityDistribution;
}

double Chromosome::getFitness() const
{
	return m_Fitness;
}
















