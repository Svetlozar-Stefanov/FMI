#include "StandardInputLabel.h"

#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::getline;

StandardInputLabel::StandardInputLabel(int timeout)
	: mText(""), mTimeout(timeout), mRequests(0), mFirst(true)
{}

string StandardInputLabel::getText() const
{
	if (mRequests == 0)
	{	
		string temp = "y";
		if (mTimeout > 0 && !mFirst)
		{
			do {
				cout << "Do you wish to change text: ";
				getline(cin, temp);
			}
			while (temp != "y" && temp != "n");
		}
		if (temp == "y")
		{
			cout << "Enter label text: ";
			getline(cin, mText);
			mFirst = false;
		}
	}
	mRequests++;
	if (mRequests == mTimeout)
	{
		mRequests = 0;
	}
	return mText;
}