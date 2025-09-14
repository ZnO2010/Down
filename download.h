/*
 * download.hpp
 *
 *  Created on: 2024年8月1日
 *      Author: 印皓显
 */
#ifndef DOWN_H
#define DOWN_H
#include<bits/stdc++.h>

using std::string;
using std::ifstream;
using std::getline;

string search(string Song_Name) {
// api:http://music.163.com/api/search/get/web?csrf_token=&type=1&s=song
	string web_str = "", ans = "", cmnd = "aria2c -d . -s 4 -o Downoutput.html ";
	
	system("del Downoutput.html");
	web_str += "\"http://music.163.com/api/search/get/web?csrf_token=&type=1&s=";
	web_str += (Song_Name + "\"");
	cmnd += web_str;
	system(cmnd.c_str());
	ifstream fin("Downoutput.html");
	getline(fin, ans);
	
	system("del Downoutput.html");
	return ans;
}

#endif
