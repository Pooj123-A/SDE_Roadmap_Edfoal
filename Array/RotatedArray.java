

import java.util.*;
public class RotatedArray {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter size of array");
        int n = sc.nextInt();

        int arr[] = new int[n];

        System.out.println("Enter array in increasing sorted format");
        for(int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.println("Enter target value");
        int tar = sc.nextInt();

        //Found function will find the position of the target and is the target is not present then will find the index where it can be inserted.
       int index= isFound(arr,tar);
       if(index>0)
         System.out.println("Element found at "+index);
        else
          System.out.println("Element Not Found");
    }

   public static int isFound(int[] nums, int target) {
        int low = 0,  high = nums.length-1;
        int mid;
        while(low <= high){
                mid = low + (high-low)/2;
                if(nums[mid] == target) return mid; //found the index
                
                //Search left part of the mid
                if(nums[low] <= nums[mid]){
                    if(target < nums[mid] && target >= nums[low])
                        high = mid-1;
                    else
                        low = mid+1;
                }
                
                //Search right part of the mid
                if(nums[mid] <= nums[high]){
                    if(target > nums[mid] && target <= nums[high])
                        low = mid+1;
                    else
                            high = mid-1;
                }
        }
        return -1;
    }

}