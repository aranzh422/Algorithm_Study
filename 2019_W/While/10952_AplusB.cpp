#include <iostream>

using namespace std;

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(1){
        int a,b;
        cin>>a>>b;
        if(a==0&&b==0) return 0;
        cout<<a+b<<"\n";
    }
    
    return 0;
}