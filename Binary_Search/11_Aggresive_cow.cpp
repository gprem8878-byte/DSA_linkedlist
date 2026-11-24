// gfg problem : https://www.geeksforgeeks.org/problems/aggressive-cows/1
class Solution {
  public:
    int aggressiveCows(vector<int> &arr, int k) {
        int start = 1 ,end ,mid,ans; 
        
        // Sort stalls in increasing order to place cows greedily from left to right
        sort(arr.begin(),arr.end());
        
        // Maximum possible minimum distance is between the first and last stall
        end = arr[arr.size()-1]-arr[0];
        
        // Binary search on the answer (minimum distance)
        while(start<=end){
            mid = start+(end-start)/2;
            
            // Place the first cow at the first stall
            int cow = 1 , pos = arr[0];
            
            // Greedily check how many cows can be placed with at least 'mid' distance
            for(int i=0;i<arr.size();i++){
                if(pos+mid<=arr[i]){
                    cow++;
                    pos = arr[i];
                }
            }
            
            // If fewer than 'k' cows are placed, 'mid' distance is too large
            if(cow<k)
            end = mid-1;
            else
            {
                // Valid arrangement found; store 'mid' and try for a larger distance
                ans = mid;
                start = mid+1;
            }
        }
        return ans;
    }
};
