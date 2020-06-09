//
//  Web_struct.hpp
//  Bots_Alive
//
//  Created by David Foster on 02/06/2020.
//  Copyright © 2020 David Foster. All rights reserved.
//

#ifndef Web_struct_hpp
#define Web_struct_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <random>

using namespace std;
// Struct of pages and probablity to visit
struct Pages {
  string name;
  double prob;
};

void Make_web_probs(vector<Pages> &Web_list);

// Subroutine to get the webpage list and relative hits.
// returns a vector of Pages (Struct defined above)
vector<Pages> Get_list();

#endif /* Web_struct_hpp */
