#ifndef BinarTree_h__
#define BinarTree_h__
#include <cassert>
#include <queue>
#include <stack>


template <class T>
class BinarTree
{
private:
	struct Node
	{
		T m_value;
		Node* m_left;
		Node* m_right;

		Node(T value = T()
			, Node* const left = NULL
			, Node* const right = NULL)
			: m_value(value)
			, m_left(left)
			, m_right(right)
		{
		}
	};

	Node* m_root;

	void insert(Node* &node, const T& m_value);
	void deleteTree(Node* node);

	int maxDepth(Node* node);
	int minDepth(Node* node);

	static bool hasLeft(const Node* const node);
	static bool hasRight(const Node* const node);
	Node* find(Node* node, T m_value);

	static Node* minHelper(Node* node);
	static Node* maxHelper(Node* node);

		

public:
	BinarTree()
		: m_root(NULL)
	{
	}

	BinarTree(std::initializer_list<T> list);

	Node* min();
	Node* max();
	Node* successor(const Node* node, T value);
	Node* predecessor(const Node* node, T value);
	Node* getRoot();

	void insert(const T& m_value);

	void print();
	void inorder(Node* node);
	void postorder(Node* node);
	void preorder(Node* node);

	void bfsTravers();
	void dfsTravers();

	int maxDepth();
	int minDepth();

	Node* find(const T& m_value);

	Node* deleteNode(Node* node, T value);

	BinarTree(const BinarTree& other) = delete;
	BinarTree& operator=(const BinarTree& rhs) = delete;

	~BinarTree();
};

// BFS
template <class T>
void BinarTree<T>::bfsTravers()
{
	std::queue<Node*> pendingNodes;
	pendingNodes.push(m_root);

	while (pendingNodes.size() > 0)
	{
		Node* current = pendingNodes.front();
		pendingNodes.pop();

		if (hasLeft(current))
		{
			pendingNodes.push(current->m_left);
		}

		if (hasRight(current))
		{
			pendingNodes.push(current->m_right);
		}

		std::cout << current->m_value << ' ';
	}
}

// DFS
template <class T>
void BinarTree<T>::dfsTravers()
{
	std::stack<Node*> dfsStack;
	dfsStack.push(m_root);

	while (dfsStack.size() > 0)
	{
		Node* curr = dfsStack.top();
		std::cout << curr->m_value << " ";
		dfsStack.pop();

		if (hasLeft(curr))
		{
			dfsStack.push(curr->m_left);
		}
		if (hasRight(curr))
		{
			dfsStack.push(curr->m_right);
		}
	}
}

// INITIALIZER
template <class T>
BinarTree<T>::BinarTree(std::initializer_list<T> list)
	: BinarTree()
{
	for (auto& element : list)
	{
		insert(element);
	}
}

template <class T>
typename BinarTree<T>::Node* BinarTree<T>::getRoot()
{
	return m_root;
}

  // Find
template <class T>
typename BinarTree<T>::Node* BinarTree<T>::find(const T& value)
{
	return find(m_root, value);
}

template <class T>
typename BinarTree<T>::Node* BinarTree<T>::find(Node* node, T value)
{
	if (node != NULL)
	{
		if (value == node->m_value)
		{
			return node;
		}
		else
		{
			if (value < node->m_value)
			{
				return find(node->m_left, value);
			}
			else
			{
				return find(node->m_right, value);
			}
		}
	}
	else
	{
		return NULL;
	}
}

// Successor  Predecessor
template <class T>
typename BinarTree<T>::Node* BinarTree<T>::successor(const Node* node, T value)
{
	Node* current = find(value);
	if (current == NULL)
	{
		return NULL;
	}
	if (current->m_right != NULL)
	{
		return minHelper(current->m_right);
	}
	else
	{
		Node* sucs = NULL;
		Node* ancestor = m_root;
		while (ancestor != current)
		{
			if (current->m_value < ancestor->m_value)
			{
				sucs = ancestor;
				ancestor = ancestor->m_left;
			}
			else
			{
				ancestor = ancestor->m_right;
			}
		}
		return sucs;
	}
}

template <class T>
typename BinarTree<T>::Node* BinarTree<T>::predecessor(const Node* node, T value)
{
	Node* current = find(value);
	if (current == NULL)
	{
		return NULL;
	}
	if (current->m_left != NULL)
	{
		return maxHelper(current->m_left);
	}
	else
	{
		Node* sucs = NULL;
		Node* ancestor = m_root;
		while (ancestor != current)
		{
			if (current->m_value > ancestor->m_value)
			{
				sucs = ancestor;
				ancestor = ancestor->m_right;
			}
			else
			{
				ancestor = ancestor->m_left;
			}
		}
		return sucs;
	}
}


// Min
template <class T>
typename BinarTree<T>::Node* BinarTree<T>::minHelper(Node* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	else
	{
		Node* temp = node;

		while (hasLeft(temp))
		{
			temp = temp->m_left;
		}

		assert(!hasLeft(temp) && "Minimum can't have left child");

		return temp;
	}
}

