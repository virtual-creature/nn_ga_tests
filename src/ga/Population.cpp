/*
 * Population.cpp
 *
 *  Created on: 28 апр. 2015
 *      Author: vadim
 */

#include "Population.h"
#include "SumInvertFitnessPredicate.h"
#include "SortByLikelihoodPredicate.h"
#include "CalculateFitnessForEachPredicate.h"
#include "DistributeLikelihoodPredicate.h"
#include <algorithm>
using namespace std;

Population::Population() :
		m_FitnessFunc( NULL )
{
}

Population::Population( const Population & src ) : m_FitnessFunc( NULL )
{
	m_Chromosomes = src.m_Chromosomes;
}

Population::~Population()
{
}

Population & Population::operator = ( const Population & src )
{
	if( this == &src )
	{
		return *this;
	}

	m_Chromosomes = src.m_Chromosomes;

	return *this;
}

void Population::setFitnesFunc( Fitness * fitnessFunc )
{
	m_FitnessFunc = fitnessFunc;
}

void Population::addChromosome( Chromosome * chromosome )
{
	m_Chromosomes.push_back( chromosome );
}

int Population::getSize() const
{
	return m_Chromosomes.size();
}

Chromosome * Population::getRandomChromosome() const
{
	int numOfChromosomes = m_Chromosomes.size();
	// TODO improve random generator
	// maybe use pattern strategy ?
	int indx = ( rand() % numOfChromosomes );
	return m_Chromosomes[ indx ];
}

Chromosome * Population::getChromosomeByIndex( int indx ) const
{
	return m_Chromosomes[ indx ];
}

void Population::getChromosomes( vector< Chromosome * > & chromosomes ) const
{
	chromosomes = m_Chromosomes;
}

void Population::sortPopulationByFitness()
{
	random_shuffle( m_Chromosomes.begin(), m_Chromosomes.end() );

	SumInvertFitnessPredicate sumlikelihood( m_FitnessFunc );
	double totalLikehood = accumulate( m_Chromosomes.begin(), m_Chromosomes.end(), (ChromosomesType)0, sumlikelihood );

	DistributeLikelihoodPredicate distributeLikelihood( totalLikehood );
	for_each( m_Chromosomes.begin(), m_Chromosomes.end(), distributeLikelihood );

	SortByLikelihoodPredicate sortByLikehood( totalLikehood, m_FitnessFunc );
	sort( m_Chromosomes.begin(), m_Chromosomes.end(), sortByLikehood );
}

void Population::calculateFitnesses()
{
	CalculateFitnessForEachPredicate calculateFitness( m_FitnessFunc );
	for_each( m_Chromosomes.begin(), m_Chromosomes.end(), calculateFitness );
}

/**
* shortening population till specific number
*/
void Population::trim( int len )
{
	vector< Chromosome * > temp( m_Chromosomes.begin(), m_Chromosomes.begin() + len );
//	vector< Chromosome * >::iterator begin = m_Chromosomes.begin() + len;
//	vector< Chromosome * >::iterator end = m_Chromosomes.end();
//	vector< Chromosome * >::iterator iter = begin;
//	for(  ; iter != end ; iter++ )
//	{
//		delete (* iter);
//	}
	m_Chromosomes.swap( temp );
}



















