//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*; 
class GFG{
    public static void main(String args[]) throws IOException { 
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine().trim());
        while(t-- > 0){
            String s = read.readLine().trim();
            Solution ob = new Solution();
            System.out.println(ob.firstRepChar(s));
        }
    }
}
// } Driver Code Ends


//User function Template for Java
class Solution 
{ 
    String firstRepChar(String s) 
    { 
        Set<Character> set = new HashSet<Character>();
        for(int i = 0 ; i < s.length() ; i++) {
            if(!set.contains(s.charAt(i))) {
                set.add(s.charAt(i));
            }
            else {
                String ans = String.valueOf(s.charAt(i));
                return ans;
            }
        }
        return "-1";
    }
    
} 