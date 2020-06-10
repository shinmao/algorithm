// attention: order of caculate water capacity
//              | 5 |
//  | 4 |///////|   |
//  |   | 2 |\\\|   | 
//  |   |   | 1 |   |
//  | _ | _ | _ | _ |
// for the water trapped in above
// we can calculate the part of backslash first
// then calculate the part of slash
// beats only over 10% of submission
class Solution {
    public int trap(int[] height) {
        if(height == null || height.length < 3) return 0;
        
        int water = 0;
        Stack<Integer> stack = new Stack<>();
        for(int i = 0; i < height.length; i++){
            int cur = height[i];
            while(!stack.isEmpty() && cur > height[stack.peek()]){
                int elevation = height[stack.pop()];
                if(stack.isEmpty()) break;
                int left = height[stack.peek()];
                int h = Math.min(left, cur) - elevation;
                int w = i - stack.peek() - 1;
                water += h*w;
            }
            stack.push(i);
        }
        
        return water;
    }
}