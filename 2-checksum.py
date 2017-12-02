from sys import argv

def line_to_numbers(str):
    return [int(e) for e in str.split("\t") if e != ""]

def input_to_lines(str):
    return  str.split("\n")

if __name__ == '__main__':
    if len(argv) < 2:
        print("Please provide spreadsheet as argument")
        exit(1)
    
    input_str = argv[1]
    if len(argv) > 2 and argv[2] == "divisible":
        total_sum = 0
        for line in input_to_lines(input_str):
            numbers = line_to_numbers(line)
            for n in numbers:
                divisor = [e for e in numbers if e != n and n%e == 0]
                if divisor:
                    total_sum += int(n/divisor[0])
        print("The evenly dividible values sum is:", total_sum)
    else:
        max_ranges = [max(line_to_numbers(line)) - min(line_to_numbers(line)) for line \
            in input_to_lines(input_str)]
        print("The checksum is:", sum(max_ranges))
