//============================================================================
// Name        : NNGA_C++.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Diophantine.h"
#include <iostream>
using namespace std;

void test_1();
void test_2();

int main() {
	srand( (unsigned int) time( NULL ) );

	test_2();

	cout << __cplusplus << endl;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}

void test_1()
{
	Diophantine dp( 1, 2, 3, 4, 3299 );//30
	Alleli * allie = dp.Solve();
	if( NULL == allie )
	{
		cout << "No solution found." << endl << flush;
	}
	else
	{
		cout << "Solution found." << endl << flush;
		vector<ChromosomesType> genes;
		allie->getGenes( genes );

		cout << genes[0] * 1 << "+" << genes[1] * 2 << "+" << genes[2] * 3 << "+" << genes[3] * 4 << "="
				<< genes[0] * 1 + genes[1] * 2 + genes[2] * 3 + genes[3] * 4 << endl << flush;
	}
}

#include "EvolvingNeuralNetwork.h"
#include <fstream>

static void dump( vector<double> & input )
{
	ofstream file( "dump.txt", ios_base::app );

	for( size_t i = 0 ; i < input.size() ; i++ )
	{
		file << input[i] << " " << std::flush;
	}
	file << endl;
	file.close();
}

void test_2()
{
	const unsigned int input_count = 2;
	const unsigned int output_count = 1;
	vector<size_t> hiddenLayers;
	hiddenLayers.push_back( 2 );
	CLayersConfiguration sequence( input_count, output_count, hiddenLayers );

	EvolvingNeuralNetwork network( sequence );
	vector<double> genes;
	network.getGenes( genes );

	dump( genes );

	EvolvingNeuralNetwork * mutated = dynamic_cast<EvolvingNeuralNetwork *>( network.mutate() );

	genes.clear();
	mutated->getGenes( genes );

	dump( genes );

	size_t genesCount = genes.size();


	int a = 0;
	a++;
}
