#include <iostream>
#include <math.h>

using namespace std;

int Heap[100001];
int Size=0;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    while(n>0){
        n--;
        int x;
        cin>>x;
        //pop
        if(x==0){
            if(Size==0){
                //cout<<"Empty pop req "<<0<<"\n";
                cout<<0<<"\n";
                continue;
            }
            //cout<<"Maximum: "<<Heap[1]<<"\n";
            cout<<Heap[1]<<"\n";
            Heap[1]=Heap[Size--];
            int idx=1;
            while(idx*2<=Size){
                int parent=idx;
                int left=idx*2;
                int right=idx*2+1;
                //right exist
                if(right<=Size){
                    if(abs(Heap[left])>abs(Heap[right])){
                        if(abs(Heap[parent])>abs(Heap[right])){
                            int temp=Heap[right];
                            Heap[right]=Heap[parent];
                            Heap[parent]=temp;
                            idx=right;
                            continue;
                        }
                        else if(abs(Heap[parent])==abs(Heap[right])){
                            if(Heap[parent]>Heap[right]){
                                int temp=Heap[right];
                                Heap[right]=Heap[parent];
                                Heap[parent]=temp;
                                idx=right;
                                continue;           
                            }
                            else break;
                        }
                        else break;
                    }

                    else if(abs(Heap[left])==abs(Heap[right])){
                        if(Heap[left]>=Heap[right]){
                            int temp=Heap[right];
                            Heap[right]=Heap[parent];
                            Heap[parent]=temp;
                            idx=right;
                            continue;                              
                        }
                        else{
                            int temp=Heap[left];
                            Heap[left]=Heap[parent];
                            Heap[parent]=temp;
                            idx=left;
                            continue;
                        }
                    }

                    else{
                        if(abs(Heap[parent])>abs(Heap[left])){
                            int temp=Heap[left];
                            Heap[left]=Heap[parent];
                            Heap[parent]=temp;
                            idx=left;
                            continue;
                        }
                        else if(abs(Heap[parent])==abs(Heap[left])){
                            if(Heap[parent]>Heap[left]){
                                int temp=Heap[left];
                                Heap[left]=Heap[parent];
                                Heap[parent]=temp;
                                idx=left;
                                continue;           
                            }
                            else break;
                        }
                        else break;
                    }
                }
                //only left
                else{
                    if(abs(Heap[parent])>abs(Heap[left])){
                        int temp=Heap[left];
                        Heap[left]=Heap[parent];
                        Heap[parent]=temp;
                        idx=left;
                        continue;
                    }
                    else if(abs(Heap[parent])==abs(Heap[left])){
                        if(Heap[parent]>Heap[left]){
                            int temp=Heap[left];
                            Heap[left]=Heap[parent];
                            Heap[parent]=temp;
                            idx=left;
                            continue;           
                        }
                        else break;
                    }
                    else break;
                }
            }
        }
        //insert
        else{
            //cout<<"insert: "<<x<<endl;
            Size++;
            Heap[Size]=x;
            int idx=Size;
            while(idx/2>0){
                int parent=idx/2;
                if(abs(Heap[idx])<abs(Heap[parent])){
                    int temp=Heap[idx];
                    Heap[idx]=Heap[parent];
                    Heap[parent]=temp;
                    idx=parent;
                    continue;
                }
                else if(abs(Heap[parent])==abs(Heap[idx])){
                    if(Heap[parent]>Heap[idx]){
                        int temp=Heap[idx];
                        Heap[idx]=Heap[parent];
                        Heap[parent]=temp;
                        idx=parent;
                        continue;           
                    }
                    else break;
                }
                else break;
            }
        }
        /*
        cout<<"Heap: ";
        for(int i=1;i<=Size;i++){
            cout<<Heap[i]<<" ";
        }
        cout<<endl;
        */
    }
    return 0;
}