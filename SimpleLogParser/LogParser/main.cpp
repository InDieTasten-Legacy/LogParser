#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> strings;
string logfilestring;


string CgetOpenFilePath(){
	string temp = "";
	OPENFILENAME ofn;
	char szFileName[MAX_PATH] = "";
	ZeroMemory(&ofn, sizeof(ofn));

	ofn.lStructSize = sizeof(ofn); // SEE NOTE BELOW

	ofn.lpstrFilter = "ulog Files (*.ulog)\0*.ulog\0All Files (*.*)\0*.*\0";
	ofn.lpstrFile = szFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrDefExt = "ulog";

	if (GetOpenFileName(&ofn))
	{
		// Do something usefull with the filename stored in szFileName
		temp = szFileName;

	}
	else {
		temp = "NULL";
	}

	return temp;

}

string CgetSaveFilePath(){
	string temp;
	char szFileName[MAX_PATH] = "";
	OPENFILENAME sfn;
	ZeroMemory(&sfn, sizeof(sfn));
	sfn.lStructSize = sizeof(sfn);
	sfn.lpstrFilter = "html Files (*.html)\0*.html\0All Files (*.*)\0*.*\0";
	sfn.lpstrFile = szFileName;
	sfn.nMaxFile = MAX_PATH;
	sfn.Flags = OFN_EXPLORER | OFN_HIDEREADONLY;
	sfn.lpstrDefExt = "html";

	if (GetSaveFileName(&sfn))
	{
		temp = szFileName;
	}
	else{
		temp = "NULL";
	}

	return temp;
}


void safeFile(string path){

	ofstream htmlfile;
	htmlfile.open(path.c_str(), ios::out | ios::trunc);
	if (htmlfile.is_open()){
		htmlfile << logfilestring;
		htmlfile.close();
	}

}






