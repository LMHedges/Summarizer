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
    WordFreqPair(string inputWord) {
        word = inputWord;
        count = 1;
    }
};
string text;
string wordHolder;
string wordcounter;
string spaces;
int pointer = 0;
int spaceNum;
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
                for (pointer; pointer <= i; pointer++) {
                    wordHolder = wordHolder + text[pointer];
                }
                cout << wordHolder << endl;
                pointer = i + 1;
                wordHolder.clear();
                for (auto savedWord : wordlist) {
                    if (savedWord.word == wordHolder) {
                        savedWord.count++;
                    }
                }
                
                //WordFreqPair obj(wordHolder);
                //wordlist.push_back(obj);
            }
            else if(text[i] == ' ' || text[i] == ',') {
                numberOfWords++;
                for (pointer; pointer <= i; pointer++) {
                    wordHolder = wordHolder + text[pointer];
                }
                cout << wordHolder << endl;
                pointer = i + 1;
                wordHolder.clear();
                for (auto savedWord : wordlist) {
                    if (savedWord.word == wordHolder) {
                        savedWord.count++;
                    }
                }

            }

        }
    }

    cout << "number of sentences is " << numberOfSentences << endl;
    cout << "number of words is " << numberOfWords << endl;
    for (auto savedWord : wordlist) {
        spaceNum = 8 - savedWord.word.length();
        for (int i = 0; i <= spaceNum; i++) {
            spaces = spaces + ' ';
        }
        cout << savedWord.word << spaces << savedWord.count << endl;
    }
    fileReader.close();
}