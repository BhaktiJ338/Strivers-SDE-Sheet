int search(int* arr, int n, int key) {
    int l=0, h=n-1;

    while(l<=h){
        int mid = (h+l)/2;

        if(arr[mid]==key) return mid;
        else if(arr[l]<=arr[mid]){
            if(key>=arr[l] && key<=arr[mid]){
                h = mid-1;
            }
            else{
                l = mid+1;  
            }
        }
        else{
            if(key>=arr[mid] && key<=arr[h]){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        
    }
    return -1;
}
