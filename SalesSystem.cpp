#include "stdafx.h"
#include "SalesSystem.h"
#include <iostream>
#include <vector>
#include "Line.h"
#include "Ticket.h"
#include "Station.h"
#include "Train.h"
#include "Buyer.h"
#include "RemainedTicketsInfo.h"
using namespace std;

RemainedTicketsInfo * SalesSystem::searchRemainedTickesInfo(Station * startStation, Station * endStation)
{

	return nullptr;
}

Ticket * SalesSystem::buyTicket(Buyer * buyer, Station * startStation, Station * endStation)
{
	Ticket* tempTicket=NULL;
	tempTicket->m_pBuyer = buyer;
	tempTicket->m_pStartStation = startStation;
	tempTicket->m_pEndStation = endStation;
	tickets.push_back(tempTicket);
	return nullptr;
}

vector<Ticket*> SalesSystem::searchTickesInfo(Buyer * buyer)
{
	int i,m = 0;
	int index[90] ;
	for (i=0 ; i < currentTicketID; i++)
	{
		if (tickets.at(i)->m_pBuyer->m_strName == buyer->m_strName || tickets.at(i)->m_pBuyer->m_iId == buyer->m_iId) 
		{
			tickets.at(i)->print();
			index[m] = i;
			m++;
		}
	}
	return vector<Ticket*>();
}

bool SalesSystem::refoundTickets(Buyer * buyer)
{
	int index[90];
	searchTickesInfo(buyer);
	vector<Ticket*>::iterator ite = tickets.begin();
	for (int i = 0; i < currentTicketID ; i++)
	{
		tickets.erase(tickets.begin() + index[i]);
	}
	return false;
}

Station * SalesSystem:: stationWithIndex(int index)
{
	Station* currentStation = m_pLine->m_pStartStation;
	while (currentStation && currentStation->m_iStationID != index)
	{
		currentStation = currentStation->m_pNextStation;
	}
	return currentStation;
}

SalesSystem::SalesSystem()
{
	Station* firstStation = setupStation();
	Train* train = setupTrain();
	m_pLine = new Line("K27", 1234, firstStation, train);
}

Train * SalesSystem::setupTrain()
{
	return new Train("Old train", 1234, 10);
}

Station * SalesSystem::setupStation()
{
	int stationID = 1;
	float distanceToNext = 99;

	Station* firstStation = NULL;
	Station* preStation = NULL;
	for (int i = 0; i < 10; i++) {
		string stationName = "A" + to_string(stationID);
		Station* station = new Station(stationID, stationName, distanceToNext, NULL);
		if (i == 0) {
			firstStation = station;
		}
		if (preStation) {
			preStation->m_pNextStation = station;
		}
		preStation = station;
		stationID++;
		distanceToNext++;
	}
	return firstStation;
}
