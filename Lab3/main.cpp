//
//  main.cpp
//  Lab3
//
//  Created by  Roman Usherenko on 19.04.17.
//  Copyright © 2017 Kushka Misha & Yazenok Misha. All rights reserved.
//

#include "functions.hpp"
#include "globals.hpp"
#include "additional.hpp"

int main() {
    string s;
    unsigned long n;
    Encode encoded;
    string decoded;
    map<unsigned long, string> dict;
    
    // Get text from file
    s = readFile("data/input1.txt");
    n = s.length();

    // Process
    dict = encoding(s, encoded, n); // encode
    decoded = decoding (encoded, n); // decode

    // Print data
    cout << "Dictionary:" << endl;
    showDict(dict);
    cout << "Encoded text: " << encoded.encoded_text << endl;
    cout << "Decoded text: " << decoded << endl;
    cout << "Encoded size: " << encoded.encoded_text.size() << " bits" << endl;
    cout << "Original size: " << s.size() * 8 << " bits" << endl << endl;

    // Find small text
    string looking_for = "bb";
    cout << "Is " << looking_for << " in dictionary: " << !!findIn(dict, looking_for) << endl;
    cout << "Is decoding successfully completed: " << (s == decoded) << endl << endl;
}
