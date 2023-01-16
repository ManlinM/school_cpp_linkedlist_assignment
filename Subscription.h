#pragma once
//Name:ManlinMao

#include<iostream>
#include<string>
#include<cassert>
#include<iomanip>

using namespace std;

struct Magazine
{
public:
	string name, isbn;
	char delivery;
	Magazine* link;
};

class Subscription {
public:
	Subscription(string/*distributor name*/);
	~Subscription();
	void showMagazines(ostream&/*output*/)const;
	void addMagazine(string/*magzine name*/, string/*isbn*/, char/*delivery*/);
	void removeMagazine(string/*isbn*/);
	int getNoMagazine()const { return numMagazines; }
	string getDistributorName()const { return distributorName; }
	
private:
	string distributorName;
	int numMagazines;
	Magazine* firstPtr;

};