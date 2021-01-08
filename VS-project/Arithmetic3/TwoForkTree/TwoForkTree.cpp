// TwoForkTree 二叉树非递归遍历算法的实现：前序，中序，后序，以及分层遍历，深度遍历。
// 二叉树的非递归后序遍历是一个难点，有时间还要仔细琢磨琢磨。

#include <iostream>
#include <stack> // 堆栈
#include<queue> // 队列

using namespace std;

// 节点类。
class Node
{
public:

	Node(int d, Node* l = NULL, Node* r = NULL) :data(d), left(l), right(r) { }
	~Node() { }

	Node* GetLeft() { return left; };
	Node* GetRight() { return right; };
	int GetData() { return data; };

	void SetLeft(Node* l) { left = l; };
	void SetRight(Node* r) { right = r; };
	void SetData(int d) { data = d; };

private:

	Node* left;
	Node* right;
	int data;

};

// 树类
class Tree
{
public:

	Tree() :head(NULL) {}
	Tree(class Node* h) :head(h) { }
	~Tree() { }

	class Node* GetHead() { return head; };
	void SetHead(class Node* h) { head = h; };

	void FrontTraverse(); // 前序遍历
	void MiddleTraverse(); // 中序遍历。
	void BehindTraverse(); // 后序遍历。
	void TierTraverse(); // 层次遍历。
	void DepthTraverse(class Node* p); // 深度遍历。

	void Init()  // 没有释放。
	{
		class Node* node0 = new Node(0); // 头结点
		head = node0;  // 树
		
		class Node* node1 = new Node(1);
		node0->SetLeft(node1);
		
		class Node* node2 = new Node(2);
		node0->SetRight(node2);

		class Node* node3 = new Node(3);
		node1->SetLeft(node3);

		class Node* node4 = new Node(4);
		node1->SetRight(node4);

		class Node* node5 = new Node(5);
		node2->SetLeft(node5);

		class Node* node6 = new Node(6);
		node2->SetRight(node6);

		class Node* node7 = new Node(7);
		node3->SetLeft(node7);

		class Node* node8 = new Node(8);
		node3->SetRight(node8);

		class Node* node9 = new Node(9);
		node4->SetLeft(node9);

		class Node* node10 = new Node(10);
		node4->SetRight(node10);

		class Node* node11 = new Node(11);
		node5->SetLeft(node11);

		class Node* node12 = new Node(12);
		node5->SetRight(node12);
	}

private:
	class Node* head;
};

void Tree::FrontTraverse() // 前序遍历
{
	stack<class Node*> heap; // 指针堆栈。
	class Node* move = head;
	while (!heap.empty() ||  move != NULL)
	{
		while (move)
		{
			heap.push(move);
			cout << move->GetData() << " ";
			move = move->GetLeft();
		}
		
		move = heap.top();
		heap.pop();
		move = move->GetRight();
	}

	cout << endl;
}

void Tree::MiddleTraverse() // 中序遍历。
{
	stack<class Node*> heap; // 指针堆栈。
	class Node* move = head;
	while (!heap.empty() || move != NULL)
	{
		while (move)
		{
			heap.push(move);
			move = move->GetLeft();
		}

		move = heap.top();
		heap.pop();
		cout << move->GetData() << " ";
		move = move->GetRight();
	}

	cout << endl;
}

