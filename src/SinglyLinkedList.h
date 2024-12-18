#pragma once

#include <iostream>

struct Node
{
	int m_data;
	Node* m_nextNode;

	Node(int data)
	{
		this->m_data = data;
		this->m_nextNode = nullptr;
	}
};

void TraverseFromLinkedList(Node* head);

bool SearchElement(Node* head, int data);

int LenghOfLinkedList(Node* head);

Node* InsertAtBegining(Node* head, int data);

Node* insertAtEnd(Node* head, int data);

Node* InsertAtPosition(Node* head, int data, int pos);

Node* RemoveHeadNode(Node* head);

Node* RemoveLastNode(Node* head);

Node* RemoveElementatGivenPose(Node* head, int pos);

void TestLinkedListInsertionProblems();

void TestLinkedListDeletionProblems();

void TestLinkedListProblems();

void printLinkList(Node* head);

/* // Remove every Kth node of the linked list
* Given a singly linked list, the task is to remove every kth node of the linked list. 
	Assume that k is always less than or equal to the length of the Linked List.
Examples : 
Input: LinkedList: 1 -> 2 -> 3 -> 4 -> 5 -> 6, k = 2
Output: 1 -> 3 -> 5 
Explanation: After removing every 2nd node of the linked list, 
			the resultant linked list will be: 1 -> 3 -> 5 .

Input: LinkedList: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10, k = 3
Output: 1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10
Explanation: After removing every 3rd node of the linked list, 
			the resultant linked list will be: 1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10.
*/
Node* RemoveEveryKthNode(Node* head, int k);