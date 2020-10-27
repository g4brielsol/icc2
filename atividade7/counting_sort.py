def counting_sort(array:list) -> list:
    max_element = 0
    # find biggest element in array
    for number in array:
        if number > max_element:
            max_element = number

    # make list with max element length   
    count = [0 for i in range(max_element + 1)]
    # go through array indexes
    for i in range(len(array)):
        # count how many times an element appears
        count[array[i]] = count[array[i]] + 1
    
    #for all elements in array
    index = 0
    for i in range(max_element + 1):
        # loop how many times it appears
        for j in range(count[i]):
            array[index] = i
            index += 1
    print(array)

counting_sort([10,1,9,2,8,0,8,3,4,4,7,5,6])