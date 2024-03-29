
#include <time.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <utility>
#include <unordered_map>
using std::endl;
using std::cerr;
using std::cout;
using std::string;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::map;
using std::pair;
using std::unordered_map;
class Dictionary
{
public:
  void read(const string &filename)
  {
    ifstream ifs(filename);
    if(!ifs)
    {
      cerr<<"ifs open"<<filename<<"error"<<endl;
    return;
    }
    string line;
    while(getline(ifs,line))
    {
      istringstream iss(line);
      string word;
      while(iss>>word)
      {
        string newWord=dealWord(word);
        if(string()!=newWord)
        {
          ++_map[newWord];
        }
      }

    }

    ifs.close();
  }
void store(const string &filename){
  ofstream ofs(filename);
    if(!ofs)
    {
      cerr<<"ofs open "<<filename<<"error"<<endl;
      return;
    }
    unordered_map<string,int>::iterator it;
    for(it=_map.begin();it !=_map.end();++it){
      ofs<<it->first<<" "<<it->second<<endl; 
    }

  
    ofs.close();
}

private:
string dealWord(const string &word)
{
  for(size_t idx=0;idx !=word.size();++idx)
  {
    if(!isalpha(word[idx]))
    {
        return string();
    }

  }
      return word;
}
private:
 unordered_map<string,int>_map;


};

int main(void)
{
    cout << "before reading..." << endl;
    Dictionary dictionary;
    
    time_t beg = time(NULL);
    dictionary.read("The_Holy_Bible.txt");
    time_t end = time(NULL);
    cout << "time: " << (end - beg) << "s" << endl;
    cout << "aftre reading..." << endl;
    dictionary.store("unordered_dictMap.dat");

    return 0;
}
