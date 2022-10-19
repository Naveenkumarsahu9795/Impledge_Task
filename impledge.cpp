#include<bits/stdc++.h>
#define int long long
using namespace std;

// Structude of the Trie Node with 26 child Nodes 

struct TrieNode{
    TrieNode *data[26];
    bool isEnd=false;
    
    TrieNode()
    {
        for(int i=0;i<26;i++)
            data[i]=NULL;
    }
};

// Checking if the string is present in the Root Node 

bool if_Present(string s,TrieNode * root)
{
	for(auto a:s)
	{
		if(root->data[a-'a'])
			root=root->data[a-'a'];
		else
		return false;
	}
	return root->isEnd;
}

// Checking the Validity of the string 

bool if_Valid(int i,string s,int count,TrieNode * root)
{
	if(i==s.size())
	{
        if(count>1)
        return true;
        else
        return false;
    }
	
	for(int k=1;k<=s.size()-i;k++)
	{
		if(if_Present(s.substr(i,k),root) && if_Valid(i+k,s,count+1,root))
		return true;	
	}	
	
	return false;
}

// Custom Comparator Function for comparing Strings

bool comp(string &a,string &b)
{
	return a.size()>b.size();
}



int32_t main()
{
	ios_base::sync_with_stdio(false);
	
	int n;
    
    cout<<"Enter Number Number of Inputs"<<endl;
	cin>>n;
	string s;
	vector<string> v;

    for(int i=0;i<n;i++)
    {
        cin>>s;
        v.push_back(s);
    }

    TrieNode * root=new TrieNode();

    // Creating Root Node for Trie

	for(int i=0;i<n;i++)
	{
		TrieNode * temp=root;
		
		for(auto x:v[i])
		{
			if(temp->data[x-'a'])
			{
				temp=temp->data[x-'a'];
			}
			else
			{
				temp->data[x-'a']=new TrieNode();
				temp=temp->data[x-'a'];
			}
		}
		temp->isEnd=true;
	}
	
	vector<string> Values;
	
	for(int i=0;i<n;i++)
	{
		if(if_Valid(0,v[i],0,root))
		Values.push_back(v[i]);
	}
	
	sort(Values.begin(),Values.end(),comp);
	
    cout<<endl;

	cout<<"First Largest Value:- "<<Values[0]<<endl;
    cout<<"Second Largest Value:- "<<Values[1]<<endl;
	
	return 0;
}