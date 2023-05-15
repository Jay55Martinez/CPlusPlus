// Jay Martinez - Assignment1 q4 - 5/15/23
// program takes in a paragraph and a sperate sentance. Prints the number of times that sentence
// is in the paragraph and the index and then replaces it with a different sentence.
#include <iostream>
using namespace std;

int main(void) {
    int count = 0;
    string paragraph, phrase1, phrase2;

    // input paragraph
    cout<<"please enter your paragraph."<<endl;
    getline(cin, paragraph);

    // input phrase that will be found
    cout<<"please enter the phrase that you would like to find."<<endl;
    getline(cin, phrase1);

    // input phrase that will replace the found phrase
    cout<<"please enter the phrase that you would like to insert for the found one."<<endl;
    getline(cin, phrase2);

    // finding all the instances of the phrase in the paragraph
    std::string::size_type found = paragraph.find(phrase1);
    while(found <= paragraph.length()) {
        // replaces the found phrase with the new one
        paragraph.replace(found, phrase1.length(), phrase2);
        // prints index of the phrase
        cout<<"The phrase was found at index: "<<found<<endl;
        found = paragraph.find(phrase1, found+1);
        count++;
    }
    cout<<"the phrase was found "<<count<<" times"<<endl;
    cout<<paragraph<<endl;
}