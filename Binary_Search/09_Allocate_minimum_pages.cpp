// gfg problem : https://practice.geeksforgeeks.org/pr...
class Solution {
  public:
    int findPages(vector<int> &arr, int k) {

        // If students are more than books, allocation is impossible
        if(k > arr.size())
            return -1;

        // Binary Search on Answer: search for the minimum possible maximum pages
        long long start = 0, end = 0, mid, ans;

        // Find the search space:
        // Minimum limit = maximum pages in a single book
        // Maximum limit = sum of pages of all books
        for(int i = 0; i < arr.size(); i++) {
            start = max(start, (long long)arr[i]);
            end += arr[i];
        }

        // Binary Search to find the smallest valid page limit
        while(start <= end) {

            // Assume mid is the maximum pages allowed per student
            mid = start + (end - start) / 2;

            // page = pages allocated to the current student
            // count = number of students required for this page limit
            long long page = 0;
            int count = 1;

            // Greedy allocation: assign books in their original order
            for(int i = 0; i < arr.size(); i++) {

                // Try adding the current book to the current student
                page += arr[i];

                // If the page limit is exceeded, assign this book to a new student
                if(page > mid) {
                    count++;        // Increase the number of students required
                    page = arr[i];  // Start the new student's allocation with this book
                }
            }

            // Check whether all books can be allocated using at most k students
            if(count <= k) {

                ans = mid;      // Current limit is a possible answer

                // We need to minimize the maximum pages,
                // so search for a smaller valid limit in the left half
                end = mid - 1;
            }
            else {

                // Current limit is too small because more than k students are needed
                // Increase the allowed pages by searching in the right half
                start = mid + 1;
            }
        }

        // Return the smallest feasible maximum page allocation
        return ans;
    }
};
