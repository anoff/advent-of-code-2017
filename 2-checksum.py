from sys import argv

def line_to_numbers(str):
    return [int(e) for e in str.split("\t") if e != ""]

def input_to_lines(str):
    return  str.split("\n")

if __name__ == '__main__':
    input_str = argv[1]
    max_ranges = [max(line_to_numbers(line)) - min(line_to_numbers(line)) for line in input_to_lines(input_str)]
    print(sum(max_ranges))
