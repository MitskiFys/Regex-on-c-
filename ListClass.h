#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class ListClass
{
public:
	struct List {
		List* prevList = NULL;
		List* nextList = NULL;
		std::string data = "";
	};
	List* qurentList = NULL;
	List* startList = new List;
	
public:
	
	ListClass();

	void addList(std::string data) {
		qurentList = startList;
		while (qurentList->nextList != NULL) qurentList = qurentList->nextList;
		if ((qurentList->prevList != NULL) || (qurentList->data != "")) {
			List* newList = new List;
			newList->data = data;
			qurentList->nextList = newList;
			newList->prevList = qurentList;
		}
		else {
			qurentList->data = data;
		}
	}

	void deleteList(List* deletelist) {
		if (((deletelist->prevList != NULL) && (deletelist->nextList != NULL))) {
			(deletelist->prevList)->nextList = deletelist->nextList;
			(deletelist->nextList)->prevList = deletelist->prevList;
		}
		else if ((deletelist->nextList == NULL) && (deletelist->prevList != NULL))
			(deletelist->prevList)->nextList = NULL;
		else if ((deletelist->prevList == NULL) && (deletelist->nextList != NULL)) {
			startList = deletelist->nextList;
			startList->prevList = NULL;
		}
		else deletelist->data = "Null";
	}

	void printStack() {
		qurentList = startList;
		while (qurentList != NULL) {
			std::cout << qurentList->data << endl;
			qurentList = qurentList->nextList;
		}
	}

	/*void chekList(Regex& regex) {
		List* qurentList = startList;
		while (qurentList != NULL) {
			if ((!regex.match(qurentList->data)) && (qurentList->data != "Null")) {
				deleteList(qurentList);
				qurentList = startList;
			}
			else
				qurentList = qurentList->nextList;
		}
	}*/

	void readFromFile(std::string file = "C://Users//Mitski//Desktop//forlabs.txt") {
		std::string line;
		ifstream filein(file);
		while (getline(filein, line)) {
			addList(line);
		}
		printStack();
	}

	~ListClass();
};

