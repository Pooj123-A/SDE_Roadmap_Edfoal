package Array;
import java.util.*;
public class RemoveValue {
    public  static void main(String args[]){

        Scanner sc = new Scanner(System.in);
        int n;
        System.out.println("Enter size of array");
        n = sc.nextInt();
        int arr[] = new int[n];

        System.out.println("Enter elements in array");

        for(int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println("Enter value to be remove from array");
        int val = sc.nextInt();
        //will take a pointer k, initially k=0
        // Now, while iterating through array we'll check the element at 'i' is equal to the val(value to be removed) or not.
//  If not it will simply put element present at 'i' position to the 'k' position and increment k.
//  But if it is equal then it will not put the 'i' element to 'k' and not increment 'k'.
//  After iterating throughout the array we'll get our result array from 0 to k-1 and we'll print the element (k-1)th index.
        int k = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i]!=val) {
                arr[k]=arr[i];
                k++;
            }
        }
        for(int i = 0; i < k; i++) {
            System.out.print(arr[i]+" ");
        }
    }
}
