//
//  additional.cpp
//  Lab3
//
//  Created by Kushka Misha on 12/17/18.
//  Copyright © 2018 Kushka Misha & Yazenok Misha. All rights reserved.
//

#include "additional.hpp"

string readFile(string filename) {
    ifstream f(filename);
    string line = "";
    string result = "";
    
    if (f.is_open()) {
        while(getline(f, line)) {
            result += line + " ";
        }
        f.close();
    }
    else return "";
    
    return result;
}
