#include "SinglyLinkedList.h"


void TraverseFromLinkedList(Node* head)
{
	Node* curNode = head;
	while (curNode != nullptr)
	{
		curNode = curNode->m_nextNode;
	}
}

bool SearchElement(Node* head, int data)
{
	Node* curNode = head;
	while (curNode != nullptr)
	{
		if (curNode->m_data == data)
			return true;
		curNode = curNode->m_nextNode;
	}
	return false;
}

int LenghOfLinkedList(Node* head)
{
	int length = 0;
	Node* curNode = head;
	while (curNode != nullptr)
	{
		length++;
		curNode = curNode->m_nextNode;
	}
	return length;
}

Node* InsertAtBegining(Node* head, int data)
{
	Node* newNode = new Node(data);

	newNode->m_nextNode = head;
	head = newNode;
	return head;
}

Node* insertAtEnd(Node* head, int data)
{
	Node* newNode = new Node(data);

	Node* curNode = head;
	while (curNode->m_nextNode != nullptr)
	{
		curNode = curNode->m_nextNode;
	}

	curNode->m_nextNode = newNode;
	return head;
}

Node* InsertAtPosition(Node* head, int data, int pos)
{
	if (pos < 0)
		return head;

	Node* newNode = new Node(data);

	int index = 0; Node* currentNode = head;
	while (index < pos - 1)
	{
		index++;
		currentNode = currentNode->m_nextNode;
	}

	Node* nextNodeOfPosElement = currentNode->m_nextNode;

	currentNode->m_nextNode = newNode;
	newNode->m_nextNode = nextNodeOfPosElement;

	return head;
}

Node* RemoveHeadNode(Node* head)
{
	Node* nextNode = head->m_nextNode;
	if (nextNode == nullptr)
	{
		// invalid deletion as only head node present
		return head;
	}

	delete head;
	head = nullptr;

	head = nextNode;
	return head;
}

Node* RemoveLastNode(Node* head)
{
	if (head == nullptr)
		return nullptr;
	if (head->m_nextNode == nullptr)
	{
		delete head;
		head = nullptr;
		return head;
	}

	Node* preNode = head;
	Node* currentNode = head->m_nextNode;
	while (currentNode->m_nextNode != nullptr)
	{
		preNode = currentNode;
		currentNode = currentNode->m_nextNode;
	}

	delete currentNode;
	currentNode = nullptr;

	preNode->m_nextNode = nullptr;
	return head;
}

Node* RemoveElementatGivenPose(Node* head, int pos)
{
	if (pos == 0)
	{
		return(head = RemoveHeadNode(head));
	}

	int index = 0;
	Node* previousNode = nullptr;
	Node* curNode = head;
	while (curNode != nullptr)
	{
		index++;
		curNode = curNode->m_nextNode;
		if (index == pos - 1)
		{
			previousNode = curNode;
		}
		else if(index == pos) // curNode is pos node
			break;
	}

	if (curNode == nullptr)
	{
		//invalid pos
		return head;
	}

	previousNode->m_nextNode = curNode->m_nextNode;
	
	delete curNode;
	curNode = nullptr;
	return head;
}

void printLinkList(Node* head)
{
	Node* curNode = head;
	std::cout << "->";
	while (curNode != nullptr)
	{
		std::cout << curNode->m_data << "->";
		curNode = curNode->m_nextNode;
	}

	std::cout << std::endl;
}

void printNodeInLinkList(Node* node)
{
	std::cout << "->";
	std::cout << node->m_data << "->";
	std::cout << std::endl;
}

// SinglyLinkedlist operations insertion problems
void TestLinkedListInsertionProblems()
{
	Node* head = new Node(1);
	insertAtEnd(head, 2);
	insertAtEnd(head, 3);
	insertAtEnd(head, 4);
	insertAtEnd(head, 6);
	insertAtEnd(head, 7);

	// check insertion at the position of the 4
	InsertAtPosition(head, 5, 4);
}

