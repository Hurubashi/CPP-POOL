
#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array
{
public:
	Array(void);
	Array(unsigned int n);
	Array(const Array & arr);
	~Array(void);
	Array 	& operator=(const Array & arr);

	T		& operator[](unsigned int index);

	unsigned int	size(void) const;

public:
	T				* _arr;
	unsigned int	_size;
};

template<typename T>
Array<T>::Array(void)
{
	this->_arr = new T[0];
	this->_size = 0;
	return ;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	this->_arr = new T[n];
	this->_size = n;
	return ;
}

template<typename T>
Array<T>::Array(const Array<T> & arr)
{
	*this = arr;
	return ;
}

template<typename T>
Array<T>::~Array(void)
{
	delete [] this->_arr;
	return;
}

template<typename T>
Array<T> 	& Array<T>::operator=(const Array<T> & arr)
{
	delete [] this->_arr;
	this->_arr = new T[arr._size];
	for (unsigned int i = 0; i < arr._size; i++) {
		this->_arr[i] = arr._arr[i];
	}
	this->_size = arr._size;
	return (*this);
}


template<typename T>
T		& Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size || index < 0) {
		throw (std::exception());
	}
	return (this->_arr[index]);
}

template<typename T>
unsigned int 	Array<T>::size(void) const
{
	return (this->_size);
}


#endif
