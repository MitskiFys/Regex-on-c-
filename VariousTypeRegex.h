#pragma once
#include "Regex.h"
class VariousTypeRegex : 
	public Regex
{
	
public:
	VariousTypeRegex() {};
	VariousTypeRegex(string regex):Regex(regex) {};

	bool IsExtensionMatch(string fileName) {
		string regex = word.regex;
		regex.erase(0, regex.find('.'));
		fileName.erase(0, fileName.find('.'));
		Regex gex(regex);
		return gex.match(fileName);
	}

	bool IsNameMatch(string fileName) {
		string regex = word.regex;
		regex.erase(regex.find('.'), regex.length());
		fileName.erase(fileName.find('.'),fileName.length());
		Regex gex(regex);
		return gex.match(fileName);
	}

	void IsFileMatch(string fileName) {
		string name = IsNameMatch(fileName) ? "Current" : "Does not match";
		string extension = IsExtensionMatch(fileName) ? "Current" : "Does not match";
		cout << "Name: " << name << " Extension: " << extension << endl;
	}

};

