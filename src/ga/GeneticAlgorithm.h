/*
 * GeneticAlgorithm.h
 *
 *  Created on: 28 апр. 2015
 *      Author: vadim
 */

#ifndef GA_GENETICALGORITHM_H_
#define GA_GENETICALGORITHM_H_

#include "Fitness.h"
#include "ChromosomesComparator.h"
#include "Population.h"
#include "IterartionListener.h"
#include <vector>
#include <limits.h>
using namespace std;

#define ALL_PARENTAL_CHROMOSOMES INT_MAX

class GeneticAlgorithm
{
public:
	GeneticAlgorithm( Population & population, Fitness & fitnessFunc );
	virtual ~GeneticAlgorithm();

	void evolve();

	void evolve( int count );

	int getIteration();

	void terminate();

	Population & getPopulation();

	Chromosome * getBest();

	Chromosome * getWorst();

	Fitness & getFitnessFunc() const;

	void setParentChromosomesSurviveCount( int parentChromosomesCount );

	int getParentChromosomesSurviveCount();

	void addMutations( Population & population );
	void addCrossovers( Population & population );
	void constructNewPopulation( Population & population );

	void addIterationListener( IterartionListener * listener );

	void removeIterationListener( IterartionListener * listener );

	double fitness( const Chromosome * chromosome );

	void clearCache();

	void dump( vector<Chromosome *> & chromosomes );

private:

	ChromosomesComparator m_ChromosomesComparator;

	Fitness & m_FitnessFunc;

	Population & m_Population;

	// listeners of genetic algorithm iterations (handle callback afterwards)
	vector< IterartionListener * > m_IterationListeners;

	bool m_Terminate;

	// number of parental chromosomes, which survive (and move to new
	// population)
	int m_ParentChromosomesSurviveCount;

	int m_Iteration;

};

#endif /* GA_GENETICALGORITHM_H_ */
