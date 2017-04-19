//
//  functions.cpp
//  Lab3
//
//  Created by  Roman Usherenko on 19.04.17.
//  Copyright © 2017 Kushka Misha & Yazenok Misha. All rights reserved.
//

#include "functions.hpp"

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

//map<unsigned long, string> FillDictWithNonRepeatedLetters(dict, n)
//{
//    string line_part;
//    unsigned long curr_number = 1;
//    for (unsigned long i = 0; i < n; ++i)
//    {
//        line_part = s[i];
//        if (!findIn(dict, line_part))
//            dict[curr_number] = line_part;
//        curr_number++;
//    }
//}
