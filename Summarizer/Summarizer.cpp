#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class WordFreqPair {
public:
    string word;
    int count;
};
string text;
int numberOfWords = 0;
int numberOfSentences = 0;
string filename = "input.txt";
vector<WordFreqPair> wordlist;

int main()
{
    ifstream fileReader(filename);
    while (getline (fileReader, text)) {
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
                numberOfSentences++;
                numberOfWords++;
            }
            else if(text[i] == ' ' || text[i] == ',') {
                numberOfWords++;
            }
        }
    }

    cout << "number of sentences is " << numberOfSentences << endl;
    cout << "number of words is " << numberOfWords << endl;
    fileReader.close();
}