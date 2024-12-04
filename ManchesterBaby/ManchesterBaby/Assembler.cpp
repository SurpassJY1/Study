#include <iostream>
#include <fstream>
#include <unordered_map>
#include <regex>
#include <bitset>
#include <algorithm>
#include<sstream>
#include<algorithm>
using namespace std;

// define opcode
unordered_map<string, int> symbolTable;

// using regex to match the lable
regex varRegex(R"((\w+):\s*VAR\s+\d+)");
smatch match;
int currentMemoryAddress = 0;

// instruction and corresponding opcode
unordered_map<string, string> instructionMap = {
	{"JMP", "101"},
	{"JRP", "100"},
	{"LDN", "010"},
	{"STO", "110"},
	{"SUB", "001"},
	{"CMP", "011"},
	{"STP", "111"},
	{"VAR", "000"}
};

// This method is used to get BigEndian number
string decimalToBigEndian(int decimal) {
	//change decimal to binary
	bitset<13> binary(decimal);
	string bigEndian = binary.to_string();
	//reverse the binary number to get BigEndian
	reverse(bigEndian.begin(), bigEndian.end());
	return bigEndian;
}

// This method is used to get opcode
void assemble(const string& inputFile, const string& outputFile) {
	ifstream inputStream(inputFile);
	if (!inputStream.is_open()) {
		cerr << "Can't open the file" << endl;
		exit(-1);
	}
	ofstream outputStream(outputFile);
	string line;

	// traverse first time to create symbolTable storing vars and address
	while (getline(inputStream, line)) {
		if (line.empty() || line[0] == ';') {
			continue;
		}
		size_t notesPos = line.find(";");
		if (notesPos != string::npos) {
			line = line.substr(0, notesPos);
		}
		if (regex_search(line, match, varRegex)) {
			symbolTable[match[1]] = currentMemoryAddress;
		}
		currentMemoryAddress++;
	}

	// reset the stream
	inputStream.clear();
	inputStream.seekg(0, ios::beg);

	// traverse second time to get opcode
	while (getline(inputStream, line)) {
		//check if the line empty or nodes
		if (line.empty() || line[0] == ';') {
			continue;
		}
		//remove the notes
		size_t notesPos = line.find(";");
		if (notesPos != string::npos) {
			line = line.substr(0, notesPos);
		}
		istringstream iss(line);
		string instruction;
		string operand;
		//store the instruction
		iss >> instruction;
		cout << "instruction :" << instruction << endl;
		//if variable instruction is varble, get the number of it
		string potentialVar = instruction.substr(0, instruction.length() - 1);
		cout << "potentialVar" << potentialVar << endl;
		//check if potentialVar is variable
		auto stit = symbolTable.find(potentialVar);
		if (stit != symbolTable.end())
		{
			iss >> instruction;
			iss >> operand;
			outputStream << decimalToBigEndian(stoi(operand)) << "";
			auto it = instructionMap.find(instruction);
			if (it != instructionMap.end()) {
				string opcode = it->second;

				outputStream << opcode << "0000000000000000" << endl;
			}
			continue;
		}
		if (instruction.back() == ':')
		{
			//if instruction is START or END or variables, assign the next word
			iss >> instruction;
		}
		//the code after instruction is variable
		iss >> operand;
		string address = decimalToBigEndian(symbolTable[operand]);
		auto addressit = symbolTable.find(operand);
		if (addressit != symbolTable.end())
		{
			outputStream << decimalToBigEndian(addressit->second) << "";
		}
		auto it = instructionMap.find(instruction);
		if (it != instructionMap.end()) {
			string opcode = it->second;

			outputStream << opcode << "0000000000000000" << endl;
		}

	}

	inputStream.close();
	outputStream.close();
}
bool endsWithTxt(const std::string& str) {
	// get length
	size_t length = str.length();

	//check if the length long enough
	if (length >= 4) {
		// check if it ends with txt
		return str.substr(length - 4) == ".txt";
	}

	return false;
}

int main() {
	string inputFile, outputFile;

	std::cout << "Enter the file: ";
	std::cin >> inputFile;

	std::cout << "Enter the outputfile: ";
	std::cin >> outputFile;

	if (endsWithTxt(inputFile)&&endsWithTxt(outputFile)) {
		assemble(inputFile, outputFile);
	}
	else {
		cout << "Please check if the file ends with txt" << endl;
		return 1;
	}
	

	return 0;
}

	
		
	
