// Write design of system for a car rental website supporting functionalities 
// addcar(availability location, carmodel, hourly price)
// addlocation(loc_name, hrs of availability(eg. 9-7)
// searchcars(pickuptime,dropofftime)
// Searchandsortbyprice(pickuptime, dropofftime)
// The system should be such that each car and location has a unique id.


// Cases:
// void addlocation(loc_name, startTime,endTime)   :return id assigned to the location
// int addCar(carLocation,carModel,price) :return id assigned to the car
// vector<int> searchCar(startTime,endTime)  :return all ids of car which is available
// vector<vector<int>> sortCarByPrice(startTime,endTime) : return ids and price of cars available sorted by price

//object needed:
// Location:locationName,startTime,endTime,id 
// Car:location,model,id,price

#include <bits/stdc++.h>
using namespace std;

class Location{
public:
    static int id;
    string locationName;
    int startTime,endTime;
    
    Location(string locationName,int startTime,int endTime)
    {
        this->locationName=locationName;
        this->startTime=startTime,
        this->endTime=endTime;
        this->id=id;
        id++;
        
    }
};
class Car{
public:
    static int id;
    string locationName;
    int price;
    string model;
    
    Car(string location,string model,int price)
    {
        this-> model= model;
        this->locationName=location,
        this->id=id;
        this->price=price;
        id++; 
    }
};
int Location :: id=0;
int Car :: id=0;

class uberRentalSystem{
    map<string,Location>locationObj;                     //all the location will have a specific ids assigned
    map<int,vector<pair<int,Car>>>Cars;                  //first int will be gor locationId,priority queue will store the hourly price
    
    int addLocation(string locationName,int startTime,int endTime)
    {
        Location loc(locationName,startTime,endTime);
        int id=loc.id;
        locationObj[locationName]=loc;
        return id;
    }
    int addCar(string location,string model,int price)
    {
        Car c(location,model,price);
        int id=c.id;
        int locId=locationObj[location].id;
        Cars[locId].push_back({c.price,c});
        return id;
    }
    vector<int>searchCars(int pickTime,int dropTime)
    {
        vector<int>carAvail;
        for(auto l:locationObj)
        {
            int startTime=l.second.startTime;
            int endTime=l.second.endTime;
            int locId=l.second.id;
            if(pickTime>endTime || dropTime<startTime)
                continue;
            // else add all the cars availeble at that location
            for(auto c:Cars[locId])
            {
                carAvail.push_back(c.second.id);
            }
        }
        return carAvail;
    }
    vector<vector<int>>searchCarsByPrice(int pickTime,int dropTime)
    {
        vector<vector<int>>carAvail;
        for(auto l:locationObj)
        {
            int startTime=l.second.startTime;
            int endTime=l.second.endTime;
            int locId=l.second.id;
            if(pickTime>endTime || dropTime<startTime)
                continue;
            
            for(auto c:Cars[locId])
            {
                carAvail.push_back({c.first,c.second.id});
            }
        }
        sort(carAvail.begin(),carAvail.end());
        return carAvail;
    }
};




