#pragma once
#include "BaseSensorBuffer.h"
#include <iostream>
#include <map>
#include <list>


template <typename T>
class MapListSensorBuffer : public BaseSensorBuffer<T>
{	
	std::map< int ,list <SensorData<T> > > buffer;		//Warning prior to C++11 putting < Type <type >> was considered a sentax error as >> is a stream opertor

	void store(SensorData<T>& data);
	void retreive(int sensorId);
	void saveBufferToFile(const char* outName);
};



template <typename T>
void MapListSensorBuffer<T>::store(SensorData<T>& data)
{
	buffer[data.get_id()].push_back(data);
}


template <typename T>
void MapListSensorBuffer<T>::retreive(int sensorId)
{
	// if ( a  && b ) processes A if false quit

	//if(buffer.contains(sensorId)) { // c++20
	if(buffer.find(sensorId) != buffer.end() && buffer[sensorId].size() !=0)
	{
			buffer[sensorId].pop_front();
	}
}


template <typename T>
void MapListSensorBuffer<T>::saveBufferToFile(const char* outName)
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
		for (auto  it = (*i).second.begin(); it != (*i).second.end(); ++it)
		{
			outFile << (*it).get_id() << " " << (*it).get_value()<<endl;
		}
	}
	outFile.close();
}
