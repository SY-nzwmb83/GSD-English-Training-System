#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime> 
#include <windows.h>
using namespace std;

struct Word
{
	
	string English;
	string Kind;
	string Chinese;
	
//	--Initialization string--
 
//	Word (string Eng = "", string Kin = "", string Chi = "")
//	{
//		English = Eng;
//		Kind = Kin;
//		Chinese = Chi;
//	}
	
} words[1005];

int vis[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string InputFileName = "";
	cout << "Practice Sourse: " << flush;
	cin >> InputFileName;
	
	ifstream file(InputFileName.c_str());
	
	string English = "";
	string Kind = "";
	string Chinese = "";
	int n = 0;
	file >> n;
	int cnt = n;
	for(int i = 1;i <= n;i++)
	{
		file >> words[i].English >> words[i].Kind >> words[i].Chinese;
	}
	
	file.close();
	
	cout << "Got!\n\n"  << flush;
	
	cout << "Choose Type: \n1. English \n2. Chinese \n\n" << flush;
	
	int type;
	cin >> type;
	
	if(type == 1)
	{
		srand(time(0));
		
		while(cnt)
		{
			int id = rand()%n+1;
			if(vis[id]) continue;
			vis[id] = 1;
			cnt--;
			
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
			cout << "No." << n-cnt << "\n" << flush;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
			
			cout << words[id].Kind << "\n" << words[id].Chinese << "\n\n" << flush;
			
			string ans_English;
			cin >> ans_English;
			
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			if(ans_English == words[id].English)cout << "\nRight!\n\n" << flush;
			else cout << "\nWrong!\n\n" << flush;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
			
			cout << "Answer: " << words[id].English << "\n\n" << flush;
		}
	}
	
	if(type == 2)
	{
		srand(time(0));
		
		while(cnt)
		{
			int id = rand()%n+1;
			if(vis[id]) continue;
			vis[id] = 1;
			cnt--;
			
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
			cout << "No." << n-cnt << "\n" << flush;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
			
			cout << words[id].Kind << "\n" << words[id].English << "\n\n" << flush;
			
			string ans_Chinese;
			cin >> ans_Chinese;
			
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			if(ans_Chinese == words[id].Chinese)cout << "\nRight!\n\n" << flush;
			else cout << "\nWrong!\n\n" << flush;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
			
			cout << "Answer: " << words[id].Chinese << "\n\n" << flush;
		}
	}
	
	cout << "Thanks!" << flush;
	
	return 0;
}
