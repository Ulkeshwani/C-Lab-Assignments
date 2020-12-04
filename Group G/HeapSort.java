import java.util.*;

public class HeapSort
{
    private static int N;

    public static void Heap(int arr[])
    {
        MakeHeap(arr);
        for (int i = N; i > 0; i--)
        {
            Swap(arr,0, i);
            N = N-1;
            MaxHeap(arr, 0);
        }
    }

    public static void MakeHeap(int arr[])
    {
        N = arr.length-1;
        for (int i = N/2; i >= 0; i--)
            MaxHeap(arr, i);
    }

    public static void MaxHeap(int arr[], int i)
    {
        int left = 2*i ;
        int right = 2*i + 1;
        int max = i;
        if (left <= N && arr[left] > arr[i])
            max = left;
        if (right <= N && arr[right] > arr[max])
            max = right;

        if (max != i)
        {
            Swap(arr, i, max);
           MaxHeap(arr, max);
        }
    }

    public static void Swap(int arr[], int i, int j)
    {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    public static void main(String[] args)
    {
        Scanner scan = new Scanner( System.in );
        System.out.println("Heap Sort\n");
        int n, i;

        System.out.println("Enter number of integer elements");
        n = scan.nextInt();

        int arr[] = new int[ n ];

        System.out.println("\nEnter "+ n +" integer elements");
        for (i = 0; i < n; i++)
            arr[i] = scan.nextInt();
        Heap(arr);

        System.out.println("\nElements after sorting ");
        for (i = 0; i < n; i++)
            System.out.print(arr[i]+" ");
        System.out.println();
    }
}
