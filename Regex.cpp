#include "Regex.h"

bool Regex::haveinline(string what, string where)
{
	if (what.length() > where.length()) { return false; };
	if ((what == "") && (where != "")) { return false; };
	for (int i = 0; i <= where.length(); i++) {
		int j = 0;
		int matches = 0;
		word.findplace++;
		while ((i < where.length()) && (what[j] == where[i])) {
			i++;
			j++;
			matches++;
			word.findplace++;
		}
		if (matches == what.length()) {
			word.findplace = i - matches;
			//currentitem->findplace
			return true;
		}
		else {
			i = i - matches;
		}
	}
	return false;
}

void Regex::setarr(string what)
{
	//todo.insert(todo.end(), 0);
	for (int i = 0; i < what.length(); i++) {
		switch (what[i])
		{
		case '*':
		{
			if (((todo.size()) % 2) == 0) {
				todo.insert(todo.end(), 2);
			}
			else {
				todo[todo.size() - 1] = 2;
			}
			break;
		}
		case '?':
		{
			if (((todo.size()) % 2) == 0) {
				todo.insert(todo.end(), 1);
			}
			break;
		}
		default:
			if (todo.size() == 0) { todo.insert(todo.end(), 0); }
			todo.insert(todo.end(), 0);
			while ((i < what.length()) && (what[i] != '?') && (what[i] != '*')) {
				i++;
				todo[todo.size() - 1]++;
			}
			i--;
			break;
		}
	}
	if (todo.size() % 2 != 0) { todo.insert(todo.end(), 0); }
	//copy(todo.begin(), todo.end(), ostream_iterator<int>(cout, " "));
	//cout << endl;
}

void Regex::write()
{
	if (word.chek != true) {
		cout << word.name << endl;
	}
}

void Regex::find(string what)
{
	string savewhat = this->word.regex;
	string word;

	string area = this->word.name;
	what = savewhat;
	for (int i = 0; i < todo.size(); i++) {
		if (this->word.chek == false) {
			int j = i;
			if (j % 2 == 0) {
				word = "";
				switch (todo[i])
				{
				case 0:
				{
					j = 0;
					for (; j < todo[i + 1]; j++) {
						word += what[j];
					}
					what.erase(0, todo[i + 1]);
					if (haveinline(word, area)) {
						if ((this->word.findplace > 0) || (word.length() != area.length())) {
							if (todo.size() < i + 3) {
								this->word.chek = true;
								break;
							}
							else {
								area.erase(0, word.length());
								this->word.findplace = 0;
								break;
							}
						}
						else {
							area.erase(0, word.length());
							this->word.findplace = 0;
							break;
						}
					}
					else {
						this->word.chek = true;
						break;
					}
				}
				case 1:
				{

					j = 0;
					int sim = 0;
					while ((what[j] == '?') || (what[j] == '*')) {
						what.erase(0, 1);
						sim++;
					}
					for (; j < todo[i + 1]; j++) {
						word += what[j];
					}
					what.erase(0, todo[i + 1]);

					if (word != "") {
						if (haveinline(word, area)) {
							if (this->word.findplace < sim + 1) {
								area.erase(0, this->word.findplace+1);
								this->word.findplace = 0;
								if ((todo.size() == (i + 2))&&(area.length()>0)) {
									this->word.chek = true;
									break;
								}
								break;
							}
							else {
								this->word.chek = true;
								break;
							}
						}
						else {
							this->word.chek = true;
							break;
						}
					}
					else {
						if (area.length() < sim + 1) {
							area.erase(0, sim + word.length() - 1);
							break;
						}
						else {
							this->word.chek = true;
							break;
						}
					}

				}
				case 2:
				{

					j = 0;
					while ((what[j] == '?') || (what[j] == '*')) {
						what.erase(0, 1);
					}
					for (; j < todo[i + 1]; j++) {
						word += what[j];
					}
					what.erase(0, todo[i + 1]);

					if (word != "") {
						if (haveinline(word, area)) {
							area.erase(0, this->word.findplace + word.length());
							if ((todo.size() == (i + 2)) && (area.length() > 0)) {
								this->word.chek = true;
								break;
							}
							break;
						}
						else {
							this->word.chek = true;
							break;
						}
					}
					else {

					}

				}
				}
			}
		}
	}
	//cout << (todo.size()) << endl;
	//copy(todo.begin(), todo.end(), ostream_iterator<int>(cout, " "));
}

bool Regex::match(string name)
{
	word.name = name;
	word.getnumb();
	find(word.name);
	if (word.chek != true) {
		word.chek = false;
		word.findplace = 0;
		return true;
	}
	else { word.chek = false; word.findplace = 0; return false; }
}

Regex& Regex::operator=(const Regex& regex)
{
	this->word.chek = regex.word.chek;
	this->word.findplace = regex.word.findplace;
	this->word.lgthname = regex.word.lgthname;
	this->word.name = regex.word.name;
	this->word.regex = regex.word.regex;
	this->todo = regex.todo;
	return *this;
}

bool Regex::operator==(string reg_1)
{
	if (reg_1 == this->word.regex) return true;
	return false;
}

bool Regex::operator!=(string reg_1)
{
	return *this == (reg_1);
}

void Regex::operator>>(string& str)
{
	str = this->word.regex;
}

Regex::operator string() const
{
	return word.regex;
}

ostream& operator << (ostream& os, Regex& regex) {
	os << regex.word.regex;
	return os;
}

bool operator==(Regex& reg_1, Regex& reg_2)
{
	return (reg_1.word.regex == reg_2.word.regex);
}

bool operator==(string reg_1, Regex& reg_2)
{
	if (reg_1 == reg_2.word.regex) return true;
	return false;
}

bool operator!=(Regex& reg_1, Regex& reg_2)
{
	if (reg_1.word.regex != reg_2.word.regex) return true;
	return false;
}

bool operator!=(string reg_1, Regex& reg_2)
{
	if (reg_1 != reg_2.word.regex) return true;
	return false;
}