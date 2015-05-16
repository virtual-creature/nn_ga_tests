/*
 * Random.h
 *
 *  Created on: 6 мая 2015
 *      Author: vadim
 */

#ifndef RANDOM_H_
#define RANDOM_H_

#include <vector>
#include <random>
#include <iomanip>
using namespace std;

class Random
{
public:
	Random();
	virtual ~Random();

	int nextInt();
	int nextInt( int n );
	bool nextBoolean();
	float nextFloat();
	double nextGaussian();

private:

	std::random_device m_RandDevice;

	std::mt19937 m_MersenneTwister;

	const double m_Mean;
	const double m_Deviation;

	std::normal_distribution<> m_NormalDistribution;

};

#endif /* RANDOM_H_ */
