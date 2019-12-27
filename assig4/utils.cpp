#include "utils.h"

int binaryToDecimal (string binary)
{

    int power_2 = 1;
    int decimal = 0;

    for (int j =7; j >= 0; j--)
    {
        decimal += (binary[j]-'0') * power_2;
        power_2 = power_2 * 2;
    }

    return decimal;
}

string decimalToBinary(int n)  
{  
    string code = "";
    while(n != 0) 
    {
        code = (n%2 == 0 ? "0" : "1") + code;
        n /= 2;
    }
    
    //add bit of fill in beginning
    int count = code.size();
    while(count<8)
    {
        code = "0" + code;
        count ++;
    }

    return code;
}  

int cutoff = 0;

Utils::Utils()  {}

Utils::~Utils()
{
    tree.release();
}

bool Utils::loadDictionary(const string& text_dic)
{
    // load the file with name text_dic, and save all characters in this->content
    ifstream load_file(text_dic);
    if (!load_file.is_open()) {
        cout << "Failed to load the article. Exit." << endl;
        return false;
    }

    ostringstream buf;
    char ch;
    while (buf && load_file.get(ch))
        buf.put(ch);
    this->content = buf.str();
    // move out the end useless '\r' of a file
    this->content.pop_back();

    load_file.close();

    // cout << "content is " << content <<endl;

    // content = "beep boop beer!";
    // scan the string this->content, calculate the frequency table
    // insert your code here ...
    for (int i =0; i<content.size(); i++)
    {
        frequency_table[content[i]] += 1;
    }

    // for(map<char, int>::const_iterator it = frequency_table.begin(); it != frequency_table.end(); ++it)
    //     cout << "<" << it->first << "," << it->second << ">" << endl;



    return true;
}

void Utils::buildTree()
{
    tree.loadMap(frequency_table);
}

void Utils::setEncodedTable()
{
    tree.encode(encoded_table);
}

void Utils::saveBinDictionary(const string& bin_file)
{
    //////////////////////
    // ofstream f("code.bin", ios::binary);
    // unsigned char test = 24;
    // f << test;
    // f.close();

    // load key file
    ifstream ifile("xor_key.bin", ios::binary);
    if (!ifile.is_open()) {
        cout << "cannot load key file, exit." << endl;
        return;
    }

    ofstream ofile(bin_file, ios::binary);

    // assuming that the length of bin_code is multiple of 8
    // so just for every 8 continuous {0,1} characters, intepret it as a binary byte number
    // for last byte you write, its valid length may be less than 8, fill the invalid bits with 0
    // eg., last byte contains only 3 valid bits, 110. You should fill it as 1100 0000, and then
    // you need to write integer 3 (bin form: 0000 0011) as one byte at the beginning of your binary file.
    // after saving data into .bin file, you should print out its hex form in command line
    // insert your code here ...

    // concat huffman code of cha
    string code;
    for(int i =0; i < content.size(); i++)
    {
        code += encoded_table[content[i]];
    }
    // cout << "content "<< content <<endl;
    // cout << " code before " << code.length() << endl<<code <<endl;

    // if not multiple of 8, append 0 at the end and convert fill into binary code and append in front
    if (code.size()%8 != 0) 
    {
        cutoff = code.size()%8;
        // cout << "cutoff size " << cutoff<<endl;
        for (int i=0; i<8-cutoff; i++)
        {
            code += "0";
        }
        code = decimalToBinary(cutoff) + code;

    }

    // cout << " code after" << code.length() << endl<<code <<endl;

    // read the key into string
    ostringstream buf;
    char ch;
    string key = "";

    while (buf && ifile.get(ch))
        buf.put(ch);
    key = buf.str();
    ifile.close();

    // cout << "key " << endl << key <<endl;

    // change huffman code into byte  
    string byte = "";
    for (int i = 0; i <= code.size()-8; i+=8)
    {  
        // cout << "code segment " << code.substr(i,8)<<endl;
        // cout << "decimal code segment " << binaryToDecimal(code.substr(i,8))<<endl;
        byte += binaryToDecimal(code.substr(i,8));
    }

    // XOR
    string result = "";
    // if(byte.size()==key.size())
    // {
    for (int i = 0 ; i < byte.size(); i++)
    {
        // cout << "key " << decimalToBinary((unsigned int)(unsigned char)key[i]) << endl;
        // cout << "byte " << decimalToBinary((unsigned int)(unsigned char)byte[i]) << endl;
        // cout << "result " << decimalToBinary((unsigned int)(unsigned char)(key[i] ^ byte[i])) <<endl;
        result += key[i] ^ byte[i]; 
        // if (i == 2) break;
    }
    // }
 
    // write file    
    for(int i = 0; i < result.size(); i++)
    {
        cout << hex << (unsigned int)(unsigned char)result[i];  // convert binary to decimal and print encoded in hexadecimal form        
    }
    cout << endl;
    ofile << result;
    ofile.close();

   


}

void Utils::decode(const string& bin_file)
{
    ifstream ifile(bin_file, ios::binary);
    if (!ifile.is_open()) {
        cout << "cannot open .bin file, stop decoding." << endl;
        return;
    }

    ifstream key_file("xor_key.bin", ios::binary);
    if (!key_file.is_open()) {
        cout << "cannot load key file, exit." << endl;
        return;
    }
    
    // the string used to search on huffman tree to decode as plaintext
    string bit_str = "";

    // bin_file: stores a binary huffman code with possible extra bits at the end
    // key_file: decryption XOR key
    // search in the encoded table
    // insert your code here ...

    // read both files
    ostringstream buf1;
    ostringstream buf2;
    char ch;
    string key = "";
    string hfcode = "";

    while (buf1 && key_file.get(ch))
        buf1.put((unsigned char) ch);
    key = buf1.str();

    while (buf2 && ifile.get(ch))
        buf2.put((unsigned char)ch);
    hfcode = buf2.str();

    // cout<< "key " <<endl<<key<<endl;
    // cout<< "hfcode " <<endl<<hfcode<<endl;

    // XOR
    // string result = "";
    // if(key.size()==hfcode.size())
    // {
    for (int i =0; i < hfcode.size(); i++)
    {
        // cout << "key " << decimalToBinary((unsigned int)(unsigned char)key[i]) << endl;
        // cout << "byte " << decimalToBinary((unsigned int)(unsigned char)hfcode[i]) << endl;
        // cout << "result " << decimalToBinary((unsigned int)(unsigned char)(key[i] ^ hfcode[i])) <<endl;
        bit_str += decimalToBinary((unsigned int)(unsigned char)(hfcode[i] ^ key[i])); 
        // if (i == 2) break;
    }
    // }

    // get first byte binary code into integer as fill
    int cutoff_d = 0;
    if (cutoff != 0)
    {
        cutoff_d = binaryToDecimal(bit_str.substr(0,8));    
        bit_str = bit_str.substr(8,bit_str.size()-8-(8-cutoff_d));    
    }


    ifile.close();
    key_file.close();
    

    // // using huffman tree you've built before to decode the bit string
    string plaintext = tree.decode(bit_str);
    cout << plaintext << endl << endl;

    // cout << "code size " << hfcode.size()<<endl;
}


