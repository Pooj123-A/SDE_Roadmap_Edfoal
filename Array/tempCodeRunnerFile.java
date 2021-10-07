package array;
import java.util.*;


public class BinarySearch {

    public static void main(String[] args) {

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
        isFound(arr,tar);


    }

    private static void isFound(int[] arr, int tar) {

        int l = 0;
        int h = arr.length-1;
        int mid ;
        int result=0;
        while(l<=h) {

            mid = l+(h-l)/2;
            if(arr[mid] == tar) {
                System.out.println("Element found at "+mid );
                return;
            }
            else if(arr[mid]<tar) {
                l=mid+1;
            }
            else {
                result=mid;
                h = mid-1;
            }
        }
        //mid will be the where the element has to be inserted or present.
        System.out.println("element should be inserted at "+ result);

    }

}