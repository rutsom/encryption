#include<stdio.h>
#include <dirent.h>
#include <windows.h>
#include <conio.h>

int find();
int enc(char []);
void end(int);
void stcls(char *);
int df=0;
char a[300];
struct dirent *dir;
void main()
{// to navigate into the dives and selecting the file or folder
	char d[5],f[20];
	int i=0,v;
	printf("select your drive: [c,d,e]");
	scanf("%s",&d);
	strcat(d,"://");
	strcat(a,d);
	while(1)
	{
		dif();
		printf("enter the file or folder name [add ~ at end of dir to enc dir] : ");
		gets(f);
		v=cm(&f);
		if(v==1)
		{
		strcat(a,f);
		enc(a);	
		}
		else if(v==2)
		{
			strcat(f,"//");
			strcat(a,f);
		dic();
		}
		strcat(f,"//");
		strcat(a,f);
		system("cls");
	}
}
int cm(char *c)
{//to distinguish between file or folder to encrypt
	int i=0;
	while(*(c+i)!='\0')
	{
		if(*(c+i)=='.'&&(*(c+(i+1))>65&&*(c+(i+1))<125))
		{
			return 1;
		}
		else if(*(c+i)=='~')
		{
			*(c+i)='\0';
			return 2;
		}
		i++;
	}
	return 0;
}
int find()
{// to distuingish between file or folder
	int i=0;
	while(dir->d_name[i]!='\0')
	{
		if(dir->d_name[i]=='.'&&(dir->d_name[i+1]>65&&dir->d_name[i+1]<125))
		{
			return 1;
		}
		i++;
	}
	return 0;
}
int dif()
{// to list different files and folder in drive
	DIR *d;
	int i=0;
	d=opendir(a);
	if(d)
	{
		while((dir=readdir(d))!=NULL)
		{
			//printf("%d %s\n",dir->d_ino,dir->d_name);
			
			if(find(dir))
			{
				printf("file %s\n",dir->d_name);
			}
			else
			{
				printf("dir %s\n",dir->d_name);
			}
			i++;
		}
		closedir(d);
	}
	else
	{
		printf("cannot open dir\n");
	end(0);
	}
	return 1;
}
int enc(char c[])
{//this is where the encryption takes place
	long l;
	FILE *f,*d;
	char b;
	
		f=fopen(c,"rb");
	
	strcat(c,"-");
	d=fopen(c,"wb");
	if(f!=NULL)
	{
		printf("file opened\n");
		fseek(f,0l,2);
		l=ftell(f);
		fseek(f,0l,0);
		printf("%d",ftell(f));
		while(ftell(f)<l)
	{
		b=fgetc(f);
		fprintf(d,"%c",b-25);//change this key to your desired cryptography
	}
	fclose(f);
	fclose(d);
	}
	else
	{
		printf("\nfile cannot be opened: \n");
		
		end (0);
	}
	if(!df)// to find if this function is called from dic() or main()
	{
		end(1);
	}
	
}
void end(int a)
{
	//give the final statement
	if(a)
	{
		printf("\noperation succesfull");		
	}
	else
	{
		printf("\noperation failed");
	}
	exit(0);
}
int dic()
{// to provide file names for folder encryption to enc()
	df=1;
	DIR *d;
	d=opendir(a);
	char c[300];
	if(d)
	{
		while((dir=readdir(d))!=NULL)
		{
			stcls(&c[0]);
			//printf("%d %s\n",dir->d_ino,dir->d_name);
			strcat(c,a);
			if(find(dir))
			{
				strcat(c,dir->d_name);
				enc(c);
			}
			else
			{
				printf("dir %s\n",dir->d_name);
			}
		}
		closedir(d);
		end(1);
	}
	else
	{
		printf("cannot open dir\n");
	return 0;
	}
	df=0;
	return 1;
}
void stcls(char *p)
{
	int i;
	for(i=0;*(p+i)!='\0';i++)
	{
		*(p+i)='\0';
	}
}
