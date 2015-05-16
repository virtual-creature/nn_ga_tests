/*
 * Population.h
 *
 *  Created on: 28 апр. 2015
 *      Author: vadim
 */

#ifndef GA_POPULATION_H_
#define GA_POPULATION_H_

#include "ChromosomesComparator.h"
#include "Fitness.h"
#include <vector>
#include <cstdlib>
using namespace std;

class Population
{
public:
	Population();
	Population( const Population & src );
	virtual ~Population();

	Population & operator = ( const Population & src );

	void addChromosome( Chromosome * chromosome );

	int getSize() const;

	void setFitnesFunc( Fitness * fitnessFunc );

	Chromosome * getRandomChromosome() const;

	Chromosome * getChromosomeByIndex( int indx ) const;

	void getChromosomes( vector< Chromosome * > & chromosomes ) const;

	void sortPopulationByFitness();

	void calculateFitnesses();

	/**
	 * shortening population till specific number
	 */
	void trim( int len );

private:

	vector< Chromosome * > m_Chromosomes;

	Fitness * m_FitnessFunc;

};

#endif /* GA_POPULATION_H_ */
