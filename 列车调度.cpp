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
        if(len==0||a[len-1]<x)   //表为空，或者当前值比最后一个数小（实际上列表中为从小到大排序）
            a[len++] = x;
        else{
            int l = 0, r = len - 1;  //二分搜索
            while(l<r){
                int mid = (l + r) /2;
//                cout << mid; 
                if(a[mid]>x)
                    r = mid;    //中间值比x大，则缩小下边界
                else
                    l = mid + 1;   //左边界变大
            }
            a[l] = x;
        }
    }
    cout << len  << endl;
    //system("pause");
    return 0;
}
