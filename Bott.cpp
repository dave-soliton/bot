//
//  Bott.cpp
//  Bots_Alive
//
//  Created by David Foster on 02/06/2020.
//  Copyright © 2020 David Foster. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <random>
#include "Web_struct.hpp"
#include "Bott.hpp"
using namespace std;

void Bot::Print_Prob()
{
    for(auto t : Web_pob)
    {
        cout<<t.name<<"  "<<t.prob<<"\n";
    }
}

double Bot::Gaussian_type(double x, double s)
{
    return exp(-pow(x,2)/(2.0*pow(s,2)));
}

void Bot::Add_chat(string web, double val)
{   //Alters the previouse probabilites so the sum is one including the new probablity.
    for (int i=0; i < Web_pob.size();++i)
    {
        Web_pob[i].prob = Web_pob[i].prob*(1-val);
    }
    // Include the new probability
    Web_pob.push_back({web, val});
}

string Bot::What_page_on(double rand)
{
    // step through cumulative distribution untill find window containing random number
    double sum = 0.0;
    string page;
    for (int i=0; i < Web_pob.size();++i)
    {
        sum += Web_pob[i].prob;
        page = Web_pob[i].name;
        if(sum >= rand)
        {
            return  page;
        }
        
    }
    // return nul
    return "No result";
}

void Bot::Print_probs_to_file()
    {
ofstream web_out;
string file_name = "./data/Bot_" + name +".txt";
web_out.open(file_name);

         for(auto t : Web_pob)
        {
            web_out<<t.name<<"  "<<t.prob<<"\n";
        }
 web_out.close();
    }

