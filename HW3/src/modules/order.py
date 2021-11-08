def inclusionSort(container):
    for i in range(1, len(container)):
        j = i
        while j > 0 and container[j] < container[j - 1]:
            container[j], container[j - 1] = container[j - 1], container[j]
            j -= 1
