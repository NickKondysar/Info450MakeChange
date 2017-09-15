
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include<iomanip>

using namespace std;


int main()
{
	cout << setiosflags(ios::fixed) << setprecision(2);
	bool program = true;

	while (program == true) {

		double cost;
		double amtPaid;
		double morePayment;
		double totalamtPaid;
		int dollars = 0;
		int quarters = 0;
		int dimes = 0;
		int nickels = 0;
		int paid = 0;
		bool error = false;
		bool vending = true;


		while (vending == true) {

			error = false;

			cout << "Please enter a cost of an item: ";
			cin >> cost;
			if (cost == 0) {
				program = false;
				break;
			}
			cout << "Please enter the amout paid: ";
			cin >> amtPaid;
			while (paid == 0)
			{

				if (amtPaid < cost)
				{
					cout << "Please enter more money.";
					cin >> morePayment;
					amtPaid += morePayment;

				}
				else {
					totalamtPaid = amtPaid;
					paid = 1;
				}
			}
			while (paid == 1) {
				if (amtPaid - cost >= 1) {
					dollars++;
					amtPaid -= 1;
				}
				else if (amtPaid - cost >= 0.25) {
					quarters++;
					amtPaid -= 0.25;
				}
				else if (amtPaid - cost >= 0.1) {
					dimes++;
					amtPaid -= 0.10;
				}
				else if (amtPaid - cost >= 0.05) {
					nickels++;
					amtPaid -= 0.05;
				}

				if (amtPaid - cost == 0) {
					vending = false;
					paid = 2;
				}
			}
			if (error == true) {
				continue;
			}

		}
		if (paid == 2) {
			cout << "Item Price: " << cost << endl;
			cout << "Amount paid:" << totalamtPaid << endl;
			cout << "Change due: $" << totalamtPaid - cost << endl;
			if (totalamtPaid - cost != 0) {
				cout << "Your change is: " << endl;
				if (dollars > 0)
					cout << dollars << " Dollar(s)" << endl;
				if (quarters > 0)
					cout << quarters << " Quarter(s)" << endl;
				if (dimes > 0)
					cout << dimes << " Dime(s)" << endl;
				if (nickels > 0)
					cout << nickels << " Nickels(s)" << endl;
			}

		}

	}
}
