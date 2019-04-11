#include <iostream>
#include "SensorData.h"			// for test purpose only
#include "BaseSensorBuffer.h"	// for test purpose only

#include "VectorSensorBuffer.h"
#include "ListSensorBuffer.h"
#include "MapListSensorBuffer.h"
#include <string>
#include <fstream>

#include <time.h>

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
	string inputfilename;
	string input = "largedata";
	string txt = ".txt";

	ofstream out("timemeasure.txt");

	for (int i = 0; i < 32; ++i)
	{
		out << i<< " ";

		VectorSensorBuffer<float> vsb;
		ListSensorBuffer<float> lsb;
		MapListSensorBuffer<float> mlsb;
		inputfilename ="";
		inputfilename.append(input);
		inputfilename.append(std::to_string(i));
		inputfilename.append(txt);
		
	    t = clock(); 
		vsb.read(inputfilename.c_str(),"outVector.txt");
		t = clock() - t; 
		
		time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 

		out << time_taken << " ";

		//cout << " vector processing took : "<<time_taken <<" s"<<endl;

	    

		t = clock(); 
		lsb.read(inputfilename.c_str(),"outList.txt");
		t = clock() - t; 

		time_taken = ((double)t)/CLOCKS_PER_SEC; 
		out << time_taken<< " ";

		//cout << " list processing took : "<<time_taken <<" s"<<endl;


		t = clock(); 
		mlsb.read(inputfilename.c_str(),"outMapList.txt");
		t = clock() - t; 

		time_taken = ((double)t)/CLOCKS_PER_SEC; 

		//cout << " Map of lists processing took : "<<time_taken <<" s"<<endl;

		out << time_taken<< endl;
	}
}

int main(int argc, char const *argv[])
{
	//test_sensor();
	//test_buffer();
	//test_vector();
	//test_list();
	//test_Maplist();

	test_asymptotic();
	

cout <<"programmed executed with no errors"<<endl;

	return 0;
}