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
//    string s = "wabbawabba";
//    string s = "mishamashapasha";
//    string s = "111111111101100011111111111000000000000000010000010010100100011001001001010001100000000000000001000000010000000000000000010010000000000001001000000000000000000011111111111000010000000100110100010001010111100001101001011001100000000000000000010011010100110100000000001010100000000000000000000000000000100000000000000001110000000100010010000000000000001100000000000000000000000000000001000000000000000100000000000000000000000100011010000000000000010100000000000000000000000000000001000000000000000000000000011000100000000100011011000000000000010100000000000000000000000000000001000000000000000000000000011010100000000100101000000000000000001100000000000000000000000000000001000000000000001000000000000000000000000100110001000000000000001000000000000000000000000000001011000000000000000000000000011100100000000100110010000000000000001000000000000000000000000000010100000000000000000000000000011111101000011101101001000000000000010000000000000000000000000000000001000000000000000000000000100100100000000000000000000000000000000000000000000000000000000001001000000000000000000000000000000000010000000000000000000000000100100000000000000000000000000000000001010100000110100001101111011101000110111101110011001000000011000100101110001101010000000000000000001100100011000000110001001101110011101000110000001100100011101000110010001100100010000000110001001101110011101000110101001101100011101000110010001101000000000000000000000010011001000000000000000000000000011100000000000000000000000000000100001100000011001000110010001100011001000000000011000000000000001000000000000000000000000000010100000000000000000000000001000001001001000000000100000000000000001000000000000000000000000000010";
//    string s = "The main unifying theme is the idea of an intelligent agent. We define AI as the study of agents that receive percepts from the environment and perform actions. Each such agent im- plements a function that maps percept sequences to actions, and we cover different ways to represent these functions, such as reactive agents, real-time planners, and decision-theoretic systems. We explain the role of learning as extending the reach of the designer into unknown environments, and we show how that role constrains agent design, favoring explicit knowl- edge representation and reasoning. We treat robotics and vision not as independently defined problems, but as occurring in the service of achieving goals. We stress the importance of the task environment in determining the appropriate agent design.Our primary aim is to convey the ideas that have emerged over the past fifty years of AI research and the past two millennia of related work. We have tried to avoid excessive formal- ity in the presentation of these ideas while retaining precision. We have included pseudocode algorithms to make the key ideas concrete; our pseudocode is described in Appendix B.This book is primarily intended for use in an undergraduate course or course sequence. The book has 27 chapters, each requiring about a week’s worth of lectures, so working through the whole book requires a two-semester sequence. A one-semester course can use selected chapters to suit the interests of the instructor and students. The book can also be used in a graduate-level course (perhaps with the addition of some of the primary sources suggested in the bibliographical notes). Sample syllabi are available at the book’s Web site, aima.cs.berkeley.edu. The only prerequisite is familiarity with basic concepts of computer science (algorithms, data structures, complexity) at a sophomore level. Freshman calculus and linear algebra are useful for some of the topics; the required mathematical back- ground is supplied in Appendix A.Exercises are given at the end of each chapter. Exercises requiring significant pro- gramming are marked with a keyboard icon. These exercises can best be solved by taking advantage of the code repository at aima.cs.berkeley.edu. Some of them are large enough to be considered term projects. A number of exercises require some investigation of the literature; these are marked with a book icon.Throughout the book, important points are marked with a pointing icon. We have in- cluded an extensive index of around jjjjj items to make it easy to find things in the book. Wherever a new term is first defined, it is also marked in the margin.";
    string s = "jjjj";
//    string s = "abba";
    unsigned long n = s.length();
    Encode encoded;
    
    // encode algorithm
    encoding(s, encoded, n);
    cout << "Encoded text: " << encoded.encoded_text << endl;
    
    // decode algorithm
    string decode = decoding (encoded, n);
    cout << "Decoded text: " << decode << endl;
    
    if (s == decode)
        cout << "True" << endl;
}
