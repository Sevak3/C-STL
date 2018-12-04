#include "Vector.h"
#include <cassert>

Vector::Vector()
	: m_capacity(10)
	, m_size(0)
	, m_data(new int[m_capacity])
{
}

Vector::Vector(const Vector& other)
	: m_capacity(other.m_capacity)
	, m_size(other.m_size)
	, m_data(new int[m_capacity])
{
	copyElements(other.m_data, m_data, m_size);
}

Vector& Vector::operator=(const Vector& other)
{
	int* const tmp = new int[other.m_capacity];
	copyElements(other.m_data, tmp, other.m_size);

	delete[] m_data;

	m_capacity = other.m_capacity;
	m_size = other.m_size;
	m_data = tmp;

	return *this;
}

void Vector::copyElements(const int* const from, int* const to, const int count)
{
	for (int i = 0; i < count; ++i)
	{
		to[i] = from[i];
	}
}

void Vector::checkIsFull()
{
	if (isFull())
	{
		assert(false);
	}
}

void Vector::checkIsEmpty()
{
	if (isEmpty())
	{
		assert(false);
	}
}

void Vector::appendElement(const int element)
{
	if (isReallocationNecessaryForMoreMemory())
	{
		reallocateMoreMemory();
	}

	pushBackInMemory(element);
}

void Vector::reducingElment(const int element)
{
	if (isReallocationNecessaryForLessMemory())
	{
		reallocateLessMemory();
	}
	popBackInMemory();
}

bool Vector::isReallocationNecessaryForMoreMemory() const
{
	return m_size == m_capacity;
}

bool Vector::isReallocationNecessaryForLessMemory() const
{
	return m_size < m_capacity / 2;
}

void Vector::reallocateMoreMemory()
{
	m_capacity *= 2;
	int* const tmp = new int[m_capacity];

	copyElements(m_data, tmp, m_size);

	delete[] m_data;
	m_data = tmp;
}

void Vector::reallocateLessMemory()
{
	m_capacity /= 2;
	int* const tmp = new int[m_capacity];

	copyElements(m_data, tmp, m_size);

	delete[] m_data;
	m_data = tmp;
}

void Vector::pushBackInMemory(const int element)
{
	m_data[m_size] = element;
	++m_size;
}

void Vector::popBackInMemory()
{
	--m_size;
}

Vector::Iterator Vector::begin()
{
	return m_data;
}

Vector::Iterator Vector::end()
{
	return m_data + m_size;
}

int Vector::size()
{
	return m_size;
}

int Vector::getCapacity()
{
	return m_capacity;
}

int Vector::getElement(const int index)
{
	return m_data[index];
}

bool Vector::isEmpty() const
{
	return m_size == 0;
}

bool Vector::isFull() const
{
	return m_size == m_capacity;
}

int& Vector::operator[](const int index)
{
	return m_data[index];
}

void Vector::insert(const Iterator position, const int value)
{
	checkIsFull();

	for (auto it = end(); it > position; --it)
	{
		*(it) = *(it - 1);
	}
	m_size++;

	*(position) = value;
}

void Vector::erase(const Iterator position)
{
	checkIsEmpty();

	for (auto it = position; it != end(); it++)
	{
		*(it) = *(it + 1);
	}
	popBackInMemory();
}

Vector::~Vector()
{
	delete[] m_data;
}