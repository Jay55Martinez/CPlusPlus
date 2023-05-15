// Jay Martinez - Assignment1 q3 - 5/15/23
// enter a paragrah the program with return the number of words, vowels and consonants, number
// of punctuation makrs, and works that use more htna one vowel.
#include <iostream>
using namespace std;

int main(void) {
    string paragraph;
    bool prev_char = false;
    int words = 0, vowels = 0, punctuations = 0, multi_vowels = 0, contained_vowels = 0;

    // input for the paragraph
    cout<< "please enter your paragraph: \n";
    getline(cin, paragraph);
    
    // loop to gather info on the paragraph
    for(auto one_char : paragraph) {
        if (one_char == 32 && prev_char) {
            // checks if the word contained more than two vowels
            if(contained_vowels >= 2) {
                multi_vowels++;
            }
            words++; // increase words

            //reset 
            prev_char = false;
            contained_vowels = 0;
        }   
        // checks for any punctuations      
        else if(one_char == 33 || one_char == 46 ||
                one_char == 63 || one_char == 44 ||
                one_char == 39 || one_char == 58 ||
                one_char == 59 || one_char == 34 ||
                one_char == 36) {
            punctuations++; // increase punctuation count
        }
        // checks for vowels
        else if(one_char == 65 || one_char == 97 ||
                one_char == 69 || one_char == 101 ||
                one_char == 73 || one_char == 105 ||
                one_char == 79 || one_char == 111 ||
                one_char == 85 || one_char == 117 ||
                one_char == 89 || one_char == 121) {
                    vowels++; // increases vowel counter
                    prev_char = true;
                    contained_vowels++; // increases vowels in word counter
                }
        else {
            prev_char = true;
        }
    }

    // increments for the final word
    if(prev_char) {
        words++;
        if(contained_vowels >= 2) {
            multi_vowels++;
        }
    }
    // prints the stats
    cout<<"The number of words are : "<< words
        <<"\nThe number of punctuations are : "<< punctuations
        <<"\nThe number of vowels are : "<< vowels
        <<"\nThe number of words with more than one vowel is: "<< multi_vowels<<endl;

    return 0;
}