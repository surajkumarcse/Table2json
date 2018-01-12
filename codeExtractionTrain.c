#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
char buffer[255];
char stationName[100];
FILE *fi;
FILE *fout;
int i;
char arrival1[100]="";
char dep[10]="";
char stationId[10]="";
char first1[]="{\"train Name\":\"";
char common[]="\",";
char second[]="\"train No \" : \"";
char arrival[]="\"train Arrival\": \"";
char departure1[]="\"train Departure\": \"";
char last[]="\"},";
fi=fopen("traintable.txt", "r");
fout=fopen("station.json", "w");
fputs("[", fout);
while(fgets(buffer, 255, (FILE*) fi))
{



for(i=72; buffer[i]!='<'; i++)
stationName[i-72]=buffer[i];
stationName[i-72]='\0';
fputs(first1, fout);
fputs(stationName, fout);
fputs(common, fout);

//first completed


int j=0;



while(buffer[i]!='(')
i++;
i++;
while(buffer[i]!=')')
stationId[j++]=buffer[i++];
stationId[j]='\0';
fputs(second, fout);
fputs(stationId, fout);
fputs(common, fout);
//second completed
j=0;

fgets(buffer, 255, (FILE *)fi);



if(buffer[30]!='<')
{
int i=30;
while(buffer[i]!='<')
arrival1[j++]=buffer[i++];
arrival1[j]='\0';
}
else
strcpy(arrival1,"starts");
fputs(arrival, fout);
fputs(arrival1, fout);
fputs(common, fout);
//third completed
 j=0;
fgets(buffer, 255, (FILE *)fi);
if(buffer[30]!='<')
{
i=30;
while(buffer[i]!='<')
arrival1[j++]=buffer[i++];
arrival1[j]='\0';
}
else
strcpy(arrival1,"ends");
fputs(departure1, fout);
fputs(arrival1, fout);
fputs(last, fout);
fgets(buffer, 255, (FILE *)fi);
fgets(buffer, 255, (FILE *)fi);
}
//fourth  completed
//printf("%s\n", stationName);
fputs("{}", fout);
fputs("]", fout);

fclose(fi);
fclose(fout);
return 0;
}

