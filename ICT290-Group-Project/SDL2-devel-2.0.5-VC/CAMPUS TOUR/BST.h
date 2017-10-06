#ifndef BST_H
#define BST_H

template <class T>
struct BSTNode
{
	BSTNode<T> * left;
	BSTNode<T> * right;
	T * value;

	BSTNode<T>(T * newValue)
	{
		left = nullptr;
		right = nullptr;
		value = newValue;
	}
};

template <class T>
class BST
{
public:
	BST<T>();
	~BST<T>();

	void Insert(T * newValue);
	void PreOrderTraversal(void(*callback)(T*));
	void InOrderTraversal(void(*callback)(T*));
	void PostOrderTraversal(void(*callback)(T*));

private:
	void recursiveInsert(BSTNode<T> * rootNode, T * newValue);
	void recursivePreOrderTraversal(BSTNode<T> * rootNode, void(*callback)(T*));
	void recursiveInOrderTraversal(BSTNode<T> * rootNode, void(*callback)(T*));
	void recursivePostOrderTraversal(BSTNode<T> * rootNode, void(*callback)(T*));

private:
	BSTNode<T> * rootNode;
};

template <class T>
BST<T>::BST()
{
	rootNode = nullptr;
}

template <class T>
BST<T>::~BST()
{

}

template <class T>
void BST<T>::Insert(T * newValue)
{
	if (rootNode == nullptr)
	{
		BSTNode<T> * node = new BSTNode<T>(newValue);
		rootNode = node;
	}
	else
	{
		recursiveInsert(rootNode, newValue);
	}
}

template <class T>
void BST<T>::PreOrderTraversal(void(*callback)(T*))
{
	if (rootNode != nullptr)
	{
		recursivePreOrderTraversal(rootNode, callback);
	}
}

template <class T>
void BST<T>::InOrderTraversal(void(*callback)(T*))
{
	if (rootNode != nullptr)
	{
		recursiveInOrderTraversal(rootNode, callback);
	}
}

template <class T>
void BST<T>::PostOrderTraversal(void(*callback)(T*))
{
	if (rootNode != nullptr)
	{
		recursivePostOrderTraversal(rootNode, callback);
	}
}

template <class T>
void BST<T>::recursiveInsert(BSTNode<T> * node, T * newValue)
{
	if (newValue < node->value)
	{
		if (node->left == nullptr)
		{
			node->left = new BSTNode<T>(newValue);
		}
		else
		{
			recursiveInsert(node->left, newValue);
		}
	}
	else if (newValue > node->value)
	{
		if (node->right == nullptr)
		{
			node->right = new BSTNode<T>(newValue);
		}
		else
		{
			recursiveInsert(node->right, newValue);
		}
	}
	else
	{

	}
}

template <class T>
void BST<T>::recursivePreOrderTraversal(BSTNode<T> * rootNode, void(*callback)(T*))
{

	callback(rootNode->value);
	if (rootNode->left != nullptr)
	{
		recursivePreOrderTraversal(rootNode->left, callback);
	}
	if (rootNode->right != nullptr)
	{
		recursivePreOrderTraversal(rootNode->right, callback);
	}

}

template <class T>
void BST<T>::recursiveInOrderTraversal(BSTNode<T> * rootNode, void(*callback)(T*))
{
	if (rootNode->left != nullptr)
	{
		recursiveInOrderTraversal(rootNode->left, callback);
	}
	callback(rootNode->value);
	if (rootNode->right != nullptr)
	{
		recursiveInOrderTraversal(rootNode->right, callback);
	}
}

template <class T>
void BST<T>::recursivePostOrderTraversal(BSTNode<T> * rootNode, void(*callback)(T*))
{
	if (rootNode->left != nullptr)
	{
		recursivePostOrderTraversal(rootNode->left, callback);
	}
	if (rootNode->right != nullptr)
	{
		recursivePostOrderTraversal(rootNode->right, callback);
	}
	callback(rootNode->value);
}



#endif