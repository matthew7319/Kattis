#include <bits/stdc++.h>
using namespace std;

typedef pair< int, int> ii;         // parent, rank
ii arr[1000000];                    // index represents the value

int find_parent( int n){
    if(arr[n].first==-1)
        return n;
    vector<int>v;
    while( arr[n].first != -1){
        v.push_back(n);
        n = arr[n].first;
    }
    for(auto x:v)
        arr[x].first=n;   // optimization
    return n;
}

void union_join( int n1, int n2){
    int start1 = n1;
    int start2 = n2;
    int super_parent;
    n1 = find_parent(n1);
    n2 = find_parent(n2);

    // same parent so do nothing
    if( n1 == n2){
        //do nothing
    }
    // n2 parent is the new super-parent
    else if( arr[n2].second > arr[n1].second ){
        arr[n1].first = n2;
        super_parent = n2;

    }
    // n1 parent is the new super-parent
    else if( arr[n1].second > arr[n2].second ){
        arr[n2].first = n1;
        super_parent = n1;
    }
    // n1 parent is the new super-parent + rank ++;
    else{
        arr[n2].first = n1;
        super_parent = n1;
        arr[n1].second++;
    }
    if( arr[n1].first != -1)
        n2 = super_parent;
    if( arr[n2].first != -1)
        n2 = super_parent;    
}

void reset(){
    for(int i=0; i<1000000; i++){
        arr[i] = ii(-1, 0);
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    reset();
    int i, n, q;
    scanf("%d %d", &n, &q);

    char ch;
    int n1, n2;

    for( i=0; i<q; i++){
        scanf("%c", &ch);

        scanf("%c %d %d", &ch, &n1, &n2);
        if( ch == '='){
            union_join(n1, n2);
        }
        else{
            if( find_parent(n1) == find_parent(n2))
                printf("yes\n");
            else
                printf("no\n");
        }
    }
}
