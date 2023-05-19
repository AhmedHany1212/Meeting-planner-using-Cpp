/*
 * Binarysearchtree.cpp
 *
 *  Created on: Jun 7, 2021
 *      Author: Ahhmed Yaser and Ahmed Hany
 */

#include "Binarysearchtree.h"

Binary_search_tree::Binary_search_tree()
{
	nulltree=true;
	title="";
	day=0;
	hour=0;
	left_tree=NULL;
	right_tree=NULL;
}
void Binary_search_tree::ADD(const BST_ElemType& In_Title,const int& In_Day,const int& In_Hour)
{
	if (nulltree)
	{
	    title = In_Title;
	    day = In_Day;
	    hour = In_Hour;
	    left_tree = new Binary_search_tree;
	    right_tree =new Binary_search_tree;
	    nulltree=false;
	 }
	else if(day > In_Day||(day==In_Day && hour > In_Hour))
	    left_tree->ADD(In_Title,In_Day,In_Hour);
    else if(day < In_Day||(day==In_Day && hour < In_Hour))
		right_tree->ADD(In_Title,In_Day,In_Hour);
    else  cout<<"Conflict"<<" "<<In_Day<<" "<<In_Hour<<endl;
}

bool Binary_search_tree::MOD(const BST_ElemType& t,const int& d,const int& h)
{
	if(!nulltree) //if this tree is not empty
	{
		if(d==day&&h==hour) //if this tree is the tree I search for
		{
			title=t;     //modify the title of the tree
			return true;
		}
		else if (d>day||(d==day&&h>hour)) //if the tree i search for has data more than the right sup tree
		{
			return right_tree->MOD(t,d,h); //false if i have not found the node i wanted
		}
		else if (d<day||(d==day&&h<hour)) //if the tree i search for has data less than the left sup tree
		{
			return left_tree->MOD(t,d,h); //false if i have not found the node i wanted
		}
		else
		{
			return false;//false if i have not found the node i wanted
		}
	}
	else return false; //if the tree is empty
}

string Binary_search_tree::find(const int& In_Day,const int& In_Hour)
{
	string s1="Empty";
	string s =""+s1+" "+to_string(In_Day)+" "+to_string(In_Hour) ;
	if(!nulltree)
	{
		if(In_Day==day && In_Hour==hour)
		{
			return title;
		}
		else if (day > In_Day||(day==In_Day && hour > In_Hour))
		{
			return left_tree->find(In_Day,In_Hour);
		}
		else if (day < In_Day||(day==In_Day && hour < In_Hour))
		{
			return right_tree->find(In_Day,In_Hour);
		}
		else
		{
			return s;
		}
	}
	else return s; //if the tree is empty
}

string Binary_search_tree::print()
{
	string s="";
	string sl="";
	string sr="";
	if(!nulltree)
	{
		sl=left_tree->print();
		s=sl+title+" "+to_string(day)+" "+to_string(hour)+'\n';
		sr=right_tree->print();
		s=s+sr;
	}
	return s;
}
bool Binary_search_tree::isEmpty()
{
	return nulltree;
}

void Binary_search_tree::DEL(const int& d,const int& h,Binary_search_tree* newtree,bool& found)
{
	if(!nulltree)
	{
		left_tree->DEL(d,h,newtree,found);
		right_tree->DEL(d,h,newtree,found);
		if(!(h==hour && d==day))
			newtree->ADD(title,day,hour);
		else if(h==hour && d==day) found=true;
	}
}
