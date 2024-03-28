#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::sort;

struct Record
{
  Record(const string &word,int frequency)
  :_word(word)//初始化成员变量_word,传入构造函数的word参数
  ,_frequency(frequency)
  {}
  string _word;
  int _frequency;
};
//排序?
bool operator<(const Record &lhs,const Record &rhs)
{
  return lhs._word<rhs._word;
}

class Dictionary


{
  public:
 //读文件,结果存放在vector
 void read(const std::string &filename)
 {
  ifstream ifs(filename);
  if(!ifs){
    cerr<<"ifs fail"<<endl;
    return;
  }
  string line;
  while(getline(ifs,line))
  {
    string word;
    istringstream iss(line);
    while(iss>>word){
      string newWord=dealWord(word);
      insert(newWord);
    }

  }
  //排序
  sort (_dict.begin(),_dict.end());
  ifs.close();

 }
 void store(const std::string &filename)
 {
    ofstream ofs(filename);
    if(!ofs)
    {
      cerr<<"ofs fail"<<endl;
      return;
    }
    //遍历,
    for(size_t idx=0;idx!=_dict.size();++idx)
      {
        ofs<<_dict[idx]._word<<"  "
        <<_dict[idx]._frequency<<endl;
      }
  ofs.close();


 }
 
string dealWord(const std::string &word){
  for(size_t idx=0;idx!=word.size();++idx)
  {
    if(!isalpha(word[idx]))
    {
      return string();
    }
  }
  return word;
}

void insert(const std::string &word)
{
  if (word==string()){
    return ;
}
  size_t idx=0;
  for(idx=0;idx!=_dict.size();++idx)
  {
    if(word==_dict[idx]._word){
      ++_dict[idx]._frequency;
      break;
    }
  }
  if(idx==_dict.size())
  {
    _dict.push_back(Record(word,1));
  }


}
  private:
  vector<Record>_dict;
};
int main(int argc, char *argv[])
{
    Dictionary dictionary;

    cout << "before reading..." << endl;
    time_t beg = time(NULL);
    dictionary.read("The_Holy_Bible.txt");
    time_t end = time(NULL);
    cout << "time: " << (end - beg) << "s" << endl;
    cout << "aftre reading..." << endl;

    dictionary.store("dictVec.dat");
    return 0;
}
