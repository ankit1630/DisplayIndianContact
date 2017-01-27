#include<bits/stdc++.h>
#include<dirent.h>

using namespace std;
// driver program
int main()
{
    string direc,filep,number;
    regex rgx("((\\+91)|[0])?[-]?[789]\\d{9}");   //regex pattern
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
                //cout <<"Number from directory "<<filep<<endl ;
                while(file >> number)  // reading word by word
                {
                 if(regex_match(number,rgx))
                    {
                    	int n=number.length();
                    	n=n-10;
                    	cout<<number.substr(n,10)<<endl;
		    }
                }
                file.close();
            }
        }
    }
    return 0;
}
