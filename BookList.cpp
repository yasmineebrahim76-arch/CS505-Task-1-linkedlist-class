#include <iostream>
#include"BookList.h"
using namespace std;
# include <string>
using std::string;

BookList::BookList()
{
	head = cursor =  prev = NULL;
}

BookList::~BookList()
{
	makeListEmpty();
}

bool BookList::listIsEmpty() const
{
	return head == NULL;
}

bool BookList::curIsEmpty() const
{
	return cursor == NULL;
}

void BookList::toFirst()
{
	  cursor = head;
    prev = NULL;
}

bool BookList::atFirst() const
{
	return cursor == head;
}

void BookList::advance()
{
	prev = cursor;
	cursor = cursor->next;
}

void BookList::toEnd()
{
    if (!listIsEmpty()) {
        if (curIsEmpty()) toFirst();
        while (cursor->next != NULL)
            advance();
    }
}

bool BookList::atEnd() const
{
	if ( listIsEmpty()) return true;
		else if (curIsEmpty()) return false;
			else return cursor->next == NULL;
}

int BookList::listSize() const
{
    node *q = head;
    int counter = 0;
    while (q != NULL) {
        counter++;
        q = q->next;
    }
    return counter;
}

void BookList::updateData(const string &d)
{
	cursor->data = d;
}
void BookList::retrieveData(string &d, int &k) const
{
	d = cursor->data;
	k = cursor->id;
}

void BookList::insertFirst(const int &k, const string &d ){
	toFirst();
	NodePointer pNew = new node;
	pNew->id = k; 
	pNew->data = d;
	pNew->next = head;
	head = pNew;
	cursor = head;
	prev = NULL;
}

void BookList::insertAfter(const int &k, const string &d ){
    NodePointer pNew = new node;
    pNew->id = k;
    pNew->data = d;
    pNew->next = cursor->next;
    cursor->next = pNew;
}

void BookList::insertBefore(const int &k, const string &d){
    if (atFirst()) insertFirst(k, d); 
    else {
        NodePointer pNew = new node;
        pNew->id = k;
        pNew->data = d;
        pNew->next = cursor;
        prev->next = pNew;
        cursor = pNew;
    }
}

void BookList::insertEnd(const int &k, const string &d)
{
	    if (listIsEmpty())insertFirst(k, d);
    else {
        toEnd();
        insertAfter(k, d);
    }
}

void BookList::deleteNode(){
    NodePointer q;
    if (!curIsEmpty()) {
        if (atFirst()) { 
               q = head;
               head = head->next;
               cursor = head;
               prev = NULL;
               delete q;
             
        } else { 
            q = cursor;
            cursor = cursor->next;
            prev->next = cursor;
            delete q;
        }
    }
}

void BookList::deleteFirst()
{
	    if (!listIsEmpty()) {
        toFirst();
        deleteNode();
    }
}

void BookList::deleteEnd()
{
    if (!listIsEmpty()) {
        toEnd();
        deleteNode();
    }
}

void BookList::makeListEmpty()
{
     toFirst();
     while (! listIsEmpty())
        deleteNode();
}


bool BookList::search(const int &k)
{
    bool found = false;
    toFirst();
    while (!found && !curIsEmpty()) {
        if (cursor->id == k)found = true;
        else advance();
    }
    return found;
}


void BookList::orderInsert(const string &d, const int &k)
{
toFirst();
    while (!curIsEmpty() && k > cursor->id)
        advance();
    if (prev == NULL) insertFirst(k, d);
    else insertBefore(k, d);
}


void BookList::traverse(){
	cout << " List of Books: " << endl;

	toFirst();

	while (! curIsEmpty()){
		cout << cursor->id << " - "<< cursor->data << endl;
		advance();
	}
}


int BookList::DisplayList(){
		int count = 0;
		toFirst();
		while (! curIsEmpty())
		{
				cout << cursor->id << " - "<< cursor->data << endl;
				advance();
				count++;
		}
		return count;
}


