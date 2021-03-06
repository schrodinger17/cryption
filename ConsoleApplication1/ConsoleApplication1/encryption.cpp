#include "stdafx.h"
#include "md5.h"
#include "des.h"
#include "base64.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cstdio>

using namespace CryptoPP;
using namespace std;
#pragma comment (lib,"cryptlib.lib")

void md5(byte message[], int n,byte *result)//md5加密
{
	byte *p = result;
	byte m[16];
	MD5 md5;
	md5.Update(message, n);
	md5.Final(m);
	for (int i = 0; i < 16; i++)
	{
		*(result++) = m[i];
	}
	result = p;
}
void desencryption(unsigned char input[],int len, unsigned char key[DES::DEFAULT_KEYLENGTH], unsigned char* result)//DES加密
{
	unsigned char *p = result;
	unsigned char input1[DES::DEFAULT_BLOCKSIZE] = { 0 };
	unsigned char output[DES::DEFAULT_BLOCKSIZE];
	DESEncryption encryption_DES;
	encryption_DES.SetKey(key, DES::DEFAULT_KEYLENGTH);
	int i = 0;
	int n = len / 8 + 1;
	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			input1[j] = 0;
			if (8 * i + j <len)
			{
				input1[j] = input[8 * i + j];
			}
		}
		encryption_DES.ProcessBlock(input1, output);
		for (int k = 0; k< DES::DEFAULT_BLOCKSIZE; k++)
		{
			*(result++) = output[k];
		}
	}
	result = p;
}
int main()
{
	int c2;
	cout << "=====================================================" << endl;
	cout << "Please choose a way of Encryption:" << endl;
	cout << "1 MD5" << endl;
	cout << "2 DES" << endl;
	cout << "0 to quit" << endl;
	cout << "=====================================================" << endl;
	while (cin >> c2)
	{
		int c3;
		if (c2 == 0)
			break;
		else if (c2 == 1)
		{
			cout << "=====================================================" << endl;
			cout << "1 Choose a txt file" << endl;
			cout << "2 Input now" << endl;
			cout << "0 to go back" << endl;
			cout << "TIPS:Please rename your file as \"md5.txt\" and put it in current directory" << endl;
			cout << "=====================================================" << endl;
			while (cin >> c3)
			{
				if (c3 == 0)
				{
					cout << "=====================================================" << endl;
					cout << "Please choose a way of Encryption:" << endl;
					cout << "1 MD5" << endl;
					cout << "2 DES" << endl;
					cout << "0 to quit" << endl;
					cout << "=====================================================" << endl;
					break;
				}
				else if (c3 == 1)
				{
					ifstream infile("md5.txt");
					if (!infile.fail())
					{
						ostringstream buf;
						char ch;
						while (infile.get(ch))
						{
							buf.put(ch);
						}
						string message = buf.str();
						//cout << message;
						infile.close();
						int n = message.length();
						byte *m = new byte[n];
						for (int i = 0; i < n; i++)
						{
							m[i] = message[i];
						}
						byte *result = new byte[16];
						md5(m, n, result);
						FILE *fp;
						fopen_s(&fp,"md5encryption.txt", "w+");
						for (int i = 0; i < 16; i++)
						{
							fprintf(fp, "%02x", *(result + i));
						}
						fclose(fp);
						cout << endl;
						delete[]m;
						delete[]result;
						m = nullptr;
						result = nullptr;
						cout << "md5encryption.txt has been generated!";
						cout << endl;
						cout << "=====================================================" << endl;
						cout << "1 Choose a txt file" << endl;
						cout << "2 Input now" << endl;
						cout << "0 to go back" << endl;
						cout << "TIPS:Please rename your file as \"md5.txt\" and put it in current directory" << endl;
						cout << "=====================================================" << endl;
					}
					else
					{
						cout << "No files in current directory!" << endl << endl;
						cout << "=====================================================" << endl;
						cout << "1 Choose a txt file" << endl;
						cout << "2 Input now" << endl;
						cout << "0 to go back" << endl;
						cout << "TIPS:Please rename your file as \"md5.txt\" and put it in current directory" << endl;
						cout << "=====================================================" << endl;
						continue;
					}
				}
				else if (c3 == 2)
				{
					string message;
					cin >> message;
					int n = message.length();
					byte *m = new byte[n];
					for (int i = 0; i < n; i++)
					{
						m[i] = message[i];
					}
					byte *result = new byte[16];
					md5(m, n, result);
					for (int i = 0; i < 16; i++)
					{
						printf("%02x", *(result + i));
					}
					cout << endl;
					delete[]m;
					delete[]result;
					m = nullptr;
					result = nullptr;
					cout << endl;
					cout << "=====================================================" << endl;
					cout << "1 Choose a txt file" << endl;
					cout << "2 Input now" << endl;
					cout << "0 to go back" << endl;
					cout << "TIPS:Please rename your file as \"md5.txt\" and put it in current directory" << endl;
					cout << "=====================================================" << endl;
				}
				else
				{
					cout << endl;
					cout << "=====================================================" << endl;
					cout << "1 Choose a txt file" << endl;
					cout << "2 Input now" << endl;
					cout << "0 to go back" << endl;
					cout << "TIPS:Please rename your file as \"md5.txt\" and put it in current directory" << endl;
					cout << "=====================================================" << endl;
					continue;
				}
					
			}
		}
		else if (c2 == 2)
		{
			cout << "=====================================================" << endl;
			cout << "1 Choose a txt file" << endl;
			cout << "2 Input now" << endl;
			cout << "0 to go back" << endl;
			cout << "TIPS:Please rename your file as \"des.txt\" and put it in current directory" << endl;
			cout << "=====================================================" << endl;
			while (cin >> c3)
			{
				if (c3 == 0)
				{
					cout << endl;
					cout << "=====================================================" << endl;
					cout << "Please choose a way of Encryption:" << endl;
					cout << "1 MD5" << endl;
					cout << "2 DES" << endl;
					cout << "0 to quit" << endl;
					cout << "=====================================================" << endl;
					break;
				}
				else if (c3 == 1)
				{
					ifstream infile("des.txt");
					if (!infile.fail())
					{
						ostringstream buf;
						char ch;
						while (infile.get(ch))
						{
							buf.put(ch);
						}
						string message = buf.str();
						int n = message.length();
						unsigned char *m = new unsigned char[n];
						for (int i = 0; i < n; i++)
						{
							m[i] = message[i];
						}
						cout << "Please input your KEY(7 digits):" << endl;
						unsigned char KEY[8];
						cin >> KEY;
						unsigned char *result = new unsigned char[(n / 8 + 1) * 8];
						desencryption(m,n, KEY, result);
						ofstream outfile("desencryption.txt");
						for (int i = 0; i < ((n-1)/8+1)*8; i++)
						{
							outfile << hex << (int)*(result + i) << ends;
						}
						outfile << endl;
						outfile << "KEY:";
						for (int i = 0; i < 7; i++)
						{
							outfile << KEY[i];
						}
						outfile << endl;
						outfile.close();
						cout << endl;
						delete[]m;
						delete[]result;
						m = nullptr;
						result = nullptr;
						cout << "desencryption.txt has been generated!";
						cout << endl;
						cout << "=====================================================" << endl;
						cout << "1 Choose a txt file" << endl;
						cout << "2 Input now" << endl;
						cout << "0 to go back" << endl;
						cout << "TIPS:Please rename your file as \"des.txt\" and put it in current directory" << endl;
						cout << "=====================================================" << endl;
					}
					else
					{
						cout << "No files in current directory!" << endl << endl;
						cout << "=====================================================" << endl;
						cout << "1 Choose a txt file" << endl;
						cout << "2 Input now" << endl;
						cout << "0 to go back" << endl;
						cout << "TIPS:Please rename your file as \"des.txt\" and put it in current directory" << endl;
						cout << "=====================================================" << endl;
						continue;
					}
				}
				else if (c3 == 2)
					{
						string message;
						cin >> message;
						int n = message.length();
						unsigned char *m = new unsigned char[n];
						for (int i = 0; i < n; i++)
						{
							m[i] = message[i];
						}
						cout << "Please input your KEY(7 digits):" << endl;
						unsigned char KEY[8];
						cin >> KEY;
						unsigned char *result = new unsigned char[(n / 8 + 1) * 8];
						desencryption(m,n,KEY, result);
						for (int i = 0; i < ((n-1)/8+1)*8; i++)
						{
							cout <<hex<<(int) *(result + i) << ends;
						}
						cout << endl;
						delete[]m;
						delete[]result;
						m = nullptr;
						result = nullptr;
						cout << endl;
						cout << "=====================================================" << endl;
						cout << "1 Choose a txt file" << endl;
						cout << "2 Input now" << endl;
						cout << "0 to go back" << endl;
						cout << "TIPS:Please rename your file as \"des.txt\" and put it in current directory" << endl;
						cout << "=====================================================" << endl;
					}
				else
					{
						cout << "=====================================================" << endl;
						cout << "1 Choose a txt file" << endl;
						cout << "2 Input now" << endl;
						cout << "0 to go back" << endl;
						cout << "TIPS:Please rename your file as \"des.txt\" and put it in current directory" << endl;
						cout << "=====================================================" << endl;
						continue;
					}

				}
			}
		else if (c3 == 3)
		{
		}
		else
		{
			cout << endl;
			cout << "=====================================================" << endl;
			cout << "Please choose a way of Encryption:" << endl;
			cout << "1 MD5" << endl;
			cout << "2 DES" << endl;
			cout << "0 to quit" << endl;
			cout << "=====================================================" << endl;
			continue;
		}

	}
	return 0;
}