#define _CRT_SECURE_NO_WARNINGS
#define MaxSize 255
#include<stdio.h>

#if 0

//´®µÄË³Ğò´æ´¢

typedef struct//´®µÄ¾²Ì¬·ÖÅä´æ´¢
{
	char ch[MaxSize];
	int length;
}SString;

typedef struct//´®µÄ¶¯Ì¬·ÖÅä´æ´¢
{
	char* ch;
	int length;
}HString;

void InitHString(HString* S)
{
	S->ch = (HString*)malloc(sizeof(HString));
	S->length = 0;
}

int SubString(SString* sub, SString s, int pos, int len)
{
	if ((pos + len - 1) > s.length)
		return 1;
	int i = 0;
	for (i = pos; i < pos + len; i++)
	{
		sub->ch[i - pos + 1] = s.ch[i];
	}
	sub->length = 0;
	return 0;
}



int main()
{ 
	SString s;
	SString sub;
	HString S;
	SubString;//Çó×Ó´®
	return 0;
}


//´®µÄÁ´Ê½´æ´¢

typedef struct
{
	char ch[MaxSize];
	struct StringNode* next;
}node,*String;

#endif


//ÆÓËØÄ£Ê½Æ¥ÅäËã·¨
int my_strstr(char* s1, char* s2,int a,int b)
{
	int k = 0;
	int i = k, j = 0;
	while (i <= a && j <= b)
	{
		if (s1[i] == s2[j])
		{
			i++;
			j++;
		}
		else
		{
			k++;
			i = k;
			j = 0;
		}
	}
	if (j > b)
		return k;
	else 
		return -1;

}

int main()
{

	char ch1[] = "abcdefg";
	char ch2[] = "def";
	int a = strlen(ch1);
	int b = strlen(ch2);
	int o = my_strstr(ch1, ch2, a-1, b-1);
	printf("%d", o);




	return 0;
}