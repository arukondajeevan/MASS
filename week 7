#include<stdio.h>
int main()
{
    char message[100], ch,cipher[100];
    int i, key;
    printf("Enter a message to encrypt: ");
    scanf("%s",message);
    printf("Enter key: ");
    scanf("%d", &key);
	if(key>=26)
	{
		key=key%26;
	}
    for(i=0;message[i]!='\0';++i)
	{
        ch = message[i];
        if(ch >='a'&&ch<='z')
	{
            ch=ch+key;
            if(ch > 'z')
		{
                ch=ch-'z'+'a'-1;
	        }
        cipher[i] = ch;
        }
        else if(ch >='A'&&ch<='Z')
	{
            ch=ch+key;
            if(ch>'Z')
	    {
              ch=ch-'Z'+'A'-1;
	    }
        cipher[i] = ch;
        }
    }
    printf("Encrypted message:%s\n",cipher);
    for(i=0;cipher[i]!='\0';++i)
	{
        ch = cipher[i];
        if(ch>='a'&&ch<='z')
	{
           ch=ch-key;
           if(ch<'a')
	   {
             ch=ch+'z'-'a'+1;
           }
            
        message[i]=ch;
        }
        else if(ch>='A'&&ch<='Z')
	{
          ch=ch-key;
          if(ch<'A')
	  {
             ch=ch+'Z'-'A'+1;
          }
        message[i]=ch;
        }
    }
    printf("Decrypted message: %s\n",message);
    return 0;
}

