#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int main(){
    int n;
    cin >> n;
    int a[maxn];
    int len = 0;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        if(len==0||a[len-1]<x)
            a[len++] = x;
        else{
            int l = 0, r = len - 1;  //�������� 
            while(l<r){
                int mid = (l + r) /2;
//                cout << mid; 
                if(a[mid]>x)
                    r = mid;    //������С�߽� 
                else
                    l = mid + 1;
            }
            a[l] = x;
        }
    }
    cout << len  << endl;
    //system("pause");
    return 0;
}
