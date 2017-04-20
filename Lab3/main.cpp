//
//  main.cpp
//  Lab3
//
//  Created by  Roman Usherenko on 19.04.17.
//  Copyright © 2017 Kushka Misha & Yazenok Misha. All rights reserved.
//

#include "functions.hpp"
#include "globals.hpp"

int main() {
    string s = "wabbawabba";
    unsigned long n = s.length();
    Encode encoded;
    
    // encode algorithm
    encoding(s, encoded);
    cout << "Encoded.encoded_text: " << encoded.encoded_text << endl;
    cout << "Encoded dict:" << endl;
    showDict(encoded.dict);
    
    // decode algorithm
    string decode = decoding (encoded, n);
    cout << "Decoded text:" << endl;
    cout << decode << endl;
}
