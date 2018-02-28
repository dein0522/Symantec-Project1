#include <iostream>
#include <string>
#include <vector>
#include<fstream>
using namespace std;
class Symancode
{
private:
	int limit = 0;
	vector<bool> Bits;
	vector<int> index;
	string input_string;
	string Symcoded;
public:
	string get_symcoded() { return Symcoded; };
	void symcode();
	void handle_input(string);
	void Form_Bits();
	void process(string);
	void preparation();
	void to_index();
	
};
class File
{
private:
	fstream file;
	fstream fin;
	string input_string;
	Symancode *object;
public:
	
	void open_file();
	void write_symcode();
	void endline() { file << endl; };
	bool no_space();
	bool get_eof() { return fin.eof(); };
	void set_InputString();
	string get_InputString() { return input_string; };

};
int main()
{
	bool check = false;
	File newfile;
	newfile.open_file();
	while (!newfile.get_eof())
	{
		newfile.set_InputString();
		if (newfile.no_space() == true)
		{
			if (check == true)newfile.endline();
			newfile.write_symcode();
		}
		check = true;
	}
	return 0;
}
bool File::no_space()
{
	if (input_string == "") 
	{
		file << endl;
		return false;
	}
	return true;

}
void File::set_InputString()
{
	getline(fin, input_string);
}
void File::open_file()
{
	fin.open("symcode-in.txt", ios::in);
	file.open("answer2.txt", ios::out);
}
void File::write_symcode()
{
	object = new Symancode();
	object->process(input_string);
	file << object->get_symcoded();
	delete object;
}
void Symancode::handle_input(string Input_String)
{
	input_string = Input_String;
	while (input_string[0] == ' ' || input_string[0] == '\t')
		input_string.erase(input_string.begin());
}
void Symancode::process(string Input_String)
{
	handle_input(Input_String);
	Form_Bits();
	preparation();
	to_index();
	symcode();
}
void Symancode::Form_Bits()
{
	int i, number, x;
	vector<bool>::iterator it;
	for (i = 0; i<input_string.size(); i++)
	{
		number = input_string[i];
		it = Bits.end();
		for (int i = 0; i < 8; i++)
		{
			if (number != 0)
			{
				x = number % 2;
				it = Bits.insert(it, x);
				number /= 2;
			}
			else
				it = Bits.insert(it, 0);
		}
	}
}
void Symancode::preparation()
{
	int Padding_Num, num2;

	Padding_Num = Bits.size() % 24;
	if (Padding_Num == 0)Padding_Num = 24;
	num2 = Bits.size() + 24 - Padding_Num;
	while (limit < Bits.size())
		limit += 3;
	for (int i = Bits.size(); i < num2; i++)
		Bits.push_back(0);

}
void Symancode::to_index()
{
	int Bin[3] = { 4,2,1 }, i, j = 0, num = 0;
	for (i = 0; i < Bits.size(); i++)
	{
		num += Bits[i] * Bin[j++];
		if (j == 3)
		{
			j = 0;
			index.push_back(num);
			num = 0;
		}
		if (i == limit)
			break;
	}
}
void Symancode::symcode()
{
	int i;
	string symantec = "symantec";
	for (i = 0; i < index.size(); i++)
		Symcoded.push_back(symantec[index[i]]);
	limit = Bits.size() - limit;
	for (i = 0; i < limit; i++)
	{
		if (i % 3 == 0)
			Symcoded.push_back('$');
	}
}