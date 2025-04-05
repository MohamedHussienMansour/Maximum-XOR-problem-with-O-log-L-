#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main(){
    int l,r;
    cin>>l>>r;
    int lenR=floor(log2(r))+1;
    int lenL=floor(log2(l))+1;
    vector<bool> rBin(lenL),lBin(lenL);
    vector<int> power2tab(lenL);
    int i=lenL-1,tempR=r,tempL=l,power=1;
    long long MaxXor=pow(2,lenR)-pow(2,lenL);
    while(i!=-1){
        rBin[lenL-i-1]=tempR%2;
        lBin[lenL-i-1]=tempL%2;
        tempR/=2;
        tempL/=2;
        power2tab[lenL-i-1]=power;
        power*=2;
        i--;
        
        
    }/*
    for(int t=0;t<lenL;t++){
        cout<<power2tab[t]<<" ";
    }
    cout<<"\n";
    for(int t=0;t<lenL;t++){
        cout<<lBin[t]<<" ";
    }
    cout<<"\n";

    for(int q=0;q<lenR;q++){
        cout<<rBin[q]<<" ";
    }
    cout<<"\n";*/
    int k=lenL-1;
    tempR=r,tempL=l;
    
    while(k!=-1){
        if(rBin[k]!=lBin[k]){
            if(tempR>tempL){
                if(rBin[k]==0 && tempR+power2tab[k]<=r && tempL-power2tab[k]>=l){

                    tempR+=power2tab[k];
                    tempL-=power2tab[k];
                    rBin[k]=1;
                    lBin[k]=0;
                }

            }else{
                if(rBin[k]==1 && tempR-power2tab[k]>=l && tempL+power2tab[k]<=r){

                    tempR-=power2tab[k];
                    tempL+=power2tab[k];
                    rBin[k]=0;
                    lBin[k]=1;
                }
            }
            MaxXor+=power2tab[k];
        }else{
            if(tempR>tempL){
                if(rBin[k]==1 && tempR-power2tab[k]>=l){
                    if(tempL-power2tab[k]>=l){
                        tempL-=power2tab[k];
                        lBin[k]=0;
                    }else{
                        tempR-=power2tab[k];
                        rBin[k]=0;
                    }
                    MaxXor+=power2tab[k];
                }else if(lBin[k]==0 && tempL+power2tab[k]<=r){
                    if(tempR+power2tab[k]<=r){
                        tempL+=power2tab[k];
                        rBin[k]=1;
                    }else{
                        tempL+=power2tab[k];
                        lBin[k]=1;

                    }
                    MaxXor+=power2tab[k];

                }
            }else{
                if(lBin[k]==1 && tempL-power2tab[k]>=l){
                    if(tempR-power2tab[k]>=l){
                        tempR-=power2tab[k];
                        rBin[k]=0;
                    }else{
                        tempL-=power2tab[k];
                        lBin[k]=0;
                    }
                    MaxXor+=power2tab[k];
                }else if(rBin[k]==0 && tempR+power2tab[k]<=r){
                    if(tempL+power2tab[k]<=r){
                        tempL+=power2tab[k];
                        lBin[k]=1;
                    }else{
                        tempR+=power2tab[k];
                        rBin[k]=1;

                    }
                    MaxXor+=power2tab[k];

                }
        }

    }
    k--;

    }
    
    /*
    for(int t=0;t<lenL;t++){
        cout<<lBin[t]<<" ";
    }
    cout<<"\n";

    for(int q=0;q<lenR;q++){
        cout<<rBin[q]<<" ";
    }cout<<"\n";
    */
    cout<<MaxXor;
    
}
