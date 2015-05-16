/*
 * GeneticAlgorithm.cpp
 *
 *  Created on: 28 апр. 2015
 *      Author: vadim
 */

#include "GeneticAlgorithm.h"
#include "FindChromosomePredicate.h"
#include "FindChromosomeFunctor.h"
#include <algorithm>
#include <fstream>
#include "Alleli.h"
using namespace std;

GeneticAlgorithm::GeneticAlgorithm( Population & population, Fitness & fitnessFunc ) :
	m_FitnessFunc( fitnessFunc ), m_Population( population ),
	m_Terminate( false ), m_ParentChromosomesSurviveCount( ALL_PARENTAL_CHROMOSOMES ), m_Iteration( 0 )
{
	m_Population.setFitnesFunc( & m_FitnessFunc );
	m_ChromosomesComparator.setFitness( & m_FitnessFunc );
	m_Population.calculateFitnesses();
	m_Population.sortPopulationByFitness();
	m_ParentChromosomesSurviveCount = m_Population.getSize();
}


GeneticAlgorithm::~GeneticAlgorithm()
{
	;
}

void GeneticAlgorithm::addMutations( Population & population )
{
	int parentPopulationSize = m_Population.getSize();

	for( int i = 0 ; i < parentPopulationSize ; i++ )
	{
		Chromosome * chromosome = m_Population.getChromosomeByIndex( i );
		do
		{
			Chromosome * mutated = chromosome->mutate();

			vector< Chromosome *> chromosomes;
			population.getChromosomes( chromosomes );
			FindChromosomePredicate findChromosome( mutated );
			if( find_if( chromosomes.begin(), chromosomes.end(), findChromosome ) != chromosomes.end() )
			{
				continue;
			}

			population.addChromosome( mutated );
			break;

		}while( true );
	}
}

//void GeneticAlgorithm::addCrossovers( Population & population )
//{
//	int parentPopulationSize = m_Population.getSize();
//
//	for( int i = 0 ; i < parentPopulationSize ; i++ )
//	{
//		Chromosome * chromosome = m_Population.getChromosomeByIndex( i );
//
//		do
//		{
//			Chromosome * otherChromosome = m_Population.getRandomChromosome();
//			if( otherChromosome == chromosome )
//			{
//				continue;
//			}
//			vector< Chromosome * > crossovered = chromosome->crossover( otherChromosome );
//			vector< Chromosome * >::iterator begin = crossovered.begin();
//			vector< Chromosome * >::iterator end = crossovered.end();
//			vector< Chromosome * >::iterator iter = begin;
//			for(  ; iter != end ; iter++ )
//			{
//				vector< Chromosome *> chromosomes;
//				population.getChromosomes( chromosomes );
//				FindChromosomePredicate findChromosome( * iter );
//				if( find_if( chromosomes.begin(), chromosomes.end(), findChromosome ) != chromosomes.end() )
//				{
//					continue;
//				}
//				population.addChromosome( * iter );
//			}
//			break;
//		}while( true );
//	}
//}

void GeneticAlgorithm::addCrossovers( Population & population )
{
	int parentPopulationSize = m_Population.getSize();

	const double average = 100.0 / parentPopulationSize;

	for( int gene_level_1_i = 0 ; gene_level_1_i < parentPopulationSize ; gene_level_1_i++ )
	{
		Chromosome * chromosome = m_Population.getChromosomeByIndex( gene_level_1_i );

		double prob = chromosome->getDistributionProb();

		const double totalRatio = ( prob / average) * 100.0;
		unsigned int crossing_count = ceil( prob / average );

		double floating = 0.0;
		double d = modf( totalRatio, &floating );

		double totalRatioBackCounter = totalRatio;

		for( unsigned int time_i = 0 ; time_i < crossing_count ; time_i++ )
		{
			int randProb = rand() % 100;

			if( ( totalRatioBackCounter - time_i * 100 ) < randProb )
			{
				break;
			}

			do
			{
				Chromosome * otherChromosome = m_Population.getRandomChromosome();
				if( otherChromosome == chromosome )
				{
					continue;
				}
				vector< Chromosome * > crossovered = chromosome->crossover( otherChromosome );
				vector< Chromosome * >::iterator begin = crossovered.begin();
				vector< Chromosome * >::iterator end = crossovered.end();
				vector< Chromosome * >::iterator iter = begin;
				for(  ; iter != end ; iter++ )
				{
					vector< Chromosome *> chromosomes;
					population.getChromosomes( chromosomes );
					FindChromosomePredicate findChromosome( * iter );
					if( find_if( chromosomes.begin(), chromosomes.end(), findChromosome ) != chromosomes.end() )
					{
						continue;
					}
					population.addChromosome( * iter );
				}
				break;
			}while( true );

		}
	}
}

