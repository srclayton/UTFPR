// lendo um texto de um arquivo
  #include <iostream>
  #include <fstream>
  #include <string>
  using namespace std;

  int main () {
  string line;
  ifstream myfile ("NomeRG1K.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}