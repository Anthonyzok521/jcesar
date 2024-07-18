/*
 * @author : Anthony Carrillo
 * @version : 0.1.0
 */
#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

vector<int> abcAscii() // Function to get all the ascii values
{
  vector<int> abc;

  for (int i = 65; i <= 122; i++)
  {
    if (i > 90 && i < 97) // Exclude special characters
    {
      continue;
    }
    else
    {
      abc.push_back(i);
    }
  }

  return abc;
}

string jcesar(string word, int n) // Encryption function | n = move letter
{

  vector<int> abc = abcAscii();
  for (int i = 0; i < word.length(); i++)
  {
    // debug
    /* cout<<"Iteration: "<<i<<endl; */
    for (auto _ : abc)
    {
      /* cout<<"ASCII: "<<_<<endl; */
      if (word[i] == _)
      {        
        //Limit
        if((int)word[i] + n > 90 && (int)word[i] + n < 97 || (int)word[i] + n > 122){
          if(islower(word[i])){
            int l = ((int)word[i] + n) - 123;
            word[i] = (char)97 + l;    
          }else{
            int u = ((int)word[i] + n) - 91;
            word[i] = (char)65 + u;    
          }
          break;
        }
        /* cout<<"Letter: "<<(int)word[i]<<" "<<word[i]<<" "; */
        word[i] = (char)(int)word[i] + n;
        /* cout<<"To: "<<(int)word[i]<<" "<<word[i]<<" "<<endl; */
        break;
      }
    }
  }

  return word;
}

int main(int args, char **argv)
{
  try
  {
    if (args != 0)
    {
      string digit;
      int n = 1;
      
      if(args == 3){
        digit = argv[2];

        if(!isdigit(*digit.c_str()) || args > 3){      
          throw "Parameter invalid";
        }

        if(atoi(digit.c_str()) > 26){
          throw "Out range - limit is 26";
        }

        n = atoi(digit.c_str());
      }      
      
      cout << jcesar(argv[1], n) << endl;

      return 0;
    }
    throw "Insert a text";
  }
  catch (char const* e)
  {
    cout << e << endl;
  }
  catch (exception e)
  {
    cout << e.what() << endl;
  }
  return 0;
}