void GeneticAlgorithm::constructNewPopulation( Population & population )
{
	int parentPopulationSize = m_Population.getSize();
	population.setFitnesFunc( & m_FitnessFunc );

	for( int chromosome_i = 0 ; ( chromosome_i < parentPopulationSize ) && ( chromosome_i < m_ParentChromosomesSurviveCount ) ; chromosome_i++ )
	{
		population.addChromosome( m_Population.getChromosomeByIndex( chromosome_i ) );
	}

	addMutations( population );
	addCrossovers( population );
}

void GeneticAlgorithm::evolve()
{
	Population newPopulation;
	constructNewPopulation( newPopulation );

	vector< Chromosome *> chromosomes;

	newPopulation.calculateFitnesses();
	newPopulation.sortPopulationByFitness();

	newPopulation.getChromosomes( chromosomes );
	dump( chromosomes );

	newPopulation.trim( m_ParentChromosomesSurviveCount );

	vector< Chromosome *> trimedChromosomes;
	newPopulation.getChromosomes( trimedChromosomes );

	////Add Lucky chromosomes
	const unsigned int luckyCount = 3;
	for( unsigned int lucky_i = 0 ; lucky_i < luckyCount ;  )
	{
		int random_idx = rand() % chromosomes.size();

		FindChromosomePredicate findChromosome( chromosomes[random_idx] );
		if( find_if( trimedChromosomes.begin(), trimedChromosomes.end(), findChromosome ) != trimedChromosomes.end() )
		{
			continue;
		}

		newPopulation.addChromosome( chromosomes[random_idx] );
		lucky_i++;
	}
	////////////////////////////////////////

	newPopulation.getChromosomes( chromosomes );
	dump( chromosomes );

	m_Population = newPopulation;
}

void GeneticAlgorithm::dump( vector<Chromosome *> & chromosomes )
{
	ofstream file( "/home/vadim/workspace_fann/NNGA_C++_WIthoutTemplates/dump_population.txt", ios_base::app );
	if( false == file.is_open() )
	{
		return;
	}

	file << endl << flush;

	size_t count = chromosomes.size();
	for( size_t chr_i = 0 ; chr_i < count ; chr_i++ )
	{
		Chromosome * chromosome = chromosomes[ chr_i ];
		Alleli * alleli = dynamic_cast< Alleli * >( chromosome );
		vector<ChromosomesType> genes;
		alleli->getGenes( genes );

		double total = 1 * genes[ 0 ];
		total += 2 * genes[ 1 ];
		total += 3 * genes[ 2 ];
		total += 4 * genes[ 3 ];

		double probability_width = chromosome->getDistributionProb();

		file << genes[0] << " " << genes[1] << " " << genes[2] << " " << genes[3] << "=" << total
			 << "; probability_width=" << probability_width << endl << flush;
	}
}

void GeneticAlgorithm::evolve( int count )
{
	m_Terminate = false;

	for( int i = 0 ; i < count ; i++ )
	{
		if( true == m_Terminate )
		{
			break;
		}
		evolve();
		m_Iteration = i + 1;
		vector< IterartionListener * >::iterator begin = m_IterationListeners.begin();
		vector< IterartionListener * >::iterator end = m_IterationListeners.end();
		vector< IterartionListener * >::iterator iter = begin;
		for(  ; iter != end ; iter++ )
		{
			(*iter)->update( this );
		}
	}
}


int GeneticAlgorithm::getIteration()
{
	return m_Iteration;
}


void GeneticAlgorithm::terminate()
{
	m_Terminate = true;
}

Population & GeneticAlgorithm::getPopulation()
{
	return m_Population;
}

Chromosome * GeneticAlgorithm::getBest()
{
	return m_Population.getChromosomeByIndex( 0 );
}


Chromosome * GeneticAlgorithm::getWorst()
{
	return m_Population.getChromosomeByIndex(m_Population.getSize() - 1);
}


void GeneticAlgorithm::setParentChromosomesSurviveCount( int parentChromosomesCount )
{
	m_ParentChromosomesSurviveCount = parentChromosomesCount;
}


int GeneticAlgorithm::getParentChromosomesSurviveCount()
{
	return m_ParentChromosomesSurviveCount;
}


void GeneticAlgorithm::addIterationListener( IterartionListener * listener)
{
	m_IterationListeners.push_back( listener );
}


void GeneticAlgorithm::removeIterationListener( IterartionListener * listener )
{
	vector< IterartionListener * >::iterator found_iter = find( m_IterationListeners.begin(), m_IterationListeners.end(), listener );
	if( found_iter == m_IterationListeners.end() )
	{
		return;
	}
	m_IterationListeners.erase( found_iter );
}


ChromosomesType GeneticAlgorithm::fitness( const Chromosome * chromosome)
{
	m_ChromosomesComparator.setFitness( & m_FitnessFunc );
	return m_ChromosomesComparator.fit( chromosome );
}


void GeneticAlgorithm::clearCache()
{
	m_IterationListeners.clear();
}


Fitness & GeneticAlgorithm::getFitnessFunc() const
{
	return m_FitnessFunc;
}



















