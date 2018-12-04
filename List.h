#ifndef List_h__
#define List_h__


class List
{
private:
	struct Node
	{
		int m_value;
		Node* m_prev;
		Node* m_next;

		Node(int value = 0
			, Node* const prev = nullptr
			, Node* const next = nullptr)
			: m_value(value)
			, m_prev(prev)
			, m_next(next)
		{
		}
	};

	class Iterator
	{
	private:
		Node* m_current;

	public:

		explicit Iterator(Node* const current)
			: m_current(current)
		{
		}

		int& operator*();
		Iterator operator++();

		Iterator& operator=(const Iterator& rhs);
		bool operator==(const Iterator& rhs) const;
		bool operator!=(const Iterator& rhs) const;

		Node* getCurrent();
	};

private:
	Node m_head;
	Node m_tail;
	int m_size;

	static void copyElements(const Node* const from, const Node* to, const int size);

public:
	List();
	List(List& other);

	int front();
	int back();

	bool isEmpty() const;
	int size() const;
	void pushBack(const int value);
	void popBack();

	void pushFront(const int value);
	void popFront();

	Iterator begin();
	Iterator end();

	Iterator insert(Iterator position, int value);
	Iterator erase(Iterator positin);


	~List();
};

#endif // List_h__