template <class T>
typename BinarTree<T>::Node* BinarTree<T>::min()
{
	if (m_root == nullptr)
	{
		return nullptr;
	}
	else
	{
		Node* temp = m_root;

		while (hasLeft(temp))
		{
			temp = temp->m_left;
		}

		assert(!hasLeft(temp) && "Minimum can't have left child");

		return temp;
	}
}

template <class T>
int BinarTree<T>::minDepth()
{
	return minDepth(m_root);
}

template <class T>
int BinarTree<T>::minDepth(Node* node)
{
	if (node == nullptr)
	{
		return -1;
	}

	if (node->m_left == NULL && node->m_right == NULL)
	{
		return 0;
	}

	int leftDepth = minDepth(node->m_left);
	int rightDepth = minDepth(node->m_right);

	return leftDepth < rightDepth ?
		leftDepth + 1 : rightDepth + 1;
}


// Max
template <class T>
typename BinarTree<T>::Node* BinarTree<T>::maxHelper(Node* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	else
	{
		Node* temp = node;

		while (hasRight(temp))
		{
			temp = temp->m_right;
		}

		assert(!hasRight(temp) && "Maximum can't have left child");

		return temp;
	}
}

template <class T>
typename BinarTree<T>::Node* BinarTree<T>::max()
{
	if (m_root == nullptr)
	{
		return nullptr;
	}
	else
	{
		Node* temp = m_root;

		while (hasRight(temp))
		{
			temp = temp->m_right;
		}

		assert(!hasRight(temp) && "Maximum can't have left child");

		return temp;
	}
}

template <class T>
int BinarTree<T>::maxDepth()
{
	return maxDepth(m_root);
}

template <class T>
int BinarTree<T>::maxDepth(Node* node)
{
	if (node == NULL || (node->m_left == NULL && node->m_right == NULL))
	{
		return 0;
	}

	int leftDepth = maxDepth(node->m_left);
	int rightDepth = maxDepth(node->m_right);

	return leftDepth > rightDepth ?
		leftDepth + 1 : rightDepth + 1;
}

// Insert
template <class T>
void BinarTree<T>::insert(Node* &node, const T& m_value)
{
	if (node == NULL)
	{
		node = new Node(m_value);
	}
	else if (m_value < node->m_value)
	{
		insert(node->m_left, m_value);
	}
	else
	{
		insert(node->m_right, m_value);
	}
}

template <class T>
void BinarTree<T>::insert(const T& m_value)
{
	insert(m_root, m_value);
}


// Has
template <class T>
bool BinarTree<T>::hasLeft(const Node* const node)
{
	return node->m_left != nullptr;
}

template <class T>
bool BinarTree<T>::hasRight(const Node* const node)
{
	return node->m_right != nullptr;
}


// Print
template <class T>
void BinarTree<T>::print()
{
	inorder(m_root);
}

template <class T>
void BinarTree<T>::inorder(Node* node)
{
	if (node != nullptr)
	{
		inorder(node->m_left);

		std::cout << node->m_value << " ";

		inorder(node->m_right);
	}
	else
	{
		return;
	}
}

template <class T>
void BinarTree<T>::postorder(Node* node)
{
	if (node != nullptr)
	{
		postorder(node->m_left);
		postorder(node->m_right);

		std::cout << node->m_value << " ";
	}
	else
	{
		return;
	}
}

template <class T>
void BinarTree<T>::preorder(Node* node)
{
	if (node != nullptr)
	{
		std::cout << node->m_value << " ";

		preorder(node->m_left);
		preorder(node->m_right);
	}
	else
	{
		return;
	}
}


// Delete
template <class T>
typename BinarTree<T>::Node* BinarTree<T>::deleteNode(Node* node, T value)
{
	if (node == NULL)
	{
		return node;
	}
	else if (value < node->m_value)
	{
		node->m_left = deleteNode(node->m_left, value);
	}
	else if (value > node->m_value)
	{
		node->m_right = deleteNode(node->m_right, value);
	}
	else
	{
		if (node->m_left == NULL && node->m_right == NULL)
		{
			delete node;
			node = NULL;
		}
		else if (node->m_left == NULL)
		{
			Node* temp = node;
			node = node->m_right;
			delete temp;
		}
		else if (node->m_right == NULL)
		{
			Node* temp = node;
			node = node->m_left;
			delete temp;
		}
		else
		{
			Node* temp = minHelper(node->m_right);
			node->m_value = temp->m_value;
			node->m_right = deleteNode(node->m_right, temp->m_value);
		}
	}
	return node;
}

template <class T>
void BinarTree<T>::deleteTree(Node* node)
{
	if (node != NULL)
	{
		deleteTree(node->m_left);
		deleteTree(node->m_right);
		delete node;
	}

}

template <class T>
BinarTree<T>::~BinarTree()
{
	deleteTree(m_root);
}

#endif // BinarTree_h__


