import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    database_csv = []

    filename = sys.argv[1]
    with open(filename) as file:
        file_reader = csv.DictReader(file)
        for row in file_reader:
            database_csv.append(row)

    # TODO: Read DNA sequence file into a variable

    file_name2 = sys.argv[2]
    with open(file_name2, 'r') as file_2:
        sequence_text = file_2.read()

    # TODO: Find longest match of each STR in DNA sequence

    # Empty dict to store longest_match count
    str_counts = {}

    # Extract DNA sequences from the keys of the "first" row in the database to exclude the "name" key
    dna_sequences = list(database_csv[0].keys())[1:]

    # iterate over dna sequence and find longest_match using the longest_match function
    for dna_sequence in dna_sequences:
        str_counts[dna_sequence] = longest_match(sequence_text, dna_sequence)

    # TODO: Check database for matching profiles

    # iterate over each profile in the database
    for profile in database_csv:
        # initialize counter to 0 and keep track of matches
        match_count = 0
        # iterate over dna sequence
        for dna_sequence in dna_sequences:
            # convert to int and check if dna sequence matches the str_counts/ if yes increment counter by 1
            if int(profile[dna_sequence]) == str_counts[dna_sequence]:
                match_count += 1
        # if there is a match print profile name
        if match_count == len(dna_sequences):
            print(profile["name"])
            return

    # if there is no match, print no match
    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
