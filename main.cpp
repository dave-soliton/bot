//
//  main.cpp
//  Bots_Alive
//
//  Created by David Foster on 27/05/2020.

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <random>
#include "Bott.hpp"
#include "Web_struct.hpp"
using namespace std;


// Prob mixer
vector<Pages> Prob_mixer(vector<Pages> Good, vector<Pages> Bad, double mix)
{
for (int i=0; i < Good.size();++i)
        {
    Good[i].prob = mix*Good[i].prob + (1.0-mix)*Bad[i].prob;
        }
return Good;
}



// Main code
int main(int argc, const char * argv[]) {
    
    vector<Pages> Web_list;
    // Grab webpage list
    Web_list =Get_list();

    // Make the web hits into a normal probablity of visiting that page.
    Make_web_probs(Web_list);

    /*
    for (int i=0; i < sizeof(Web_list);++i)
       {
           cout <<"Web2: "<<Web_list[i].prob<<"\n";
       }
    */

    // Define an instnce of a Bot
    Bot Bott1("1", Web_list, 0.7, 0.2);
  
    // Define an instnce of a second Bot
    Bot Bott2("Bad", Web_list, 0.1, 0.8);
    //vector<Pages> Web_list2;
    
    // 'GoodChat' is a page for the bots to chat on
    Bott1.Add_chat("www.GoodChat.co.uk", 0.1);
    Bott2.Add_chat("www.GoodChat.co.uk", 0.1);
    //Insert a certain probality to visit 'BadChat'
    Bott1.Add_chat("www.BadChat.co.uk", 0.0);
    Bott2.Add_chat("www.BadChat.co.uk", 0.1);
    // Print probability distribution for Bott2
    Bott1.Print_Prob();
    cout <<"hi \n";
    string page1, page2;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1);//uniform distribution between 0 and 1
    // Loop over occurances
    double s = 0;
    // Loop over bot chat generations
    for(int i=0; i < 100000; ++i)
    {
        page1 = Bott1.What_page_on(dis(gen));
        page2 = Bott2.What_page_on(dis(gen));
        // If the bots are both on 'GoodChat' lets make them interact
        // the most infulential bot passes some internet trends to the
        // least infulential bot. The passing P_n = sP_I + (1-s)P_old where
        // s is the influensibility of the easily influenced bot.
        if(page1 == "www.GoodChat.co.uk" && page2 == "www.GoodChat.co.uk"){
        cout<< "Yes: "<<page1 <<"\n";
            cout <<"Suseptibility: "<<Bott1.Suseptability_no(10.0*dis(gen)) <<"\n";
            s = Bott1.Suseptability_no(10.0*dis(gen));//Needs to be better
     //       Need to write a subroutine to add the two probablities together, with the susceptability
     //       constants s. And then update the most susecptible bot.
        Bott1.get_new_probs(Prob_mixer(Bott1.get_probs(), Bott2.get_probs(), s));
//Bott1.get_probs();
        }
    }
Bott1.Print_probs_to_file();

    // This returns a random number
    /*
    for (int n = 0; n < 10; ++n) {
        cout << dis(gen) << ' ';
    }
    */
    // Interact the botts
    
    

    return 0;
}

