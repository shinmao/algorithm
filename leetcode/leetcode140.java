// think from dictionary
// each substring can be start from one word in dictionary
// use hashmap to do memoization
// if we already find a way to segment the string with specific prefix
// we don't need to work again on it next time
// only beats over 37% of submission
class Solution {
    public List<String> dfs(String s, List<String> dict, Map<String, List<String>> map){
        if(map.containsKey(s)){
            return map.get(s);
        }
        
        List<String> result = new LinkedList<>();
        
        if(s.length() == 0){
            result.add("");
            return result;
        }
        
        for(String d : dict){
            if(s.startsWith(d)){
                List<String> sublist = dfs(s.substring(d.length()), dict, map);
                for(String t : sublist){
                    result.add(d + (t.length() > 0 ? " " : "") + t);
                }
            }
        }
        
        map.put(s, result);
        return result;
    }
    
    public List<String> wordBreak(String s, List<String> wordDict) {
        List<String> result = new LinkedList<>();
        if(s.length() == 0) return result;
        
        return dfs(s, wordDict, new HashMap<String, List<String>>());
    }
}

// size of wordDict might be so large
// beats only over 5% of submission
class Solution {
    Map<String, List<String>> map = new HashMap<>();
    public List<String> wordBreak(String s, List<String> wordDict) {
        if(map.containsKey(s)){
            return map.get(s);
        }
        
        List<String> result = new LinkedList<>();
        if(s.length() == 0){
            return result;
        }
    
        if(wordDict.contains(s)){
            result.add(s);
        }
        
        for(int i = 1; i <= s.length(); i++){
            String word = s.substring(0, i);
            if(wordDict.contains(word)){
                List<String> sublist = wordBreak(s.substring(i), wordDict);
                if(sublist.size() != 0){
                    for(String sub : sublist){
                        result.add(word + " " + sub);
                    }
                }
            }
        }
        
        map.put(s, result);
        
        return result;
    }
}