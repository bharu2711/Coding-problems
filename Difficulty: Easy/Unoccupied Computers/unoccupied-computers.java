class Solution {
    public int solve(int n, String s) {
        // code here
        int []set=new int[26];
        int curr=0,ans=0;
        for(char c:s.toCharArray()){
            int idx=c-'A';
            if(curr<n && set[idx]==0){
                set[idx]=1;
                curr++;
            }
            else if(set[idx]==1) {
                set[idx]--;
                curr--;
            }
            else if(curr>=n && set[idx]!=-1){
                set[idx]=-1;
                ans++;
            }
        }
        return ans;
    }
}