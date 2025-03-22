#include<iostream>
#include<string>

using namespace std;

int main(){
    string answer;
    int numcount = 0,size=0; // numcount记录数字个数，size记录长度
    char tem;
    while(cin>>tem){
        if(tem>='0'&&tem<='9') numcount++;
        answer.push_back(tem);
        size++;
    }
    int newsize = size+numcount*5; // 重设数组大小
    answer.resize(newsize);

    int left=size-1,right=newsize-1; // 双指针，一个指向原数组最后，一个从新数组最后开始

    while(left>=0){
        if(answer[left]>='0'&&answer[left]<='9'){
            answer[right--]='r';
            answer[right--]='e';
            answer[right--]='b';
            answer[right--]='m';
            answer[right--]='u';
            answer[right--]='n';
            left--;
        }
        else{
            answer[right]=answer[left];
            right--;
            left--;
        }
    }
    for(const auto &it:answer)cout<<it;
}