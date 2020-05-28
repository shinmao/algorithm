class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        if(text1 == null || text2 == null){
            return -1;
        }
        
        int size1 = text1.length();
        int size2 = text2.length();
        char[] c1 = text1.toCharArray();
        char[] c2 = text2.toCharArray();
        int[][] lcs = new int[size1][size2];
        
        if(c1[0] == c2[0]){
            lcs[0][0] = 1;
        }else{
            lcs[0][0] = 0;
        }
        
        for(int i = 1; i < size2; i++){
            if(lcs[0][i-1] == 1){
                lcs[0][i] = 1;
            }else{
                if(c1[0] == c2[i]){
                    lcs[0][i] = 1;
                }else{
                    lcs[0][i] = 0;
                }
            }
        }
        
        for(int j = 1; j < size1; j++){
            if(lcs[j-1][0] == 1){
                lcs[j][0] = 1;
            }else{
                if(c1[j] == c2[0]){
                    lcs[j][0] = 1;
                }else{
                    lcs[j][0] = 0;
                }
            }
        }
        
        int tmp;
        for(int i = 1; i < size1; i++){
            for(int j = 1; j < size2; j++){
                tmp = 0;
                if(c1[i] == c2[j]){
                    tmp = lcs[i-1][j-1] + 1;
                }
                lcs[i][j] = Math.max(Math.max(lcs[i-1][j], lcs[i][j-1]), tmp);
            }
        }
        
        return lcs[size1-1][size2-1];
    }
}