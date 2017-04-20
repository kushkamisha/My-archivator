//
//  functions.hpp
//  Lab3
//
//  Created by  Roman Usherenko on 19.04.17.
//  Copyright © 2017 Kushka Misha & Yazenok Misha. All rights reserved.
//

#ifndef functions_hpp
#define functions_hpp

#include "stdafx.hpp"
#include "globals.hpp"

unsigned long findIn (map<unsigned long, string>, string); // check is value in map
void showDict (map<unsigned long, string>); // show map on the screen
string toBinary (unsigned long, int);
unsigned long toDecimal (unsigned long);
void encoding (string, Encode&, unsigned long);
string decoding (Encode, unsigned long);

#endif /* functions_hpp */
