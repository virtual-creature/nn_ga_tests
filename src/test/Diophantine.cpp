/*
 * Diophantine.cpp
 *
 *  Created on: 6 мая 2015
 *      Author: vadim
 */

#include "Diophantine.h"
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

Diophantine::Diophantine( int a, int b, int c, int d, int res ) :
	m_A( a ), m_B( b ), m_C( c ), m_D( d ), m_ExpectedResult( res ),
	m_FitnessFunction( m_A, m_B, m_C, m_D, m_ExpectedResult ),
	m_GA( NULL )
{
}

Diophantine::~Diophantine()
{
}

void Diophantine::fillInitialPopulation( int populationSize )
{
	for( int i = 0; i < populationSize; i++ )
	{
		Alleli * chr = new Alleli( m_ExpectedResult );
		m_Population.addChromosome( chr );
	}
}

void Diophantine::dump( vector<Chromosome *> & chromosomes )
{
	ofstream file( "/home/vadim/workspace_fann/NNGA_C++_WIthoutTemplates/dump.txt", ios_base::app );
	if( false == file.is_open() )
	{
		return;
	}

	file << endl << flush;
	size_t count = chromosomes.size();
	for( size_t chr_i = 0 ; chr_i < count ; chr_i++ )
	{
		Alleli * alleli = dynamic_cast< Alleli * >( chromosomes[ chr_i ] );
		vector<ChromosomesType> genes;
		alleli->getGenes( genes );

		double total = m_A * genes[ 0 ];
		total += m_B * genes[ 1 ];
		total += m_C * genes[ 2 ];
		total += m_D * genes[ 3 ];

		file << genes[0] << " " << genes[1] << " " << genes[2] << " " << genes[3] << "=" << total << endl << flush;
	}
}

void Diophantine::update( GeneticAlgorithm * environment )
{
	Alleli * best = dynamic_cast< Alleli * >( environment->getBest() );
	Alleli * worst = dynamic_cast< Alleli * >( environment->getWorst() );
	int iterationCount = environment->getIteration();

	vector<ChromosomesType> genes;
	best->getGenes( genes );

	double total = m_A * genes[ 0 ];
	total += m_B * genes[ 1 ];
	total += m_C * genes[ 2 ];
	total += m_D * genes[ 3 ];

	vector< Chromosome * > chromosomes;
	m_Population.getChromosomes( chromosomes );

	dump( chromosomes );

	if( m_ExpectedResult == total )
	{
		int a = 0;
		a++;
		environment->terminate();
	}
	int iteration = m_GA->getIteration();

	cout << "m_ExpectedResult=" << m_ExpectedResult << "; Best=" << total << endl << flush;
}

Alleli * Diophantine::Solve()
{
	fillInitialPopulation( 3 );

	m_GA = new GeneticAlgorithm( m_Population, m_FitnessFunction );

	m_GA->addIterationListener( this );
	int iterationsCountMax = 100000;
	m_GA->evolve( iterationsCountMax );
	if( iterationsCountMax == m_GA->getIteration() )
	{
		return NULL;
	}
	Alleli * best = dynamic_cast<Alleli *>( m_GA->getBest() );
	return best;
}















