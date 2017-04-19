//
//  main.cpp
//  Lab3
//
//  Created by  Roman Usherenko on 19.04.17.
//  Copyright © 2017 Kushka Misha & Yazenok Misha. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;

unsigned long findIn (map<unsigned long, string>, string); // check is value in map
void showDict (map<unsigned long, string>); // show map on the screen

int main() {
    map<unsigned long, string> dictionary;
    string s = "wabbawabba";
    string p = "", c = "", p_plus_c = "";
    unsigned long n = s.length(),
                  curr_number = 1;
    string line_part, encode = "";
    
    // fill the dictionary by non-repeated letters in s
    for (unsigned long i = 0; i < n; ++i)
    {
        line_part = s[i];
        if (!findIn(dictionary, line_part))
            dictionary[curr_number] = line_part;
        curr_number++;
    }
    showDict(dictionary);
    
    // encode algorithm
    unsigned long last_index = dictionary.size() + 1;
    for (unsigned long i = 0; i < n; ++i)
    {
        c = s[i];
        p_plus_c = p + c;
        if (findIn(dictionary, p_plus_c))
            p = p_plus_c;
        else
        {
            dictionary[last_index] = p_plus_c;
            last_index++;
            encode += to_string(findIn(dictionary, p));
            p = c;
        }
        if (i == n - 1)
            encode += to_string(findIn(dictionary, p));
    }
    showDict(dictionary);
    cout << encode << endl;
}

unsigned long findIn (map<unsigned long, string> dict, string value)
{
    for (int i = 0; i < dict.size(); ++i)
        if (dict[i] == value)
            return i;
    return NULL;
}

void showDict (map<unsigned long, string> dict)
{
    for (int i = 0; i < dict.size(); ++i)
        cout << "dict[" << i + 1 << "] = " << dict[i + 1] << endl;
}
