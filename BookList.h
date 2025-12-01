#ifndef BOOK_LIST_H
#define BOOK_LIST_H
# include <iostream>
# include <string>
using namespace std;
using std::string;

class node{
    	
    	public:
    		int id; 
    		string data;
    		node* next;	
};

class BookList {
	public:	
    BookList();

    ~BookList();
    
     //operations/functions
  bool listIsEmpty() const;
	bool curIsEmpty() const;
  void toFirst();
	bool atFirst() const;
	void advance();
	void toEnd();
	bool atEnd() const;
	int listSize() const;
	void updateData(const string & );
	void retrieveData(string &, int &) const;
	void retrieveKey(int &) const;
	void insertFirst(const int &, const string & );	
	void insertAfter(const int &, const string & );	
	void insertBefore(const int &, const string & );
	void insertEnd(const int &, const string & );
	void deleteNode();
	void deleteFirst();
	void deleteEnd();
	void makeListEmpty();
	bool search(const int & );
	void orderInsert(const string &, const int & );
	void traverse();
	int DisplayList();

private:

	typedef node * NodePointer;
	NodePointer head, cursor, prev; 

};

#endif
