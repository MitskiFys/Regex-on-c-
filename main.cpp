#include <iostream>
//#include "ListClass.h"
#include <string>
#include "ListClass.h"
#include "SimplifiedRegex.h"
#include "VariousTypeRegex.h"

using namespace std;

Regex* getRegex(string regex);

int main() {

	Regex* gex = getRegex("?t");
	Regex* gex1 = getRegex("?t");

	int i;
	cin >> i;

	ListClass* list = new ListClass;
	ListClass* list1 = new ListClass;

	for (int j = 0; j < i; j++) {
		string line;
		cin >> line;
		list1->addList(line);
	}
	list1->printStack();
	cout << endl;
	gex->chekList(list1);
	list1->printStack();
	list->readFromFile();
	gex->chekList(list);
	cout << endl;
	list->printStack();
	//gex->readFromFile();
	//newList.chekList(*gex);
	//gex->chekList();
	//cout << endl;
	//gex->printStack();

	//cout << gex->match("ttheh.txt") << endl;
	//auto gex = SimplifiedRegex::getOjkSimple("?t.txt");
	//VariousTypeRegex gex("?i.t?t");
	/*cout << gex.IsExtensionMatch("ehe.txt") << endl;
	cout << gex.IsNameMatch("yi.txt") << endl;
	gex.IsFileMatch("yi.tx");*/
	//gex.IsExtensionMatch()
	/*Regex gex("*i?");
	Regex gex_1(".txt*");
	cout << gex.match("lskjfkshuij") << endl;
	cout << gex << endl;
	gex = gex_1;

	cout << (gex == gex_1) << endl;
	cout << (gex == ".txt*") << endl;
	cout << (".txt*" == gex) << endl;

	cout << (gex != gex_1) << endl;
	cout << (gex != ".txt*") << endl;
	cout << (".txt*" != gex) << endl;

	string str;
	gex >> str;
	cout << str << endl;
	string str2;
	str2 = gex_1;
	cout << str2 << endl;*/
 	system("pause");

	return 0;
}

Regex* getRegex(string regex)
{
	int val;
	cout << "select type of regex: " << endl;
	cout << "1- usual regex\n2- simplifiedregex  -> " && cin >> val;
	switch (val)

	{
	case 1:
		return new Regex(regex);
		break;
	case 2:
		return SimplifiedRegex::getOjkSimple(regex);
		break;
	}

}