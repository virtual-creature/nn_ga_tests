/*
 * Random.cpp
 *
 *  Created on: 6 мая 2015
 *      Author: vadim
 */

#include "Random.h"
#include <cassert>
#include <cmath>
#include <ctime>

Random::Random() : m_MersenneTwister( m_RandDevice() ), m_Mean( 7 ), m_Deviation( 2 ), m_NormalDistribution( m_Mean, m_Deviation )
{
	srand( (unsigned int) time( NULL ) );
}

Random::~Random()
{
}

int Random::nextInt()
{
	return rand();//next( 32 );
}

int Random::nextInt( int n )
{
	return rand() % n;
}

bool Random::nextBoolean()
{
	return ( rand() % 2 ) != 0;
}

float Random::nextFloat()
{
	return (float)( (double)rand() / (double)RAND_MAX );//next( 24 ) / (float) ( 1 << 24 );
}

double Random::nextGaussian()
{
    return m_NormalDistribution( m_MersenneTwister );
}















