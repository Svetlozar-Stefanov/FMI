#include <iostream>
#include <string>

#include "Figures/FigureFactories/FigureFactory.h"
#include "Figures/FigureFactories/AbstractFactory.h"
#include "FigureCollection.h"

using std::cin;
using std::cout;
using std::string;
using std::stoi;

int main()
{
	AbstractFactory af;
	unique_ptr<FigureFactory> figureFactory = nullptr;

	cout << "Choose figure input method: \n";
	string userInput;
	getline(cin, userInput);
	if (userInput == "exit") { return 0; }
	while (true)
	{
		try
		{
			figureFactory = af.createFactory(userInput);
			break;
		}
		catch (const std::invalid_argument&)
		{
			figureFactory.reset();
			cout << "Invalid input method\n";
			cout << "Please enter valid input method or exit:\n";
			getline(cin, userInput);
			if (userInput == "exit") { return 0; }
		}
	}

	FigureCollection figures;
	cout << "Enter number of figures: \n";
	getline(cin, userInput);
	int n = 0;
	while (true)
	{
		try
		{
			n = stoi(userInput);
			break;
		}
		catch (const std::invalid_argument&)
		{
			cout << "Invalid number. Please enter new number or exit: \n";
			getline(cin, userInput);
			if (userInput == "exit") { return 0; }
		}
		catch (const std::out_of_range&)
		{
			cout << "Number too big. Please enter new number or exit: \n";
			getline(cin, userInput);
			if (userInput == "exit") { return 0; }
		}
	}
	
	try
	{
		bool errorOccured = false;
		for(int i = 0; i < n; i++)
		{
			try
			{
				figures.add(figureFactory->createFigure());
			}
			catch (const std::invalid_argument&)
			{
				errorOccured = true;
				cout << "Invalid parameters passed for figure number " << i << "\n";
			}
		}
		if (errorOccured)
		{
			throw std::runtime_error("Could not read all figures properly.\n");
		}
	}
	catch (const std::runtime_error&)
	{
		cout << "Could not load all figures. Do you wish to exit: \n";
		getline(cin, userInput);
		if (userInput == "yes") { return 0; }
	}

	cout << "Enter operation: \n";
	cin >> userInput;
	while (userInput != "exit")
	{
		if (userInput == "print")
		{
			figures.print();
		}
		else if (userInput == "delete")
		{
			int index = 0;
			cin >> index;
			try
			{
				figures.remove(index);
			}
			catch (const std::out_of_range&)
			{
				cout << "Could not delete at " << index << " position.\n";
			}
			
		}
		else if (userInput == "duplicate")
		{
			int index = 0;
			cin >> index;
			try
			{
				figures.duplicate(index);
			}
			catch (const std::out_of_range&)
			{
				cout << "Could not duplicate at " << index << " position.\n";
			}
		}
		else if (userInput == "save")
		{
			string filename;
			cin >> filename;
			try
			{
				figures.saveToFile(filename);
			}
			catch (const std::runtime_error&)
			{
				cout << "Could not save to file with name: " << filename << '\n';
			}
		}
		cout << "Enter operation: \n";
		cin >> userInput;
	}

	return 0;
}