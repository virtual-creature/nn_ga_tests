/*
 * FindChromosomeFunctor.cpp
 *
 *  Created on: 13 мая 2015
 *      Author: vadim
 */

#include <FindChromosomeFunctor.h>

FindChromosomeFunctor::FindChromosomeFunctor( vector<Chromosome *> & chromosomes ) :
	m_Chromosomes( chromosomes )
{
}

FindChromosomeFunctor::~FindChromosomeFunctor()
{
}

bool FindChromosomeFunctor::operator() ( const Chromosome * chromosome )
{
	return true;
}













