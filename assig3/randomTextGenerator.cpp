// SUBMIT THIS FILE

#include "randomTextGenerator.h"
#include <fstream>
using namespace std;

    //read the file content from the file specified by the fileName, and save it to the data member original
    //for Eclipse, the file should be put in the same location as the source files
    //for other IDEs, you need to look it up yourself
    //for simplicity, as the original text shouldn't contain any newline character,
    //just read the first line in the file 
    //(i.e. read until the first newline character or EOF, but don't include those characters in the original)
    void RandomTextGenerator::readOriginalFromFile(const char fileName[])
    {
    	ifstream fin(fileName);
    	string s;
    	while(getline(fin,s))
    		original += s;
        fin.close( ); 
    }

    //verify the original content text
    //A valid text is defined as a text that consists of only valid characters 
    //return the null character '\0' if no invalid character is found
    //otherwise, return the first invalid character found
    //valid characters are
    //- alphabets, lower case or upper case
    //- digits (i.e., '0' - '9')
    //- space ' ' 
    //- comma ','
    //- the following 8 symbols '.', ';', ':', '\'', '\"', '-', '!', '?'
    //note that there should be no newline character ('\n') or other special characters (such as '\t' or '\r' or some chinese full-width character, etc.)
    char RandomTextGenerator::verifyOriginal()
    {
    	char symbol[] = {' ',',','.', ';', ':', '\'', '\"', '-', '!', '?'};
    	bool invalid = false;

    	for(int i =0; i < original.length(); i++)
    	{
    		char ch = original[i];
    		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) continue;
    		else if (ch >= '0' && ch <= '9') continue;
    			
    		// if the ch do not belong to the symbol, invalid
    		invalid = true;
			for (int j = 0; j < 10; j++)
			{
				if (ch == symbol[j])
				{
					invalid = false;
					break;
				}
			}

            if (invalid == true) return original[i];
    		
    	}
    	return '\0';
    }

    //prepare the WFM
    //check the webpage for explanation and examples
    void RandomTextGenerator::prepareWFM()
    {
    	
        string *KeyList = wfm.getKeyList();
        for(int i =0; i<wfm.getSize(); i++)
        {
            wfm[KeyList[i]].clean();
        }
        delete [] KeyList;
        wfm.clean();

        if(verifyOriginal()=='\0')
        {
            // define a array to store each word
            string *arr = new string [original.size()];
            int j = 0; // count size of arr
            string word = "";
            for(int i=0; i<original.size(); ++i)
            {
                if (original[i] != ' ' )
                {
                    word += original[i];
                    if (i == original.size()-1)  // the last word that is not space
                    {
                        arr[j] = word;
                        j++;
                    }
                }
                else   // when has space, store the previous word
                {
                    if (word != "" && word != " ")
                    {
                        arr[j] = word;
                        j++;
                    }
                    word = "";                  
                }                
            }

            // iterate array to store in dict  
             for (int i =0; i<j; i++)
             {
                if (i == 0)
                {
                    wfm[""][arr[i]] = 1;
                }   
                if (i+1 == j) break;

                wfm[arr[i]][arr[i+1]] += 1;
             } 
             delete [] arr;               
        }
    }

    //generate a random text of the given length
    //rng is used as the random number generator
    //check the webpage for explanation and examples
	string RandomTextGenerator::generate(RNG* rng, int length)
	{
		WeightedRandomItemPicker<string> picker;
        string result = "";
        string prevWord = "";
   
        string *SumKey = wfm.getKeyList();
        int *ValueList = NULL;
        string *KeyList  = NULL;
        int s = 0;

        if (wfm.getSize() > 0){
            for (int i =0; i < length; i++)
            {
                bool exist = false;
                // avoid prevWord don't appear in dict           
                for (int i =0; i<wfm.getSize(); i++)
                {
                    if (SumKey[i] == prevWord) 
                    {
                        exist = true;
                        break;
                    }
                }
                
                if (exist)
                {   
                    ValueList = wfm[prevWord].getValueList();
                    KeyList = wfm[prevWord].getKeyList();
                    s = wfm[prevWord].getSize();
                }
                else  // if the last word doesn't appear in the dict before 
                {
                    ValueList = wfm[""].getValueList();
                    KeyList = wfm[""].getKeyList();
                    s = wfm[""].getSize();
                    prevWord = "";
                }
                cout<<"Previous word is \""<<prevWord<<"\"."<<endl;
                string pickValue = picker.pick(ValueList, KeyList, s, rng);
                prevWord = pickValue;
                
                    
                result = result + pickValue + ' ';

                delete [] ValueList;
                delete [] KeyList;

            }
        }
        delete [] SumKey;
		return result;
	}
