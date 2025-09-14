/*
 * main.cpp
 *
 *  Created on: 2024年3月9日
 *      Author: 印皓显
 */

#include <bits/stdc++.h>
#include "download.h"
using namespace std;

struct Song {
	Song(string i, string n, string a): id(i), name(n), artist(a) {}
	string id, name, artist;
} tmp("", "", "");

vector<Song> v;
vector<int> pos_id, pos_art;

string test_song = "Dissension";

void do_nothing() {
	return ;
}

Song f(int idpos, int artpos, string List) {
	tmp = Song("", "", "");
	long long i = idpos + 5;
	string Id = "";
	while (isdigit(List[i]))Id += List[i++];
	i += 9;
	string Name = "";
	while (List[i] != '\"' || List[i - 1] == '\\')Name += List[i++];
	i = artpos;
	while (List[i++] != ',');
	i += 8;
	string Artist = "";
	while (List[i] != '\"' || List[i - 1] == '\\')Artist += List[i++];
	tmp = Song(Id, Name, Artist);
	return tmp;
}

void parse(string List) {
	long long cnt = 0;
	size_t len = List.size();

	for (long long i = 0; i < (long long)(len - 4); i++)
		if (List[i] == '\"' && List[i + 1] == 'i' && List[i + 2] == 'd' && List[i + 3] == '\"')
			switch ((++cnt) % 4) {
				case 1:
					pos_id.push_back(i);
					break;
				case 2:
					pos_art.push_back(i);
					break;
				default:
					do_nothing();
			}

	for (long long i = 0; i < (long long)pos_id.size(); i++) {
		long long _Id = pos_id[i], _Art = pos_art[i];  
		v.push_back(f(_Id, _Art, List));
	}
//	cout << cnt << endl;
	return ;
}

void delete_last_space(string &str) {
	if (str.empty())str = " ";
	while (*(str.end() - 1) == ' ')str.erase(str.end() - 1);
	return ;
}

int main(int argc, char **argv) {
	/* Test argument
		for(int i=0;i<argc;i++) {
			cout<<"argument["<<i<<"] is: "<<argv[i]<<endl;
		}
		system("pause");
	*/
//	cout << argv[1] << endl;
	string song_ordered = argv[1] == NULL ? test_song : argv[1];
	string result = search(song_ordered);
	parse(result);
	
	system("del Downoutput.html");
//	string result = search("Dissension");
//	parse(result);
//	cout << v.size() << endl;
	
	if (v.size() != 0) {
		ofstream fout("songdata.txt");
		for (long long i = 0; i < (long long)v.size() - 1; i++) {
			delete_last_space(v[i].id);
			delete_last_space(v[i].name);
			delete_last_space(v[i].artist);
			fout << v[i].id << "\n" << v[i].name << "\n" << v[i].artist << endl;
		}
		long long t = (long long)v.size() - 1;
		fout << v[t].id << "\n" << v[t].name << "\n" << v[t].artist;
	}
	
	return 0;
}
