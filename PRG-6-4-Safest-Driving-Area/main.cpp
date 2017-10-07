//
//  main.cpp
//  PRG-6-4-Safest-Driving-Area
//
//  Created by Keith Smith on 10/7/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//
//  Write a program that determines which of the five geographic regions within a major city
//  (north, south, east, west, and central) had the fewest reported automobile accidents last
//  year. It should have the following two functions, which are called by main:
//  int getNumAccidents() is passed the name of a region. It asks the user for the
//  number of automobile accidents reported in that region during the last year, validates
//  the input, then returns it. It should be called once for each city region.
//  void findLowest() is passed the five accident totals. It determines which is the
//  smallest and prints the name of the region, along with its accident figure.
//
//  Input validation: Do not accept an accident number that is less than 0


#include <iostream>

using namespace std;

int getNumAccidents(string);
void findLowest(int, int, int, int, int);

int main()
{
    string strRegion;
    
    int intNumAccidentsNorth,
        intNumAccidentsSouth,
        intNumAccidentsEast,
        intNumAccidentsWest,
        intNumAccidentsCentral;
    
    // Call function to populate variables
    intNumAccidentsNorth = getNumAccidents("north");
    intNumAccidentsSouth = getNumAccidents("south");
    intNumAccidentsEast = getNumAccidents("east");
    intNumAccidentsWest = getNumAccidents("west");
    intNumAccidentsCentral = getNumAccidents("central");
    
    // Pass variables through to see which is the lowest
    findLowest(intNumAccidentsNorth, intNumAccidentsSouth, intNumAccidentsEast, intNumAccidentsWest, intNumAccidentsCentral);
    
    return 0;
}

// Called for each region, gets number of accidents from user and returns that to main
int getNumAccidents(string strRegion)
{
    int intNumAccidents;
    
    cout << "Please enter the number of accidents for the " << strRegion << " region:\n";
    cin >> intNumAccidents;
    // Data validation
    while(!cin || intNumAccidents < 0 || intNumAccidents > 10000)
    {
        cout << "Please enter a number of accidents greater than\n"
        << "or equal to zero and less than or equal to 10,000:\n";
        cin.clear();
        cin.ignore();
        cin >> intNumAccidents;
    }
    
    cout << "getNumAccidents completed successfully.\n";
    
    return intNumAccidents;
}

// Compare values and output lowest region's value
void findLowest(int intNorth, int intSouth, int intEast, int intWest, int intCentral)
{
    if(intNorth < intSouth && intNorth < intEast && intNorth < intWest && intNorth < intCentral)
    {
        cout << "Region North has the lowest accidents this month\n"
        << "with a total of " << intNorth << " accidents.\n";
    }
    else if(intSouth < intNorth && intSouth < intEast && intSouth < intWest && intSouth < intCentral)
    {
        cout << "Region South has the lowest accidents this month\n"
        << "with a total of " << intSouth << " accidents.\n";
    }
    else if(intEast < intNorth && intEast < intSouth && intEast < intWest && intEast < intCentral)
    {
        cout << "Region East has the lowest accidents this month\n"
        << "with a total of " << intEast << " accidents.\n";
    }
    else if(intWest < intNorth && intWest < intSouth && intWest < intEast && intWest < intCentral)
    {
        cout << "Region West has the lowest accidents this month\n"
        << "with a total of " << intWest << " accidents.\n";
    }
    else if(intCentral < intNorth && intCentral < intSouth && intCentral < intEast && intCentral < intWest)
    {
        cout << "Region Central has the lowest accidents this month\n"
        << "with a total of " << intCentral << " accidents.\n";
    }
    else
    {
        cout << "There was a tie.\n";
    }
}

