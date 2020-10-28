# since it is not a comparing method, it must be different

def counting_sort(array:list) -> list:
    min_element = 0
    max_element = 0
    # find minimum element in array
    for number in array:
        if number < min_element:
            min_element = number

    # find biggest element in array
    for number in array:
        if number > max_element:
            max_element = number

    #offset max element by minimum value, it will make it bigger
    max_element = max_element - min_element

    # make list with max element length   
    count = [0 for i in range(max_element + 1)]
    # go through array indexes
    for i in array:
        # count how many times an element appears (if i == min_element -> is the first element of the array)
        count[i - min_element] +=  1
    
    #for all elements in array
    index = 0
    # loop how many times it appears (goes through a lot elements that count[i] == 0)
    for i in range(max_element + 1):
        # enter for loop when the range(count[i]) is bigger than 0 
        for j in range(count[i]):
            array[index] = i + min_element
            index += 1
    print(array)

counting_sort([500,-50,400,0,-1,-2,0,10,300,2,20,-1,-2,-3,-5])