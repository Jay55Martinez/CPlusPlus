// Jay Martinez -- Assignment2 Phish Scanning -- 5/22/23
// Create a list of posible phising word and give them a value and then
// have the user enter an email and return a point value based on how likely
// it is to be phishing email.
#include <iostream>
using namespace std;

int main() {
    // list of words and values
    string phishing_words[] = {"account", "alert", "bank", "credit card", "confidential", "confirm",
                               "restore", "deactivate", "details", "fraud", "important",
                               "information needed", "login", "password", "personal", "protect",
                               "security", "suspicious", "verify", "update", "urgent",
                               "accounting", "notification", "prince", "hack", "phishing",
                               "reset", "breach", "money needed", "help"};
    int words_value[] = {1, 2, 2, 0, 1, 3, -1, -1, 1, 2, 2, 2, 1, 2, 3, 0, 0, 0, 2, 1, 3, 0, 0, 3,
                         2, -1, 3, 0, 2, 3};
    int value = 0;

    // Takes in the email from the command line
    string email;
    cout<<"Please enter your phishing email: "<<endl;
    getline(cin, email);

    // get the phishing value for the email
    for(int i=0; i<30; i++) {
        string::size_type pos = email.find(phishing_words[i]);
        while (pos <= email.length()) {
            value += words_value[i];
            pos = email.find(phishing_words[i], pos+phishing_words[i].length());  // Move past the current occurrence
        }
    }
    cout<<"The phishing value of the email is: "<<value<<endl;
}