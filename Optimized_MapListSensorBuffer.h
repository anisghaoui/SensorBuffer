#pragma once
#include "BaseSensorBuffer.h"
#include <iostream>
#include <map>
#include <list>
#include <utility> 


static unsigned int count = 0;


template <typename T>
class Optimized_MapListSensorBuffer : public BaseSensorBuffer<T>
{	

	std::map< int ,list < std::pair <int,SensorData<T> > > > buffer;		//Warning prior to C++11 putting < Type <type >> was considered a sentax error as >> is a stream opertor

	void store(SensorData<T>& data);
	void retreive(int sensorId);
	void saveBufferToFile(const char* outName);
};



template <typename T>
void Optimized_MapListSensorBuffer<T>::store(SensorData<T> & data)
{
	buffer[data.get_id()].push_back(std::pair<int,SensorData<T> > (++count,data));
}


template <typename T>
void Optimized_MapListSensorBuffer<T>::retreive(int sensorId)
{
	// if ( a  && b ) processes A if false quit

	//if(buffer.contains(sensorId)) { // c++20
	if(buffer.find(sensorId) != buffer.end() && buffer[sensorId].size() !=0)
	{
			buffer[sensorId].pop_front();
	}
}


template <typename T>
void Optimized_MapListSensorBuffer<T>::saveBufferToFile(const char* outName)
{
	ofstream outFile;
	outFile.open(outName);
	if (!outFile)
	{
		cerr << "Unable to create file named "<<outName<<"; maybe you don't have the right permissions ?"<<endl;
		exit(2);
	}
	for (auto i = buffer.begin(); i != buffer.end(); ++i)
	{
		std::vector<char> v;
		(*i).second.second.get_value();
	}
	outFile.close();
}


/*

for (auto  it = (*i).second.begin(); it != (*i).second.end(); ++it)
{
	outFile << (*it).second.get_id() << " " << (*it).second.get_value()<<endl;
}

*/
