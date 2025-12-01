#include <iostream>
#include <string>
#include "BookList.h"
#include"stdio.h"
using namespace std;
# include <string>
using std::string;

int main()
{
	BookList Book;
	
	Book.insertFirst(1,"C++");
	Book.insertAfter(2,"JAVA");

	Book.traverse();
		
	
	return 0;
}