// singly linked list deletion problems
void TestLinkedListDeletionProblems()
{
	Node* head = new Node(1);
	insertAtEnd(head, 2);
	insertAtEnd(head, 3);
	insertAtEnd(head, 4);
	insertAtEnd(head, 5);
	insertAtEnd(head, 6);
	insertAtEnd(head, 7);
	insertAtEnd(head, 8);


	// Delete head
	head = RemoveHeadNode(head);
	head = RemoveLastNode(head);
	head = RemoveElementatGivenPose(head, 2);
	int debug = 0;
}

void TestLinkedListProblems()
{
	Node* head = new Node(1);
	if (1)
	{
		insertAtEnd(head, 2);
		insertAtEnd(head, 3);
		insertAtEnd(head, 4);
		insertAtEnd(head, 5);
		insertAtEnd(head, 6);
		insertAtEnd(head, 7);
		insertAtEnd(head, 8);
		insertAtEnd(head, 9);


		printLinkList(head);
		//head = RemoveEveryKthNode(head, 3);

		head = SortLinkedListByEvenFirstOddNext(head);
		printLinkList(head);
	}

	if (0)
	{
		head->m_nextNode = new Node(2);
		head->m_nextNode->m_nextNode = new Node(3);
		head->m_nextNode->m_nextNode->m_nextNode = new Node(4);
		head->m_nextNode->m_nextNode->m_nextNode->m_nextNode = head;

		bool isCircular = isCircularLinkedList(head);
		std::cout << "isCircular = " << isCircular << std::endl;
	}

	//printLinkList(head);
}

Node* RemoveEveryKthNode(Node* head, int k)
{
	Node* previousNode = nullptr;
	Node* curNode = head;

	int index = 1;
	while (curNode != nullptr)
	{
		index++;
		previousNode = curNode;
		curNode = curNode->m_nextNode;
		if (index == k && curNode != nullptr)
		{
			// delete current node and assign next node of current node to previous node
			Node* nextNodeOfCur = curNode->m_nextNode;
			previousNode->m_nextNode = nextNodeOfCur;
			delete curNode;
			curNode = nextNodeOfCur;
			index = 1;
		}
	}

	return head;
}

Node* ReturnMiddleNode(Node* head) 
{
	int length = 0;
	Node* curNode = head;
	while (curNode != nullptr)
	{
		length++;
		curNode = curNode->m_nextNode;
	}
	
	int pos = (length / 2 )+ 1;
	curNode = head; int index = 1;
	while (curNode != nullptr)
	{
		index++;
		curNode = curNode->m_nextNode;
		if (index == pos)
			return curNode;
	}

	return nullptr;
}

bool isCircularLinkedList(Node* head)
{
	Node* curNode = head;
	while (curNode != nullptr)
	{
		Node* nextNode = curNode->m_nextNode;
		if (nextNode == head)
			return true;

		curNode = nextNode;
	}
	return false;
}

Node* RemoveAllOddValueNodes(Node* head)
{
	Node* curNode = head;
	Node* preNode = nullptr;
	while (curNode != nullptr)
	{
		// delete the current node
		Node* nextNode = curNode->m_nextNode;
		if ((curNode->m_data) % 2 != 0)
		{		
			delete curNode;
			curNode = nullptr;
			if (preNode != nullptr)
				preNode->m_nextNode = nextNode;
			else
				head = nextNode;
		}
		preNode = curNode;
		curNode = nextNode;
	}

	return head;
}

Node* SortLinkedListByEvenFirstOddNext(Node* head)
{
	if (head->m_nextNode == nullptr)
		return head;

	Node* evenList = nullptr; Node* evenListCur = nullptr;
	Node* oddList = nullptr; Node* oddCurrent = nullptr;
	
	Node* curNode = head;
	while(curNode != nullptr)
	{
		if (curNode->m_data % 2 == 0) // even
		{
			if (evenList == nullptr)
				evenList = curNode;
			else
				evenListCur->m_nextNode = curNode;

			evenListCur = curNode;
		}
		else // odd
		{
			if (oddList == nullptr)
				oddList = curNode;
			else
				oddCurrent->m_nextNode = curNode;

			oddCurrent = curNode;
		}

		curNode = curNode->m_nextNode;
	}

	if(evenListCur != nullptr)
		evenListCur->m_nextNode = oddList;

	head = evenList != nullptr ? evenList : oddList;
	return head;
}