/*
 * Binarysearchtree.h
 *
 *  Created on: Jun 7, 2021
 *      Author: Ahhmed Yaser and Ahmed Hany
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <iostream>
#include <string.h>
using namespace std;

#define BST_ElemType string

class Binary_search_tree
{
public:
	Binary_search_tree();
	~Binary_search_tree()
	{
		delete left_tree;
		delete right_tree;
		//cout<<"deleting"<<title<<" "<<day<<" "<<hour<<'\n';
	}
	void ADD(const BST_ElemType&,const int&,const int&);
	bool MOD(const BST_ElemType&,const int&,const int&);
	string print();
	string find(const int&,const int&);
	void DEL (const int&,const int&,Binary_search_tree*,bool&);
	bool isEmpty();
	//void dest();
private:
	BST_ElemType title ;
	int day;
	int hour;
	bool nulltree;
	Binary_search_tree* left_tree;
	Binary_search_tree* right_tree;
};

#endif
