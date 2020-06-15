class Solution {
    public int minTriple(int x, int y, int z){
        return Math.min(Math.min(x, y), z);
    }
    
    public int minDistance(String word1, String word2) {
        if(word1 == null || word2 == null){
            return -1;
        }
        if(word1.length() == 0 && word2.length() == 0){
            return 0;
        }else if(word1.length() == 0 && word2.length() != 0){
            return word2.length();
        }else if(word1.length() != 0 && word2.length() == 0){
            return word1.length();
        }
        if(word1.equals(word2)){
            return 0;
        }
        
        // use toCharArray() then we can replace charAt() with s1[idx]
        // char[] s1 = word1.toCharArray();
        // char[] s2 = word2.toCharArray();

        int size1 = word1.length();
        int size2 = word2.length();
        // dist[i][j]
        // the smallest distance to convert word1(0,i) to word2(0,j)
        int[][] dist = new int[size1][size2];
        
        // word1(0) to word2(0)
        if(word1.charAt(0) - word2.charAt(0) == 0){
            dist[0][0] = 0;
        }else{
            // replace
            dist[0][0] = 1;
        }
        
        // insert or delete if contains word1(0)
        for(int i = 1; i < size2; i++){
            if(word2.charAt(i) - word1.charAt(0) == 0){
                dist[0][i] = i;
            }else{
                dist[0][i] = dist[0][i-1] + 1;
            }
        }
        
        for(int i = 1; i < size1; i++){
            if(word1.charAt(i) - word2.charAt(0) == 0){
                dist[i][0] = i;
            }else{
                dist[i][0] = dist[i-1][0] + 1;
            }
        }
        
        for(int i = 1; i < size1; i++){
            for(int j = 1; j < size2; j++){
                if(word1.charAt(i) - word2.charAt(j) == 0){
                    dist[i][j] = dist[i-1][j-1];
                }else{
                    dist[i][j] = minTriple(
                        dist[i-1][j-1] + 1,
                        dist[i][j-1] + 1,
                        dist[i-1][j] + 1
                    );
                }
            }
        }
        
        return dist[size1-1][size2-1];
    }
}