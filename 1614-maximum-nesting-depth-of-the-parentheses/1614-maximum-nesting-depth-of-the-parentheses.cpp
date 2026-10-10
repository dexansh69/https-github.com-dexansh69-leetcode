class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int count=0;
        int max=0;
       for(int i=0;i<n;i++){
        if(s[i]=='('){
            count++;
            if(max<count){
                max=count;
            }
        }else{
            if(s[i]==')'){
                count--;
            }
        }
    }
        return max;
}
};