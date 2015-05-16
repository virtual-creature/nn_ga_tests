/*
 * Links.h
 *
 *  Created on: 5 мая 2015
 *      Author: vadim
 */

#ifndef NN_LINKS_H_
#define NN_LINKS_H_

#include <vector>
#include <map>
using namespace std;

class Links
{
public:
	Links();
	Links( const Links & src );
	Links & operator == ( const Links & src );
	virtual ~Links();

	map<int, map<int, double> > m_Links;

	unsigned int m_TotalLinksCount;

	vector<int> getReceivers( int activatorNeuronNumber );
	double getWeight( int activatorNeuronNumber, int receiverNeuronNumber );
	void addWeight( int activatorNeuronNumber, int receiverNeuronNumber, double weight );
	void getAllWeights( vector<double> & weights );

	void setAllWeights( vector<double> & weights);
};

#endif /* NN_LINKS_H_ */
