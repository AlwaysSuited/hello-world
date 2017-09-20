#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#define max 1000

string to_upper(string s) {
    string r;
    for(int i=0;i<s.length();i++) r += toupper(s[i]);
    return r;
}

int sum(string a[], int bw[], int count, string s) {
    int temp = 0;
    for(int i=0; i<count; i++) 
       if (a[i] == s) temp += bw[i];
    return temp;
}

int main(int argc, char *argv[]) {
    string from[max], to[max], distinct[max];
    int bw[max],lines,i=0,j, num=0, isum, osum;
    ifstream infile(argv[1]);
    while(infile>>from[i]>>to[i]>>bw[i]) {
        from[i] = to_upper(from[i]);
        to[i] = to_upper(to[i]);
        for(j=0; j<num; j++)
           if(from[i]==distinct[j]) break;
        if(j==num) distinct[num++] = from[i];
        for(j=0; j<num; j++)
           if(to[i]==distinct[j]) break;
        if(j==num) distinct[num++] = to[i];       
        i++;
    }
    lines = i;
    for(i=0;i<num;i++) cout << distinct[i] << endl;
    cout << endl << fixed << setprecision(2);
    for(i=0;i<num;i++) 
        if((osum=sum(from,bw,lines,distinct[i])) && (isum=sum(to,bw,lines,distinct[i])))
            cout <<distinct[i]<<" "<<osum<<" "<<isum<<" "<<isum/(float) osum<<endl;
}
