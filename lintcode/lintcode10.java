// this solution seems right but would cause to MLE
public class Solution {
    /**
     * @param str: A string
     * @return: all permutations
     */
    private void dfs(char[] s, boolean[] visited, List<Character> sublist, List<String> result){
        if(sublist.size() == s.length){
            String subresult = "";
            for(Character c : sublist){
                subresult += c;
            }
            result.add(subresult);
        }
        
        for(int i = 0; i < s.length; i++){
            if(visited[i]) continue;
            if(i > 0 && s[i] == s[i-1] && !visited[i-1]) continue;
            sublist.add(s[i]);
            visited[i] = true;
            dfs(s, visited, sublist, result);
            visited[i] = false;
            sublist.remove(sublist.size()-1);
        }
    } 
    
    public List<String> stringPermutation2(String str) {
        // write your code here
        List<String> result = new LinkedList<>();
        if(str.length() == 0 || str == null){
            String ss = "";
            result.add(ss);
            return result;
        }
        
        char[] s = str.toCharArray();
        Arrays.sort(s);
        dfs(s, new boolean[s.length], new ArrayList<>(), result);
        
        return result;
    }
}