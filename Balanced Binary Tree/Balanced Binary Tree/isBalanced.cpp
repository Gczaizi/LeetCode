#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int DFSHeight(TreeNode *root)
{//深度优先查找高度
	if (root == NULL)
		return 0;
	int leftHeight = DFSHeight(root->left);
	if (leftHeight == -1)
		return -1;
	int rightHeight = DFSHeight(root->right);
	if (rightHeight == -1)
		return -1;

	if (abs(leftHeight - rightHeight) > 1)
		return -1;
	return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode* root)
{
	if (DFSHeight(root) != -1)
		return true;
	else
		return false;
}

int main()
{
	TreeNode *root = &TreeNode(0);
	TreeNode *a = &TreeNode(1);
	TreeNode *b = &TreeNode(2);
	TreeNode *c = &TreeNode(3);
	TreeNode *d = &TreeNode(4);
	root->left = a;
	root->right = b;
	a->left = c;
	c->left = d;

	cout << isBalanced(root) << endl;
}