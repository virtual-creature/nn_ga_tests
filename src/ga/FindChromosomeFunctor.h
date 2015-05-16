/*
 * FindChromosomeFunctor.h
 *
 *  Created on: 13 мая 2015
 *      Author: vadim
 */

#ifndef GA_FINDCHROMOSOMEFUNCTOR_H_
#define GA_FINDCHROMOSOMEFUNCTOR_H_

#include "Chromosome.h"
#include <vector>
using namespace std;

class FindChromosomeFunctor
{
public:
	FindChromosomeFunctor( vector<Chromosome *> & chromosomes );
	virtual ~FindChromosomeFunctor();

	bool operator() ( const Chromosome * chromosome );

private:

	vector<Chromosome *> & m_Chromosomes;

};

#endif /* GA_FINDCHROMOSOMEFUNCTOR_H_ */
