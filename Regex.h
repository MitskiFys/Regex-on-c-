#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <fstream>
#include "Helper.h"
#include "ListClass.h"


using namespace std;


class Regex 
{
protected:
	struct DataBase
	{
		string name;
		int lgthname;
		int findplace = 0;
		bool chek = false;
		void getnumb() { lgthname = name.length(); }
		string regex;
	}word;

	vector <int> todo;
	bool haveinline(string, string);
	void setarr(string);
	void write();
	void find(string);
public:

	Regex() {

	};

	Regex(string regex)
	{
		setarr(regex);
		word.regex = regex;
	}

	virtual bool match(string);

	friend ostream& operator << (ostream& os, Regex& regex);

	Regex& operator = (const Regex& regex);

	bool operator == (string reg_1);
	friend bool operator == (Regex& reg_1, Regex& reg_2);
	friend bool operator == (string reg_1, Regex& reg_2);

	bool operator != (string reg_1);
	friend bool operator != (Regex& reg_1, Regex& reg_2);
	friend bool operator != (string reg_1, Regex& reg_2);

	void operator >> (string& str);
	operator string () const;

	void chekList(ListClass* list) {
		list->qurentList = list->startList;
		while (list->qurentList != NULL) {
			if ((!match(list->qurentList->data)) && (list->qurentList->data != "Null")) {
				list->deleteList(list->qurentList);
				list->qurentList = list->startList;
			}
			else list->qurentList = list->qurentList->nextList;
		}
		
	}

};