//============================================================================
// Name        : a3_main.cpp
// Author      : Ahmed Yasser and Ahmed Hany
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Binarysearchtree.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
#include <bits/stdc++.h>
#include <vector>
#include <iterator>
#include <cctype>
const std::string WHITESPACE = " \n\r\t\f\v";
void removeSpaces(string &str)
{
    int n = str.length();

    int i = 0, j = -1;

    bool spaceFound = false;

    while (++j < n && (str[j] == ' ' ));

    while (j < n+1)
    {
        if (str[j] != ' ')
        {
            if ((str[j] == '.' || str[j] == ',' ||
                 str[j] == '?') && i - 1 >= 0 &&
                 str[i - 1] == ' ')
                str[i - 1] = str[j++];

            else
                str[i++] = str[j++];

            spaceFound = false;
        }
        else if (str[j++] == ' ')
        {
            if (!spaceFound)
            {
                str[i++] = ' ';
                spaceFound = true;
            }
        }
    }

    if (i <= 1)
        str.erase(str.begin() + i, str.end());
    else
        str.erase(str.begin() + i - 1, str.end());
}
std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string &s)
{
    return rtrim(ltrim(s));
}
bool isInteger(double N)
{
    int X = N;
    double temp2 = N - X;
    if (temp2 > 0) {
        return false;
    }
    return true;
}

void   ADD(string str1,string str2,string d,Binary_search_tree* TREE)
{
	int f1=0;
	int f2=0;
	int f3=0;
	int f4=0;
	int f5=0;
	float x;
	float y;
	if(str1[0]!='"' || str1[str1.length()-1]!='"'  )
	{
		cout<<"Invalid title"<<endl;
		f1=1;
	}
	for(unsigned int i=0;i<str2.length();i++)
	{
        if (!isdigit(str2[i])&&f4!=1)
        {
        	f4=1;
			f2=1;
		cout<<"Invalid day"<<endl;
        }
	}
	if(f4!=1)
	{
	     x = stof(str2)	;
	    if(x<1 || x>365|| !isInteger(x))
	    {
			cout<<"Invalid day"<<endl;
			f2=1;
	    }
	}
	for(unsigned int i=0;i<d.length();i++)
	{
        if (!isdigit(d[i])&&f5!=1)
        {
        	f5=1;
			f3=1;
		cout<<"Invalid hour"<<endl;
        }
	}
	if(f3!=1)
	{
	     y = stof(d);
	    if(y>23||y<0 || !isInteger(y))
	    {
			cout<<"Invalid hour"<<endl;
			f3=1;
	    }
	}
    if (f1==0 && f2==0 && f3==0)
    TREE->ADD( str1, x, y);
}

void   Find(string str1,string d,Binary_search_tree* TREE)
{
	int f1=0;
	int f2=0;
	int f3=0;
	int f4=0;
	float x;
	float y;
	for(unsigned int i=0;i<str1.length();i++)
	{
        if (!isdigit(str1[i])&&f3!=1)
        {
        	f3=1;
        	f1=1;
		cout<<"Invalid day"<<endl;
        }
	}
	if(f3!=1)
	{
	     x = stof(str1)	;
	    if(x<1 || x>365|| !isInteger(x))
	    {
			cout<<"Invalid day"<<endl;
			f1=1;
	    }
	}
	for(unsigned int i=0;i<d.length();i++)
	{
        if (!isdigit(d[i])&&f4!=1)
        {
        	f4=1;
			f2=1;
		cout<<"Invalid hour"<<endl;
        }
	}
	if(f4!=1)
	{
	     y = stof(d);
	    if(y>23||y<0 || !isInteger(y))
	    {
			cout<<"Invalid hour"<<endl;
			f2=1;
	    }
	}
    if (f1==0 && f2==0 )
     cout<<TREE->find( x, y)<<endl;
}
void   MOD(string str1,string str2,string d,Binary_search_tree* TREE)
{
	int f1=0;
	int f2=0;
	int f3=0;
	int f4=0;
	int f5=0;
	float x;
	float y;
	if(str1[0]!='"' || str1[str1.length()-1]!='"'  )
	{
		cout<<"Invalid title"<<endl;
		f1=1;
	}
	for(unsigned int i=0;i<str2.length();i++)
	{
        if (!isdigit(str2[i])&&f4!=1)
        {
        	f4=1;
			f2=1;
		cout<<"Invalid day"<<endl;
        }
	}
	if(f4!=1)
	{
	     x = stof(str2)	;
	    if(x<1 || x>365|| !isInteger(x))
	    {
			cout<<"Invalid day"<<endl;
			f2=1;
	    }
	}
	for(unsigned int i=0;i<d.length();i++)
	{
        if (!isdigit(d[i])&&f5!=1)
        {
        	f5=1;
			f3=1;
		cout<<"Invalid hour"<<endl;
        }
	}
	if(f3!=1)
	{
	     y = stof(d);
	    if(y>23||y<0 || !isInteger(y))
	    {
			cout<<"Invalid hour"<<endl;
			f3=1;
	    }
	}
    if (f1==0 && f2==0 && f3==0)
	if(!TREE->MOD( str1,x, y))
	{
	  cout<<"Empty "<<x<<" "<<y<<endl;
	}
}

