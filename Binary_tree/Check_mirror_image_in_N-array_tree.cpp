class Solution {
 
  public:
    int checkMirrorTree(int n, int e, int a[], int b[]) {
         unordered_map<int,stack<int>> mapp;
         for(int i=0;i<2*e;i+=2)
         mapp[a[i]].push(a[i+1]);
         for(int i=0;i<2*e;i+=2){
         if(mapp[b[i]].top()!=b[i+1]) return 0; mapp[b[i]].pop();}
         return 1;
    }
    
};
