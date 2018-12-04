#ifndef Vector_h__
#define Vector_h__
#include <vector>
#include <iterator>

class Vector
{
public:
	typedef int* Iterator;

public:
	Vector();
	Vector(const Vector& vec);

	Vector& Vector::operator=(const Vector& other);
	
	void appendElement(const int element);
	void reducingElment(const int element);
	
	Iterator begin();
	Iterator end();

	bool isEmpty() const;
	bool isFull() const; 

	void pushBackInMemory(const int element);
	void popBackInMemory();

	int size(); 
	int getCapacity();
	int getElement(const int index);

	int& operator[](const int index);

	void insert(const Iterator position, const int value); 
	void erase(const Iterator position); 

	~Vector();

private:
	int m_capacity;
	int m_size;
	int* m_data;

private:
	static void copyElements(const int* const from, int* const to, const int count);

	void checkIsFull();
	void checkIsEmpty();

	bool isReallocationNecessaryForMoreMemory() const;
	bool isReallocationNecessaryForLessMemory() const;
	void reallocateMoreMemory();
	void reallocateLessMemory();
	
};
#endif // Vector_h__