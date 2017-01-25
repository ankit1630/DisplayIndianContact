#include<bits/stdc++.h>
#include<dirent.h>

using namespace std;
/*the function return either it is a indian mobile contact or not*/
bool isPhoneNumber(string s)
{
    if(s.size()==11 && s[0]=='0' && (s[1]=='7' || s[1]=='8' || s[1]=='9') )//if mobile number starting with 0
    {
        for(int i=2;i<11;i++)
            if(s[i]>57 || s[i]<48)
                return false;
        return true;
    }
    else if(s.size()==13 && s.substr(0,3).compare("+91")==0 && (s[3]=='7' || s[3]=='8' || s[3]=='9'))//if number starting with +91
    {
        for(int i=4;i<13;i++)
            if(s[i]>57 || s[i]<48)
                return false;
        return true;
    }
    return false;
}
// driver program
int main()
{
    string direc,filep,number;
    DIR* ptr;
    struct dirent *dirp;
    cout<<"Enter file path: ";
    getline(cin,direc);               //input dirctory
    ptr= opendir(direc.c_str());
    if(ptr==NULL)                     // wrong directory
    {
        cout<<"wrong directory";
    }
    else
    {
        while(dirp = readdir(ptr))    //it execute current file and increment pointer to next file till it read all the file in that directory
        {
            filep = direc + "/"+ dirp->d_name;
            ifstream file(filep.c_str());
            if (file.is_open())      // opens a file
            {
                cout <<"Number from "<<filep<<endl ;
                while(file>> number)  // reading word by word
                {
                    if(isPhoneNumber(number))  //valid number test
                    cout<<number<<endl;
                }
                file.close();
            }
        }
    }
    return 0;
}
