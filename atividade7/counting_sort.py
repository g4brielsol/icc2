def counting_sort(array:list) -> list:
    max_element = 0
    for number in array:
        if number > max_element:
            max_element = number
        
    count = [0 for i in range(max_element + 1)]
    for i in range(len(array)):
        count[array[i]] = count[array[i]] + 1
    for i in range(max_element + 1):
        for j in range(count[i]):
            print(i)

counting_sort([10,1,9,2,8,0,8,3,4,4,7,5,6])