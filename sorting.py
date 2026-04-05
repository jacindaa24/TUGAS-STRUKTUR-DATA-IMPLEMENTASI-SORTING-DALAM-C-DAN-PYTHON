def print_array(msg, arr):
    print(f"{msg}: {arr}")

def bubble_sort(arr):
    n = len(arr)
    data = arr.copy()
    print("\n--- BUBBLE SORT ---")
    for i in range(n):
        swapped = False
        for j in range(0, n-i-1):
            if data[j] > data[j+1]:
                data[j], data[j+1] = data[j+1], data[j]
                swapped = True
        print_array(f"Iterasi ke-{i+1}", data)
        if not swapped:
            break
    print_array("Hasil Akhir Bubble Sort", data)

def selection_sort(arr):
    n = len(arr)
    data = arr.copy()
    print("\n--- SELECTION SORT ---")
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if data[min_idx] > data[j]:
                min_idx = j
        data[i], data[min_idx] = data[min_idx], data[i]
        print_array(f"Iterasi ke-{i+1}", data)
    print_array("Hasil Akhir Selection Sort", data)

def insertion_sort(arr):
    data = arr.copy()
    print("\n--- INSERTION SORT ---")
    for i in range(1, len(data)):
        key = data[i]
        j = i-1
        while j >= 0 and key < data[j]:
            data[j+1] = data[j]
            j -= 1
        data[j+1] = key
        print_array(f"Iterasi ke-{i}", data)
    print_array("Hasil Akhir Insertion Sort", data)

def quick_sort_recursive(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        print_array(f"Proses Partisi (pivot {arr[pi]})", arr)
        quick_sort_recursive(arr, low, pi-1)
        quick_sort_recursive(arr, pi+1, high)

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] <= pivot:
            i = i + 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i+1], arr[high] = arr[high], arr[i+1]
    return i + 1

def run_quick_sort(arr):
    data = arr.copy()
    print("\n--- QUICK SORT ---")
    quick_sort_recursive(data, 0, len(data)-1)
    print_array("Hasil Akhir Quick Sort", data)

def merge_sort_recursive(arr):
    if len(arr) > 1:
        mid = len(arr)//2
        L = arr[:mid]
        R = arr[mid:]

        merge_sort_recursive(L)
        merge_sort_recursive(R)

        i = j = k = 0
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1

        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1
        print_array("Proses Merge", arr)

def run_merge_sort(arr):
    data = arr.copy()
    print("\n--- MERGE SORT ---")
    merge_sort_recursive(data)
    print_array("Hasil Akhir Merge Sort", data)

if __name__ == "__main__":
    try:
        n = int(input("Masukkan jumlah data: "))
        data_awal = []
        for i in range(n):
            angka = int(input(f"Masukkan data ke-{i+1}: "))
            data_awal.append(angka)
        
        print(f"\nData awal: {data_awal}")
        
        bubble_sort(data_awal)
        selection_sort(data_awal)
        insertion_sort(data_awal)
        run_quick_sort(data_awal)
        run_merge_sort(data_awal)
        
    except ValueError:
        print("Harap masukkan angka yang valid.")