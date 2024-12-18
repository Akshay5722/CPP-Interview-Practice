#include "DoublyLinkedList.h"

void ForwardTravelsal(DNode* head)
{
	DNode* curNode = head;
	while (curNode != nullptr)
	{
		curNode = curNode->m_nxtNode;
	}
}

void BackwardTravelsal(DNode* tail)
{
	DNode* curNode = tail;
	while (curNode != nullptr)
	{
		curNode = curNode->m_preNode;
	}
}

int lengthOfList(DNode* head)
{
	if (head == nullptr)
		return 0;
	DNode* curNode = head;
	int length = 1;
	while (curNode->m_nxtNode != nullptr)
	{
		curNode = curNode->m_nxtNode;
		length++;
	}
	return length;
}

int lengthOfList2(DNode* head)
{
	if (head == nullptr)
		return 0;

	int length = 0;
	for (DNode* curNode = head; curNode != nullptr; curNode = curNode->m_nxtNode)
		length++;

	return length;
}

void printDoublyLinkList(DNode* head)
{
	DNode* curNode = head;
	std::cout << "<->";
	while (curNode != nullptr)
	{
		std::cout << curNode->m_data << "<->";
		curNode = curNode->m_nxtNode;
	}

	std::cout << std::endl;
}

DNode* InsertAtBegining(DNode* head, int data)
{
	DNode* newNode = new DNode(data);
	newNode->m_nxtNode = head;
	if(head != nullptr)
		head->m_preNode = newNode;

	return newNode;
}

DNode* InsertAtEnd(DNode* head, int data)
{
	DNode* newNode = new DNode(data);

	DNode* curNode = head;
	while (curNode->m_nxtNode != nullptr)
		curNode = curNode->m_nxtNode;

	curNode->m_nxtNode = newNode;
	newNode->m_preNode = curNode;
	return head;
}

DNode* InsertAtPos(DNode* head, int data, int pos)
{
	DNode* newNode = new DNode(data);

	if (head == nullptr)
		return newNode;

	if (head->m_nxtNode == nullptr && pos == 0)
	{
		head->m_preNode = newNode;
		newNode->m_nxtNode = head;
		return newNode;
	}

	int index = 0;
	DNode* posNode = head;
	while (posNode != nullptr)
	{
		index++;
		posNode = posNode->m_nxtNode;
		if (index == pos)
			break;
	}

	if (posNode == nullptr)
	{
		// invalid pos
		return head;
	}

	newNode->m_nxtNode = posNode;
	newNode->m_preNode = posNode->m_preNode;

	posNode->m_preNode->m_nxtNode = newNode;
	posNode->m_preNode = newNode;
	return head;
}

DNode* RemoveAtBegining(DNode* head)
{
	if (head == nullptr)
		return nullptr;

	DNode* headNext = head->m_nxtNode;
	if (headNext == nullptr)
	{
		delete head;
		head = nullptr;
		return nullptr;
	}

	headNext->m_preNode = nullptr;

	delete head;
	head = nullptr;
	return headNext;
}

DNode* RemoveAtEnd(DNode* head)
{
	if (head == nullptr)
		return nullptr;

	DNode* curNode = head;
	while (curNode->m_nxtNode != nullptr)
	{
		curNode = curNode->m_nxtNode;
	}

	// here curNode is becoe tail of the list
	DNode* lastNodepre = curNode->m_preNode;
	lastNodepre->m_nxtNode = nullptr;
	delete curNode;
	curNode = nullptr;

	return head;
}

DNode* RemoveAtPos(DNode* head, int pos)
{
	if (head == nullptr)
		return nullptr;

	if (head != nullptr && pos == 0)
		return RemoveAtBegining(head);

	int index = 0;
	DNode* posNode = head;
	while (posNode != nullptr)
	{
		index++;
		posNode = posNode->m_nxtNode;
		if (index == pos)
			break;
	}

	if (posNode == nullptr)
	{
		// invalid pos
		return head;
	}

	DNode* posNext = posNode->m_nxtNode;
	DNode* posPre = posNode->m_preNode;

	posPre->m_nxtNode = posNext;
	posNext->m_preNode = posPre;

	delete posNode;
	posNode = nullptr;
	return head;
}

// Doubly linked list insertion problems
void TestDoublyLinkedListInserrtionProblem()
{
	DNode* head = new DNode(2);
	head = InsertAtBegining(head, 1);
	head = InsertAtEnd(head, 3);
	head = InsertAtEnd(head, 4);
	head = InsertAtEnd(head, 5);
	head = InsertAtEnd(head, 6);

	printDoublyLinkList(head);

	head = InsertAtPos(head, 55, 5);
	printDoublyLinkList(head);

	head = RemoveAtBegining(head);
	printDoublyLinkList(head);

	head = RemoveAtEnd(head);
	printDoublyLinkList(head);

	head = RemoveAtPos(head, 2);
	printDoublyLinkList(head);
}