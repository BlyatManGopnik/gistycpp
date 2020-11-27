#include <iostream>
#include <algorithm>
#include "headless.hpp"
using std::cout, std::cin, std::endl, std::string;
int main() {
    cout << "gistycpp v0.0.1" << endl;
    const char clientid[] = "e60ca2f3b68366243edd";
    string devicecode = headless::getdevicecode(clientid);
    //cout << "The device code is " + devicecode << endl;
    string authtoken = headless::getauthtoken(devicecode, clientid);
    //cout << "We got the access token: " + authtoken << endl;
    string sentence;
    cout << "Type a sentence here!: ";
    std::getline(std::cin, sentence);
    sentence.erase(std::remove(sentence.begin(), sentence.end(), '\n'), sentence.end());
    cout << "Posting to GitHub" << endl;
    string url = post::post(authtoken, sentence);
    cout << "We got the URL!: " + url << endl;
}
