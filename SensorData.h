#pragma once
template <typename T>
class SensorData
{
private :
	int id;
	T value;
public:
	SensorData(int new_id, T new_value);	
	~SensorData();
	SensorData(const SensorData &src);
	SensorData& operator =(const SensorData &src);

	void set_id(int new_id);
	void set_value(T new_value);

	T get_value()const;
	int get_id()const;
};

template <typename T>
SensorData<T>::SensorData(int new_id, T new_value)
{
	set_id(new_id);
	set_value(new_value);
}

template <typename T>
SensorData<T>::~SensorData()
{
	//empty
}

// why do you ask for both a cpy and assignement operator
template <typename T>
SensorData<T>::SensorData(const SensorData &src)
{
	set_id(src.get_id());
	set_value(src.get_value());
}

template <typename T>
SensorData<T>& SensorData<T>::operator =(const SensorData &src)
{
	if ( &src != this)
	{
		set_id(src.get_id());
		set_value(src.get_value());
	}
	return *this;
}

template <typename T>
void SensorData<T>::set_id(int new_id)
{
	id = new_id;
}

template <typename T>
void SensorData<T>::set_value(T new_value)
{
	value = new_value;
}

template <typename T>
int SensorData<T>::get_id()const
{
	return id;
}

template <typename T>
T SensorData<T>::get_value()const
{
	return value;
}
