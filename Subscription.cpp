#include"Subscription.h"
//Name:ManlinMao
//Purpose:assignment 3, writting a program that use linked
//list to keep track of a magazine distributor's magazine
//subscriptions
//Section101
Subscription::Subscription(string newDistriName)
{
	distributorName = (newDistriName.length() > 0) ? newDistriName : "Unknown";
	numMagazines = 0;
	firstPtr = NULL;
}
//destructor
Subscription::~Subscription() {
	Magazine* walker = firstPtr;
	while (walker != NULL)
	{
		walker = walker->link;
		cout << "Deleting:" << firstPtr->name << endl;
		delete firstPtr;
		firstPtr = walker;
	}

}
//function that display magzines to the screen
void Subscription::showMagazines(ostream& out)const {

	Magazine* walker = firstPtr;
	out << "Distributor Name: " << distributorName << endl;
	out << "Magazine Name" << setw(20)
		<< right << "ISBN" << right
		<< setw(30) << "Delivery Type" << endl << endl;

	while (walker != NULL)
	{
		string delivery = (toupper(walker->delivery) == 'D') ? "Daily" :
			(toupper(walker->delivery) == 'W') ? "Weekly"
			: (toupper(walker->delivery) == 'M') ? "Monthly" : "Unknown";
		out << setw(29) << left << walker->name 
			<< left << setw(21) << walker->isbn
			<< right << delivery << endl;
		walker = walker->link;

	}
	out << "# of magazines=" << numMagazines << endl << endl;
}
//function add node to a list
void Subscription::addMagazine(string newMagName, 
	string newIsbn, char newDelivery)
{
	string addRecordMsg = "+++++Record added+++++";
	Magazine* walker = firstPtr, * stalker = NULL;
	Magazine* builder = new Magazine;
	assert(builder != 0);
	builder->name = (newMagName.length() > 0) ? newMagName : "Unknown";
	builder->isbn = (newIsbn.length() > 0) ? newIsbn : "Unknown";
	builder->delivery = (toupper(newDelivery) == 'D') ? newDelivery :
		(toupper(newDelivery) == 'W') ? newDelivery :
		(toupper(newDelivery) == 'M') ? newDelivery : 'N';
	builder->link = NULL;
	if (firstPtr == NULL)//checking if the list is empty
	{
		firstPtr = builder;
		cout << addRecordMsg << endl;
		numMagazines++;
	}
	else {
		while (walker != NULL)//while not the end of the list
		{

			if (walker->isbn == builder->isbn)//checking if isbn exist
			{
				cout << "isbn already exist" << endl;
				break;
			}

			if (firstPtr->name > builder->name)//add to begin
			{
				firstPtr = builder;
				builder->link = walker;
				cout << addRecordMsg << endl;
				numMagazines++;
				break;
			}

			if (walker->name > builder->name)//add to middle
			{
				stalker->link = builder;
				builder->link = walker;
				cout << addRecordMsg << endl;
				numMagazines++;
				break;
			}

			if (walker->link == NULL)//add to end
			{
				walker->link = builder;
				cout << addRecordMsg << endl;
				numMagazines++;
				break;
			}

			stalker = walker;
			walker = walker->link;
		}



	}

}
//function removing node from list
void Subscription::removeMagazine(string delIsbn)
{
	Magazine* walker = firstPtr, * stalker = NULL;
	if (firstPtr == NULL)
	{
		cout << "list is empty";
	}
	else
	{
		while (walker != NULL)
		{
			if (walker->isbn == delIsbn)
			{
				if (walker == firstPtr)//remove first
				{
					firstPtr = walker->link;
					delete walker;
					break;
				}
				else {
					stalker->link = walker->link;
					delete walker;

					break;
				}
			}
			stalker = walker;
			walker = walker->link;
		}

		if (walker == NULL)
		{
			cout << "______Isbn not found______" << endl;
		}
		else
		{
			numMagazines--;
			cout << "-----Record deleted-----" << endl;
		}

	}
}