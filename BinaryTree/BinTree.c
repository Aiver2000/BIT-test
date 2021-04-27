void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PrevOrder(root->_left);
	PrevOrder(root->_right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->_left);
	printf("%c ", root->data);
	InOrder(root->_right);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->_left);
	PostOrder(root->_right);
	printf("%c ", root->data);
}


BTNode* BinaryTreeCreate(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->data = x;
	node->_left = NULL;
	node->_right = NULL;
	return node;



}
void DestroyNode(BTNode* node)
{
	free(node);
	return;
}
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
		return;
	BinaryTreeDestory(&((*root)->_left));
	BinaryTreeDestory(&((*root)->_right));
	DestroyNode(*root);
	*root = NULL;
	return;

}
int BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL &&root->_right == NULL);
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left)+BinaryTreeLeafSize(root->_right);
	
}
int BinaryTreeLeveKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLeveKSize(root->_left, k - 1) + BinaryTreeLeveKSize(root->_right, k - 1);
}
void BinaryTreeLeveOrder(BTNode* root);
int BinaryTreeComplete(BTNode* root);