import java.util.Scanner;

public class BinarySearch {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int n = in.nextInt();
        int[] a = new int[n];
        System.out.print("Enter elements in ascending order: ");
        for (int i = 0; i < n; i++)
            a[i]= in.nextInt();
        System.out.print("Enter element to be searched: ");
        int t = in.nextInt();
        System.out.println(binarySearch(a,t));
    }

    private static int binarySearch(int[] a, int t) {
        int start = 0, end = a.length - 1;
        while (start<=end){
            int mid = start + (end-start)/2 ;
            if(t<a[mid])
                end = mid-1;
            else if (t>a[mid])
                start = mid+1;
            else
                return mid;
        }
        return -1;
    }
}
