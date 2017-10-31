#include<iostream>
#include<sstream>
#include<iterator>
#include<fstream>
#include <algorithm>
#include <list>

using namespace std;

 struct mem{
    string number;
    string voca="";
};

int main(int argc, char* argv[])
{
    string delim = " ";
    string check,voc,start,s;
    int clock = 1,turn=0,i =0,check_int=0;
    struct mem temp;
    list < mem> member;
    list<mem>::iterator memIterator=member.begin();
    fstream fin;
    fin.open(argv[1],ios::in);
    ofstream output;
    output.open (argv[2]);
    getline(fin, start, '\n');
    getline(fin, s, '\n');
    size_t begin_pos=0, end_pos=s.find(delim);// locate the first delimiter in string
    while(check_int>=0) {
        temp.number =s.substr(begin_pos, end_pos-begin_pos);
        member.push_back(temp); // extract the sub-string before current delimiter
        begin_pos = end_pos+delim.size();
        end_pos = s.find(delim, begin_pos);// locate the next delimiter in string
        check = s.substr(begin_pos, end_pos-begin_pos);
        stringstream ss(check);
        ss>> check_int;
    }
    memIterator=member.begin();
    while((*memIterator).number != start){
        memIterator++;
    }
    while(getline(fin, voc, '\n')){
        if(clock==1){
            for (i = 0;i<voc.length()-1;i++){
                (*memIterator).voca=(*memIterator).voca+voc[i];
                memIterator++;
                if(memIterator==member.end()) memIterator = member.begin();
            }
            (*memIterator).voca=(*memIterator).voca+voc[i];
            output<<(*memIterator).number <<" "<<(*memIterator).voca<<"\n";
            memIterator=member.erase(memIterator);
            if(voc[voc.length()-1]!='a'&&voc[voc.length()-1]!='e'&&voc[voc.length()-1]!='i'&&voc[voc.length()-1]!='o'&&voc[voc.length()-1]!='u'){
                clock = clock*-1;
                if(memIterator==member.begin()) memIterator = member.end();
                memIterator--;
            }
            else clock =clock*1;
            if(memIterator==member.end()) memIterator = member.begin();
        }
        else{
            for (i = 0;i<voc.length()-1;i++){
                (*memIterator).voca=voc[i]+(*memIterator).voca;
                if(memIterator==member.begin()) {
                    memIterator = member.end();
                    memIterator--;
                }
                else
                    memIterator--;
            }
            (*memIterator).voca=voc[i]+(*memIterator).voca;
            output<<(*memIterator).number <<" "<<(*memIterator).voca<<"\n";
            memIterator=member.erase(memIterator);
            if(voc[voc.length()-1]=='a'||voc[voc.length()-1]=='e'||voc[voc.length()-1]=='i'||voc[voc.length()-1]=='o'||voc[voc.length()-1]=='u'){
                clock = clock*1;
                if(memIterator==member.begin()) memIterator = member.end();
                memIterator--;
            }
            else clock = clock*-1;
            if(memIterator==member.end()) memIterator = member.begin();
        }
    }
    output<<(*memIterator).number <<" "<<(*memIterator).voca<<"\n";
    output.close();
    return 0;
}