void Tree::BehindTraverse() // 后序遍历。
{
	stack<class Node*> heap; // 指针堆栈。

	stack<bool> assis; // 指针堆栈。

	class Node* move = head;
	class Node* lastnode = NULL; // 上一个节点。
	
	// 仅仅使用一个辅助指针实现的后序遍历。
	while (!heap.empty() || move != NULL)
	{
		while (move) // 处理左子树
		{
			heap.push(move);
			move = move->GetLeft();
		}

		move = heap.top();
		
		// 当当前节点的右子节点为null或者当前节点的右子节点为上一次处理节点时，当前节点即可以处理。
		if (move->GetRight() == NULL || move->GetRight() == lastnode) 
		{
			cout << move->GetData() << " ";
			heap.pop();

			lastnode = move;
			
			// 只要进入这个条件就说明当前节点已经可以处理，那么就说明其左子树右子树都已经处理完毕，那么这里的move必须置null否则将可能会导致重复处理。
			move = NULL; 
		}
		else // 否则要先处理右子树后才能处理当前节点。
		{
			lastnode = move;
			
			move = move->GetRight();
		}

		/*
		if (move->GetRight() == NULL) // 如果当前节点的右节点为空则可直接输出
		{
			cout << move->GetData() << " ";
			heap.pop(); 
			
			lastnode = move;
			move = NULL; // 只要能够处理当前节点那么说明其左子树右子树都已经处理完毕。 
		}
		else if(move->GetRight() == lastnode) // 如果上一个操作节点是当前节点的右节点，则可以输出。
		{
			cout << move->GetData() << " ";
			heap.pop();

			lastnode = move;
			move = NULL; // 如果进入这里条件说明当前处理的节点的右子树已经处理完毕所以可以直接处理，必须直接置null，否则会造成重复处理。
		}
		else // 否则要先处理右子树后才能处理当前节点。
		{
			lastnode = move;
			move = move->GetRight();
		}
		*/
	}


	/*
	// 依然要使用到辅助堆栈，但辅助堆栈只用于标记对应堆栈位置的节点的状态是第一次访问还是第二次如果是第二次则直接访问，否则先访问其右节点。
	while (!heap.empty() || move != NULL)
	{
		while (move)
		{
			heap.push(move);
			assis.push(true); // 表示第一次访问

			move = move->GetLeft();
		}
		
		move = heap.top();

		bool flag = assis.top(); // 标志位
		assis.pop();

		if (flag)
		{
			assis.push(false); // 表示第二次访问。
			move = move->GetRight();
		}
		else
		{
			heap.pop();
			cout << move->GetData() << " ";
			move = NULL;
		}

	}
	*/

	/*
	heap.push(head); // 
	while (!heap.empty())
	{
		move = heap.top();
		if (lastnode == NULL || lastnode->GetLeft() == move || lastnode->GetRight() == move)
		{
			if (move->GetRight() != NULL)
			{
				heap.push(move->GetRight());
			}
			if (move->GetLeft() != NULL)
			{
				heap.push(move->GetLeft());
			}
		}
			
		if ((lastnode == move) || (move->GetLeft() == NULL && move->GetRight() == NULL))
		{
			cout << move->GetData() << " ";
			heap.pop();
			
			if (!heap.empty() && lastnode == move)
			{
				class Node* middle = heap.top();
				heap.pop();
				if (heap.empty())
				{
					move = middle;
					heap.push(move);
				}
				else
				{
					move = heap.top();
					heap.pop();
					heap.push(move);
					heap.push(middle);
				}
			}
		}

		lastnode = move;

	}
	*/
	/*
	while (!heap.empty() || move != NULL)
	{
		while (move) // 处理左子树
		{
			heap.push(move);
			move = move->GetLeft();
		}

		move = heap.top();

		if (move->GetRight() == NULL) // 如果右子树为空
		{
			cout << move->GetData() << " ";
			heap.pop(); // 如果右子节点为空则访问,并弹出。否则既不会访问，也不会弹出。
			move = NULL;
		}
		else if(!assis.empty() && move == assis.top())
		{
			cout << move->GetData() << " ";
			heap.pop(); // 如果右子节点为空则访问,并弹出。否则既不会访问，也不会弹出。
			assis.pop();
			move = NULL;
		}
		else
		{
			assis.push(move);
			move = move->GetRight();
		}

	}
	*/

	/* 最好理解的一个方法，只是要使用额外的空间开销
	while (!heap.empty() || move != NULL)
	{
		while (move) // 处理左子树
		{
			assis.push(move);
			heap.push(move);
			move = move->GetRight();
		}

		move = heap.top();
		heap.pop();

		move = move->GetLeft();

	}

	while (!assis.empty())
	{
		cout << assis.top()->GetData() << " ";
		assis.pop();
	}
	*/

	cout << endl;

}

void Tree::TierTraverse() // 层次遍历。广度优先
{
	queue<class Node*> list;
	list.push(head);

	while (!list.empty())
	{
		class Node* move = list.front();
		list.pop();
		cout << move->GetData() << " ";

		if (move->GetLeft())
		{
			list.push(move->GetLeft());
		}
		if (move->GetRight())
		{
			list.push(move->GetRight());
		}
	}

	cout << endl;

	cout << "深度遍历结果：" << endl;
	DepthTraverse(head);
	cout << endl;
}


void Tree::DepthTraverse(class Node* p) // 深度遍历。跟中序遍历类似。
{
	class Node* q = p;

	while (q != NULL)
	{
		DepthTraverse(q->GetLeft());

		cout << q->GetData() << " ";
		
		q = q->GetRight();
	}
	
	/* //  完全递归的深度优先搜索。
	if (p->GetLeft()) 
	{
		DepthTraverse(p->GetLeft());
	}
	
	cout << p->GetData() << " ";

	if (p->GetRight())
	{
		DepthTraverse(p->GetRight());
	}
	*/
}

int main()
{
	Tree tree;
	tree.Init(); // 初始化。

	cout << "前序遍历结果：" << endl;
	tree.FrontTraverse();
	
	cout << "中序遍历结果：" << endl;
	tree.MiddleTraverse();
	
	cout << "后序遍历结果：" << endl;
	tree.BehindTraverse();

	cout << "层次遍历结果：" << endl;
	tree.TierTraverse();

	

	system("pause");
	return 0;
}
