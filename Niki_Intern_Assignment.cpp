#include<bits/stdc++.h>
#include<dirent.h>

using namespace std;

bool isPhoneNumber(string s)
{
    if(s.size()==11 && s[0]=='0' && (s[1]=='7' || s[1]=='8' || s[1]=='9') )
    {
        for(int i=2;i<11;i++)
            if(s[i]>57 || s[i]<48)
                return false;
        return true;
    }
    else if(s.size()==13 && s.substr(0,3).compare("+91")==0 && (s[3]=='7' || s[3]=='8' || s[3]=='9'))
    {
        for(int i=4;i<13;i++)
            if(s[i]>57 || s[i]<48)
                return false;
        return true;
    }
    return false;
}

int main()
{
    string direc,filep,name,word;
    int number=0;
    DIR* ptr;
    struct dirent *dirp;
    cout<<"Enter file path: ";
    getline(cin,direc);
    ptr= opendir(direc.c_str());
    if(ptr==NULL)
    {
        cout<<"wrong directory";
    }
    else
    {
        while(dirp = readdir(ptr))
        {
            filep = direc + "/"+ dirp->d_name;
            ifstream file_(filep.c_str());
            if (file_.is_open())
            {
                cout <<"Number from "<<filep<<endl ;
                while(file_ >> word)
                {
                    if(isPhoneNumber(word))
                    cout<<word<<endl;
                }
                file_.close();
            }
        }
    }
    return 0;
}
