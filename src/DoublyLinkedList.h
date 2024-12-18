#pragma once

#include <iostream>

struct DNode
{
	// Data
	int m_data;
	DNode* m_preNode;
	DNode* m_nxtNode;

	DNode(int data): m_data(data), m_preNode(nullptr), m_nxtNode(nullptr)
	{}
};

void ForwardTravelsal(DNode* head);
void BackwardTravelsal(DNode* tail);

int lengthOfList(DNode* head);
int lengthOfList2(DNode* head);

DNode* InsertAtBegining(DNode* head, int data);
DNode* InsertAtEnd(DNode* head, int data);
DNode* InsertAtPos(DNode* head, int data, int pos);

void printDoublyLinkList(DNode* head);

DNode* RemoveAtBegining(DNode* head);
DNode* RemoveAtEnd(DNode* head);
DNode* RemoveAtPos(DNode* head, int pos);

void TestDoublyLinkedListInserrtionProblem();