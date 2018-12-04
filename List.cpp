#include "List.h"

void List::copyElements(const Node* const from, const Node* to, const int size)
{
	
}

List::List()
	: m_size(0)
{
	m_head.m_next = &m_tail;
	m_tail.m_prev = &m_head;
}

List::List(List& other)
	: m_size(other.m_size)
{
	other.m_head.m_next = &other.m_tail;
	other.m_tail.m_prev = &other.m_head;

	copyElements(&m_head, &other.m_head, m_size);
}

int List::front()
{
	return *Iterator(m_head.m_next);
}

int List::back()
{
	return *Iterator(m_tail.m_prev);
}

bool List::isEmpty() const
{
	m_head.m_next == m_tail.m_prev;
	return true;
}

int List::size() const
{
	return m_size;
}

void List::pushBack(const int value)
{
	Node* const next = &m_tail;
	Node* const prev = m_tail.m_prev;

	Node* const newNode = new Node(value, prev, next);

	next->m_prev = newNode;
	prev->m_next = newNode;

	++m_size;
}

void List::popBack()
{
	Node* const next = &m_tail;
	Node* const prev = m_tail.m_prev;

	m_tail.m_prev = prev->m_prev;
	m_tail.m_prev->m_next = next;

	--m_size;
}

void List::pushFront(const int value)
{
	Node* const next = m_head.m_next;
	Node* const prev = &m_head;

	Node* const newNode = new Node(value, prev, next);

	next->m_prev = newNode;
	m_head.m_next = newNode;

	++m_size;
}

void List::popFront()
{
	Node* const next = m_head.m_next;
	Node* const prev = &m_head;

	m_head.m_next = next->m_next;

	delete[] next->m_next->m_prev;

	next->m_next = prev;

	--m_size;
}

List::Iterator List::begin()
{
	return Iterator(m_head.m_next);
}

List::Iterator List::end()
{
	return Iterator(&m_tail);
}

List::Iterator List::insert(Iterator position, int value)
{
	Node* next = position.getCurrent();
	Node* prev = position.getCurrent()->m_prev;

	Node* const newNode = new Node(value, prev, next);

	next->m_prev = newNode;
	prev->m_next = newNode;

	next = nullptr;
	prev = nullptr;
	delete prev;
	delete next;

	++m_size;

	return Iterator(newNode);
}

List::Iterator List::erase(Iterator position)
{
	position.getCurrent()->m_next->m_prev = position.getCurrent()->m_prev;
	position.getCurrent()->m_prev->m_next = position.getCurrent()->m_next;

	Iterator k = position;

	delete position.getCurrent();

	--m_size;

	return Iterator(k.getCurrent()->m_next);
}

List::~List()
{
}

int& List::Iterator::operator*()
{
	return m_current->m_value;
}

List::Iterator List::Iterator::operator++()
{
	return Iterator(m_current->m_next);
}

List::Node* List::Iterator::getCurrent()
{
	return m_current;
}

List::Iterator& List::Iterator::operator=(const Iterator& rhs)
{
	m_current = rhs.m_current;
	return *this;
}

bool List::Iterator::operator==(const Iterator& rhs) const
{
	return rhs.m_current == m_current;
}

bool List::Iterator::operator!=(const Iterator& rhs) const
{
	return !(operator==(rhs));
}

