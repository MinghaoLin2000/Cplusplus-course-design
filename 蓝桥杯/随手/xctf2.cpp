#include <iostream>
using namespace std;
#include <string>
char small_letter[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
char big_letter[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
char result[1000];
int p;
void decrypt(unsigned int* v, unsigned int* key) {
	unsigned int l = v[0], r = v[1], sum = 0, delta = 0x9e3779b9;
	sum = delta * 32;
	for (size_t i = 0; i < 32; i++) {
		r -= (((l << 4) ^ (l >> 5)) + l) ^ (sum + key[(sum >> 11) & 3]);
		sum -= delta;
		l -= (((r << 4) ^ (r >> 5)) + r) ^ (sum + key[sum & 3]);
	}
	v[0] = l;
	v[1] = r;
}
char* carse(char* estr,int move) {
	for (int i = 0; i < strlen(estr); i++)
	{
		if(estr[i]>='A'&&estr[i]<='Z')
        {
            p=((estr[i]-'A')- move);
            while(p<0)p+=26;
            result[i]=big_letter[p];
        }
        else if (estr[i]>='a'&&estr[i]<='z')
        {
            p=((estr[i]-'a')- move);
            while(p<0)p+=26;
            result[i]=small_letter[p];
        }
        else result[i]= estr[i];
	}
	return result;
}
int main(int argc, char const *argv[])
{
	//test
	unsigned int v[2] = { (unsigned int)-355481616,(unsigned int)1654711569 }, key[4] = { 1,2,3,4 };
	char *FK = (char*)malloc(50);
	char *b = (char*)malloc(50);
	int c[] = { 122,125,119,121,71,104,84,85,79,99,13,79,99,125,99,107,78,12,110,91,99,122,13,12,91,65 };
	decrypt(v, key);
	for (int i = 0; i < 26; i++) {
		FK[i] = c[i] ^ v[0];
	}
	b = carse(FK, 18);
	string eflag=b;
	cout << "flag is:" << eflag.substr(0,26);
	return 0;
}