//
//  Bott.hpp
//  Bots_Alive
//
//  Created by David Foster on 02/06/2020.
//  Copyright © 2020 David Foster. All rights reserved.
//

#ifndef Bott_hpp
#define Bott_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <random>
#include "Web_struct.hpp"
using namespace std;


class Bot {
    string name;
    vector<Pages> Web_pob;
    double susceptibility;
    double influencer;
    
public:
    Bot(string name, vector<Pages> Webs, double suspect, double inf)
    {
       this->name = name;
       Web_pob = Webs;
       susceptibility = suspect;
       influencer = inf;
    }

    vector<Pages> get_probs()
    {
        return Web_pob;
    }
    
    void get_new_probs(vector<Pages> New_Web_pob)
    {
        Web_pob = New_Web_pob;
    }

   void get_probs(vector<Pages> &New_Web_pob)
    {
        Web_pob = New_Web_pob;
    }
    
    void Print_Prob();
    
    // Returns a gaussian which is normalised at the origine
    double Gaussian_type(double x, double s);

    //Alters the previouse probabilites so the sum is one including the new probablity.
    void Add_chat(string web, double val);
    
    // step through cumulative distribution untill find window containing random number
    string What_page_on(double rand);
    
    
    double Suseptability_no(double rand)
    {
        return Gaussian_type(rand, susceptibility);
    }

    void Print_probs_to_file();


};


#endif /* Bott_hpp */
