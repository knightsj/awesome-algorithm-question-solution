import java.util.Arrays;

public class Main {

    public static void main(String[] args) {

        System.out.println("Hello World!");

        // test for bubble sort
        int arr[] = new int[]{1,6,2,2,5};
        BubbleSort(arr);
        System.out.println(Arrays.toString(arr));


        // test for selection sort
        int arr1[] = new int[]{7,6,0,1,5};
        SelectionSort(arr1);
        System.out.println(Arrays.toString(arr1));


        // test for insertion sort
        int arr2[] = new int[]{10,2,8,4,1};
        InsertionSort(arr2);
        System.out.println(Arrays.toString(arr2));


        // test for quick sort
        int arr3[] = new int[]{10,8,4,9,2,1,5,3};
        QuickSort(arr3, 0, arr3.length-1);
        System.out.println(Arrays.toString(arr3));


    }


    public static void BubbleSort(int[] arr) {

        int n = arr.length;

        for( int i = 0; i < n-1; i++ ){

            for( int j = 0; j < n - i - 1; j++ ){

                if( arr[j+1] < arr[j] ){

                    int tmp;

                    tmp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = tmp;
                }
            }
        }
    }


    public static void SelectionSort(int[] arr) {

        int n = arr.length;

        for ( int i = 0; i < n; i++){

            int min = i;

            for ( int j = i + 1; j < n; j++){

                if (arr[min] > arr[j]){
                    min = j;
                }
            }

            if (min != i){

                int tmp;
                tmp = arr[i];
                arr[i] = arr[min];
                arr[min] = tmp;
            }

        }
    }

    public static void InsertionSort(int[] arr) {

        int n = arr.length;

        for ( int i = 1; i < n; i ++){

            for (int j = i; j > 0; j --){

                if (arr[j] < arr[j - 1]){

                    int tmp;
                    tmp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = tmp;

                }else{

                    break;

                }
            }
        }
    }






    public static void QuickSort(int[] array,int low ,int high){

        if(low>=high){

            return ;
        }

        int index=partition(array,low,high);

        QuickSort(array,low,index-1);
        QuickSort(array,index+1,high);
    }

    public static int partition(int []array,int low,int high){

        int mid = low + (high - low)/2;

        if( array[mid] > array[high] ){

            swap(array[mid],array[high]);
        }

        if( array[low] > array[high] ){
            swap(array[low],array[high]);
        }

        if( array[mid] > array[low] ){
            swap(array[mid],array[low]);
        }

        int key = array[low];

        while(low < high){

            while( array[high] >= key && high > low ){
                high--;
            }

            array[low] = array[high];

            while( array[low] <= key && high > low ){
                low++;
            }

            array[high] = array[low];
        }

        array[high] = key;

        return high;
    }

    public static void swap(int a,int b){

        int temp=a;
        a = b;
        b = temp;
    }




}
