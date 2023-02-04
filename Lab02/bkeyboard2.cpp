#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <list>
using namespace std;
int main() {
    string input;
    stringstream ss(input);  // Create a stringstream from the input string
    string line;
    vector<string> sentense;
    while (getline(cin, line)) {  // Read lines delimited by '\n'
       sentense.push_back(line);
    }
    vector<string>::iterator it;
    for(it = sentense.begin();it != sentense.end();it++)
    {
        vector<char> all_sen;
        string word = *it;
        int back=1,k=0;
        for(int i=0;i<word.size();i++){
            if(word[i]=='[') 
            {
                back=0; continue;
            }
            else if(word[i]==']') {
                back=1; continue;
            }
            if(back) all_sen.push_back(word[i]);
            else {
                all_sen.insert(all_sen.begin()+k,word[i]);
                k++;
            }
        }
        for(int i=0;i<all_sen.size();i++){
            cout<<all_sen[i];
        }
        cout<<"\n";
    }
    
}