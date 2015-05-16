/*
 * Alleli.cpp
 *
 *  Created on: 6 мая 2015
 *      Author: vadim
 */

#include "Alleli.h"
#include <cstdlib>
#include <cassert>
#include <algorithm>

Alleli::Alleli( int expectedResult ) : m_Genes( 4, 0 ), m_ExpectedResult( expectedResult )
{
	size_t genesCount = m_Genes.size();
	for( size_t gene_i = 0 ; gene_i < genesCount ; gene_i++ )
	{
		m_Genes[ gene_i ] = rand() % ( m_ExpectedResult );
	}
}

Alleli::Alleli( const Alleli & src )
{
	m_Genes = src.m_Genes;
	m_ExpectedResult = src.m_ExpectedResult;
}

Alleli::~Alleli()
{
}

vector<Chromosome *> Alleli::crossover( Chromosome * anotherChromosome )
{
	Alleli * anotherAlleli = dynamic_cast<Alleli *>( anotherChromosome );
	int crossover = ( rand() % 3 ) + 1;//Create the crossover point ( not first )
	int first = rand() % 100;// Which parent comes first

	Alleli * child1 = new Alleli( *this );
	Alleli * child2 = new Alleli( *this );

	int initial_1 = 0, final_1 = 4;
	int initial_2 = 0, final_2 = 4;
	if( first < 50 )
	{
		initial_1 = crossover; //If first parent first, start from crossover
		final_2 = crossover;
	}
	else
	{
		final_1 = crossover; //Else end at crossover
		initial_2 = crossover;
	}

	vector<ChromosomesType> anotherGenes;
	anotherAlleli->getGenes( anotherGenes );

	vector<ChromosomesType> thisGenes_1;
	{

		child1->getGenes( thisGenes_1 );
		for( int gene_i = initial_1 ; gene_i < final_1 ; gene_i++ )//Crossover
		{
			thisGenes_1[ gene_i ] = anotherGenes[ gene_i ];
		}
		child1->setGenes( thisGenes_1 );
	}
	vector<ChromosomesType> thisGenes_2;
	{
		child2->getGenes( thisGenes_2 );
		for( int gene_i = initial_2 ; gene_i < final_2 ; gene_i++ )//Crossover
		{
			thisGenes_2[ gene_i ] = anotherGenes[ gene_i ];
		}
		child2->setGenes( thisGenes_2 );
	}

	vector<Chromosome *> res;
	res.push_back( child1 );
	res.push_back( child2 );
	return res;
}

void Alleli::getGenes(  vector<ChromosomesType> & genes ) const
{
	genes = m_Genes;
}

void Alleli::setGenes( vector<ChromosomesType> & genes )
{
	m_Genes = genes;
}

void Alleli::setFitness( double fitness )
{
	m_Fitness = fitness;
}

Chromosome * Alleli::mutate()
{
	Chromosome * chromosome = NULL;
	int choise = rand() % 6;
	switch( choise )
	{
		case 0:
				chromosome = mutateChangeRandomOneGene();
			break;
		case 1:
				chromosome = mutateChangeRandomAllGenes();
			break;
		case 2:
				chromosome = mutateRearangeRandomOneGenes();
			break;
		case 3:
				chromosome = mutateRearangeRandomAllGenes();
			break;
		case 4:
				chromosome = mutateRandomPlusOne();
			break;
		case 5:
				chromosome = mutateRandomMinusOne();
			break;
		default:
			assert( false );
			break;
	}
	return chromosome;
}

Chromosome * Alleli::mutateRandomPlusOne()
{
	Alleli * newChild = new Alleli( *this );
	{
		vector<ChromosomesType> genes;
		newChild->getGenes( genes );
		size_t chr_count = genes.size();
		int rand_gene_idx = rand() % chr_count;
		genes[ rand_gene_idx ] = genes[ rand_gene_idx ] + 1;

		newChild->setGenes( genes );
	}
	return newChild;
}

Chromosome * Alleli::mutateRandomMinusOne()
{
	Alleli * newChild = new Alleli( *this );
	{
		vector<ChromosomesType> genes;
		newChild->getGenes( genes );
		size_t chr_count = genes.size();
		int rand_gene_idx = rand() % chr_count;
		genes[ rand_gene_idx ] = genes[ rand_gene_idx ] - 1;

		newChild->setGenes( genes );
	}
	return newChild;
}

Chromosome * Alleli::mutateChangeRandomOneGene()
{
	Alleli * newChild = new Alleli( *this );
	{
		vector<ChromosomesType> genes;
		newChild->getGenes( genes );
		size_t chr_count = genes.size();
		int rand_gene_idx = rand() % chr_count;
		int rand_gene_value = rand() % ( m_ExpectedResult + 1 );
		genes[ rand_gene_idx ] = rand_gene_value;

		newChild->setGenes( genes );
	}
	return newChild;
}

Chromosome * Alleli::mutateChangeRandomAllGenes()
{
	Alleli * newChild = new Alleli( *this );
	{
		vector<ChromosomesType> genes;
		newChild->getGenes( genes );
		size_t genes_count = genes.size();
		for( unsigned int gene_i = 0 ; gene_i < genes_count ; gene_i++ )
		{
			int rand_gene_value = rand() % ( m_ExpectedResult + 1 );
			genes[ gene_i ] = rand_gene_value;
		}
		newChild->setGenes( genes );
	}
	return newChild;
}

Chromosome * Alleli::mutateRearangeRandomOneGenes()
{
	Alleli * newChild = new Alleli( *this );
	{
		vector<ChromosomesType> genes;
		newChild->getGenes( genes );
		size_t genes_count = genes.size();
		unsigned int first_index = rand() % genes_count;

		unsigned int second_index = 0;
		do
		{
			second_index = rand() % genes_count;

		}while( second_index == first_index );

		{
			ChromosomesType geneFirst = genes[first_index];
			ChromosomesType geneSecond = genes[second_index];
			genes[second_index] = geneFirst;
			genes[first_index] = geneSecond;//Optimization is not critical, first - readable
		}

		newChild->setGenes( genes );
	}
	return newChild;
}

Chromosome * Alleli::mutateRearangeRandomAllGenes()
{
	Alleli * newChild = new Alleli( *this );
	{
		vector<ChromosomesType> genes;
		newChild->getGenes( genes );

		random_shuffle( genes.begin(), genes.end() );

		newChild->setGenes( genes );
	}
	return newChild;
}

Alleli & Alleli::operator = ( const Alleli & src )
{
	if( this == &src )
	{
		return *this;
	}

	m_Genes = src.m_Genes;
	m_ExpectedResult = src.m_ExpectedResult;

	return *this;
}

















