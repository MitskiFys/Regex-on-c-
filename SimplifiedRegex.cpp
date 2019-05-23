#include "SimplifiedRegex.h"
void SimplifiedRegex::find(string what)
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
							if (this->word.findplace == sim + 1) {
								area.erase(0, this->word.findplace +1);
								this->word.findplace = 0;
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


bool SimplifiedRegex::match(string name)
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

