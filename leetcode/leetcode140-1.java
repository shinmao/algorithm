// based on the idea of word break
// if problem changes to ask number of all possible segmentation sentence
public class Solution {
    public int wordBreak(String s, List<String> dict){
        if(s == null || s.length() == 0 || dict == null || dict.size() == 0) return 0;

        Set<String> set = new HashSet<>();
        for(String word : dict){
            set.add(word);
        }

        int len = s.length();
        int[] nums = new int[len+1];
        nums[len] = 1;

        for(int i = len-1; i >= 0; i--){
            for(int j = i; j <= len; j++){
                String prefix = s.substring(i, j);
                if(set.contains(prefix)){
                    nums[i] += nums[j];
                }
            }
        }

        return nums[0];
    }
}