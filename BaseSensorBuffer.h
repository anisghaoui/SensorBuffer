#pragma once
#include <fstream>
#include <iostream>
#include "SensorData.h"

using namespace std;

template <typename T>
class BaseSensorBuffer
{
private:
	virtual void store(SensorData<T>& data); // why not const data?
	virtual void retreive(int sensorId);
	virtual void saveBufferToFile(const char* outName);
public:
	BaseSensorBuffer();
	~BaseSensorBuffer();
	
	void read (const char* fName, const char* outputFile);
};

template <typename T>
BaseSensorBuffer<T>::BaseSensorBuffer()
{
	//empty
}

template <typename T>
BaseSensorBuffer<T>::~BaseSensorBuffer()
{
	//empty
}

template <typename T>
void BaseSensorBuffer<T>::read(const char* fName, const char* outputFile)
{
	
	ifstream inFile;
	inFile.open(fName);
	if (!inFile) {
 		cerr << "Unable to open file "<<fName << "; maybe it is missing ? your folder contains: "<<endl;
    	#if defined(_WIN32)
    		system("dir");
    	#else
    		system("ls");
    	#endif
    	exit(1);   // call system to stop
    }
    T order, id, value;
	while (inFile >> order >>id ) 
	{	
		if (order == 0){
			inFile>>value;
			SensorData<T> data(id,value);
			store(data);
		}
		else
			retreive(id);
	}
	inFile.close();
	saveBufferToFile(outputFile);
}

template <typename T>
void BaseSensorBuffer<T>::store(SensorData<T>& data)
{
	cout << "stored data "<< data.get_value()<<" from sensor #" <<data.get_id()<<endl;
}


template <typename T>
void BaseSensorBuffer<T>::retreive(int sensorId)
{
	cout << "retreived data  from sensor #" <<sensorId <<endl;
}

template <typename T>
void BaseSensorBuffer<T>::saveBufferToFile(const char* outName)
{
	ofstream outFile;
	outFile.open(outName);
	if (!outFile)
	{
		cerr << "Unable to create file named "<<outName<<"; maybe you don't have the right permissions ?"<<endl;
		exit(2);
	}

	cout <<"I'm just a base buffer, I did not save any data actually. Sorry, human"<<endl;
	outFile.close();
}