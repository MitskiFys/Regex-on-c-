#include "Regex.h"
static string restriction[1] = { "*" };
class SimplifiedRegex : 
	public Regex
{
public:
	SimplifiedRegex() {};
	SimplifiedRegex(string regex):Regex(regex) {};
	
	static SimplifiedRegex* getOjkSimple(string regex) {
		while (true) {
			for (const string& val : restriction) {
				if (regex.find(val) == -1) {
					return new SimplifiedRegex(regex);
				}
				else
					return nullptr;
			}
		}
	}
	bool match(string);
	void find(string);
	
};