void   DEL(string str1,string d,Binary_search_tree* TREE,Binary_search_tree* newtree)
{
	int f1=0;
	int f2=0;
	int f3=0;
	int f4=0;
	float x;
	float y;
	for(unsigned int i=0;i<str1.length();i++)
	{
        if (!isdigit(str1[i])&&f3!=1)
        {
        	f3=1;
        	f1=1;
		cout<<"Invalid day"<<endl;
        }
	}
	if(f3!=1)
	{
	     x = stof(str1)	;
	    if(x<1 || x>365|| !isInteger(x))
	    {
			cout<<"Invalid day"<<endl;
			f1=1;
	    }
	}
	for(unsigned int i=0;i<d.length();i++)
	{
        if (!isdigit(d[i])&&f4!=1)
        {
        	f4=1;
			f2=1;
		cout<<"Invalid hour"<<endl;
        }
	}
	if(f4!=1)
	{
	     y = stof(d);
	    if(y>23||y<0 || !isInteger(y))
	    {
			cout<<"Invalid hour"<<endl;
			f2=1;
	    }
	}
    if(f1==0 &&f2==0)
    {
    	bool flag = false;
    	TREE->DEL(x,y,newtree,flag);
    	if(flag==false)
    	{
    		cout<<"Empty"<<" "<<str1<<" "<<d<<'\n';
    	}
    }
}
void Print(Binary_search_tree* TREE)
{
	if(!TREE->isEmpty())
		cout<<TREE->print();
	else
		cout<<"Empty Planner"<<'\n';
}
int main(int argc, char** argv)
{
	 Binary_search_tree* TREE=new Binary_search_tree;
	 if (argc!=2 ) cout<<"Invalid arguments"<<endl;
	 else
	 {
		int counter=0;
		int counter2=0;
		int counter3=0;
		int arr[50];
		int arr2[50];
		int p=0;
		string  h,d,str1,str2,s1;
		int f1=0; int f2=0 ; int f3=0; int f4=0;
		int f5=0;
		ifstream file2;
		file2.open(argv[1]);
		if(!file2)
		{
			cout<<"File not found"<<endl;
			return   0;
		}
		while (getline(file2,h))
		{
			if(h=="")
			{
				continue;
			}
			str1="";
			h=trim(h);
			//h.erase(std::remove(h.begin(), h.end(), '\t'), h.end());
			for(unsigned int  i=0;i<h.length();i++)
			{
				if(h[i]==' '&&h[i+1]!=' ') p++;
				if (h[i]=='"')
				{
					arr[counter]=i;
					counter++;
				}
			}
			s1=h;
		    removeSpaces(s1);
			for(unsigned int  i=0;i<h.length();i++)
			{
				if (s1[i]=='"')
				{
					arr2[counter3]=i;
					counter3++;
				}
			}
			//cout<<counter<<s1[arr[counter-1] +1]<<s1[4];
		    //&&!(s1[4]!='"' && counter==2)&&!(s1[counter]='"')
			if(counter>=2  &&!(arr[1]-arr[0]==1 && counter==2) &&(s1[4]=='"') && (s1[arr2[counter3-1] +1]==' ')  )
			{
				for(signed int  i=arr[0];i<arr[counter-1]+1;i++)
				{
					if(h[i]==' '&&h[i+1]!=' ' )
					{
						p--;
					}

					str1=str1+h[i];
				}
				h.erase(std::remove(h.begin(), h.end(), '\t'), h.end());

			    removeSpaces(h);
			for(unsigned int  i=0;i<str1.length();i++)
			{
				if(str1[i]==' ' && str1[i+1]!=' ')
				{
					counter2++;
				}
			}
			counter2++;

			}
			h.erase(std::remove(h.begin(), h.end(), '\t'), h.end());

		    removeSpaces(h);

	 	 	d = "";
			for (auto x : h)
			{
				if (x == ' ')
	            {
					if( counter2==0)
					{
						str2=d;
					}
			    	if((f1==1  || f2==1 || f3==1|| f4==1) && counter2!=0)
					{

			    		counter2--;
						//fstr2=1;
				  	}

					if(d=="ADD")
					{
						f1=1;
					}
	  		        else if(d=="Find")
					{
						f2=1;
			    	}
					else if(d=="MOD")
					{
						f3=1;
					}
					else if(d=="DEL")
					{
						f4=1;
					}
			        else if(d=="Print")  f5=1;
				    d = "";
				}
				else
				{
					d = d + x;
				}
			}
			if(d=="Print")
			{
				for(unsigned int l=0;l<d.length();l++)
				{
					if (p>0)
					{
						cout<<"Invalid arguments"<<endl;
		        		break;
					}
				}
				if ( p==0) Print(TREE);
			}
			else if(d=="ADD")	cout<<"Invalid arguments"<<endl;
			else if(d=="Find")	cout<<"Invalid arguments"<<endl;
			else  if(d=="MOD")	cout<<"Invalid arguments"<<endl;
			else if(d=="DEL")	cout<<"Invalid arguments"<<endl;
			else if(f1==1)
			{
				for(unsigned int l=0;l<d.length();l++)
				{
					if (p!=3)
					{
						cout<<"Invalid arguments"<<endl;
						break;
					}
				}
				if ( p==3 )
				{

					ADD(str1,str2,d,TREE);
				}
			}
			else if(f2==1)
			{
				for(unsigned int l=0;l<d.length();l++)
				{
					if (p!=2)
					{
						cout<<"Invalid arguments"<<endl;
						break;
				    }
				}
				if ( p==2)
				{

				    Find(str2,d,TREE);
				}
			}
			else if(f3==1)
			{
				for(unsigned int l=0;l<d.length();l++)
				{
					if (p!=3)
					{
						cout<<"Invalid arguments"<<endl;
						break;
					}
				}
				if ( p==3)
				{
					MOD(str1,str2,d,TREE);
				}
			}
			else if(f4==1)
			{
			    for(unsigned int l=0;l<d.length();l++)
			    {
					if (p!=2)
					{
						cout<<"Invalid arguments"<<endl;
				        break;
				    }
				}
				if ( p==2)
				{
					Binary_search_tree* newtree=new Binary_search_tree;
					DEL(str2,d,TREE,newtree);
					delete(TREE);
					TREE=newtree;
				}
			}
			else if(f5==1)	cout<<"Invalid arguments"<<endl;
			else 			cout<<"Invalid command"<<endl;
			f1=0; f2=0; f3=0; f4=0; f5=0;
			p=0; counter=0;
			for(signed int  w=0;w<counter;w++)
			{
				arr[w]=0;
			}
			for(signed int  w=0;w<counter3;w++)
			{
				arr2[w]=0;
			}

			counter2=0; counter3=0;
		}
		file2.close();
	}
	return 0;
}