int main() {


	string header;
	string footer;
	string divStartStart;
	string divStartEnd;
	string divEnd;
	string css;

	string temp;
	bool isPrevC = false;

	string path = CgetOpenFilePath();

	cout << "FILE OPENED\n";


	ifstream logfile;
	logfile.open(path.c_str(), ios::in);
	if (logfile.is_open()){
		while (std::getline(logfile, temp)){
			strings.push_back(temp);

		}
		logfile.close();
	}


	for (int i = 0; i < strings.size(); i++){
		logfilestring += strings[i];
		logfilestring += "\n";
	}




	size_t pos = 0;
	css = "<style> @import url(http://fonts.googleapis.com/css?family=Ubuntu+Mono);body{ letter-spacing: 1.5px; background-color:#444444; font-family: 'Ubuntu Mono' ;} .black{ color:#000000; } .darkblue{ color:#000080; } .darkgreen{ color:#008000; } .darkcyan{ color:#008080; } .darkred{ color:#800000; } .darkmagenta{ color:#800080; } .darkyellow{ color:#808000; } .darkwhite{ color:#C0C0C0; } .darkgrey{ color:#808080; } .blue{ color:#0000FF; } .green{ color:#00FF00; } .cyan{ color:#00FFFF; } .red{ color:#FF0000; } .magenta{ color:#FF00FF; } .yellow{ color:#FFFF00; } .white{ color:#FFFFFF; } </style> ";
	divStartStart = "<span class=\"";
	divStartEnd = "\">";

	divEnd = "</span>";
	footer = "</body></html>";
	header = "<!DOCTYPE html>\
			 <html lang=\"en\">\
			 <head>\
			 <meta charset=\"UTF-8\">\
			 <title>Document</title>\
			 <script src=\"//ajax.googleapis.com/ajax/libs/jquery/2.1.1/jquery.min.js\"></script>\
			 </head>\
			 <body> ";

	std::string prepared;

	prepared = header + divStartStart + "white" + divStartEnd;
	logfilestring.insert(pos, prepared);
	pos += prepared.size();

	while (pos < logfilestring.size())
	{
		if ((pos % 1000) == 0) // rate should be about 5k instead of 1k
		{
			float progress = pos;
			float total = logfilestring.size();
			cout << "Raw: " << pos << " / " << logfilestring.size() << endl;
			cout << "progress = " << progress << "; total = " << total << ";" << endl;
			cout << "Progress calculated: " << progress/total*100.0f << " % complete" << endl;
		}
		if (logfilestring[pos] == '\n')
		{
			prepared = "<br>";
			logfilestring.insert(pos, prepared);
			pos += prepared.size();
		}
		if (isPrevC)
		{
			switch (logfilestring[pos])
			{
			case '&':
				logfilestring.erase(pos, 1);
				break;
			case '0':
				pos--;
				logfilestring.erase(pos, 2);
				prepared = divEnd + divStartStart + "black" + divStartEnd;
				logfilestring.insert(pos, prepared);
				pos += prepared.size();
				break;
			case '1':
				pos--;
				logfilestring.erase(pos, 2);
				prepared = divEnd + divStartStart + "darkblue" + divStartEnd;
				logfilestring.insert(pos, prepared);
				pos += prepared.size();
				break;
			case '2':
				pos--;
				logfilestring.erase(pos, 2);
				prepared = divEnd + divStartStart + "darkgreen" + divStartEnd;
				logfilestring.insert(pos, prepared);
				pos += prepared.size();
				break;
			case '3':
				pos--;
				logfilestring.erase(pos, 2);
				prepared = divEnd + divStartStart + "darkcyan" + divStartEnd;
				logfilestring.insert(pos, prepared);
				pos += prepared.size();
				break;
			case '4':
				pos--;
				logfilestring.erase(pos, 2);
				prepared = divEnd + divStartStart + "darkred" + divStartEnd;
				logfilestring.insert(pos, prepared);
				pos += prepared.size();
				break;
			case '5':
				pos--;
				logfilestring.erase(pos, 2);
				prepared = divEnd + divStartStart + "darkmagenta" + divStartEnd;
				logfilestring.insert(pos, prepared);
				pos += prepared.size();
				break;
			case '6':
				pos--;
				logfilestring.erase(pos, 2);
				prepared = divEnd + divStartStart + "darkyellow" + divStartEnd;
				logfilestring.insert(pos, prepared);
				pos += prepared.size();
				break;
			case '7':
				pos--;
				logfilestring.erase(pos, 2);
				prepared = divEnd + divStartStart + "darkwhite" + divStartEnd;
				logfilestring.insert(pos, prepared);
				pos += prepared.size();
				break;
			case '8':
				pos--;
				logfilestring.erase(pos, 2);
				prepared = divEnd + divStartStart + "darkgrey" + divStartEnd;
				logfilestring.insert(pos, prepared);
				pos += prepared.size();
				break;
			case '9':
				pos--;
				logfilestring.erase(pos, 2);
				prepared = divEnd + divStartStart + "blue" + divStartEnd;
				logfilestring.insert(pos, prepared);
				pos += prepared.size();
				break;
			case 'a':
				pos--;
				logfilestring.erase(pos, 2);
				prepared = divEnd + divStartStart + "green" + divStartEnd;
				logfilestring.insert(pos, prepared);
				pos += prepared.size();
				break;
			case 'b':
				pos--;
				logfilestring.erase(pos, 2);
				prepared = divEnd + divStartStart + "cyan" + divStartEnd;
				logfilestring.insert(pos, prepared);
				pos += prepared.size();
				break;
			case 'c':
				pos--;
				logfilestring.erase(pos, 2);
				prepared = divEnd + divStartStart + "red" + divStartEnd;
				logfilestring.insert(pos, prepared);
				pos += prepared.size();
				break;
			case 'd':
				pos--;
				logfilestring.erase(pos, 2);
				prepared = divEnd + divStartStart + "magenta" + divStartEnd;
				logfilestring.insert(pos, prepared);
				pos += prepared.size();
				break;
			case 'e':
				pos--;
				logfilestring.erase(pos, 2);
				prepared = divEnd + divStartStart + "yellow" + divStartEnd;
				logfilestring.insert(pos, prepared);
				pos += prepared.size();
				break;
			case 'f':
				pos--;
				logfilestring.erase(pos, 2);
				prepared = divEnd + divStartStart + "white" + divStartEnd;
				logfilestring.insert(pos, prepared);
				pos += prepared.size();
				break;
			default:

				;
			}
		}

		isPrevC = (logfilestring[pos] == '&');
		pos++;
	}
	cout << "COMPLETE!!!" << endl;
	prepared = divEnd + css + footer;
	logfilestring.insert(pos, prepared);
	pos += prepared.size();



	temp = CgetSaveFilePath();
	if (temp != "NULL"){
		safeFile(temp);
	}





	return 0;
}
