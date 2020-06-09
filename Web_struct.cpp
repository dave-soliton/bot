//
//  Web_struct.cpp
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
using namespace std;

// Makes Web hits number into a probability
void Make_web_probs(vector<Pages> &Web_list)
{
    long double Norm =0;
    //Sum hits
    for(auto t : Web_list)
    {
    Norm += t.prob;
    }
    
    for (int i=0; i < Web_list.size();++i)
    {
        Web_list[i].prob = Web_list[i].prob/Norm;
    }

}

// Subroutine to get the webpage list and relative hits.
// returns a vector of Pages (Struct defined above)
vector<Pages> Get_list()
{
    vector<Pages> Web_list;
 fstream newfile;
    newfile.open("/Users/Dave/Documents/Bots_Alive/Web_data/uk_webpages.txt",ios::in); //open a file to perform read operation using file object
//newfile.open("uk_webpages.txt",ios::in); //open a file to perform read operation using file object
    double prob;
    string name;
    if (newfile.is_open()){   //checking whether the file is open

       while(newfile >> name>> prob){ //read data from file object and put it into string.
           Web_list.push_back({name, prob});
          
       }
       newfile.close(); //close the file object.
    }
    return Web_list;
}
