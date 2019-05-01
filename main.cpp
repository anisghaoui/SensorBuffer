#include <iostream>
#include "SensorData.h"			// for test purpose only
#include "BaseSensorBuffer.h"	// for test purpose only
#include "Optimized_MapListSensorBuffer.h"
#include "VectorSensorBuffer.h"
#include "ListSensorBuffer.h"
#include "MapListSensorBuffer.h"
#include <string>
#include <fstream>

#include <time.h>


int number_of_files =12; // MODIFY ME !

using namespace std;

void test_sensor()
{
	
	SensorData<int> A(1,2);
	SensorData<int> B(A);
	SensorData<int> C(2,-5);
	C = A;
}
void test_buffer()
{
	BaseSensorBuffer<int> bsb;
	bsb.read("sensors.txt","outBaseInt.txt");
}

void test_vector()
{
	VectorSensorBuffer<int> vsb;
	vsb.read("sensors.txt","outVectorInt.txt");
}

void test_list()
{
	ListSensorBuffer<int> lsb;
	lsb.read("sensors.txt","outListInt.txt");
}


void test_Maplist()
{
	MapListSensorBuffer<int> mlsb;

	mlsb.read("sensors.txt","outMapListInt.txt");
}

void test_asymptotic()
{
	int i = 0;

	double time_taken ;
	clock_t t;
	VectorSensorBuffer<float> vsb;
	ListSensorBuffer<float> lsb;
	MapListSensorBuffer<float> mlsb;
	Optimized_MapListSensorBuffer<float> omsb;
	string inputfilename ="largedata.txt";
	
    t = clock(); 
	vsb.read(inputfilename.c_str(),"outVector.txt");
	t = clock() - t; 
	
	time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 

	cout << " vector processing took : "<<time_taken <<" s"<<endl;

    

	t = clock(); 
	lsb.read(inputfilename.c_str(),"outList.txt");
	t = clock() - t; 

	time_taken = ((double)t)/CLOCKS_PER_SEC; 
	cout << " list processing took : "<<time_taken <<" s"<<endl;

	t = clock(); 
	mlsb.read(inputfilename.c_str(),"outMapList.txt");
	t = clock() - t; 

	time_taken = ((double)t)/CLOCKS_PER_SEC; 

	cout << " Map of lists processing took : "<<time_taken <<" s"<<endl;

	t = clock();

	omsb.read(inputfilename.c_str(),"outMapList.txt");
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC; 
	cout << " Otimized Map of lists processing took : "<<time_taken <<" s"<<endl;
}

void timing_test()
{
	ifstream inputfile;
	ofstream out;
	out.open("timing.txt");
	string filename;
	string a("largedata");
	string b(".txt");
	
	clock_t clk;
	double time;

	for (int i = 0; i < number_of_files; ++i)
	{	
		filename = a + to_string(i) + b;
		inputfile.open(filename.c_str());


		out << i << " ";

		VectorSensorBuffer<float> V;
		ListSensorBuffer<float> L;
		MapListSensorBuffer<float> M;	

		clk = clock();
		V.read(filename.c_str(),"outVector.txt");
		clk = clock() - clk;
		time = (double)clk / CLOCKS_PER_SEC;

		out << time << " ";

		clk = clock();
		L.read(filename.c_str(),"outList.txt");
		clk = clock() - clk;
		time = (double)clk / CLOCKS_PER_SEC;

		out << time << " ";


		clk = clock();
		M.read(filename.c_str(),"outMapList.txt");
		clk = clock() - clk;
		time = (double)clk / CLOCKS_PER_SEC;

		out << time << endl;
		inputfile.close();
	}
	out.close();
}

void test_opt()
{
	Optimized_MapListSensorBuffer <float> Opt;
	Opt.read("sensors.txt","outOpt.txt");
}

int main(int argc, char const *argv[])
{
	//test_sensor();
	//test_buffer();
	//test_vector();
	//test_list();
	//test_Maplist();
	test_asymptotic();
	//timing_test();

	//test_opt();

cout <<"programmed executed with no errors"<<endl;

	return 0;
}