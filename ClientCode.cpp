#include"Subscription.h"
//Name:ManlinMao
//Purpose:assignment 3, writting a program that use linked
//list to keep track of a magazine distributor's magazine
//subscriptions
//Section101
int main() {
	//create instance of Subscription class on heap
	cout << "*********Create an instance on the heap*********" << endl;
	Subscription* readerOne = new Subscription("People Magazine");
	assert(readerOne != 0);
	cout << "Distributor Name:" << readerOne->getDistributorName()
		<< ", Number of magazines: " << readerOne->getNoMagazine()
		<< endl << endl;

	cout << "*******Insert one when list is empty****" << endl;
	readerOne->addMagazine("Cats In The Wild", "345-24223-8-596", 'd');
	readerOne->showMagazines(cout);

	cout << "*******Insert One with false data*******" << endl;
	readerOne->addMagazine("", "", 'k');
	readerOne->showMagazines(cout);

	cout << "****Insert One with same ISBN 345-24223-8-596***" << endl;
	readerOne->addMagazine("Cats", "345-24223-8-596", 'M');
	readerOne->showMagazines(cout);

	cout << "**********Insert One at the end*********" << endl;
	readerOne->addMagazine("What's out there", "345-24223-8-598", 'd');
	readerOne->showMagazines(cout);


	cout << "*************Insert One at the begin*****" << endl;
	readerOne->addMagazine("Apple From Space", "345-24223-8-599", 'w');
	readerOne->showMagazines(cout);

	cout << "***************Add to the middle*********" << endl;
	readerOne->addMagazine("Blink", "345-24223-8-595", 'm');
	readerOne->showMagazines(cout);

	cout << "*********************Remove first*********" << endl;
	readerOne->removeMagazine("345-24223-8-599");
	readerOne->showMagazines(cout);

	cout << "******************Remove Last**************" << endl;
	readerOne->removeMagazine("345-24223-8-598");
	readerOne->showMagazines(cout);

	cout << "*********************Remove Middle*********" << endl;
	readerOne->removeMagazine("345-24223-8-596");
	readerOne->showMagazines(cout);


	cout << "******Remove same ISBN 345-24223-8-596*****" << endl;
	readerOne->removeMagazine("345-24223-8-596");
	readerOne->showMagazines(cout);


	delete readerOne;

	system("pause");
}
/*
*********Create an instance on the heap*********
Distributor Name:People Magazine, Number of magazines: 0

*******Insert one when list is empty****
+++++Record added+++++
Distributor Name: People Magazine
Magazine Name                ISBN                 Delivery Type

Cats In The Wild             345-24223-8-596      Daily
# of magazines=1

*******Insert One with false data*******
+++++Record added+++++
Distributor Name: People Magazine
Magazine Name                ISBN                 Delivery Type

Cats In The Wild             345-24223-8-596      Daily
Unknown                      Unknown              Unknown
# of magazines=2

****Insert One with same ISBN 345-24223-8-596***
isbn already exist
Distributor Name: People Magazine
Magazine Name                ISBN                 Delivery Type

Cats In The Wild             345-24223-8-596      Daily
Unknown                      Unknown              Unknown
# of magazines=2

**********Insert One at the end*********
+++++Record added+++++
Distributor Name: People Magazine
Magazine Name                ISBN                 Delivery Type

Cats In The Wild             345-24223-8-596      Daily
Unknown                      Unknown              Unknown
What's out there             345-24223-8-598      Daily
# of magazines=3

*************Insert One at the begin*****
+++++Record added+++++
Distributor Name: People Magazine
Magazine Name                ISBN                 Delivery Type

Apple From Space             345-24223-8-599      Weekly
Cats In The Wild             345-24223-8-596      Daily
Unknown                      Unknown              Unknown
What's out there             345-24223-8-598      Daily
# of magazines=4

***************Add to the middle*********
+++++Record added+++++
Distributor Name: People Magazine
Magazine Name                ISBN                 Delivery Type

Apple From Space             345-24223-8-599      Weekly
Blink                        345-24223-8-595      Monthly
Cats In The Wild             345-24223-8-596      Daily
Unknown                      Unknown              Unknown
What's out there             345-24223-8-598      Daily
# of magazines=5

*********************Remove first*********
-----Record deleted-----
Distributor Name: People Magazine
Magazine Name                ISBN                 Delivery Type

Blink                        345-24223-8-595      Monthly
Cats In The Wild             345-24223-8-596      Daily
Unknown                      Unknown              Unknown
What's out there             345-24223-8-598      Daily
# of magazines=4

******************Remove Last**************
-----Record deleted-----
Distributor Name: People Magazine
Magazine Name                ISBN                 Delivery Type

Blink                        345-24223-8-595      Monthly
Cats In The Wild             345-24223-8-596      Daily
Unknown                      Unknown              Unknown
# of magazines=3

*********************Remove Middle*********
-----Record deleted-----
Distributor Name: People Magazine
Magazine Name                ISBN                 Delivery Type

Blink                        345-24223-8-595      Monthly
Unknown                      Unknown              Unknown
# of magazines=2

******Remove same ISBN 345-24223-8-596*****
______Isbn not found______
Distributor Name: People Magazine
Magazine Name                ISBN                 Delivery Type

Blink                        345-24223-8-595      Monthly
Unknown                      Unknown              Unknown
# of magazines=2

Deleting:Blink
Deleting:Unknown
Press any key to continue . . .

*/