/*
 * LinkedList.h
 *
 *  Created on: Apr 27, 2020
 *      Author: theresesmith
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "Room.h"
#include "Terminal.h"

typedef struct
{
	int roomNumber;
	float treasure;
}SearchResults;

typedef Terminal Payload;

typedef SearchResults Payload2;


struct LLNode;
typedef struct LLNode
{
	struct LLNode* next;
	struct LLNode* prev;
	Payload* payP;
}LLNode;

struct LLNode2;
typedef struct LLNode2
{
	struct LLNode2* next;
	struct LLNode2* prev;
	Payload2* payP;
}LLNode2;

typedef struct
{
	Payload* mp;
	LLNode* newQHead;
}backFromDQFIFO;

class LinkedList {
public:
	LinkedList();
	virtual ~LinkedList();


	LLNode* makeEmptyLinkedList();
	LLNode2* makeEmptyLinkedList2();
	LLNode* removeFromList(Payload* pP);
	void savePayload(Payload* mp);
	void savePayload2(Payload2* mp);
	bool isEmpty();
	bool isEmpty2();
	Payload* dequeueLIFO();
	backFromDQFIFO* dequeueFIFO();
	void printHistory();
    LLNode* getBegin1();
    LLNode2* getBegin2();
    void setBegin1(LLNode*);
    void setBegin2(LLNode2*);
    void printHistory1();



private:
	LLNode* begin1;
	LLNode2* begin2;

};








#endif /* LINKEDLIST_H_ */
