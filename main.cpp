#include <iostream>
#include<string>
using namespace std;

string getTime();
void convert(string ntime);

int main()
{

    string time;

    time= getTime();
    convert(time);

    return 0;
}


//-------------------------------------------
string getTime() // function to take time from user and makes user re-enters the time if his input is wrong
{
    unsigned short int len;
    string time;
    while(true){
    bool bol=0;
    cout<<"Enter the time in form (HH:MM am/pm) : ";
    getline(cin,time);
    len = time.length();
    if (len != 8){
        bol=1;
     }
    if (time[2]!= ':' ){
        bol=1;
     }
    if (time[5]!= ' '){
        bol=1;
       }
    if((time[0]=='1' )&&!(time[1]=='1'||time[1]=='2'||time[1]=='0'))
        {
        bol=1;
        }
    if (time[0]=='0'){
    if (!(time[1]=='0'||time[1]=='1'||time[1]=='2'||time[1]=='3'||time[1]=='4'||time[1]=='5'||time[1]=='6'||time[1]=='7'||time[1]=='8'||time[1]=='9')){
        bol=1;
   }
        }
        if(!(time[0]=='1' || time[0]=='0')){
            bol=1;
        }
    if (time[3]=='6'){
    if (time[4]!='0'){
        bol=1;
        }}
    if (time[3]=='0'||time[3]=='1'||time[3]=='2'||time[3]=='3'||time[3]=='4'||time[3]=='5'){
        if(!(time[4]=='0'||time[4]=='1'||time[4]=='2'||time[4]=='3'||time[4]=='4'||time[4]=='5'||time[4]=='6'||time[4]=='7'||time[4]=='8'||time[4]=='9')){
            bol=1;
    }}
    if (!(time[3]=='0'||time[3]=='1'||time[3]=='2'||time[3]=='3'||time[3]=='4'||time[3]=='5' ||time[3]=='6')){
        bol=1;
    }
    if(time[6]=='A' || time[6]=='a'){
        if (!(time[7]=='m' || time[7]=='M')){
            bol=1;
        }
    }
    if (time[6]=='P' || time[6]=='p'){
        if (!(time[7]=='m' || time[7]=='M')){
            bol=1;
        }
    }
    if (!(time[6]=='p'||time[6]=='P'||time[6]=='A'||time[6]=='a'))
        {
        bol=1;
    }
    if (bol==false)
        break;
    }
return time;
}
//-------------------------------------------
void convert(string ntime)
{
    unsigned short int hours = 0 , mins = 0;
    if(ntime[0] == '1')
        hours += 10;
    hours += ((unsigned short) int(ntime[1]) - 48);
    if(ntime[6] == 'p' || ntime[6] == 'P')
        hours += 12;
    mins+=(((unsigned short) int(ntime[3]) - 48) * 10); //convert string to it's ascci number
    mins+=((unsigned short) int(ntime[4]) - 48);        //convert string to it's ascci number

    if(hours == 12)
        hours = 0;

    if (hours == 24 ){
        hours=12;}


    if (hours < 10)
        cout<<"0";
    if (mins == 0)
     cout<<hours<<mins<<mins;
     else if (mins  < 10)
        cout<<hours<<"0"<<mins;
        if (mins >=10)
            cout<<hours<<mins;
    cout<<"  hours"<<endl;

}
