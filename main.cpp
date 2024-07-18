/*
 * @author : Anthony Carrillo
 * @version : 0.0.1
 */
#include <iostream>
#include <vector>
using namespace std;

int toInt(char n){
  return (int)(n - '0');
}

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
      int n = 1;
      char digit;

      if(args == 3){
        digit = *argv[2];

        if(!isdigit(digit) || args > 3){      
          throw "Parameter invalid";
        }
        n = toInt(digit);        
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