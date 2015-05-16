/*
 * Links.cpp
 *
 *  Created on: 5 мая 2015
 *      Author: vadim
 */

#include "Links.h"
#include <algorithm>
#include <cassert>

Links::Links() : m_TotalLinksCount( 0 )
{
}

Links::Links( const Links & src )
{
	m_TotalLinksCount = src.m_TotalLinksCount;
	m_Links = src.m_Links;
}

Links & Links::operator == ( const Links & src )
{
	if( this == &src )
	{
		return * this;
	}
	m_TotalLinksCount = src.m_TotalLinksCount;
	m_Links = src.m_Links;

	return *this;
}

Links::~Links()
{
}

vector<int> Links::getReceivers( int activatorNeuronNumber )
{
	vector<int> ret;
	if( m_Links.find( activatorNeuronNumber ) != m_Links.end() )
	{
		map<int, double> & receiverMap = m_Links[activatorNeuronNumber];
		map<int, double>::iterator begin = receiverMap.begin();
		map<int, double>::iterator end = receiverMap.end();
		map<int, double>::iterator iter = begin;
		for(  ; iter != end ; iter++ )
		{
			ret.push_back( (* iter).first );
		}
	}
	return ret;
}

double Links::getWeight( int activatorNeuronNumber, int receiverNeuronNumber )
{
	double weight = 0;

	if( m_Links.find( activatorNeuronNumber ) != m_Links.end() )
	{
		map<int, double> receiverNumToWeight = m_Links[activatorNeuronNumber];

		if( receiverNumToWeight.find( receiverNeuronNumber ) != receiverNumToWeight.end() )
		{
			weight = receiverNumToWeight[ receiverNeuronNumber ];
		}
		else
		{
			assert( false );
//			throw new IllegalArgumentException();
		}
	} else {
		assert( false );
//		throw new IllegalArgumentException();
	}
	return weight;
}

void Links::addWeight(int activatorNeuronNumber, int receiverNeuronNumber, double weight)
{
	if( m_Links.find( activatorNeuronNumber ) == m_Links.end() )
	{
		m_Links[activatorNeuronNumber] = map<int, double>();
	}
	m_Links[activatorNeuronNumber][receiverNeuronNumber] = weight;
	m_TotalLinksCount++;
}

void Links::getAllWeights( vector<double> & weights )
{
	weights.resize( m_TotalLinksCount, 0.0 );

	map<int, map<int, double> >::iterator begin = m_Links.begin();
	map<int, map<int, double> >::iterator end = m_Links.end();
	map<int, map<int, double> >::iterator iter = begin;

	for(   ; iter != end ; iter++ )
	{
		int activatorIndx = (* iter).first;
		map<int, double> & receiverIndxToWeight = m_Links[activatorIndx];

		map<int, double>::iterator receiver_begin = receiverIndxToWeight.begin();
		map<int, double>::iterator receiver_end = receiverIndxToWeight.end();
		map<int, double>::iterator receiver_iter = receiver_begin;

		for(   ; receiver_iter != receiver_end ; receiver_iter++ )
		{
			weights.push_back( (* receiver_iter).second );
		}
	}
}

void Links::setAllWeights( vector<double> & weights )
{
	if( weights.size() != m_TotalLinksCount)
	{
		assert( false );
//		throw new IllegalArgumentException("Number of links is " + this.totalLinksCount
//				+ ". But weights list has size " + weights.size());
	}

	int indx = 0;
	map<int, map<int, double> >::iterator begin = m_Links.begin();
	map<int, map<int, double> >::iterator end = m_Links.end();
	map<int, map<int, double> >::iterator iter = begin;

	for(   ; iter != end ; iter++ )
	{
		int activatorIndx = (* iter).first;
		map<int, double> & receiverIndxToWeight = m_Links[ activatorIndx ];


		map<int, double>::iterator receiver_begin = receiverIndxToWeight.begin();
		map<int, double>::iterator receiver_end = receiverIndxToWeight.end();
		map<int, double>::iterator receiver_iter = receiver_begin;

		for(   ; receiver_iter != receiver_end ; receiver_iter++ )
		{
			(* receiver_iter).second = weights[indx];
			indx++;
		}
	}
}



















