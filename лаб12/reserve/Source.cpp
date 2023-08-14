#include "Header.h"
void Tree::AddNode(int k)
{
	if (this->node == NULL)
		{
			this->node = new Node;
			this->node->key = k;
			this->node->val1 = 0;
			this->node->val2 = 0;
			this->node->left = this->node->right = NULL;
			return;
		}
	
	Node* temp = this->node;
	
	while (true)
		{
			if (k == temp->key)
				{
					return;
				}
			
			if (k < temp->key)
				{
					if (temp->left == NULL)
						{
							temp->left = new Node;
							temp->left->key = k;
							temp->left->val1 = 0;
							temp->left->val2 = 0;
							temp->left->left = temp->left->right = NULL;
							return;
						}
					else
						{
							temp = temp->left;
							continue;
						}
				}
			
			if (k > temp->key)
				{
					if (temp->right == NULL)
						{
							temp->right = new Node;
							temp->right->key = k;
							temp->right->val1 = 0;
							temp->right->val2 = 0;
							temp->right->left = temp->right->right = NULL;
							return;
						}
					else
						{
							temp = temp->right;
							continue;
						}
				}
		}
}
void pushFromFile(Node** t, int a) {
	if ((*t) == NULL) {	
		(*t) = new Node;	
		(*t)->key = a;	
		(*t)->left = (*t)->right = NULL;
		return;
	}
	if (a > (*t)->key)
		pushFromFile(&(*t)->right, a);	
	else                                
		pushFromFile(&(*t)->left, a);	
}

void Tree::PrintTree(Node* temp, int tab){
	int i;
	if (temp != NULL)
	{
		PrintTree(temp->right, tab + 1);
		for (i = 1; i <= tab; i++)
			cout << "   ";
		cout << temp->key << endl;
		PrintTree(temp->left, tab + 1);
	}
}
void Tree::Delete(int key)
{
	Node* Del, * Prev_Del, * R, * Prev_R;
	Del = this->node;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->left;
		else
			Del = Del->right;
	}
	if (Del == NULL)
	{
		puts("\n�� ������");
	}
	if (Del->right == NULL)
		R = Del->left;
	else
		if (Del->left == NULL)
			R = Del->right;
		else
		{
			Prev_R = Del;
			R = Del->left;
			while (R->right != NULL)
			{
				Prev_R = R;
				R = R->right;
			}
			if (Prev_R == Del)
				R->right = Del->right;
			else
			{
				R->right = Del->right;
				Prev_R->right = R->left;
				R->left = Prev_R;
			}
		}
	if (Del == this->node) this->node = R;
	else
		if (Del->key < Prev_Del->key)
			Prev_Del->left = R;
		else
			Prev_Del->right = R;
	int tmp = Del->key;
	delete Del;
}
void Tree::DirectBypass(Node* temp)
{
	if (temp)
	{
		cout << temp->key << "  ";
		if (temp->left)
			DirectBypass(temp->left);
		if (temp->right)
			DirectBypass(temp->right);	
	}
}

void Tree::ReverseBypass(Node* temp)
{
	if (temp)
	{
		if (temp->left)
			ReverseBypass(temp->left);
		cout << temp->key << "  ";
		if (temp->right)
			ReverseBypass(temp->right);
	}
}
void Tree::DownScan(Node* temp)
{
	if (temp != NULL)
	{
		DownScan(temp->left);
		DownScan(temp->right);
		cout << temp->key << "  ";
	}

}


bool Tree::Balance(Node* temp)
{
	if (temp)
	{
		if (temp->right)
		{
			this->counter++;
			Balance(temp->right);
		}

		if (temp->left)
		{
			this->counter--;
			Balance(temp->left);
		}
		if (this->counter >= -1 && this->counter <= 1)
			return true;
		// else
		// 	return false;
	}
	return false;
}