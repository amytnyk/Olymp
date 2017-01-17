// Virus2016.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

vector<vector<int>> GetViruses(vector<vector<int>> map_viruses)
{
  vector<vector<int>> viruses;
  int size = map_viruses.size();
  viruses.resize(size + 2);
  for (size_t i = 0; i < size + 2; i++)
  {
    viruses[i].resize(size + 2);
    for (size_t j = 0; j < size + 2; j++)
    {
      viruses[i][j] = 0;
    }
  }
  for (size_t i = 0; i < map_viruses.size(); i++)
  {
    for (size_t j = 0; j < map_viruses[i].size(); j++)
    {
      if (map_viruses[i][j] == 1)
      {
        viruses[i][j + 1]++;//Up
        viruses[i + 2][j + 1]++;//Down
        viruses[i + 1][j]++;//Left
        viruses[i + 1][j + 2]++;//Right
      }
    }
  }
  for (size_t i = 0; i < viruses.size(); i++)
  {
    for (size_t j = 0; j < viruses[i].size(); j++)
    {
      if (viruses[i][j] > 1)
      {
        viruses[i][j] = 0;
      }
    }
  }
  return viruses;
}

int main()
{
  int n;
  cout << "Enter 200" << endl;
  cin >> n;
  cout << "Wait 30 sec plz" << endl;
  vector<vector<int>> viruses;
  viruses.resize(1);
  viruses[0].resize(1);
  viruses[0][0] = 1;
  vector<int> j;
  for (size_t i = 0; i < n; i++)
  {
    viruses = GetViruses(viruses);
    j.push_back(0);
    for (size_t k = 0; k < viruses.size(); k++)
    {
      for (size_t l = 0; l < viruses[k].size(); l++)
      {
        if (viruses[k][l])
        {
          j[i]++;
        }
      }
    }
  }
  for (size_t i = 0; i < n; i++)
  {
    cout << i << "         ---------         "<< j[i] << endl;
  }
  cin >> n;
  return 0;
}

