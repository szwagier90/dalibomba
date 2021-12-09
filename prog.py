import csv
import json

def find_subsets(data, target, partial=[]):
    partial_subsets = []

    s = sum(value for _, value in partial)

    # check if the partial sum is equals to target
    if s == target: 
        partial_subsets.append(partial)
    if s >= target:
        return partial_subsets  # if we reach the number why bother to continue
    
    for i in range(len(data)):
        n = data[i]
        remaining = data[i+1:]
        partial_subsets.extend(find_subsets(remaining, target, partial + [n]))

    # print(partial)
    return partial_subsets
   

if __name__ == "__main__":
    target = float(input("Podaj wartość do znalezienia: ").strip().replace(' ', ''))

    ready_data = {}

    with open('zzz.csv', newline='') as csvfile:
        ready_data = csv.reader(csvfile, delimiter=';')
        ready_data = [(k, v) for k, v, *_ in ready_data]
        ready_data = map(lambda x: (x[0], float(x[1].replace(' ', '').replace(',', '.'))), ready_data)
        ready_data = list(filter(lambda x: x[1] < target, ready_data))
        ready_data = list(filter(lambda x: x[1] > 0, ready_data))

    print("Data len: ", len(ready_data))
    all_subsets = find_subsets(ready_data, target)

    for subset in all_subsets:
        for s in subset:
            print(s)
        print('')
