#include<iostream>
#include<fstream>
using namespace std;

//this method is used to encrypt my picture
void encrypt(char key)
{
	ifstream ifs("DemoPicture.jpg", ios::binary | ios::in);
	if (!ifs.is_open())
	{
		cout << "ERROR" << endl;
		return;
	}
	//Determine the size of picture
	ifs.seekg(0,ios::end);
	long size = ifs.tellg();
	//reset the pointer
	ifs.seekg(0,ios::beg);
	//create a container to store the binary data
	char* buff = new char[size];
	ifs.read(buff,size);//�洢��ַָ�룬��С
	//move every byte 
	for (size_t i = 0; i < size-1; i++)
	{
		buff[i] =buff[i]^key;
	}
	//close stream
	ifs.close();
	//put the data in ofstream
	ofstream ofs("DemoPicture.jpg",ios::binary|ios::trunc|ios::out);
	ofs.write( buff,size);
	//close stream
	ofs.close();
	delete[]buff;
}
void decrypt(char key)
{
	ifstream ifs("DemoPicture.jpg", ios::binary | ios::in);
	if (!ifs.is_open())
	{
		cout << "ERROR" << endl;
		return;
	}
	//Determine the size of picture
	ifs.seekg(0, ios::end);
	long size = ifs.tellg();
	//reset the pointer
	ifs.seekg(0, ios::beg);
	//create a container to store the binary data
	char* buff = new char[size];
	ifs.read(buff, size);//�洢��ַָ�룬��С
	//XOR every byte
	for (size_t i = 0; i < size - 1; i++)
	{
		buff[i] ^=key;
	}
	//close stream
	ifs.close();
	//put the data in ofstream
	ofstream ofs("DemoPicture.jpg", ios::binary | ios::trunc | ios::out);
	ofs.write(buff, size);
	//close stream
	ofs.close();
	//free memory
	delete[]buff;
}
int main()
{
	decrypt('a');
	return 0;
}