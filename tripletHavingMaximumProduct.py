# Given an integer array, find a triplet having maximum product.

def maximum3(arr):
    is_zero = False
    result = arr[0]

    max1 = max(arr[0], arr[1], arr[2])
    max3 = min(arr[0], arr[1], arr[2])
    max2 = arr[0] + arr[1] + arr[2] - max1 - max3

    min1 = max3
    min2 = max2
    min3 = max1

    max_neg1 = 0
    max_neg2 = 0
    max_neg3 = 0

    total_positives = 0

    for i in range(3, len(arr)):
        if arr[i] > max1:
            max3, max2, max1 = max2, max1, arr[i]
        elif arr[i] == max1 or arr[i] > max2:
            max3, max2 = max2, arr[i]
        elif arr[i] == max2 or arr[i] > max3:
            max3 = arr[i]

        if arr[i] < min1:
            min3, min2, min1 = min2, min1, arr[i]
        elif arr[i] == min1 or arr[i] < min2:
            min3, min2 = min2, arr[i]
        elif arr[i] == min2 or arr[i] < min3:
            min3 = arr[i]

        if arr[i] > 0:
            total_positives += 1
        elif arr[i] == 0:
            is_zero = True

        else:
            if max_neg1 == 0:
                max_neg1 = arr[i]
            elif max_neg2 == 0:
                max_neg2 = arr[i]
            elif max_neg3 == 0:
                x, y = max_neg1, max_neg2
                max_neg1 = max(x, y, arr[i])
                max_neg3 = min(x, y, arr[i])
                max_neg2 = x + y + arr[i] - max_neg1 - max_neg3
            else:
                if arr[i] > max_neg1:
                    max_neg3, max_neg2, max_neg1 = max_neg2, max_neg1, arr[i]
                elif arr[i] == max_neg1 or arr[i] > max_neg2:
                    max_neg3, max_neg2 = max_neg2, arr[i]
                elif arr[i] == max_neg2 or arr[i] > max_neg3:
                    max_neg3 = arr[i]

    if total_positives >= 3:
        result = max(max1 * max2 * max3, max1 * min1 * min2)
        x, y, z = (max1, max2, max3) if max1 * max2 * max3 > max1 * min1 * min2 else (max1, min1, min2)
    elif 1 <= total_positives <= 2:
        result = max1 * min1 * min2
        x, y, z = max1, min1, min2
    elif is_zero:
        result = 0
        x, y, z = 0, max_neg1, max_neg2
    else:
        result = max_neg1 * max_neg2 * max_neg3
        x, y, z = max_neg1, max_neg2, max_neg3

    print(f"The triplet having the maximum product is: ({x}, {y}, {z}) and the maximum product is: {result}")

    return result


# Test Cases
arr1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
arr2 = [-2, -1, 0, 1, 2]
arr3 = [5, -2, -1, 3, 2]
arr4 = [-4, 1, -8, 9, 6]
arr5 = [1, 7, 2, -2, 5]

# Function calls
maximum3(arr1) #The triplet having the maximum product is: (10, 9, 8) and the maximum product is: 720
maximum3(arr2) #The triplet having the maximum product is: (2, -2, -1) and the maximum product is: 4
maximum3(arr3) #The triplet having the maximum product is: (5, -2, -1) and the maximum product is: 10
maximum3(arr4) #The triplet having the maximum product is: (9, -8, -4) and the maximum product is: 288
maximum3(arr5) #The triplet having the maximum product is: (7, -2, 1) and the maximum product is: -14
