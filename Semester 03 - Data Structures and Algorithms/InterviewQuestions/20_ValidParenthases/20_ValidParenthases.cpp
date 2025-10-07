#include <iostream>
#include <stack>

using namespace std;

bool close(char o, char e) {
	if (o == '(' && e == ')')
	{
		return true;
	}
	else if (o == '{' && e == '}')
	{
		return true;
	}
	else if (o == '[' && e == ']') {
		return true;
	}
	return false;
}

bool isValid(string s) {
	stack<char> par;
	for (int i = 0; i < s.size(); i++)
	{
		char p = s[i];

		if (p == '('
			|| p == '{'
			|| p == '[')
		{
			par.push(p);
		}
		else if (p == ')'
			|| p == '}'
			|| p == ']')
		{
			if (!close(par.top(), p))
			{
				return false;
			}
			par.pop();
		}
	}

	if (par.size() <= 0)
	{
		return true;
	}

	return false;
}

int main()
{


}
